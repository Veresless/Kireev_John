#ifndef H_INKY
#define H_INKY

#include "Gost.h"
class Inky : public Gost
{
public:
	virtual void setStartPosition() override;
	virtual void setDirectionPoint(const POINT Point, const Direction direction, const POINT blinky) override;
	Inky();
};
#endif