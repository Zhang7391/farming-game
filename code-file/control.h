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

	int FarmlandChose;
	int ShopChose;
	int SubShopPageNow;
public:
	void RefreshMain(void);
	void MainInIt(void);

	void RefreshShop(void);
	void ShopSellPage(void);	//this page control is in the 'Class Store'
	void ShopInIt(void);

	int NowPlace = 0;
	/* Place Code:
	 * Main: 0
	 * Shop: 1
	 * End Game: 99
	 * Shop Sell: 100 */
} view;

class Farmland
{
public:
	int FarmlandNumber = 1;

	string *status = new string[UNI]();
	int *time = new int[UNI]();
	string *chose = new string[UNI]();
} FLvalue;

class Store
{
public:
	string CoutTimeOutputFormat(int);
	int ShopSellPageControl(int, int, int);

	string *Name = new string[PAR]();
	int *SellPrice = new int[PAR]();
	int *GrowthTime = new int[PAR]();
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

	/* other */
	int money = 100;
} push;
#endif
