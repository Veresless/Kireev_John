#include <algorithm>
#include <ctime>

#include "Gost.h"
#include "Blinky.h"
#include "Pinky.h"
#include "Inky.h"
#include "Clyde.h"
#include "Constants.h"
#include "MapConstants.h"

void Gost::setType(const SpriteType type)
{
	type_ = type;
}
const int Gost::distanse(const POINT position, const POINT directionPoint)
{
	return (position.x - directionPoint.x) * (position.x - directionPoint.x) + (position.y - directionPoint.y) * (position.y - directionPoint.y);
}
const POINT Gost::getPoint(const Direction direction)
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
void Gost::setMode(GostMode mode)
{
	if (mode == GostMode::FEAR) direction_ = (Direction)(((int)direction_ + 2) % 4); // Reverse direction
	mode_ = mode;
}
Gost* Gost::createGost(const GostType type)
{
	Gost* gost = nullptr;
	switch (type)
	{
	case BLINKY:
	{
		gost = new Blinky();
		gost->setMainColor(getRed());
		break;
	}
	case PINKY:
	{
		gost = new Pinky();
		gost->setMainColor(getPink());
		break;
	}
	case INKY:
	{
		gost = new Inky();
		gost->setMainColor(getCayan());
		break;
	}
	case CLYDE:
	{
		gost = new Clyde();
		gost->setMainColor(getOrange());
		break;
	}
	default:
		break;
	}
	gost->initializeSample(SPRITE_GOST);
	return gost;
}
Gost::Gost()
{
	setType(SpriteType::GOST);
}
void Gost::setMainColor(COLORREF color)
{
	mainColor_ = color;
}
void Gost::decision(std::vector<Direction> & directions, const POINT directionPoint)
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
void Gost::choiseDirection(bool ways[4])
{
	ways[((int)direction_ + 2) % 4] = false; 
	std::vector<Direction> directions;
	for (int i = 0; i < 4; i++) if (ways[i]) directions.push_back((Direction)i);
	if (directions.size() == 1) direction_ = directions[0];
	else
	{
		switch (mode_)
		{
		case GostMode::ATTACK:
		{
			decision(directions, directionPoint_);
			return;
		}
		case GostMode::FEAR:
		{
			std::srand(time(0));
			direction_ = directions[rand() % directions.size()];
			return;
		}
		case GostMode::RETREAT:
		{
			decision(directions, retreatPoint_);
			return;
		}
		}
	}
}
void Gost::setReadyPosition()
{
	point_ = getCastReadyPosition();
	direction_ = LEFT;
}
