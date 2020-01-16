#ifndef H_DINAMIC_SPRITE
#define H_DINAMIC_SPRITE

#include "BaseSprite.h"

enum Direction
{
	UP,
	LEFT,
	DOWN,
	RIGHT
};

class DinamicSprite : public BaseSprite
{
public:
	inline const POINT getPosition() const
	{
		return point_;
	}
	inline const Direction getDirection() const
	{
		return direction_;
	}
	inline const int getSpeed() const
	{
		return speed_;
	}
	virtual void setStartPosition() = 0;
	void setSpeed(const int speed);
	void move();
	void setDirection(const Direction direction);
	const void print(const HDC hdc);
protected:
	POINT point_;
	Direction direction_;
	int speed_;
};
#endif