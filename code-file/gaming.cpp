#include"control.h"

int main()
{
	Page view;

	int keyboard;
	view.main();

	while(1)
	{
		break;
	}

	return 0;
}

//Page public
void Page::main()
{
	string ShowFull("Welcome to this large farmland!");
	int JumpTime = ShowFull.length();
	string ShowDown = ShowFull;
	string ShowUp(JumpTime, ' ');

	int Jump=0;
	while(JumpTime >= Jump)
	{
		system("clear");
		
		ShowUp[Jump] = ShowFull[Jump];
		ShowDown[Jump] = ' ';

		cout << '\n' << ShowUp << '\n';
		cout << ShowDown << '\n';

		ShowUp[Jump] = ' ';
		ShowDown[Jump] = ShowFull[Jump];

		Jump++;
		system("sleep 0.09s");
	}

//cout << ShowFull[5] << '\n';
}
