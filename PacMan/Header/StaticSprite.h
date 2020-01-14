#pragma once
#include "BaseSprite.h"
class StaticSprite : public BaseSprite
{
public:
	void printOn(int x, int y, HDC hdc);
};