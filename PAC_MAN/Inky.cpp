#include "Inky.h"
#include "Constants.h"

void Inky::setStartPosition()
{
	point_ = getInkyStartPosition();
}
Inky::Inky()
{
	setStartPosition();
	retreatPoint_ = getInkyRetreatPoint();
}
void Inky::setDirectionPoint(const POINT point, const Direction direction, const POINT blinky)
{
	const int count = 2;
	switch (direction)
	{
	case UP:
	{
		directionPoint_.x = (point.x - blinky.x) * 2 + blinky.x;
		directionPoint_.y = (point.y - count * size_ - blinky.y) * 2 + blinky.y;
		return;
	}
	case LEFT:
	{
		directionPoint_.x = (point.x - count * size_ - blinky.x) * 2 + blinky.x;
		directionPoint_.y = (point.y - blinky.y) * 2 + blinky.y;
		return;
	}
	case DOWN:
	{
		directionPoint_.x = (point.x - blinky.x) * 2 + blinky.x;
		directionPoint_.y = (point.y + count * size_ - blinky.y) * 2 + blinky.y;
		return;
	}
	case RIGHT:
	{
		directionPoint_.x = (point.x + count * size_ - blinky.x) * 2 + blinky.x;
		directionPoint_.y = (point.y - blinky.y) * 2 + blinky.y;
		return;
	}
	default:
		return;
	}
}