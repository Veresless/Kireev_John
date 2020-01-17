#include "StaticSprite.h"
#include "Constants.h"

StaticSprite::StaticSprite() :size_(getSize()), mainColor_(getBackgroundColor()), backgroundColor_(getBackgroundColor())
{
	createSample();
}
void StaticSprite::setType(SpriteType type)
{
	type_ = type;
}
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
void StaticSprite::setMainColor(const COLORREF color)
{
	mainColor_ = color;
}
void StaticSprite::initializeSample(const bool sample[])
{
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			sample_[i][j] = ((true == sample[i * size_ + j]) ? mainColor_ : backgroundColor_);
		}
	}
}
void StaticSprite::createSample()
{
	sample_ = new COLORREF * [size_];
	for (int i = 0; i < size_; i++)
	{
		sample_[i] = new COLORREF[size_];
	}
}
StaticSprite* StaticSprite::createSprite(const SpriteType type)
{
	StaticSprite* sprite = new StaticSprite();
	sprite->setType(type);
	return sprite;
}
StaticSprite::~StaticSprite()
{
	if (sample_ != nullptr)
	{
		for (int i = 0; i < size_; i++)
		{
			if (sample_[i] != nullptr)
			{
				delete[] sample_[i];
			}
		}
		delete[] sample_;
	}
}

