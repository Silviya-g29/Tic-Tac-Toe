#include "stdafx.h"
#include "Board.h"

Board::Board()
	:figure(nullptr)
{
	this->figure = new Figure**[3];
	for (int i = 0; i < 3; i++)
	{
		this->figure[i] = new Figure*[3];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			this->figure[i][j] = nullptr;
		}
	}
}

Board::~Board()
{
	this->clean();
}

bool Board::addFigure(const Figure* newFigure, int i, int j)
{
	if (newFigure->getType() == Type::typeX)
	{
		this->figure[i][j] = new FigureX();
	}
	else
	{
		this->figure[i][j] = new FigureO();
	}
	return this->checkIfWeHaveWinner(newFigure, i, j);
}

bool Board::isEmptyPosition(int i, int j) const
{
	return  (figure[i][j] == nullptr);
}

void Board::print() const
{
	cout << (*this);
}

void Board::printInFile(const char* filename)
{
	fstream myFile;
	myFile.open(filename,ios::app);
	myFile << endl;
	myFile << (*this);
	myFile << endl;
	myFile.close();
}


void Board::clean()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			delete this->figure[i][j];
		}
		delete[] this->figure[i];
	}
	delete[] this->figure;
}

bool Board::checkIfWeHaveWinner(const Figure* newFigure, int i , int j)
{
	bool flag12 = true;
	bool flag11 = true;
	for (int k = 0; k < 3; k++)
	{
		if (this->figure[i][k]== nullptr || this->figure[i][k]->getType() != newFigure->getType())
		{
			flag12 = false;
		}
		if (this->figure[k][j] == nullptr || this->figure[k][j]->getType() != newFigure->getType())
		{
			flag11 = false;
		}
	}
	bool flag2 = false;
	if (i == j)
	{
		bool helpFlag = true;
		for (int k = 0; k < 3; k++)
		{
			if (this->figure[k][k] == nullptr || this->figure[k][k]->getType() != newFigure->getType())
			{
				helpFlag = false;
			}
		}
		flag2 = helpFlag;
	}
	bool flag3 = true;
	for (int k = 0; k < 3; k++)
	{
		if (this->figure[k][3 - k - 1] == nullptr || this->figure[k][3 - k - 1]->getType() != newFigure->getType())
		{
			flag3 = false;
		}
	}
	return (flag11 || flag12 || flag2 || flag3);
}

ostream & operator<<(ostream & os, const Board & other)
{
	char arr[40] = "+---+---+---+";
	for (int i = 0; i < 3; i++)
	{
		os << arr << endl;
		for (int j = 0; j < 3; j++)
		{
			os << "| ";
			if (other.figure[i][j] == nullptr)
			{
				os << " ";
			}
			else
			{
				os << other.figure[i][j]->getSymbol();
			}
			os << " ";
		}
		os << "|" << endl;
	}
	os << arr << endl;

	return os;
}
