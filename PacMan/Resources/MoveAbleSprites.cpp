#include "MoveAbleSprites.h"
#include <algorithm>
#include <ctime>

void PacMan::setDefaultType()
{
	Type_ = SpriteType::TPacMan;
}
void PacMan::initializeSample(COLORREF Color, COLORREF Background)
{
	for (int i = 0; i < Size_; i++)
	{
		for (int j = 0; j < Size_; j++)
			Sample_[i][j] = Color;
		Sample_[0][0] = Sample_[0][Size_ - 1] = Sample_[Size_ - 1][0] = Sample_[Size_ - 1][Size_ - 1] = Sample_[1][0] = Sample_[1][Size_ - 1] = Sample_[Size_ - 2][0] = Sample_[Size_ - 2][Size_ - 1] = Sample_[0][1] = Sample_[0][Size_ - 2] = Sample_[Size_ - 1][1] = Sample_[Size_ - 1][Size_ - 2] = Background;
	}
}
void PacMan::setStartPosition()
{
	X_ = 13*Size_+Size_/2;
	Y_ = 26*Size_;
}
PacMan::PacMan()
{
	setDefaultType();
	setStartPosition();
}

void Cast::initializeSample(COLORREF Color, COLORREF Background)
{
	for (int i = 0; i < Size_; i++)
	{
		for (int j = 0; j < Size_; j++)
			Sample_[i][j] = Color;
		Sample_[0][0] = Sample_[0][Size_-1] = Sample_[0][1] = Sample_[0][Size_-2] = Sample_[1][0] = Sample_[1][Size_ - 1] = Background;
	}
}
void Cast::setDefaultType()
{
	Type_ = SpriteType::TCast;
}
int Cast::distanse(std::pair<int, int> Position, std::pair<int, int> DirectionPoint)
{
	return (Position.first - DirectionPoint.first) * (Position.first - DirectionPoint.first) + (Position.second - DirectionPoint.second) * (Position.second - DirectionPoint.second);
}
std::pair<int, int> Cast::getPoint(int Direction)
{
	switch (Direction)
	{
	case 0:
		return { X_, Y_-Size_ };
	case 3:
		return { X_ + Size_, Y_ };
	case 2:
		return { X_, Y_ + Size_ };
	case 1:
		return { X_ - Size_, Y_ };
	default:
		return {X_, Y_};
	}
}
CastMode Cast::getMode()
{
	return Mode_;
}
void Cast::changeMode(CastMode Mode)
{
	if (Mode == CastMode::Fear) Direction_ = (Direction_ + 2) % 4;
	Mode_ = Mode;
}
Cast::Cast()
{
	setDefaultType();
	Mode_ = CastMode::Attack;
}
void Cast::decision(std::vector<int> &Directions, std::pair<int, int> DirectionPoint)
{
	std::vector<int> Indexes;
	Indexes.push_back(Directions.back());
	Directions.pop_back();
	double Distanse = distanse(getPoint(Indexes[0]), DirectionPoint);
	for (int Element : Directions)
	{
		int NewDistanse = distanse(getPoint(Element), DirectionPoint);
		if (NewDistanse < Distanse)
		{
			Distanse = NewDistanse;
			Indexes.clear();
			Indexes.push_back(Element);
		}
		else if (NewDistanse == Distanse)
		{
			Indexes.push_back(Element);
		}
	}
	if (Indexes.size() == 1) Direction_ = Indexes[0];
	else
	{
		std::sort(Indexes.begin(), Indexes.end());
		Direction_ = Indexes[0];
	}
}
void Cast::choiseDirection(bool Ways[4])
{
	Ways[(Direction_ + 2) % 4] = false; 
	std::vector<int> Directions;
	for (int i = 0; i < 4; i++) if (Ways[i]) Directions.push_back(i);
	if (Directions.size() == 1) Direction_ = Directions[0];
	else
	{
		switch (Mode_)
		{
		case CastMode::Attack:
		{
			decision(Directions, DirectionPoint_);
			return;
		}
		case CastMode::Fear:
		{
			std::srand(time(0));
			Direction_ = Directions[rand() % Directions.size()];
			return;
		}
		case CastMode::Retreat:
		{
			decision(Directions, RetreatPoint_);
			return;
		}
		}
	}
}
void Cast::preparePosition()
{
	X_ = 13 * Size_ + Size_ / 2;
	Y_ = 14 * Size_;
	Direction_ = 1;
}

