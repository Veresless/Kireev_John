#include "Blinky.h"
#include "Constants.h"

void Blinky::setStartPosition()
{
	point_ = getBlinkyStartPosition();
}
Blinky::Blinky(): Gost(getRed(), getBlue(), getBlinkyRetreatPoint())
{
	setStartPosition();
}
void Blinky::setDirectionPoint(const POINT& point, const Direction direction, const POINT& blinky)
{
	directionPoint_ = point;
}