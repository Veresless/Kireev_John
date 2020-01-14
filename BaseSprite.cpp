#include "BaseSprite.h"

void BaseSprite::setDefaultSize()
{
	Size_ = 8;
}
void BaseSprite::setDefaultType()
{

}
void BaseSprite::createSample()
{
	Sample_ = new COLORREF * [Size_];
	for (int i = 0; i < Size_; i++) Sample_[i] = new COLORREF[Size_];
}
void BaseSprite::initializeSample(COLORREF Color, COLORREF Background)
{

}
int BaseSprite::getSize()
{
	return Size_;
}
SpriteType BaseSprite::getType()
{
	return Type_;
}
void BaseSprite::clearSample()
{
	for (int i = 0; i < Size_; i++)
		delete[] Sample_[i];
	delete[] Sample_;
}
BaseSprite::BaseSprite()
{
	setDefaultSize();
	setDefaultType();
	createSample();
}