#pragma once
#include "DinamicSprite.h"
#include <vector>

enum CastMode
{
	Attack,
	Retreat,
	Fear
};

class PacMan : public DinamicSprite
{
protected:
	void setDefaultType();
public:
	PacMan();
	void setStartPosition();
	void initializeSample(COLORREF Color, COLORREF Background);
};
class Cast : public DinamicSprite
{
protected:
	CastMode Mode_;
	void setDefaultType();
	std::pair<int, int> RetreatPoint_, DirectionPoint_;
	int distanse(std::pair<int, int> Position, std::pair<int, int> DirectionPoint);
	std::pair<int, int> getPoint(int Direction);
	void decision(std::vector<int> &Directions, std::pair<int, int> DirectionPoint);
public:
	Cast();
	CastMode getMode();
	void preparePosition();
	void choiseDirection(bool Ways[4]);
	void changeMode(CastMode Mode);
	void initializeSample(COLORREF Color, COLORREF Background);
};
class Blinky : public Cast
{
public:
	void setStartPosition();
	void setDirectionPoint(std::pair<int, int> Point);
	Blinky();
};
class Pinky : public Cast
{
public:
	void setStartPosition();
	void setDirectionPoint(std::pair<int, int> Point, int Direction);
	Pinky();
};
class Inky : public Cast
{
public:
	void setStartPosition();
	void setDirectionPoint(std::pair<int, int> Point, int Direction, std::pair<int, int> Blinky);
	Inky();
};
class Clyde : public Cast
{
public:
	void setStartPosition();
	void setDirectionPoint(std::pair<int, int> Point);
	Clyde();
};