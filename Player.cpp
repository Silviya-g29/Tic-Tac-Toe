#include "stdafx.h"
#include "Player.h"

void Player::CopyFrom(const Player& other)
{
	figure = this->createFigure(other.figure->getType());
}

void Player::Clean()
{
	delete[] figure;
}

Figure* Player::createFigure(Type type)
{
	Figure* temp = nullptr;
	if (type == Type::typeO)
	{
		temp = new FigureO();
	}
	else
	{
		temp = new FigureX();
	}
	return temp;
}

Player::Player(Type type)
	:figure(nullptr)
{
	figure = this->createFigure(type);
}

Player::Player(const Player& other)
	:figure(nullptr)
{
	CopyFrom(other);
}

Player& Player::operator=(const Player & other)
{
	if (this != &other)
	{
		Clean();
		CopyFrom(other);
	}
	return *this;
}

Player::~Player()
{
	Clean();
}

const Figure * Player::getFigurePointer() const
{
	return this->figure;
}

