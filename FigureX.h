#pragma once
#include<iostream>
#include "Figure.h"

class FigureX :public Figure
{
public:
	FigureX();
	void print() const;
	Type getType() const;
	char getSymbol() const;
private:
	char symbol;
};