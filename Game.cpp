#include "stdafx.h"
#include "Game.h"
#include "Board.h"

Game::Game(Type X, Type O,char fileName[30])
	:first(X),second(O),count(0)
{
	for (int i = 0; i < 30; i++)
	{
		this->fileName[i] = fileName[i];
	}
	this->openFileAndClean();
}

bool Game::checkPosition(int xCoord, int yCoord)
{
	return  xCoord >= 0 && xCoord < 3
		&& yCoord >= 0 && yCoord < 3;
}

bool Game::addMove(int x , int y)
{
	bool flag = false;
	if (this->checkPosition(x, y))
	{
		if (this->count % 2 == 0)
		{
			flag = this->board.addFigure(this->first.getFigurePointer(), x, y);
		}
		else
		{
			flag = this->board.addFigure(this->second.getFigurePointer(), x, y);
		}
		this->board.printInFile(this->fileName);
	}
	this->count++;
	return flag;
}

void Game::printCurrentBoard() const
{
	this->board.print();
}

void Game::openFileAndClean()
{
	ofstream myFile;
	myFile.open(this->fileName);
	myFile.close();
}


