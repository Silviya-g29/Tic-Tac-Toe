#pragma once
enum Type
{
	typeX,
	typeO
};
class Figure
{
public:
	virtual void print() const = 0;
	virtual Type getType() const = 0;
	virtual char getSymbol() const = 0;
};