#include "StaticSprite.h"

void StaticSprite::printOn(int x, int y, HDC hdc)
{
	int XStart = Size_ * x;
	int YStart = Size_ * y;
	for (int i = 0; i < Size_; i++)
		for (int j = 0; j < Size_; j++)
			SetPixel(hdc, j + XStart, i + YStart, Sample_[i][j]);
}


