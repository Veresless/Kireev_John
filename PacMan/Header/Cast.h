#ifndef H_CAST
#define H_CAST

#include <vector>

#include "DinamicSprite.h"

enum CastMode
{
	ATTACK,
	RETREAT,
	FEAR
};

class Cast : public DinamicSprite
{
public:
	Cast();
	inline const CastMode getMode() const
	{
		return mode_;
	}
	void setReadyPosition();
	virtual void setStartPosition() = 0;
	void choiseDirection(bool ways[4]);
	void setMode(const CastMode mode);
protected:
	CastMode mode_;
	POINT retreatPoint_;
	POINT directionPoint_;
	virtual void setDefaultType() override;
	const int distanse (const POINT position, const POINT directionPoint);
private:
	const POINT getPoint(const Direction direction);
	void decision(std::vector<Direction>& directions, const POINT directionPoint);
};
class Blinky : public Cast
{
public:
	virtual void setStartPosition() override;
	void setDirectionPoint(const POINT point);
	Blinky();
};
class Pinky : public Cast
{
public:
	virtual void setStartPosition() override;
	void setDirectionPoint(const POINT point, const Direction direction);
	Pinky();
};
class Inky : public Cast
{
public:
	virtual void setStartPosition() override;
	void setDirectionPoint(const POINT point, const Direction direction, const POINT Blinky);
	Inky();
};
class Clyde : public Cast
{
public:
	virtual void setStartPosition() override;
	void setDirectionPoint(const POINT Point);
	Clyde();
};
#endif