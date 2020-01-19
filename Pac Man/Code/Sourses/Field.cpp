#include <Windows.h>
#include <string>

#include "../Headers/Field.h"

Field::Field(): hwnd_(GetConsoleWindow()), hdc_(GetDC(hwnd_)), 
blinkyReady(false), pinkyReady(false), inkyReady(false), clydeReady(false), mode_(GostMode::ATTACK),
empty_(StaticSprite::createSprite(StaticSpriteType::EMPTY, SPRITE_EMPTY)),
wallVertical_(StaticSprite::createSprite(StaticSpriteType::WALL, WALL_VERTICAL)),
wallHorizontal_(StaticSprite::createSprite(StaticSpriteType::WALL, WALL_HORIZONTAL)),
wallLeftBottom_(StaticSprite::createSprite(StaticSpriteType::WALL, WALL_LEFT_BOTTOM)),
wallRightBottom_(StaticSprite::createSprite(StaticSpriteType::WALL, WALL_RIGHT_BOTTOM)),
wallLeftTop_(StaticSprite::createSprite(StaticSpriteType::WALL, WALL_LEFT_TOP)),
wallRightTop_(StaticSprite::createSprite(StaticSpriteType::WALL, WALL_RIGHT_TOP)),
door_(StaticSprite::createSprite(StaticSpriteType::WALL, WALL_HORIZONTAL)),
blinky_(Gost::createGost(GostType::BLINKY)),
pinky_(Gost::createGost(GostType::PINKY)),
inky_(Gost::createGost(GostType::INKY)),
clyde_(Gost::createGost(GostType::CLYDE)),
schorePoint_(StaticSprite::createSprite(StaticSpriteType::SCHORE_POINT, SPRITE_SCHORE_POINT)),
energiser_(StaticSprite::createSprite(StaticSpriteType::ENERGISER, SPRITE_ENERGISER)),
pacMan_(std::make_shared<PacMan>())
{
	level_ = std::unique_ptr<std::unique_ptr<std::shared_ptr<StaticSprite>[]>[]>(new std::unique_ptr<std::shared_ptr<StaticSprite>[]>[getVertical()]);
	for (int i = 0; i < getVertical(); i++)
	{
		level_[i] = std::unique_ptr<std::shared_ptr<StaticSprite>[]>(new std::shared_ptr<StaticSprite>[getHorizontal()]);
	}
	resetMap();
}
void Field::setGostMode(GostMode Mode)
{
	mode_ = Mode;
	blinky_->setMode(Mode);
	pinky_->setMode(Mode);
	inky_->setMode(Mode);
	clyde_->setMode(Mode);
}
const std::shared_ptr<Gost> const Field::getGost(const GostType type) const
{
	std::shared_ptr<Gost> gost;
	switch (type)
	{
	case BLINKY:
	{
		gost = blinky_;
		break;
	}
	case PINKY:
	{
		gost = pinky_;
		break;
	}
	case INKY:
	{
		gost = inky_;
		break;
	}
	case CLYDE:
	{
		gost = clyde_;
		break;
	}
	default:
	{
		break;
	}
	}
	return gost;
}
void Field::setBlinkyReady()
{
	eraseDinamic(blinky_->getPosition());
	blinky_->setPosition(getCastReadyPosition());
	blinky_->setDirection(LEFT);
	blinkyReady = true;
}
void Field::setPinkyReady()
{
	eraseDinamic(pinky_->getPosition());
	pinky_->setPosition(getCastReadyPosition());
	pinky_->setDirection(LEFT);
	pinkyReady = true;
}
void Field::setInkyReady()
{
	eraseDinamic(inky_->getPosition());
	inky_->setPosition(getCastReadyPosition());
	inky_->setDirection(LEFT);
	inkyReady = true;
}
void Field::setClydeReady()
{
	eraseDinamic(clyde_->getPosition());
	clyde_->setPosition(getCastReadyPosition());
	clyde_->setDirection(LEFT);
	clydeReady = true;
}
void Field::setEasySpeed()
{
	pacMan_->setSpeed(getMiddleSpeed());
	blinky_->setSpeed(getLowSpeed());
	pinky_->setSpeed(getLowSpeed());
	inky_->setSpeed(getLowSpeed());
	clyde_->setSpeed(getLowSpeed());
}
void Field::setMediumSpeed()
{
	pacMan_->setSpeed(getHighSpeed());
	blinky_->setSpeed(getMiddleSpeed());
	pinky_->setSpeed(getMiddleSpeed());
	inky_->setSpeed(getMiddleSpeed());
	clyde_->setSpeed(getMiddleSpeed());
}
void Field::setHardSpeed()
{
	pacMan_->setSpeed(getMiddleSpeed());
	blinky_->setSpeed(getHighSpeed());
	pinky_->setSpeed(getHighSpeed());
	inky_->setSpeed(getHighSpeed());
	clyde_->setSpeed(getHighSpeed());
}
void Field::setEmptyAt(const int x, const int y)
{
	level_[y][x] = empty_;
}
StaticSpriteType Field::getSpriteTypeAt(const int x, const int y)
{
	return level_[y][x]->getType();
}
void Field::fearGost()
{
	setGostMode(GostMode::FEAR);
	blinky_->setFear(true);
	blinky_->updateSample();
	pinky_->setFear(true);
	pinky_->updateSample();
	inky_->setFear(true);
	inky_->updateSample();
	clyde_->setFear(true);
	clyde_->updateSample();
}
void Field::normalGost()
{
	normalBlinky();
	normalPinky();
	normalInky();
	normalClyde();
	mode_ = GostMode::ATTACK;
}
void Field::normalBlinky()
{
	blinky_->setFear(false);
	blinky_->updateSample();
	blinky_->setMode(GostMode::ATTACK);
}
void Field::normalPinky()
{
	pinky_->setFear(false);
	pinky_->updateSample();
	pinky_->setMode(GostMode::ATTACK);
}
void Field::normalInky()
{
	inky_->setFear(false);
	inky_->updateSample();
	inky_->setMode(GostMode::ATTACK);

}
void Field::normalClyde()
{
	clyde_->setFear(false);
	clyde_->updateSample();
	clyde_->setMode(GostMode::ATTACK);
}
void Field::printAll()
{
	const int vertical = getVertical();
	const int horizontal = getHorizontal();
	for (int i = 0; i < vertical; i++)
		for (int j = 0; j < horizontal; j++)
			level_[i][j]->printOn(j, i, hdc_);
	pacMan_->print(hdc_);
	blinky_->print(hdc_);
	pinky_->print(hdc_);
	inky_->print(hdc_);
	clyde_->print(hdc_);
}
void Field::resetLevel()
{
	resetMap();
	resetDinamic();
	printAll();
}
void Field::resetDinamic()
{
	eraseDinamic(pacMan_->getPosition());
	eraseDinamic(blinky_->getPosition());
	eraseDinamic(pinky_->getPosition());
	eraseDinamic(inky_->getPosition());
	eraseDinamic(clyde_->getPosition());

	pacMan_->setPosition(getPacManStartPosition());
	blinky_->setPosition(getBlinkyStartPosition());
	pinky_->setPosition(getPinkyStartPosition());
	inky_->setPosition(getInkyStartPosition());
	clyde_->setPosition(getClydeStartPosition());

	pacMan_->setDirection(UP);
	blinky_->setDirection(UP);
	pinky_->setDirection(UP);
	inky_->setDirection(UP);
	clyde_->setDirection(UP);

	pacMan_->print(hdc_);
	blinky_->print(hdc_);
	pinky_->print(hdc_);
	inky_->print(hdc_);
	clyde_->print(hdc_);
}
void Field::gostMovement()
{
	int size = getSize();
	if (blinkyReady)
	{
		POINT position = blinky_->getPosition();
		if (position.x % size == 0 && position.y % size == 0)
		{
			const int countDirections = getCountDirections();
			const Direction direction = blinky_->getDirection();
			const Direction left = (Direction)(((int)direction - 1 + countDirections) % countDirections);
			const Direction right = (Direction)(((int)direction + 1) % countDirections);
			if (!checkEmpty(position, direction) || checkEmpty(position, left) || checkEmpty(position, right))
			{
				bool ways[4];
				for (int i = 0; i < 4; i++)
				{
					ways[i] = checkEmpty(position, (Direction)i);
				}
				if (GostMode::ATTACK == blinky_->getMode())
				{
					blinky_->setDirectionPoint(pacMan_->getPosition(), pacMan_->getDirection(), blinky_->getPosition());
				}
				if (checkSpecial(position.x / size, position.y / size))
				{
					ways[0] = false;
				}
				blinky_->choiseDirection(ways);
			}
		}
	}
	if (pinkyReady)
	{
		POINT position = pinky_->getPosition();
		if (position.x % size == 0 && position.y % size == 0)
		{
			const int countDirections = getCountDirections();
			const Direction direction = pinky_->getDirection();
			const Direction left = (Direction)(((int)direction - 1 + countDirections) % countDirections);
			const Direction right = (Direction)(((int)direction + 1) % countDirections);
			if (!checkEmpty(position, direction) || checkEmpty(position, left) || checkEmpty(position, right))
			{
				bool ways[4];
				for (int i = 0; i < 4; i++)
				{
					ways[i] = checkEmpty(position, (Direction)i);
				}
				if (pinky_->getMode() == 0)
				{
					pinky_->setDirectionPoint(pacMan_->getPosition(), pacMan_->getDirection(), blinky_->getPosition());
				}
				if (checkSpecial(position.x / size, position.y / size))
				{
					ways[0] = false;
				}
				pinky_->choiseDirection(ways);
			}
		}
	}
	if (inkyReady)
	{
		POINT position = inky_->getPosition();
		if (position.x % size == 0 && position.y % size == 0)
		{
			const int countDirections = getCountDirections();
			const Direction direction = inky_->getDirection();
			const Direction left = (Direction)(((int)direction - 1 + countDirections) % countDirections);
			const Direction right = (Direction)(((int)direction + 1) % countDirections);
			if (!checkEmpty(position, direction) || checkEmpty(position, left) || checkEmpty(position, right))
			{
				bool ways[4];
				for (int i = 0; i < 4; i++)
				{
					ways[i] = checkEmpty(position, (Direction)i);
				}
				if (inky_->getMode() == 0)
				{
					inky_->setDirectionPoint(pacMan_->getPosition(), pacMan_->getDirection(), blinky_->getPosition());
				}
				if (checkSpecial(position.x / size, position.y / size))
				{
					ways[0] = false;
				}
				inky_->choiseDirection(ways);
			}
		}
	}
	if (clydeReady)
	{
		POINT position = clyde_->getPosition();
		if (position.x % size == 0 && position.y % size == 0)
		{
			const int countDirections = getCountDirections();
			const Direction direction = clyde_->getDirection();
			const Direction left = (Direction)(((int)direction - 1 + countDirections) % countDirections);
			const Direction right = (Direction)(((int)direction + 1) % countDirections);
			if (!checkEmpty(position, direction) || checkEmpty(position, left) || checkEmpty(position, right))
			{
				bool ways[4];
				for (int i = 0; i < 4; i++)
				{
					ways[i] = checkEmpty(position, (Direction)i);
				}
				if (clyde_->getMode() == 0)
				{
					clyde_->setDirectionPoint(pacMan_->getPosition(), pacMan_->getDirection(), blinky_->getPosition());
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
void Field::moveAllDinamic()
{
	bool IsUpdatePacMan = checkEmpty(pacMan_->getPosition(), pacMan_->getDirection());
	bool IsUpdateBlinky = checkEmpty(blinky_->getPosition(), blinky_->getDirection());
	bool IsUpdatePinky = checkEmpty(pinky_->getPosition(), pinky_->getDirection());
	bool IsUpdateInky = checkEmpty(inky_->getPosition(), inky_->getDirection());
	bool IsUpdateClyde = checkEmpty(clyde_->getPosition(), clyde_->getDirection());
	
	if (IsUpdatePacMan) eraseDinamic(pacMan_->getPosition());
	if (IsUpdateBlinky) eraseDinamic(blinky_->getPosition());
	if (IsUpdatePinky) eraseDinamic(pinky_->getPosition());
	if (IsUpdateInky) eraseDinamic(inky_->getPosition());
	if (IsUpdateClyde) eraseDinamic(clyde_->getPosition());
	if (IsUpdatePacMan) moveDinamic(pacMan_, pacMan_->getPosition(), pacMan_->getDirection());
	if (IsUpdateBlinky) moveDinamic(blinky_, blinky_->getPosition(), blinky_->getDirection());
	if (IsUpdatePinky) moveDinamic(pinky_, pinky_->getPosition(), pinky_->getDirection());
	if (IsUpdateInky) moveDinamic(inky_, inky_->getPosition(), inky_->getDirection());
	if (IsUpdateClyde) moveDinamic(clyde_, clyde_->getPosition(), clyde_->getDirection());
}
void Field::turnPacMan(Direction const direction)
{
	if (checkEmpty(pacMan_->getPosition(), direction)) pacMan_->setDirection(direction);
}
void Field::resetMap()
{
	const int height = getVertical();
	const int width = getHorizontal();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			switch (MAP[i][j])
			{
			case WALL_RIGHT_BOTTOM_CHAR:
			{
				level_[i][j] = wallRightBottom_;
				break;
			}
			case WALL_LEFT_BOTTOM_CHAR:
			{
				level_[i][j] = wallLeftBottom_;
				break;
			}
			case WALL_RIGHT_TOP_CHAR:
			{
				level_[i][j] = wallRightTop_;
				break;
			}
			case WALL_LEFT_TOP_CHAR:
			{
				level_[i][j] = wallLeftTop_;
				break;
			}
			case WALL_HORIZONTAL_CHAR:
			{
				level_[i][j] = wallHorizontal_;
				break;
			}
			case DOOR_CHAR:
			{
				level_[i][j] = door_;
				break;
			}
			case WALL_VERTICAL_CHAR:
			{
				level_[i][j] = wallVertical_;
				break;
			}
			case EMPTY_CHAR:
			{
				level_[i][j] = empty_;
				break;
			}
			case SCHORE_POINT_CHAR:
			{
				level_[i][j] = schorePoint_;
				break;
			}
			case ENERGISER_CHAR:
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
bool Field::checkEmpty(const POINT& position, const Direction direction) const 
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
		StaticSpriteType type = level_[y][x]->getType();
		rezult = (position.x % size == 0 && (type == StaticSpriteType::EMPTY || type == StaticSpriteType::SCHORE_POINT || type == StaticSpriteType::ENERGISER));
		break;
	}
	case RIGHT:
	{
		x += 1;
		x %= getHorizontal();
		StaticSpriteType type = level_[y][x]->getType();
		rezult = (position.y % size == 0 && (type == StaticSpriteType::EMPTY || type == StaticSpriteType::SCHORE_POINT || type == StaticSpriteType::ENERGISER));
		break;
	}
	case DOWN:
	{
		y += 1;
		y %= getVertical();
		StaticSpriteType type = level_[y][x]->getType();
		rezult = (position.x % size == 0 && (type == StaticSpriteType::EMPTY || type == StaticSpriteType::SCHORE_POINT || type == StaticSpriteType::ENERGISER));
		break;
	}
	case LEFT:
	{
		x += ((position.x % size != 0) ? 0 : -1) + getHorizontal();
		x %= getHorizontal();
		StaticSpriteType type = level_[y][x]->getType();
		rezult = (position.y % size == 0 && (type == StaticSpriteType::EMPTY || type == StaticSpriteType::SCHORE_POINT || type == StaticSpriteType::ENERGISER));
		break;
	}
	default:
		break;
	}
	return rezult;
}
void Field::moveDinamic(const std::shared_ptr<DinamicSprite> sprite, const POINT& position, const Direction direction)
{
	if (checkEmpty(position, direction))
	{
		sprite->move();
		sprite->print(hdc_);
	}
}
void Field::eraseDinamic(const POINT& Point)
{
	const int size = getSize();
	const int x = (Point.x / size + getHorizontal())%getHorizontal();
	const int y = (Point.y / size + getVertical())%getVertical();
	if (0 == Point.y % size)
	{
		if (0 == Point.x % size)
		{
			level_[y][x]->printOn(x, y, hdc_);
		}
		else
		{
			const int xNew = (x+1) % getHorizontal();
			level_[y][x]->printOn(x, y, hdc_);
			level_[y][xNew]->printOn(xNew, y, hdc_);
		}
	}
	else
	{
		if (0 == Point.x % size)
		{
			const int yNew = (y + 1) % getVertical();
			level_[y][x]->printOn(x, y, hdc_);
			level_[yNew][x]->printOn(x, yNew, hdc_);
		}
		else
		{
			const int xNew = (x + 1) % getHorizontal();
			const int yNew = (y + 1) % getVertical();
			level_[y][x]->printOn(x, y, hdc_);
			level_[yNew][x]->printOn(x, yNew, hdc_);
			level_[y][xNew]->printOn(xNew, y, hdc_);
			level_[yNew][xNew]->printOn(xNew, yNew, hdc_);
		}
	}
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