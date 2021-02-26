#include "Pinky.h"

Pinky::Pinky() : Gost(getPink(), getBlue(), getPinkyStartPosition(), getPinkyRetreatPoint()) {}
void Pinky::setDirectionPoint(const POINT& point, const Direction direction, const POINT& blinky)
{
	const int count = getPinkyDistanse();
	switch (direction)
	{
	case 0:
	{
		directionPoint_.x = point.x;
		directionPoint_.y = point.y - count * size_;
		break;
	}
	case 1:
	{
		directionPoint_.x = point.x - count * size_;
		directionPoint_.y = point.y;
		break;
	}
	case 2:
	{
		directionPoint_.x = point.x;
		directionPoint_.y = point.y + count * size_;
		break;
	}
	case 3:
	{
		directionPoint_.x = point.x + count * size_;
		directionPoint_.y = point.y;
		break;
	}
	default:
	{
		break;
	}
	}
}
