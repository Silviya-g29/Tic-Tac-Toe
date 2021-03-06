// ConsoleApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include  "Game.h"
using namespace std;
int main()
{
	cout << "Hello ! " << endl;
	cout << "Choice first player symbol," << endl;
	char first;
	do
	{
		cout << "x or o" << endl;
		cin >> first;
	} while (first != 'x' && first != 'o');
	Type firstT, secondT;
	if (first == 'x')
	{
		firstT = Type::typeX;
		secondT = Type::typeO;
	}
	else
	{
		firstT = Type::typeO;
		secondT = Type::typeX;
	}
	Game a(firstT, secondT,"file.txt");
	bool flag = 0;
	int count = 0;
	do
	{
		a.printCurrentBoard();
		cout << "Position:";
		int i, j;
		do
		{
			cin >> i >> j;
		} while (a.checkPosition(i,j) == false);
		flag = a.addMove(i,j);
		count++;
	} while (flag == false && count < 10);
	if (count < 10)
	{
		if (count % 2 == 0)
		{
			cout << "Second player is winner." << endl;
		}
		else
		{
			cout << "First player is winner." << endl;
		}
	}
	else
	{
		cout << "Players are equal." << endl;
	}

    return 0;
}
