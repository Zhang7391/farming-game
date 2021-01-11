#include"control.h"

int main()
{
	Page view;

//	int keyboard;
	view.main();

	while(1)
	{
		break;
	}

	return 0;
}

//Page private
void Page::MainInIt(int JumpTime, string ShowFull)
{
	int Jump = 0;
	while(JumpTime >= Jump)
	{
		Game value;
		system("clear");
		system("clear");

		string ShowDown = ShowFull;
		string ShowUp(JumpTime, ' ');

		ShowUp[Jump] = ShowFull[Jump];
		ShowDown[Jump] = ' ';

		cout << "My farmland" << "\n\n";

		cout << "Farmland Name\tStatus\t\tTime\t\t\n";
		for(int a=0;value.FarmlandNumber>a;a++) cout << "Farmland NO." << a+1 << "\tloading...\tloading...\n";

		cout << "\n" << ShowUp << '\n';	//jump text
		cout << ShowDown << '\n';

		Jump++;
		system("sleep 0.09s");
	}
}

//Page public
void Page::main()
{
	Game value;

	string ShowFull("Welcome to this large farmland!");
	int ShowFullLong = ShowFull.length();

	this->MainInIt(ShowFullLong, ShowFull);
}
