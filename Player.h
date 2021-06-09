#pragma once
#include "Figure.h"
#include "FigureO.h"
#include "FigureX.h"
class Player
{
public:
	Player(Type);
	Player(const Player&other);
	Player&operator=(const Player&other);
	~Player();
	const Figure* getFigurePointer() const;

private:
	void CopyFrom(const Player&other);
	void Clean();
	Figure* figure;
	Figure* createFigure(Type);
};