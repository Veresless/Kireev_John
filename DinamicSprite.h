#pragma once
#include "BaseSprite.h"

class DinamicSprite : public BaseSprite
{
protected:
	int X_, Y_;
	int Direction_, Speed_;
public:
	DinamicSprite();
	int getSpeed();
	void setStartPosition();
	void setLowSpeed();
	void setMiddleSpeed();
	void setHigthSpeed();
	std::pair<int, int> getPoint();
	void changePosition(int Horizontal, int Vertical);
	void changeDirection(int Direction);
	int getDirection();
	void print(int Horizontal, int Vertical, HDC hdc);
};