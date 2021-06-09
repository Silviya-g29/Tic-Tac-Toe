#include "stdafx.h"
#include "FigureO.h"
using namespace std;

FigureO::FigureO()
{
	this->symbol = 'o';
}

void FigureO::print() const
{
	cout << this->symbol;
}

Type FigureO::getType() const
{
	return Type::typeO;
}

char FigureO::getSymbol() const
{
	return this->symbol;
}
