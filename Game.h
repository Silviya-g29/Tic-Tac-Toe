#pragma once
#include "Board.h"
#include "Player.h"
class Game 
{
public:
	Game(Type,Type,char[30]);
	bool checkPosition(int, int);
	bool addMove(int,int); 
	void printCurrentBoard() const;

private:
	Player first;
	Player second;
	Board board;
	int count;
	char fileName[30];
	void openFileAndClean();
};