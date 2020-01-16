#include "StaticSprite.h"

void StaticSprite::printOn(int x, int y, HDC hdc)
{
	const int xStart = size_ * x;
	const int yStart = size_ * y;
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			SetPixel(hdc, j + xStart, i + yStart, sample_[i][j]);
		}
	}
}


