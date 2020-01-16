#include <algorithm>
#include <ctime>

#include "Cast.h"
#include "Constants.h"

void Cast::setDefaultType()
{
	type_ = SpriteType::CAST;
}
const int Cast::distanse(const POINT position, const POINT directionPoint)
{
	return (position.x - directionPoint.x) * (position.x - directionPoint.x) + (position.y - directionPoint.y) * (position.y - directionPoint.y);
}
const POINT Cast::getPoint(const Direction direction)
{
	POINT point;
	point.x = point_.x;
	point.y = point_.y;
	switch (direction)
	{
	case UP:
		{
		point.y -= size_;
		break;
	}
	case RIGHT:
	{ 
		point.x += size_;
		break;
	}
	case DOWN:
	{
		point.y += size_;
		break;
	}
	case LEFT:
	{ 
		point.x -= size_;
		break;
	}
	default:
	{
		break;
	}
	}
	return point;
}
void Cast::setMode(CastMode mode)
{
	if (mode == CastMode::FEAR) direction_ = (Direction)(((int)direction_ + 2) % 4); // Reverse direction
	mode_ = mode;
}
Cast::Cast()
{
	setDefaultType();
}
void Cast::decision(std::vector<Direction> & directions, const POINT directionPoint)
{
	std::vector<Direction> indexes;
	indexes.push_back(directions.back());
	directions.pop_back();
	int length = distanse(getPoint(indexes[0]), directionPoint);
	for (Direction element : directions)
	{
		int newDistanse = distanse(getPoint(element), directionPoint);
		if (newDistanse < length)
		{
			length = newDistanse;
			indexes.clear();
			indexes.push_back(element);
		}
		else if (newDistanse == length)
		{
			indexes.push_back(element);
		}
	}
	if (indexes.size() == 1) direction_ = indexes[0];
	else
	{
		std::sort(indexes.begin(), indexes.end());
		direction_ = indexes[0];
	}
}
void Cast::choiseDirection(bool ways[4])
{
	ways[((int)direction_ + 2) % 4] = false; 
	std::vector<Direction> directions;
	for (int i = 0; i < 4; i++) if (ways[i]) directions.push_back((Direction)i);
	if (directions.size() == 1) direction_ = directions[0];
	else
	{
		switch (mode_)
		{
		case CastMode::ATTACK:
		{
			decision(directions, directionPoint_);
			return;
		}
		case CastMode::FEAR:
		{
			std::srand(time(0));
			direction_ = directions[rand() % directions.size()];
			return;
		}
		case CastMode::RETREAT:
		{
			decision(directions, retreatPoint_);
			return;
		}
		}
	}
}
void Cast::setReadyPosition()
{
	point_ = getCastReadyPosition();
	direction_ = LEFT;
}
void Blinky::setStartPosition()
{
	point_ = getBlinkyStartPosition();
}
Blinky::Blinky()
{
	setStartPosition();
	retreatPoint_ = getBlinkyRetreatPoint();
}
void Blinky::setDirectionPoint(const POINT Point)
{
	directionPoint_ = Point;
}
void Pinky::setStartPosition()
{
	point_ = getPinkyStartPosition();
}
Pinky::Pinky()
{
	setStartPosition();
	retreatPoint_ = getPinkyRetreatPoint();
}
void Pinky::setDirectionPoint(const POINT point, const Direction direction)
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
void Inky::setStartPosition()
{
	point_ = getInkyStartPosition();
}
Inky::Inky()
{
	setStartPosition();
	retreatPoint_ = getInkyRetreatPoint();
}
void Inky::setDirectionPoint(const POINT Point, const Direction direction, const POINT Blinky)
{
	const int count = 2;
	switch (direction)
	{
	case UP:
	{
		directionPoint_.x = (Point.x - Blinky.x) * 2 + Blinky.x;
		directionPoint_.y = (Point.y - count * size_ - Blinky.y) * 2 + Blinky.y;
		return;
	}
	case LEFT:
	{
		directionPoint_.x = (Point.x - count * size_ - Blinky.x) * 2 + Blinky.x;
		directionPoint_.y = (Point.y - Blinky.y) * 2 + Blinky.y;
		return;
	}
	case DOWN:
	{
		directionPoint_.x = (Point.x - Blinky.x) * 2 + Blinky.x;
		directionPoint_.y = (Point.y + count * size_ - Blinky.y) * 2 + Blinky.y;
		return;
	}
	case RIGHT:
	{
		directionPoint_.x = (Point.x + count * size_ - Blinky.x) * 2 + Blinky.x;
		directionPoint_.y = (Point.y - Blinky.y) * 2 + Blinky.y;
		return;
	}
	default:
		return;
	}
}
void Clyde::setStartPosition()
{
	point_ = getClydeStartPosition();
}
Clyde::Clyde()
{
	setStartPosition();
	retreatPoint_ = getClydeRetreatPoint();
}
void Clyde::setDirectionPoint(const POINT point)
{
	const int count = getClydeDistanse();
	directionPoint_ = ((sqrt(distanse(point_, point)) >= count * size_)? point : retreatPoint_);
}
