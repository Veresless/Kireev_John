#include <Windows.h>
#include <string>

#include "Field.h"
#include "MapConstants.h"
#include "StaticSprite.h"
#include "Gost.h"
#include "Constants.h"

void Field::setSprites()
{
	empty_ = StaticSprite::createSprite(SpriteType::EMPTY);
	wallVertical_ = StaticSprite::createSprite(SpriteType::WALL);
	wallHorizontal_ = StaticSprite::createSprite(SpriteType::WALL);
	wallLeftBottom_ = StaticSprite::createSprite(SpriteType::WALL);
	wallRightBottom_ = StaticSprite::createSprite(SpriteType::WALL);
	wallLeftTop_ = StaticSprite::createSprite(SpriteType::WALL);
	wallRightTop_ = StaticSprite::createSprite(SpriteType::WALL);
	door_ = StaticSprite::createSprite(SpriteType::WALL);
	blinky_ = Gost::createGost(GostType::BLINKY);
	pinky_ = Gost::createGost(GostType::PINKY);
	inky_ = Gost::createGost(GostType::INKY);
	clyde_ = Gost::createGost(GostType::CLYDE);
	schorePoint_ = StaticSprite::createSprite(SpriteType::SCHORE_POINT);
	energiser_ = StaticSprite::createSprite(SpriteType::ENERGISER);
	empty_->setMainColor(getBlue());
	empty_->initializeSample(SPRITE_EMPTY);
	wallVertical_->setMainColor(getBlue());
	wallVertical_->initializeSample(WALL_VERTICAL);
	wallHorizontal_->setMainColor(getBlue());
	wallHorizontal_->initializeSample(WALL_HORIZONTAL);
	wallLeftBottom_->setMainColor(getBlue());
	wallLeftBottom_->initializeSample(WALL_LEFT_BOTTOM);
	wallRightBottom_->setMainColor(getBlue());
	wallRightBottom_->initializeSample(WALL_RIGHT_BOTTOM);
	wallLeftTop_->setMainColor(getBlue());
	wallLeftTop_->initializeSample(WALL_LEFT_TOP);
	wallRightTop_->setMainColor(getBlue());
	wallRightTop_->initializeSample(WALL_RIGHT_TOP);
	door_->setMainColor(getRed());
	door_->initializeSample(WALL_HORIZONTAL);
	normalCast();
	schorePoint_->setMainColor(getWhite());
	schorePoint_->initializeSample(SPRITE_SCHORE_POINT);
	energiser_->setMainColor(getWhite());
	energiser_->initializeSample(SPRITE_ENERGISER);
}
void Field::normalCast()
{
	normalBlinky();
	normalPinky();
	normalInky();
	normalClyde();
	mode_ = GostMode::ATTACK;
}
void Field::normalBlinky()
{
	blinky_->setMainColor(getRed());
	blinky_->initializeSample(SPRITE_GOST);
	blinky_->setMode(GostMode::ATTACK);
}
void Field::normalPinky()
{
	pinky_->setMainColor(getPink());
	pinky_->initializeSample(SPRITE_GOST);
	pinky_->setMode(GostMode::ATTACK);
}
void Field::normalInky()
{
	inky_->setMainColor(getCayan());
	inky_->initializeSample(SPRITE_GOST);
	inky_->setMode(GostMode::ATTACK);

}
void Field::normalClyde()
{
	clyde_->setMainColor(getOrange());
	clyde_->initializeSample(SPRITE_GOST);
	clyde_->setMode(GostMode::ATTACK);
}
void Field::fearCast()
{
	changeCastMode(GostMode::FEAR);
	blinky_->setMainColor(getBlue());
	blinky_->initializeSample(SPRITE_GOST);
	pinky_->setMainColor(getBlue());
	pinky_->initializeSample(SPRITE_GOST);
	inky_->setMainColor(getBlue());
	inky_->initializeSample(SPRITE_GOST);
	clyde_->setMainColor(getBlue());
	clyde_->initializeSample(SPRITE_GOST);
}

