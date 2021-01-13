#ifndef Control_H
#define Control_H

#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include<ctime>

#define UNI 10	//Fareland Number Maximum
#define PAR 60	//Store Merchandise & Backpack Number Maximum

using namespace std;

class Game
{
private:
	void MainPage(int);
	void ShopPage(int);

	int FarmlandChose = 0;
	int ShopChose = 0;
	int SubShopPageNow = 0;

public:
	void RefreshMain(void);
	void MainInIt(void);

	void RefreshShop(void);
	void ShopInIt(void);

	int NowPlace = 0;
	/* Place Code:
	 * Main: 0
	 * Shop: 1
	 * End Game: 99 */
};

class Farmland	//just have the game global value
{
public:
	int FarmlandNumber = 1;

	string *status = new string[UNI]();
	int *time = new int[UNI]();
	string *chose = new string[UNI]();
};
Farmland FLvalue;

class StoreMerchandise
{
public:
	string *Name = new string[PAR]();
	int *SellPrice = new int[PAR]();
	int *AcquisitionPrice = new int[PAR]();
	string *chose = new string[PAR]();

	int HowMuchMerchandise = 0;
};
StoreMerchandise Merchandise;

class BackPack
{
public:
	/* store merchandise information */
	string *SName = new string[PAR]();
	int *SHaveNumber = new int[PAR]();

	/* other */
	string Name[0];
	int HaveNumber[0];
};
BackPack push;
#endif
