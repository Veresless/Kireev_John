#ifndef H_PACMAN
#define H_PACMAN

#include <windows.h>

#include "DinamicSprite.h"

class PacMan : public DinamicSprite
{
public:
	PacMan();
	virtual void setType(const SpriteType type) override;
	virtual void setMainColor(const COLORREF color) override;
	virtual void setStartPosition() override;
};
#endif