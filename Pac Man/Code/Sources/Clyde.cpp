#include "../Headers/Clyde.h"
#include "math.h"

Clyde::Clyde() : Gost(getOrange(), getBlue(), getClydeStartPosition(), getClydeRetreatPoint()){}
void Clyde::setDirectionPoint(const POINT& point, const Direction direction, const POINT& blinky)
{
	const int count = getClydeDistanse();
	directionPoint_ = ((sqrt(distanse(point_, point)) >= count * size_) ? point : retreatPoint_);
}