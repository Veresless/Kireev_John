#include "DinamicSprite.h"
#include "Constants.h"

DinamicSprite::DinamicSprite(const SpriteType type, const COLORREF mainColor, const bool sample[]) : 
	size_(getSize()), type_(type), mainColor_(mainColor), backgroundColor_(getBackgroundColor())
{
	sample_ = std::unique_ptr<std::unique_ptr<COLORREF[]>[]>(new std::unique_ptr<COLORREF[]>[size_]);
	for (int i = 0; i < size_; i++)
	{
		sample_[i] = std::unique_ptr<COLORREF[]>(new COLORREF[size_]);
	}
	initializeSample(sample);
}
void DinamicSprite::setDirection(const Direction direction)
{
	direction_ = direction;
}
void DinamicSprite::setSpeed(const int speed)
{
	speed_ = speed;
}
void DinamicSprite::move()
{
	const int higth = getVertical() * size_;
	const int width = getHorizontal() * size_;

	switch (direction_)
	{
	case DOWN:
	{
		point_.y += speed_;
		point_.y %= higth;
		break;
	}
	case UP:
	{
		point_.y -= speed_;
		point_.y += higth;
		point_.y %= higth;
		break;
	}
	case RIGHT:
	{
		point_.x += speed_;
		point_.x %= width;
		break;
	}
	case LEFT:
	{
		point_.x -= speed_;
		point_.x += width;
		point_.x %= width;
		break;
	}
	default:
		break;
	}
}
void DinamicSprite::initializeSample(const bool sample[])
{
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			sample_[i][j] = ((true == sample[i * size_ + j]) ? mainColor_ : backgroundColor_);
		}
	}
}
const void DinamicSprite::print(const HDC hdc) const
{
	const int HIGTH = getVertical() * size_;
	const int WIDTH = getHorizontal() * size_;
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			const int X = (j + point_.x + WIDTH) % WIDTH;
			const int Y = (i + point_.y + HIGTH) % HIGTH;
			SetPixel(hdc, X, Y, sample_[i][j]);
		}
	}
}
