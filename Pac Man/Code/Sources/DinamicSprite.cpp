#include "../Headers/DinamicSprite.h"

DinamicSprite::DinamicSprite(const COLORREF mainColor, const POINT& position, const bool sample[]) : 
	size_(getDinamicSize()), mainColor_(mainColor), backgroundColor_(getBackgroundColor()),
	direction_(UP), point_(position), speed_(getLowSpeed())
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
void DinamicSprite::setDirection(const Direction direction)
{
	direction_ = direction;
}
void DinamicSprite::setSpeed(const int speed)
{
	speed_ = speed;
}
void DinamicSprite::setPosition(const POINT& position)
{
	point_ = position;
}
void DinamicSprite::move()
{
	const int size = getSize();
	const int higth = getVertical() * size;
	const int width = getHorizontal() * size;

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
void DinamicSprite::print(const HDC hdc) const
{
	const int start = (getSize() - size_) / 2;
	const int HIGTH = getVertical() * size_;
	const int WIDTH = getHorizontal() * size_;
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			const int X = (start + j + point_.x + WIDTH) % WIDTH;
			const int Y = (start + i + point_.y + HIGTH) % HIGTH;
			SetPixel(hdc, X, Y, sample_[i][j]);
		}
	}
}