void Field::setStart()
{
	
	const int height = getVertical();
	const int width = getHorizontal();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			switch (MAP[i][j])
			{
			case 'F':
			{
				level_[i][j] = wallRightBottom_;
				break;
			}
			case 'T':
			{
				level_[i][j] = wallLeftBottom_;
				break;
			}
			case 'L':
			{
				level_[i][j] = wallRightTop_;
				break;
			}
			case 'J':
			{
				level_[i][j] = wallLeftTop_;
				break;
			}
			case '-':
			{
				level_[i][j] = wallHorizontal_;
				break;
			}
			case '=':
			{
				level_[i][j] = door_;
				break;
			}
			case '|':
			{
				level_[i][j] = wallVertical_;
				break;
			}
			case ' ':
			{
				level_[i][j] = empty_;
				break;
			}
			case '.':
			{
				level_[i][j] = schorePoint_;
				break;
			}
			case 'O':
			{
				level_[i][j] = energiser_;
				break;
			}
			default:
			{
				break;
			}
			}
		}
	}
}
void Field::printAll()
{
	const int vertical = getVertical();
	const int horizontal = getHorizontal();
	for (int i = 0; i < vertical; i++)
		for (int j = 0; j < horizontal; j++)
			level_[i][j]->printOn(j, i, hdc_);
	pacMan_.print(hdc_);
	blinky_->print(hdc_);
	pinky_->print(hdc_);
	inky_->print(hdc_);
	clyde_->print(hdc_);
}
void Field::resetDinamic()
{
	eraseDinamic(pacMan_.getPosition());
	eraseDinamic(blinky_->getPosition());
	eraseDinamic(pinky_->getPosition());
	eraseDinamic(inky_->getPosition());
	eraseDinamic(clyde_->getPosition());

	pacMan_.setStartPosition();
	blinky_->setStartPosition();
	pinky_->setStartPosition();
	inky_->setStartPosition();
	clyde_->setStartPosition();

	pacMan_.print(hdc_);
	blinky_->print(hdc_);
	pinky_->print(hdc_);
	inky_->print(hdc_);
	clyde_->print(hdc_);
}
void Field::resetLevel()
{
	setStart();
	resetDinamic();
	printAll();
}
void Field::eraseDinamic(const POINT Point)
{
	const int size = getSize();
	int xFirst = Point.x / size;
	int xSecond = xFirst + ((Point.x % size != 0) ? 1 : 0);
	xSecond %= getHorizontal();
	int yFirst = Point.y / size;
	int ySecond = yFirst + ((Point.y % size != 0) ? 1 : 0);
	ySecond %= getVertical();
	if (yFirst == ySecond)
	{
		if (xFirst != xSecond)
		{
			level_[yFirst][xFirst]->printOn(xFirst, yFirst, hdc_);
			level_[ySecond][xSecond]->printOn(xSecond, ySecond, hdc_);
		}
		else 
			level_[yFirst][xFirst]->printOn(xFirst, yFirst, hdc_);
	}
	else
	{
		if (xFirst != xSecond)
		{
			level_[yFirst][xFirst]->printOn(xFirst, yFirst, hdc_);
			level_[ySecond][xFirst]->printOn(xFirst, yFirst, hdc_);
			level_[yFirst][xSecond]->printOn(xSecond, ySecond, hdc_);
			level_[ySecond][xSecond]->printOn(xSecond, ySecond, hdc_);
		}
		else
			level_[yFirst][xFirst]->printOn(xFirst, yFirst, hdc_);
			level_[ySecond][xSecond]->printOn(xSecond, ySecond, hdc_);
	}
}

