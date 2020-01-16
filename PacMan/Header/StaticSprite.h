#ifndef H_STATIC_SPRITE
#define H_STATIC_SPRITE

#include "BaseSprite.h"

class StaticSprite : public BaseSprite
{
public:
	void printOn(int x, int y, HDC hdc);
};
#endif