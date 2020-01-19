#ifndef H_PAC_MAN
#define H_PAC_MAN

#include "DinamicSprite.h"

class PacMan : public DinamicSprite
{
public:
	PacMan();
	virtual void setStartPosition() override;
private:
	PacMan(PacMan const& pacMan);
	PacMan(PacMan const&& pacMan);
};
#endif