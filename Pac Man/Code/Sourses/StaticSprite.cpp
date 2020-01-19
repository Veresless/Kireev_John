#include "../Headers/StaticSprite.h"

StaticSprite::StaticSprite(const StaticSpriteType type, const COLORREF mainColor, const bool sample[]) :
	size_(getSize()), type_(type), mainColor_(mainColor), backgroundColor_(getBackgroundColor())
{
	sample_ = std::unique_ptr<std::unique_ptr<COLORREF[]>[]>(new std::unique_ptr<COLORREF[]>[size_]);
	for (int i = 0; i < size_; i++)
	{
		sample_[i] = std::unique_ptr<COLORREF[]>(new COLORREF[size_]);
		for (int j = 0; j < size_; j++)
		{
			sample_[i][j] = ((true == sample[i * size_ + j]) ? mainColor_ : backgroundColor_);
		}
	}
}
void StaticSprite::printOn(const int x, const int y, const HDC hdc) const
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
const std::shared_ptr<StaticSprite> const StaticSprite::createSprite(const StaticSpriteType type, const bool sample[])
{
	COLORREF mainColor;
	switch (type)
	{
	case WALL:
	{
		mainColor = getBlue();
		break;
	}
	default:
	{
		mainColor = getWhite();
		break;
	}
	}
	return std::shared_ptr<StaticSprite>(new StaticSprite(type, mainColor, sample));
}
