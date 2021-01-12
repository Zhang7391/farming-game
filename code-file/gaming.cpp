#include"control.h"

int main()
{
	Page view;
	AllValue value;

	string ShowFull("Welcome to this large farmland!");
	int ShowFullLong = ShowFull.length();

	view.MainInIt(ShowFullLong, ShowFull);
	view.main(300);

	while(1)
	{
		if(kbhit())
		{
			view.main(getch());
		}
		else view.main(300);
	}

	return 0;
}

//Page private

/* When player first opening this game.
 * First welcome player's window. */
void Page::MainInIt(int JumpTime, string ShowFull)
{
	int Jump = 0;
	while(JumpTime >= Jump)
	{
		AllValue value;
		system("clear");
		system("clear");

		string ShowDown = ShowFull;
		string ShowUp(JumpTime, ' ');

		ShowUp[Jump] = ShowFull[Jump];
		ShowDown[Jump] = ' ';

		cout << "My farmland" << "\n\n";

		cout << "Farmland Name\t\tStatus\t\tTime\t\t\n\n";
		for(int a=0;value.FarmlandNumber>a;a++) cout << "Farmland NO." << a+1 << "\t\tloading...\tloading...\n";

		cout << "\n" << ShowUp << '\n';	//jump text
		cout << ShowDown << "\n";

		Jump++;
		system("sleep 0.09s");
	}
}

//Page public

/* When loading window in the end.
 * This window will keep running.
 * Such that player home page.
 * Mark the player's current status. */
void Page::main(int control)
{
	AllValue value;
	system("clear");
	system("clear");

	if(57 >= control && control >= 48)
	{
		if(control == 48) control += 10;
		if(value.FarmlandNumber > control - 49)
		{
			value.FarmlandInfo[this->FarmlandChose].chose = "";
			this->FarmlandChose = control - 49;
		}
	}
	value.FarmlandInfo[this->FarmlandChose].chose = "<-";

	cout << "My farmland" << "\n\n";
	cout << "Farmland Name\t\tStatus\t\tTime\t\n\n";
	for(int a=0;value.FarmlandNumber>a;a++)
	{
		cout << "Farmland NO." << a+1 << "\t\t" << value.FarmlandInfo[a].status;
		if(value.FarmlandInfo[a].status == "idle") cout << "\t\t-:-:-\t";
		else cout << "\t";	//not finish!!!!!
		cout << value.FarmlandInfo[a].chose << "\n";
	}

	cout << "\nInstructions:\n";
	cout << "  1.Keyboard number keys select the farmland.\n";

	cout << "\nRemark: Plase wait screen refreshed, then enter the next command.\n";

	if(control == 300) system("sleep 1s");
}
