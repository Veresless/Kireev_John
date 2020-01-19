#ifndef H_INKY
#define H_INKY

#include "Gost.h"

class Inky : public Gost
{
public:
	Inky();
	virtual void setDirectionPoint(const POINT& point, const Direction direction, const POINT& blinky) override;
private:
	Inky(Inky const& inky);
	Inky(Inky const&& inky);
};
#endif