#include "DinamicSprite.h"

void DinamicSprite::setStartPosition()
{
	
}
std::pair<int, int>DinamicSprite::getPoint()
{
	return { X_, Y_ };
}
void DinamicSprite::changePosition(int Horizontal, int Vertical)
{
	int Higth = Vertical * Size_;
	int Width = Horizontal * Size_;
	switch (Direction_)
	{
	case 2:
	{
		Y_+= Speed_;
		Y_ %= Higth;
		break;
	}
	case 0:
	{
		Y_ -= Speed_;
		Y_ += Higth;
		Y_ %= Higth;
		break;
	}
	case 3:
	{
		X_ += Speed_;
		X_ %= Width;
		break;
	}
	case 1:
	{
		X_ -= Speed_;
		X_ += Width;
		X_ %= Width;
		break;
	}
	default:
		break;
	}
}
DinamicSprite::DinamicSprite()
{
	Direction_ = 0;
	Speed_ = 4;
}
int DinamicSprite::getSpeed()
{
	return Speed_;
}
void DinamicSprite::setLowSpeed()
{
	Speed_ = 1;
}
void DinamicSprite::setMiddleSpeed()
{
	Speed_ = 2;
}
void DinamicSprite::setHigthSpeed()
{
	Speed_ = 4;
}
void DinamicSprite::changeDirection(int Direction)
{
	Direction_ = Direction;
}
int DinamicSprite::getDirection()
{
	return Direction_;
}
void DinamicSprite::print(int Horizontal, int Vertical, HDC hdc)
{
	int MaxX = Size_ * Horizontal;
	int MaxY = Size_ * Vertical;
	for (int i = 0; i < Size_; i++)
		for (int j = 0; j < Size_; j++)
			SetPixel(hdc, (j + X_ + MaxX)%MaxX, (i + Y_ + MaxY) % MaxY, Sample_[i][j]);
}