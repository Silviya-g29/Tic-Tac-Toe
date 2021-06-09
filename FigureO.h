#pragma once
#include<iostream>
#include "Figure.h"

class FigureO :public Figure
{
public:
	FigureO();
	void print() const;
	Type getType() const;
	char getSymbol() const;
private:
	char symbol;
};