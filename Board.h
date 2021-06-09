#pragma once
#include "Figure.h"
#include "FigureX.h"
#include "FigureO.h"
#include <fstream>
using namespace std;
class Board 
{
public:
	Board();
	~Board();
	Board(const Board&other) = delete;
	Board&operator=(const Board&other) = delete;
	bool addFigure(const Figure*,int, int); 
	bool isEmptyPosition(int, int) const; 
	void print() const;
	void printInFile(const char*);

	friend ostream& operator<<(ostream&, const Board&);

private:
	Figure*** figure;
	void clean();
	bool checkIfWeHaveWinner(const Figure*, int, int);
};