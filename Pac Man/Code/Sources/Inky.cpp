#include "../Headers/Inky.h"


Inky::Inky() : Gost(getCayan(), getBlue(), getInkyStartPosition(), getInkyRetreatPoint()){}
void Inky::setDirectionPoint(const POINT& point, const Direction direction, const POINT& blinky)
{
	const int count = getInkyDistanse();
	switch (direction)
	{
	case UP:
	{
		directionPoint_.x = (point.x - blinky.x) * 2 + blinky.x;
		directionPoint_.y = (point.y - count * size_ - blinky.y) * 2 + blinky.y;
		break;
	}
	case LEFT:
	{
		directionPoint_.x = (point.x - count * size_ - blinky.x) * 2 + blinky.x;
		directionPoint_.y = (point.y - blinky.y) * 2 + blinky.y;
		break;
	}
	case DOWN:
	{
		directionPoint_.x = (point.x - blinky.x) * 2 + blinky.x;
		directionPoint_.y = (point.y + count * size_ - blinky.y) * 2 + blinky.y;
		break;
	}
	case RIGHT:
	{
		directionPoint_.x = (point.x + count * size_ - blinky.x) * 2 + blinky.x;
		directionPoint_.y = (point.y - blinky.y) * 2 + blinky.y;
		break;
	}
	default:
	{
		break;
	}
	}
}