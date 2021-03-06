#include"control.h"

int main()
{
	view.MainInIt();
	view.ShopInIt();

	while(1)
	{
		while(1) //Main -> place Code 0
		{
			if(view.NowPlace != 0) break;
			view.RefreshMain();
		}
		while(1) //Shop -> place Code 1
		{
			if(view.NowPlace != 1) break;
			view.RefreshShop();
		}
		while(1)
		{
			if(view.NowPlace != 100) break;
			view.ShopSellPage();
		}
		if(view.NowPlace == 99) break;
	}

	cout << '\n';
	return 0;
}

//Game private

/* 1. When loading window in the end.
 *    This window will keep running.
 *    Such that player home page.
 * 2. Display the player's current status. */
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
	cout << "Seed shop(S)    Quit(Q)\n\n\n";

	cout << "Instructions:\n";
	cout << "  1.Keyboard number keys select the farmland.\n";

	cout << "\nRemark: Plase wait screen refreshed, then enter the next command.\n";

	if(control == 300) system("sleep 1s");
}

/* 1.Responsible for detecting whether the player has operated.
 * 2.Show the word of ShopPage. */
void Game::ShopPage(int control)
{
	system("clear");
	system("clear");

	if(128 > control) view.ShopPageControl(control);

	long unsigned int tab;
	if(this->SubShopPageNow == 0) tab = 14;
	else tab = 13;

	cout << "Welcome to Zhang7391's seed store!\n";
	cout << "Although it's author store, it's not cheaper.\n\n";

	cout << "You have how much money: " << push.money << "\n\n";

	cout << "Name\t\t\tGrowth Time\tSell\town\n";
	for(int Nth=this->SubShopPageNow;this->SubShopPageNow + 10>Nth;Nth++)
	{
		if(Merchandise.Name[Nth] == "") break;

		cout << Nth+1 << '.' << Merchandise.Name[Nth];
		if(Merchandise.Name[Nth].length() >= tab) cout << "\t";
		else cout << "\t\t";
		cout << Merchandise.CoutTimeOutputFormat(Nth);
		cout << Merchandise.SellPrice[Nth] << "\t";
		cout << push.SHaveNumber[Nth] << "\t";
		cout << Merchandise.chose[Nth] << '\n';
	}
	cout << "\t\t\tPage " << this->SubShopPageNow / 10 + 1 << '/';
	if(Merchandise.HowMuchMerchandise % 10 == 0) cout << Merchandise.HowMuchMerchandise / 10 << '\n';
	else cout << Merchandise.HowMuchMerchandise / 10 + 1 << '\n';

	cout << "\n\t    Previous page(B) Next Page(N)\n\n";

	cout << "What are you want to do?" << '\n';
	cout << "Buy this seed(U)\n\n\n";

    cout << "What are you want to go?\n";
	cout << "    Home(M)    Quit(Q)\n\n";

	cout << "Instructions:\n";
	cout << "  1.Keyboard number keys select the merchandise.\n";

	if(control == 300) system("sleep 0.2s");
}

void Game::ShopSellPage(void)
{
	system("clear");
	system("clear");

	cout << "You will get this:" << '\n';
   	cout << Merchandise.Name[this->ShopChose + this->SubShopPageNow] << '\t';
	cout << Merchandise.SellPrice[this->ShopChose + this->SubShopPageNow];
	cout << " * " << Merchandise.PlayerWillBuyNumber;
	cout << " = " << Merchandise.SellPrice[this->ShopChose + this->SubShopPageNow] * Merchandise.PlayerWillBuyNumber <<  "\n\n";
	
	cout << "  +10(R) +1(T) -1(G) -10(F)";
	if(Merchandise.ErrorMessage == 0) cout << "\n\n\n";
	else cout << "\n\n";

	if(Merchandise.ErrorMessage == 1) cout << "Error! Buy at least one item.\n\n";
	if(Merchandise.ErrorMessage == 2) cout << "Not enough money to cash out!\n\n";

	cout << "your money:" << push.money << " -> " << push.money - (Merchandise.SellPrice[this->ShopChose + this->SubShopPageNow] * Merchandise.PlayerWillBuyNumber) << "\n";
	cout << "If you confirm finished, please press \'C\'.\n";
	cout << "Or press \'X\' to go back the seed shop menu.\n";

	cout << "\n";

	if(kbhit()) Merchandise.ErrorMessage = Merchandise.ShopSellPageControl(getch(), Merchandise.SellPrice[this->ShopChose + this->SubShopPageNow] * Merchandise.PlayerWillBuyNumber, this->ShopChose + this->SubShopPageNow);

	system("sleep 0.2s");
}

