#include"control.h"

int main()
{
	Game view;

	view.MainInIt();
	view.ShopInIt();
Main:	//Place Code 0
	while(1)
	{
		view.RefreshMain();
		if(view.NowPlace == 1) goto Shop;
		if(view.NowPlace == 99) goto EndGame;
	}

Shop:	//Place Code 1
	while(1)
	{
		view.RefreshShop();
		if(view.NowPlace == 0) goto Main;
		if(view.NowPlace == 99) goto EndGame;
	}

EndGame:	//Place Code 99
	cout << '\n';
	return 0;
}

//Game private

/* When loading window in the end.
 * This window will keep running.
 * Such that player home page.
 * Display the player's current status. */
void Game::MainPage(int control)
{
	system("clear");
	system("clear");

	if('9' >= control && control >= '0')
	{
		if(control == '0') control += 10;
		if(FLvalue.FarmlandNumber > control - 49)
		{
			FLvalue.chose[this->FarmlandChose] = "";
			this->FarmlandChose = control - 49;
		}
	}
	FLvalue.chose[this->FarmlandChose] = "<-";

	cout << "My farmland" << "\n\n";
	cout << "Farmland Name\t\tStatus\t\tTime\t\n";
	for(int a=0;FLvalue.FarmlandNumber>a;a++)
	{
		cout << "Farmland NO." << a+1 << "\t\t" << FLvalue.status[a];
		if(FLvalue.status[a] == "idle") cout << "\t\t-:-:-\t";
		else cout << "\t";	//not finish!!!!!
		cout << FLvalue.chose[a] << '\n';
	}

	cout << "\nWhat are you want to go?\n";
	cout << "    Shop(S)    Quit(Q)\n\n\n";

	cout << "Instructions:\n";
	cout << "  1.Keyboard number keys select the farmland.\n";

	cout << "\nRemark: Plase wait screen refreshed, then enter the next command.\n";

	if(control == 300) system("sleep 1s");
}

void Game::ShopPage(int control)
{
	system("clear");
	system("clear");

	if(control == 'N' || control == 'n')
		if(Merchandise.HowMuchMerchandise > this->SubShopPageNow + 10) this->SubShopPageNow += 10;

	if(control == 'B' || control == 'b')
		if(this->SubShopPageNow - 10 >= 0) this->SubShopPageNow -= 10;

	if('9' >= control && control >= '0')
	{
		if(control == '0') control += 10;
		for(int a=0;PAR>a;a+=10) Merchandise.chose[this->ShopChose + a] = "";
		this->ShopChose = control - 49;
	}
	if(this->SubShopPageNow + 10 > Merchandise.HowMuchMerchandise)
	{
		for(int a=0;PAR>a;a+=10) Merchandise.chose[this->ShopChose + a] = "";
		if(this->ShopChose > Merchandise.HowMuchMerchandise % 10)
			this->ShopChose =  Merchandise.HowMuchMerchandise % 10 - 1;
	}
	for(int a=0;PAR>a;a+=10) Merchandise.chose[this->ShopChose + a] = "<-";

	long unsigned int tab;
	if(this->SubShopPageNow == 0) tab = 6;
	else tab = 5;

	cout << "Welcome to Zhang7391's store!\n";
	cout << "Although it's author store, it's not cheaper.\n\n";

	cout << "Name\t\tSell\tbuy\town\n";
	for(int a=this->SubShopPageNow;this->SubShopPageNow + 10>a;a++)
	{
		if(Merchandise.Name[a] == "") break;

		cout << a+1 << '.' << Merchandise.Name[a];
		if(Merchandise.Name[a].length() >= tab) cout << "\t";
		else cout << "\t\t";
		cout << Merchandise.SellPrice[a] << "\t";
		cout << Merchandise.AcquisitionPrice[a] << "\t";
		cout << push.SHaveNumber[a] << "\t";
		cout << Merchandise.chose[a] << '\n';
	}
	cout << "\t\tPage " << this->SubShopPageNow / 10 + 1 << '/';
	if(Merchandise.HowMuchMerchandise % 10 == 0) cout << Merchandise.HowMuchMerchandise / 10 << '\n';
	else cout << Merchandise.HowMuchMerchandise / 10 + 1 << '\n';

	cout << "\n   Previous page(B)\tNext Page(N)\n\n";

    cout << "\nWhat are you want to go?\n";
	cout << "    Home(M)    Quit(Q)\n\n";

	cout << "Instructions:\n";
	cout << "  1.Keyboard number keys select the merchandise.\n";

	if(control == 300) system("sleep 1s");
}

//Game public

/* Control display window now.
 * And keep Refreshing the MainPage. */
void Game::RefreshMain(void)
{
	if(kbhit())
	{
		int control = getch();

		if(control == 's' || control == 'S') this->NowPlace = 1;
		if(control == 'q' || control == 'Q') this->NowPlace = 99;

		this->MainPage(control);
	}
	else this->MainPage(300);
}

/* When player first opening this game.
 * First welcome player's window. */
void Game::MainInIt(void)
{
	string ShowFull("Welcome to this large farmland!");
	int JumpTime = ShowFull.length();
	int Jump = 0;

	for(int a=0;UNI>a;a++) FLvalue.status[a] = "idle";

	while(JumpTime >= Jump)
	{
		system("clear");
		system("clear");

		string ShowDown = ShowFull;
		string ShowUp(JumpTime, ' ');

		ShowUp[Jump] = ShowFull[Jump];
		ShowDown[Jump] = ' ';

		cout << "My farmland" << "\n\n";

		cout << "Farmland Name\t\tStatus\t\tTime\t\t\n";
		for(int a=0;FLvalue.FarmlandNumber>a;a++) cout << "Farmland NO." << a+1 << "\t\tloading...\tloading...\n";

		cout << "\n" << ShowUp << '\n';	//jump text
		cout << ShowDown << "\n";

		Jump++;
		system("sleep 0.09s");
	}
}

/* 1.Control display window now.
 * 2.keep Refreshing the Store Page. */
void Game::RefreshShop(void)
{
	if(kbhit())
	{
		int control = getch();

		if(control == 'M' || control == 'm') this->NowPlace = 0;
		if(control == 'Q' || control == 'q') this->NowPlace = 99;

		this->ShopPage(control);
	}
	else this->ShopPage(300);
}

/* 1.When game initialization, loading the store merchandise information. 
 * 2.Initialization the backpack information. */
void Game::ShopInIt(void)
{
	string clear;
	ifstream ui;
	ui.open("store_merchandise");

	while(getline(ui, Merchandise.Name[Merchandise.HowMuchMerchandise]))
	{
		ui >> Merchandise.SellPrice[Merchandise.HowMuchMerchandise];
		ui >> Merchandise.AcquisitionPrice[Merchandise.HowMuchMerchandise] >> clear;

		push.SName[Merchandise.HowMuchMerchandise] = Merchandise.Name[Merchandise.HowMuchMerchandise];
		push.SHaveNumber[Merchandise.HowMuchMerchandise] = 0;

		ui.ignore();
		Merchandise.HowMuchMerchandise += 1;
	}
}
