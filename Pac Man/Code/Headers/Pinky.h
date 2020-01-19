#ifndef H_PINKY
#define H_PINKY

#include "Gost.h"

class Pinky : public Gost
{
public:
	Pinky();
	virtual void setStartPosition() override;
	virtual void setDirectionPoint(const POINT& point, const Direction direction, const POINT& blinky) override;
private:
	Pinky(Pinky const& pinky);
	Pinky(Pinky const&& pinky);
};
#endif