#include "BaseSprite.h"
#include "Constants.h"

void BaseSprite::initializeSample(bool sample[], COLORREF color, COLORREF background)
{
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			sample_[i][j] = ((true == sample[i*size_+j]) ? color : background);
		}
	}
}
void BaseSprite::createSample()
{
	sample_ = new COLORREF * [size_];
	for (int i = 0; i < size_; i++)
	{
		sample_[i] = new COLORREF[size_];
	}
}
BaseSprite::BaseSprite()
{
	size_ = getSize();
	createSample();
}
BaseSprite::~BaseSprite()
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