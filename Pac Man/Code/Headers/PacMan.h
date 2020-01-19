#ifndef H_PAC_MAN
#define H_PAC_MAN

#include "DinamicSprite.h"

class PacMan : public DinamicSprite
{
public:
	PacMan();
private:
	PacMan(PacMan const& pacman);
	PacMan(PacMan const&& pacman);
};

#endif
