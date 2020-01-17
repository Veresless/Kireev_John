#ifndef H_CLYDE
#define H_CLYDE

#include "Gost.h"

class Clyde : public Gost
{
public:
	virtual void setStartPosition() override;
	virtual void setDirectionPoint(const POINT Point, const Direction direction, const POINT blinky) override;
	Clyde();
};
#endif