void Blinky::setStartPosition()
{
	X_ = 13 * Size_ + Size_ / 2;
	Y_ = 14 * Size_;
}
Blinky::Blinky()
{
	setStartPosition();
	RetreatPoint_ = { 25 * Size_, 0 };
}
void Blinky::setDirectionPoint(std::pair<int, int> Point)
{
	DirectionPoint_ = Point;
}
void Pinky::setStartPosition()
{
	X_ = 13 * Size_ + Size_ / 2;
	Y_ = 17 * Size_;
}
Pinky::Pinky()
{
	setStartPosition();
	RetreatPoint_ = { 2 * Size_, 0 };
}
void Pinky::setDirectionPoint(std::pair<int, int> Point, int Direction)
{
	int Count = 4;
	switch (Direction)
	{
	case 0:
	{
		DirectionPoint_.first = Point.first;
		DirectionPoint_.second = Point.second - Count * Size_;
		return;
	}
	case 1:
	{
		DirectionPoint_.first = Point.first - Count * Size_;
		DirectionPoint_.second = Point.second;
		return;
	}
	case 2:
	{
		DirectionPoint_.first = Point.first;
		DirectionPoint_.second = Point.second + Count * Size_;
		return;
	}
	case 3:
	{
		DirectionPoint_.first = Point.first + Count * Size_;
		DirectionPoint_.second = Point.second;
		return;
	}
	default:
		return;
	}
}

void Inky::setStartPosition()
{
	X_ = 11 * Size_ + Size_ / 2;
	Y_ = 17 * Size_;
}
Inky::Inky()
{
	setStartPosition();
	RetreatPoint_ = { 27 * Size_, 35 * Size_ };
}
void Inky::setDirectionPoint(std::pair<int, int> Point, int Direction, std::pair<int, int> Blinky)
{
	int Count = 2;
	switch (Direction)
	{
	case 0:
	{
		DirectionPoint_.first = (Point.first - Blinky.first)*2 + Blinky.first;
		DirectionPoint_.second = (Point.second - Count * Size_ - Blinky.first) * 2 + Blinky.first;
		return;
	}
	case 1:
	{
		DirectionPoint_.first = (Point.first - Count * Size_ - Blinky.first) * 2 + Blinky.first;
		DirectionPoint_.second = (Point.second - Blinky.first) * 2 + Blinky.first;
		return;
	}
	case 2:
	{
		DirectionPoint_.first = (Point.first - Blinky.first) * 2 + Blinky.first;
		DirectionPoint_.second = (Point.second + Count * Size_ - Blinky.first) * 2 + Blinky.first;
		return;
	}
	case 3:
	{
		DirectionPoint_.first = (Point.first + Count * Size_ - Blinky.first) * 2 + Blinky.first;
		DirectionPoint_.second = (Point.second - Blinky.first) * 2 + Blinky.first;
		return;
	}
	default:
		return;
	}
}

void Clyde::setStartPosition()
{
	X_ = 15 * Size_ + Size_ / 2;
	Y_ = 17 * Size_;
}
Clyde::Clyde()
{
	setStartPosition();
	RetreatPoint_ = { 0, 35 * Size_ };
}
void Clyde::setDirectionPoint(std::pair<int, int> Point)
{
	int Count = 8;
	DirectionPoint_ = ((sqrt(distanse({ X_, Y_ }, Point)) >= Count * Size_)? Point : RetreatPoint_);
}