/* Feedback on player's operation in Shop Page. */
void Game::ShopPageControl(int control)
{
	if(control == 'M' || control == 'm') this->NowPlace = 0;
	if(control == 'Q' || control == 'q') this->NowPlace = 99;
	if(control == 'U' || control == 'u') this->NowPlace = 100;

	if(control == 'N' || control == 'n')
		if(Merchandise.HowMuchMerchandise > this->SubShopPageNow + 10) this->SubShopPageNow += 10;
	if(control == 'B' || control == 'b')
		if(this->SubShopPageNow >= 10) this->SubShopPageNow -= 10;

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
}

//Game public

/* 1. Control display window now.
 * 2. keep Refreshing the MainPage. */
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

/* 1.When player first opening this game.
 *   First welcome player's window.
 * 2.Control the jumping text!
 * 3.Initialization the farmland chose(<-).
 * 4.Initialization the farmland status. */
void Game::MainInIt(void)
{
	string ShowFull("Welcome to this large farmland!");
	int JumpTime = ShowFull.length();
	int Jump = 0;

	this->FarmlandChose = 0;

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
 * 2.Refresh Store Page when player has operation. */
void Game::RefreshShop(void)
{
	if(kbhit())
	{
		this->ShopPage(getch());
	}
	else this->ShopPage(300);
}

/* 1.When game initialization, loading the store merchandise information from outside file(store_merchandise). 
 * 2.Initialization the backpack information.
 * 3.Initialization the Shop Page chose(<-).
 * 4.Initialization the sub-Shop Page(in first page). */
void Game::ShopInIt(void)
{
	string clear;
	ifstream ui;
	ui.open("store_merchandise");

	this->ShopChose = 0;
	this->SubShopPageNow = 0;

	while(getline(ui, Merchandise.Name[Merchandise.HowMuchMerchandise]))
	{
		ui >> Merchandise.SellPrice[Merchandise.HowMuchMerchandise];
		ui >> Merchandise.GrowthTime[Merchandise.HowMuchMerchandise] >> clear;

		push.SHaveNumber[Merchandise.HowMuchMerchandise] = 0;

		ui.ignore();
		Merchandise.HowMuchMerchandise += 1;
	}

	this->ShopPageControl(300);
}

//Store public

string Store::CoutTimeOutputFormat(int Nth)
{
	string TheCout("");
	int time = Merchandise.GrowthTime[Nth];

	if(time > 3600)
	{
		string hr("hr ");
		TheCout = TheCout + to_string(time/3600) + hr;
		time %= 3600;
	}
	if(time > 60)
	{
		string min("min ");
		TheCout = TheCout + to_string(time/60) + min;
		time %= 60;
	}
	if(time > 0)
	{
		string s("s");
		TheCout = TheCout + to_string(time) + s;
	}

	if(16 > TheCout.length() && TheCout.length() >= 8) TheCout = TheCout + "\t";
	else TheCout = TheCout + "\t\t";

	return TheCout;
}

int Store::ShopSellPageControl(int control, int WillSellPrice, int Nth)
{
	if(control == 'X' || control == 'x') view.NowPlace = 1;

	if(control == 'R' || control == 'r')
	{
		if(push.money - WillSellPrice > 0) this->PlayerWillBuyNumber += 10;
		else return 2;
	}
	if(control == 'T' || control == 't') 
	{
		 if(push.money - WillSellPrice > 0) this->PlayerWillBuyNumber += 1;
		 else return 2;
	}
	if(control == 'G' || control == 'g') 
	{
		if(this->PlayerWillBuyNumber > 1) this->PlayerWillBuyNumber -= 1;
		else return 1;
	}
	if(control == 'F' || control == 'f') 
	{
		if(this->PlayerWillBuyNumber > 10) this->PlayerWillBuyNumber -= 10;
		else
		{
			this->PlayerWillBuyNumber = 1;
			return 1;
		}
	}

	if(control == 'C' || control == 'c')
	{
		push.SHaveNumber[Nth] += (WillSellPrice / this->SellPrice[Nth]);
		push.money -= WillSellPrice;
		this->PlayerWillBuyNumber = 1;
		system("clear");
		system("clear");
		cout << "Purchase success! Walk back to the shop happily~~~\n";
		system("sleep 3s");
		view.NowPlace = 1;
	}

	return 0;
}