void Field::setBlinky()
{
	eraseDinamic(blinky_->getPosition());
	blinky_->setReadyPosition();
	blinkyReady_ = true;
}
void Field::setPinky()
{
	eraseDinamic(pinky_->getPosition());
	pinky_->setReadyPosition();
	pinkyReady_ = true;
}
void Field::setInky()
{
	eraseDinamic(inky_->getPosition());
	inky_->setReadyPosition();
	inkyReady_ = true;
}
void Field::setClyde()
{
	eraseDinamic(clyde_->getPosition());
	clyde_->setReadyPosition();
	clydeReady_ = true;
}
void Field::setEasySpeed()
{
	pacMan_.setSpeed(getMiddleSpeed());
	blinky_->setSpeed(getLowSpeed());
	pinky_->setSpeed(getLowSpeed());
	inky_->setSpeed(getLowSpeed());
	clyde_->setSpeed(getLowSpeed());
}
void Field::setMediumSpeed()
{
	pacMan_.setSpeed(getHighSpeed());
	blinky_->setSpeed(getMiddleSpeed());
	pinky_->setSpeed(getMiddleSpeed());
	inky_->setSpeed(getMiddleSpeed());
	clyde_->setSpeed(getMiddleSpeed());
}
void Field::setHardSpeed()
{
	pacMan_.setSpeed(getMiddleSpeed());
	blinky_->setSpeed(getHighSpeed());
	pinky_->setSpeed(getHighSpeed());
	inky_->setSpeed(getHighSpeed());
	clyde_->setSpeed(getHighSpeed());
}
const bool Field::isEmpty(const POINT position, const Direction direction)
{
	const int size = getSize();
	int y = position.y / size;
	int x = position.x / size;
	bool rezult = false;
	switch (direction)
	{
	case UP:
	{
		y += ((position.y % size != 0) ? 0 : - 1) + getVertical();
		y %= getVertical();
		SpriteType type = level_[y][x]->getType();
		rezult = (position.x % size == 0 && (type == SpriteType::EMPTY || type == SpriteType::SCHORE_POINT || type == SpriteType::ENERGISER));
		break;
	}
	case RIGHT:
	{
		x += 1;
		x %= getHorizontal();
		SpriteType type = level_[y][x]->getType();
		rezult = (position.y % size == 0 && (type == SpriteType::EMPTY || type == SpriteType::SCHORE_POINT || type == SpriteType::ENERGISER));
		break;
	}
	case DOWN:
	{
		y += 1;
		y %= getVertical();
		SpriteType type = level_[y][x]->getType();
		rezult = (position.x % size == 0 && (type == SpriteType::EMPTY || type == SpriteType::SCHORE_POINT || type == SpriteType::ENERGISER));
		break;
	}
	case LEFT:
	{
		x += ((position.x % size != 0) ? 0 : -1) + getHorizontal();
		x %= getHorizontal();
		SpriteType type = level_[y][x]->getType();
		rezult = (position.y % size == 0 && (type == SpriteType::EMPTY || type == SpriteType::SCHORE_POINT || type == SpriteType::ENERGISER));
		break;
	}
	default:
		break;
	}
	return rezult;
}
void Field::moveDinamic(DinamicSprite* sprite, const POINT position, const Direction direction)
{
	if (isEmpty(position, direction))
	{
		sprite->move();
		sprite->print(hdc_);
	}
}
void Field::moveAllDinamic()
{
	bool IsUpdatePacMan = isEmpty(pacMan_.getPosition(), pacMan_.getDirection());
	bool IsUpdateBlinky = isEmpty(blinky_->getPosition(), blinky_->getDirection());
	bool IsUpdatePinky = isEmpty(pinky_->getPosition(), pinky_->getDirection());
	bool IsUpdateInky = isEmpty(inky_->getPosition(), inky_->getDirection());
	bool IsUpdateClyde = isEmpty(clyde_->getPosition(), clyde_->getDirection());
	
	if (IsUpdatePacMan) eraseDinamic(pacMan_.getPosition());
	if (IsUpdateBlinky) eraseDinamic(blinky_->getPosition());
	if (IsUpdatePinky) eraseDinamic(pinky_->getPosition());
	if (IsUpdateInky) eraseDinamic(inky_->getPosition());
	if (IsUpdateClyde) eraseDinamic(clyde_->getPosition());
	if (IsUpdatePacMan) moveDinamic(&pacMan_, pacMan_.getPosition(), pacMan_.getDirection());
	if (IsUpdateBlinky) moveDinamic(blinky_, blinky_->getPosition(), blinky_->getDirection());
	if (IsUpdatePinky) moveDinamic(pinky_, pinky_->getPosition(), pinky_->getDirection());
	if (IsUpdateInky) moveDinamic(inky_, inky_->getPosition(), inky_->getDirection());
	if (IsUpdateClyde) moveDinamic(clyde_, clyde_->getPosition(), clyde_->getDirection());
}
void Field::turnDinamic(DinamicSprite* sprite, const Direction direction)
{
	if (isEmpty(sprite->getPosition(), direction)) sprite->setDirection(direction);
}
void Field::turnPacMan(Direction const direction)
{
	turnDinamic(&pacMan_, direction);
}
bool Field::checkSpecial(const int x, const int y)
{
	POINT firstPoint = getFirstSpecialPoint();
	POINT secondPoint = getSecondSpecialPoint();
	POINT thirdPoint = getThirdSpecialPoint();
	POINT fourthPoint = getFourthSpecialPoint();
	return (y == firstPoint.y) && (x == firstPoint.x) || (y == secondPoint.y) && (x == secondPoint.x) ||
		(y == thirdPoint.y) && (x == thirdPoint.x) || (y == fourthPoint.y) && (x == fourthPoint.x);
}
void Field::castMovement()
{
	int size = getSize();
	if (blinkyReady_)
	{
		POINT position = blinky_->getPosition();
		if (position.x % size == 0 && position.y % size == 0)
		{
			const int countDirections = getCountDirections();
			const Direction direction = blinky_->getDirection();
			const Direction left = (Direction)(((int)direction - 1 + countDirections) % countDirections);
			const Direction right = (Direction)(((int)direction + 1) % countDirections);
			if (!isEmpty(position, direction) || isEmpty(position, left) || isEmpty(position, right))
			{
				bool ways[4];
				for (int i = 0; i < 4; i++)
				{
					ways[i] = isEmpty(position, (Direction)i);
				}
				if (blinky_->getMode() == 0)
				{
					blinky_->setDirectionPoint(pacMan_.getPosition(), pacMan_.getDirection(), blinky_->getPosition());
				}
				if (checkSpecial(position.x / size, position.y / size))
				{
					ways[0] = false;
				}
				blinky_->choiseDirection(ways);
			}
		}
	}
	if (pinkyReady_)
	{
		POINT position = pinky_->getPosition();
		if (position.x % size == 0 && position.y % size == 0)
		{
			const int countDirections = getCountDirections();
			const Direction direction = pinky_->getDirection();
			const Direction left = (Direction)(((int)direction - 1 + countDirections) % countDirections);
			const Direction right = (Direction)(((int)direction + 1) % countDirections);
			if (!isEmpty(position, direction) || isEmpty(position, left) || isEmpty(position, right))
			{
				bool ways[4];
				for (int i = 0; i < 4; i++)
				{
					ways[i] = isEmpty(position, (Direction)i);
				}
				if (pinky_->getMode() == 0)
				{
					pinky_->setDirectionPoint(pacMan_.getPosition(), pacMan_.getDirection(), blinky_->getPosition());
				}
				if (checkSpecial(position.x / size, position.y / size))
				{
					ways[0] = false;
				}
				pinky_->choiseDirection(ways);
			}
		}
	}
	if (inkyReady_)
	{
		POINT position = inky_->getPosition();
		if (position.x % size == 0 && position.y % size == 0)
		{
			const int countDirections = getCountDirections();
			const Direction direction = inky_->getDirection();
			const Direction left = (Direction)(((int)direction - 1 + countDirections) % countDirections);
			const Direction right = (Direction)(((int)direction + 1) % countDirections);
			if (!isEmpty(position, direction) || isEmpty(position, left) || isEmpty(position, right))
			{
				bool ways[4];
				for (int i = 0; i < 4; i++)
				{
					ways[i] = isEmpty(position, (Direction)i);
				}
				if (inky_->getMode() == 0)
				{
					inky_->setDirectionPoint(pacMan_.getPosition(), pacMan_.getDirection(), blinky_->getPosition());
				}
				if (checkSpecial(position.x / size, position.y / size))
				{
					ways[0] = false;
				}
				inky_->choiseDirection(ways);
			}
		}
	}
	if (clydeReady_)
	{
		POINT position = clyde_->getPosition();
		if (position.x % size == 0 && position.y % size == 0)
		{
			const int countDirections = getCountDirections();
			const Direction direction = clyde_->getDirection();
			const Direction left = (Direction)(((int)direction - 1 + countDirections) % countDirections);
			const Direction right = (Direction)(((int)direction + 1) % countDirections);
			if (!isEmpty(position, direction) || isEmpty(position, left) || isEmpty(position, right))
			{
				bool ways[4];
				for (int i = 0; i < 4; i++)
				{
					ways[i] = isEmpty(position, (Direction)i);
				}
				if (clyde_->getMode() == 0)
				{
					clyde_->setDirectionPoint(pacMan_.getPosition(), pacMan_.getDirection(), blinky_->getPosition());
				}
				if (checkSpecial(position.x / size, position.y / size))
				{
					ways[0] = false;
				}
				clyde_->choiseDirection(ways);
			}
		}
	}
}
void Field::changeCastMode(GostMode Mode)
{
	mode_ = Mode;
	blinky_->setMode(Mode);
	pinky_->setMode(Mode);
	inky_->setMode(Mode);
	clyde_->setMode(Mode);
}
const GostMode Field::getCastMode()
{
	return mode_;
}
Field::Field()
{
	hwnd_ = GetConsoleWindow();
	hdc_ = GetDC(hwnd_);
	setSprites();
	const int vertical = getVertical();
	const int horizontal = getHorizontal();
	level_ = new StaticSprite** [vertical];
	
	for (int i = 0; i < vertical; i++)
	{
		level_[i] = new StaticSprite * [horizontal];
	}
	setStart();
	blinkyReady_ = pinkyReady_ = inkyReady_ = clydeReady_ = false;
	mode_ = GostMode::ATTACK;
}
const SpriteType Field::getSpriteTypeAt(const int x, const int y)
{
	return level_[y][x]->getType();
}
void Field::setEmptyAt(const int x, const int y)
{
	level_[y][x] = empty_;
}
Field::~Field()
{
	if (level_ != nullptr)
	{
		const int vertical = getVertical();
		for (int i = 0; i < vertical; i++)
		{
			if (level_[i] != nullptr)
			{
				delete[] level_[i];
			}
		}
		delete[] level_;
	}
	ReleaseDC(hwnd_, hdc_);
}