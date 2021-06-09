#include "stdafx.h"
#include "FigureX.h"
using namespace std;

FigureX::FigureX()
{
	this->symbol = 'x';
}

void FigureX::print() const
{
	cout << this->symbol;
}

Type FigureX::getType() const
{
	return Type::typeX;
}

char FigureX::getSymbol() const
{
	return this->symbol;
}
