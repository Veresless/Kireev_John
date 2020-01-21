#ifndef H_CLYDE
#define H_CLYDE

#include "Gost.h"

class Clyde : public Gost
{
public:
	Clyde();
	virtual void setDirectionPoint(const POINT& point, const Direction direction, const POINT& blinky) override;
private:
	Clyde(Clyde const& clyde);
	Clyde(Clyde const&& clyde);
};
#endif