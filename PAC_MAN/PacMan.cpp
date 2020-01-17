#include "PacMan.h"
#include "Constants.h"
#include "MapConstants.h"

void PacMan::setType(const SpriteType type)
{
	type_ = type;
}
void PacMan::setStartPosition()
{
	point_ = getPacManStartPosition();
}
void PacMan::setMainColor(const COLORREF color)
{
	mainColor_ = color;
}
PacMan::PacMan()
{
	setMainColor(getYellow());
	initializeSample(PAC_MAN);
	setType(SpriteType::PACMAN);
	setStartPosition();
}