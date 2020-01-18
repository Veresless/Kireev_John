#ifndef H_BLINKY
#define H_BLINKY

#include "Gost.h"

class Blinky : public Gost
{
public:
	Blinky();
	virtual void setStartPosition() override;
	virtual void setDirectionPoint(const POINT& point, const Direction direction, const POINT& blinky) override;
private:
	Blinky(Blinky const& blinky);
	Blinky(Blinky const&& blinky);
};
#endif