#include "PacMan.h"
#include "Constants.h"

void PacMan::setDefaultType()
{
	type_ = SpriteType::PACMAN;
}
void PacMan::setStartPosition()
{
	point_ = getPacManStartPosition();
}
PacMan::PacMan()
{
	setDefaultType();
	setStartPosition();
}