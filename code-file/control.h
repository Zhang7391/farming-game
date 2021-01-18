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
	void ShopPageControl(int);

public:
	void RefreshMain(void);
	void MainInIt(void);

	void FarmlandInformation(void);
	void FarmlandControl(int);
	void UpdateBackpackInformation(void);	//useless function

	void RefreshShop(void);
	void ShopSellPage(void);	//this page control is in the 'Class Store'
	void ShopInIt(void);

	int NowPlace = 0;
	/* Place Code:
	 * Main: 0
	 * Shop: 1
	 * End Game: 99
	 * Shop Sell: 100
	 * Farmland information: 101 */
} view;

class Farmland
{
public:
	int FarmlandNumber = 1;
	int FarmlandChose; 

	string *status = new string[UNI]();
	int *time = new int[UNI]();
	string *chose = new string[UNI]();

	int Nowchose = 0;
	string *SubChose = new string[10]();
	int SubPageNow = 0; 
} FLvalue;

class Store
{
public:
	string CoutTimeOutputFormat(int);
	int ShopSellPageControl(int, int, int);

	int ShopChose;
	int SubShopPageNow;

	string *Name = new string[PAR]();
	int *SellPrice = new int[PAR]();
	int *GrowthTime = new int[PAR]();
	string *Discription = new string[PAR]();
	string *chose = new string[PAR]();

	int PlayerWillBuyNumber = 1;
	int HowMuchMerchandise = 0;
	int ErrorMessage = 0;
	/* 1: Buy at least one item.
	 * 2: Not enough money to cash out! */
} Merchandise;

class BackPack
{
public:
	/* store merchandise information */
	int *SHaveNumber = new int[PAR]();
	int *SHavePlace = new int[PAR]();

	/* other */
	int eat = 0;
	int money = 100;
	int TureHaveNumber;
} push;
#endif
