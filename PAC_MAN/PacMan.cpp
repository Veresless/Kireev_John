#include "PacMan.h"
#include "Constants.h"
#include "MapConstants.h"


void PacMan::setStartPosition()
{
	point_ = getPacManStartPosition();
}

PacMan::PacMan() : DinamicSprite(SpriteType::PAC_MAN, getYellow(), SPRITE_PAC_MAN)
{
	setStartPosition();
}