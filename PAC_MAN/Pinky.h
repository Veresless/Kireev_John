#ifndef H_PINKY
#define H_PINKY

#include "Gost.h"
class Pinky : public Gost
{
public:
	virtual void setStartPosition() override;
	virtual void setDirectionPoint(const POINT Point, const Direction direction, const POINT blinky) override;
	Pinky();
};
#endif