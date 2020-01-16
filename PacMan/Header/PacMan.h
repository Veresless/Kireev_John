#ifndef H_PACMAN
#define H_PACMAN

#include <windows.h>

#include "DinamicSprite.h"

class PacMan : public DinamicSprite
{
public:
	PacMan();
	void setStartPosition();
protected:
	virtual void setDefaultType() override;
};
#endif