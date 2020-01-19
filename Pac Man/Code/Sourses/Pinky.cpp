#include "../Headers/Pinky.h"

void Pinky::setStartPosition()
{
	point_ = getPinkyStartPosition();
}
Pinky::Pinky() : Gost(getPink(), getBlue(), getPinkyRetreatPoint())
{
	setStartPosition();
}
void Pinky::setDirectionPoint(const POINT& point, const Direction direction, const POINT& blinky)
{
	const int count = getPinkyDistanse();
	switch (direction)
	{
	case 0:
	{
		directionPoint_.x = point.x;
		directionPoint_.y = point.y - count * size_;
		return;
	}
	case 1:
	{
		directionPoint_.x = point.x - count * size_;
		directionPoint_.y = point.y;
		return;
	}
	case 2:
	{
		directionPoint_.x = point.x;
		directionPoint_.y = point.y + count * size_;
		return;
	}
	case 3:
	{
		directionPoint_.x = point.x + count * size_;
		directionPoint_.y = point.y;
		return;
	}
	default:
		return;
	}
}