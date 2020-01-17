#ifndef H_BLINKY
#define H_BLINKY

#include "Gost.h"
class Blinky : public Gost
{
public:
	virtual void setStartPosition() override;
	virtual void setDirectionPoint(const POINT Point, const Direction direction, const POINT blinky) override;
	Blinky();
};
#endif