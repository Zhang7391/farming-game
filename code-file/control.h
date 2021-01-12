#ifndef Control_H
#define Control_H

#include<iostream>
#include<conio.h>
#include<string>
#include<ctime>

#define UNI 10	//Fareland Number Maximum

using namespace std;

class Game
{
private:

public:

};

class Page
{
private:
	int FarmlandChose = 0;
public:
	void MainInIt(int, string);
	void main(int);
};

class AllValue	//just have the game global value
{
public:
	int FarmlandNumber = 10;
	struct FramlandAttributes
	{
		string status = "idle";
		int time;
		string chose;
	}FarmlandInfo[UNI];	//Farmland Number Maximum
};
#endif
