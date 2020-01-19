#include "../Headers/Blinky.h"

Blinky::Blinky(): Gost(getRed(), getBlue(), getBlinkyStartPosition(), getBlinkyRetreatPoint()){}
void Blinky::setDirectionPoint(const POINT& point, const Direction direction, const POINT& blinky)
{
	directionPoint_ = point;
}