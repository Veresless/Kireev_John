#include <Windows.h>
#include <string>

#include "Field.h"
#include "Constants.h"

void Field::setSprites()
{
	const int size = getSize();
	COLORREF Red = RGB(255, 0, 0);
	COLORREF Blue = RGB(0, 0, 255);
	COLORREF Yellow = RGB(255, 255, 0);
	COLORREF White = RGB(255, 255, 255);
	COLORREF Black = RGB(0, 0, 0);
	bool empty[] = {	0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0};
	empty_.initializeSample(empty, Blue, Black);
	bool wallVertical[] = {	0, 0, 0, 1, 1, 0, 0, 0,
							0, 0, 0, 1, 1, 0, 0, 0,
							0, 0, 0, 1, 1, 0, 0, 0,
							0, 0, 0, 1, 1, 0, 0, 0,
							0, 0, 0, 1, 1, 0, 0, 0,
							0, 0, 0, 1, 1, 0, 0, 0,
							0, 0, 0, 1, 1, 0, 0, 0,
							0, 0, 0, 1, 1, 0, 0, 0 };
	wallVertical_.initializeSample(wallVertical, Blue, Black);
	bool wallHorizontal[] = {	0, 0, 0, 0, 0, 0, 0, 0,
								0, 0, 0, 0, 0, 0, 0, 0,
								0, 0, 0, 0, 0, 0, 0, 0,
								1, 1, 1, 1, 1, 1, 1, 1,
								1, 1, 1, 1, 1, 1, 1, 1,
								0, 0, 0, 0, 0, 0, 0, 0,
								0, 0, 0, 0, 0, 0, 0, 0,
								0, 0, 0, 0, 0, 0, 0, 0 };
	wallHorizontal_.initializeSample(wallHorizontal, Blue, Black);
	bool wallLeftBottom[] = {	0, 0, 0, 0, 0, 0, 0, 0,
								0, 0, 0, 0, 0, 0, 0, 0,
								0, 0, 0, 0, 0, 0, 0, 0,
								1, 1, 1, 1, 0, 0, 0, 0,
								1, 1, 1, 1, 1, 0, 0, 0,
								0, 0, 1, 1, 1, 0, 0, 0,
								0, 0, 0, 1, 1, 0, 0, 0,
								0, 0, 0, 1, 1, 0, 0, 0 };
	wallLeftBottom_.initializeSample(wallLeftBottom, Blue, Black);
	bool wallRightBottom[] = {	0, 0, 0, 0, 0, 0, 0, 0,
								0, 0, 0, 0, 0, 0, 0, 0,
								0, 0, 0, 0, 0, 0, 0, 0,
								0, 0, 0, 0, 1, 1, 1, 1,
								0, 0, 0, 1, 1, 1, 1, 1,
								0, 0, 0, 1, 1, 1, 0, 0,
								0, 0, 0, 1, 1, 0, 0, 0,
								0, 0, 0, 1, 1, 0, 0, 0 };
	wallRightBottom_.initializeSample(wallRightBottom, Blue, Black);
	bool wallLeftTop[] = {		0, 0, 0, 1, 1, 0, 0, 0,
								0, 0, 0, 1, 1, 0, 0, 0,
								0, 0, 1, 1, 1, 0, 0, 0,
								1, 1, 1, 1, 1, 0, 0, 0,
								1, 1, 1, 1, 0, 0, 0, 0,
								0, 0, 0, 0, 0, 0, 0, 0,
								0, 0, 0, 0, 0, 0, 0, 0,
								0, 0, 0, 0, 0, 0, 0, 0 };
	wallLeftTop_.initializeSample(wallLeftTop, Blue, Black);
	bool wallRightTop[] = {		0, 0, 0, 1, 1, 0, 0, 0,
								0, 0, 0, 1, 1, 0, 0, 0,
								0, 0, 0, 1, 1, 1, 0, 0,
								0, 0, 0, 1, 1, 1, 1, 1,
								0, 0, 0, 0, 1, 1, 1, 1,
								0, 0, 0, 0, 0, 0, 0, 0,
								0, 0, 0, 0, 0, 0, 0, 0,
								0, 0, 0, 0, 0, 0, 0, 0 };
	wallRightTop_.initializeSample(wallRightTop, Blue, Black);
	door_.initializeSample(wallHorizontal, Red, Black);
	bool pacMan[] = {	0, 0, 0, 1, 1, 0, 0, 0,
						0, 1, 1, 1, 1, 1, 1, 0,
						0, 1, 0, 1, 1, 0, 1, 0,
						1, 1, 0, 1, 1, 0, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1,
						0, 1, 0, 1, 1, 0, 1, 0,
						0, 1, 1, 0, 0, 1, 1, 0,
						0, 0, 0, 1, 1, 0, 0, 0 };
	pacMan_.initializeSample(pacMan, Yellow, Black);
	normalCast();
	bool schorePoint[] = {	0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 1, 1, 0, 0, 0,
							0, 0, 0, 1, 1, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0 };
	schorePoint_.initializeSample(schorePoint, White, Black);
	bool energiser[] = {	0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 1, 1, 0, 0, 0,
							0, 0, 1, 1, 1, 1, 0, 0,
							0, 1, 1, 1, 1, 1, 1, 0,
							0, 1, 1, 1, 1, 1, 1, 0,
							0, 0, 1, 1, 1, 1, 0, 0,
							0, 0, 0, 1, 1, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0 };
	energiser_.initializeSample(energiser, White, Black);
}
void Field::normalCast()
{
	normalBlinky();
	normalPinky();
	normalInky();
	normalClyde();
	mode_ = CastMode::ATTACK;
}
void Field::normalBlinky()
{
	COLORREF Black = RGB(0, 0, 0);
	COLORREF Red = RGB(255, 0, 0);
	bool cast[] = {		0, 0, 0, 1, 1, 0, 0, 0,
						0, 0, 1, 1, 1, 1, 0, 0,
						0, 1, 1, 1, 1, 1, 1, 0,
						0, 1, 1, 1, 1, 1, 1, 0,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 0, 1, 1, 0, 1, 0, 1 };
	blinky_.initializeSample(cast, Red, Black);
	blinky_.setMode(CastMode::ATTACK);
}
void Field::normalPinky()
{
	COLORREF Black = RGB(0, 0, 0);
	COLORREF Pink = RGB(255, 190, 200);
	bool cast[] = {		0, 0, 0, 1, 1, 0, 0, 0,
						0, 1, 1, 1, 1, 1, 1, 0,
						0, 1, 1, 1, 1, 1, 1, 0,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 0, 1, 1, 0, 1, 0, 1 };
	pinky_.initializeSample(cast, Pink, Black);
	pinky_.setMode(CastMode::ATTACK);
}
void Field::normalInky()
{
	COLORREF Black = RGB(0, 0, 0);
	COLORREF Cayan = RGB(0, 255, 255);
	bool cast[] = {		0, 0, 0, 1, 1, 0, 0, 0,
						0, 1, 1, 1, 1, 1, 1, 0,
						0, 1, 1, 1, 1, 1, 1, 0,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 0, 1, 1, 0, 1, 0, 1 };
	inky_.initializeSample(cast, Cayan, Black);
	inky_.setMode(CastMode::ATTACK);

}
void Field::normalClyde()
{
	COLORREF Black = RGB(0, 0, 0);
	COLORREF Orange = RGB(255, 100, 0);
	bool cast[] = {		0, 0, 0, 1, 1, 0, 0, 0,
						0, 1, 1, 1, 1, 1, 1, 0,
						0, 1, 1, 1, 1, 1, 1, 0,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 0, 1, 1, 0, 1, 0, 1 };
	clyde_.initializeSample(cast, Orange, Black);
	clyde_.setMode(CastMode::ATTACK);
}
void Field::fearCast()
{
	COLORREF Black = RGB(0, 0, 0);
	COLORREF Blue = RGB(0, 0, 255);

	changeCastMode(CastMode::FEAR);
	bool cast[] = {		0, 0, 0, 1, 1, 0, 0, 0,
						0, 1, 1, 1, 1, 1, 1, 0,
						0, 1, 1, 1, 1, 1, 1, 0,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1,
						1, 0, 1, 1, 0, 1, 0, 1 };
	blinky_.initializeSample(cast, Blue, Black);
	pinky_.initializeSample(cast, Blue, Black);
	inky_.initializeSample(cast, Blue, Black);
	clyde_.initializeSample(cast, Blue, Black);
}

void Field::setStart()
{
	std::string map[] = {
					"                            ",
					"                            ",
					"                            ",
					"F------------TF------------T",
					"|............||............|",
					"|.F--T.F---T.||.F---T.F--T.|",
					"|O|  |.|   |.||.|   |.|  |O|",
					"|.L--J.L---J.LJ.L---J.L--J.|",
					"|..........................|",
					"|.F--T.FT.F------T.FT.F--T.|",
					"|.L--J.||.L--TF--J.||.L--J.|",
					"|......||....||....||......|",
					"L----T.|L--T || F--J|.F----J",
					"     |.|F--J LJ L--T|.|     ",
					"     |.||          ||.|     ",
					"     |.|| F--==--T ||.|     ",
					"-----J.LJ |      | LJ.L-----",
					"      .   |      |   .      ",
					"-----T.FT |      | FT.F-----",
					"     |.|| L------J ||.|     ",
					"     |.||          ||.|     ",
					"     |.|| F------T ||.|     ",
					"F----J.LJ L--TF--J LJ.L----T",
					"|............||............|",
					"|.F--T.F---T.||.F---T.F--T.|",
					"|.L-T|.L---J.LJ.L---J.|F-J.|",
					"|O..||.......  .......||..O|",
					"L-T.||.FT.F------T.FT.||.F-J",
					"F-J.LJ.||.L--TF--J.||.LJ.L-T",
					"|......||....||....||......|",
					"|.F----JL--T.||.F--JL----T.|",
					"|.L--------J.LJ.L--------J.|",
					"|..........................|",
					"L--------------------------J",
					"                            ",
					"                            "};
	const int height = getVertical();
	const int width = getHorizontal();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			switch (map[i][j])
			{
			case 'F':
			{
				level_[i][j] = &wallRightBottom_;
				break;
			}
			case 'T':
			{
				level_[i][j] = &wallLeftBottom_;
				break;
			}
			case 'L':
			{
				level_[i][j] = &wallRightTop_;
				break;
			}
			case 'J':
			{
				level_[i][j] = &wallLeftTop_;
				break;
			}
			case '-':
			{
				level_[i][j] = &wallHorizontal_;
				break;
			}
			case '=':
			{
				level_[i][j] = &door_;
				break;
			}
			case '|':
			{
				level_[i][j] = &wallVertical_;
				break;
			}
			case ' ':
			{
				level_[i][j] = &empty_;
				break;
			}
			case '.':
			{
				level_[i][j] = &schorePoint_;
				break;
			}
			case 'O':
			{
				level_[i][j] = &energiser_;
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
	blinky_.print(hdc_);
	pinky_.print(hdc_);
	inky_.print(hdc_);
	clyde_.print(hdc_);
}
void Field::resetDinamic()
{
	eraseDinamic(pacMan_.getPosition());
	eraseDinamic(blinky_.getPosition());
	eraseDinamic(pinky_.getPosition());
	eraseDinamic(inky_.getPosition());
	eraseDinamic(clyde_.getPosition());

	pacMan_.setStartPosition();
	blinky_.setStartPosition();
	pinky_.setStartPosition();
	inky_.setStartPosition();
	clyde_.setStartPosition();

	pacMan_.print(hdc_);
	blinky_.print(hdc_);
	pinky_.print(hdc_);
	inky_.print(hdc_);
	clyde_.print(hdc_);
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
	eraseDinamic(blinky_.getPosition());
	blinky_.setReadyPosition();
	blinkyReady_ = true;
}
void Field::setPinky()
{
	eraseDinamic(pinky_.getPosition());
	pinky_.setReadyPosition();
	pinkyReady_ = true;
}
void Field::setInky()
{
	eraseDinamic(inky_.getPosition());
	inky_.setReadyPosition();
	inkyReady_ = true;
}
void Field::setClyde()
{
	eraseDinamic(clyde_.getPosition());
	clyde_.setReadyPosition();
	clydeReady_ = true;
}
void Field::setEasySpeed()
{
	pacMan_.setSpeed(getMiddleSpeed());
	blinky_.setSpeed(getLowSpeed());
	pinky_.setSpeed(getLowSpeed());
	inky_.setSpeed(getLowSpeed());
	clyde_.setSpeed(getLowSpeed());
}
void Field::setMediumSpeed()
{
	pacMan_.setSpeed(getHighSpeed());
	blinky_.setSpeed(getMiddleSpeed());
	pinky_.setSpeed(getMiddleSpeed());
	inky_.setSpeed(getMiddleSpeed());
	clyde_.setSpeed(getMiddleSpeed());
}
void Field::setHardSpeed()
{
	pacMan_.setSpeed(getMiddleSpeed());
	blinky_.setSpeed(getHighSpeed());
	pinky_.setSpeed(getHighSpeed());
	inky_.setSpeed(getHighSpeed());
	clyde_.setSpeed(getHighSpeed());
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
		rezult = (position.x % size == 0 && (type == SpriteType::EMPTY || type == SpriteType::SHOREPOINT || type == SpriteType::ENERGISER));
		break;
	}
	case RIGHT:
	{
		x += 1;
		x %= getHorizontal();
		SpriteType type = level_[y][x]->getType();
		rezult = (position.y % size == 0 && (type == SpriteType::EMPTY || type == SpriteType::SHOREPOINT || type == SpriteType::ENERGISER));
		break;
	}
	case DOWN:
	{
		y += 1;
		y %= getVertical();
		SpriteType type = level_[y][x]->getType();
		rezult = (position.x % size == 0 && (type == SpriteType::EMPTY || type == SpriteType::SHOREPOINT || type == SpriteType::ENERGISER));
		break;
	}
	case LEFT:
	{
		x += ((position.x % size != 0) ? 0 : -1) + getHorizontal();
		x %= getHorizontal();
		SpriteType type = level_[y][x]->getType();
		rezult = (position.y % size == 0 && (type == SpriteType::EMPTY || type == SpriteType::SHOREPOINT || type == SpriteType::ENERGISER));
		break;
	}
	default:
		break;
	}
	return rezult;
}
void Field::moveDinamic(DinamicSprite& sprite, const POINT position, const Direction direction)
{
	if (isEmpty(position, direction))
	{
		sprite.move();
		sprite.print(hdc_);
	}
}
void Field::moveAllDinamic()
{
	bool IsUpdatePacMan = isEmpty(pacMan_.getPosition(), pacMan_.getDirection());
	bool IsUpdateBlinky = isEmpty(blinky_.getPosition(), blinky_.getDirection());
	bool IsUpdatePinky = isEmpty(pinky_.getPosition(), pinky_.getDirection());
	bool IsUpdateInky = isEmpty(inky_.getPosition(), inky_.getDirection());
	bool IsUpdateClyde = isEmpty(clyde_.getPosition(), clyde_.getDirection());
	
	if (IsUpdatePacMan) eraseDinamic(pacMan_.getPosition());
	if (IsUpdateBlinky) eraseDinamic(blinky_.getPosition());
	if (IsUpdatePinky) eraseDinamic(pinky_.getPosition());
	if (IsUpdateInky) eraseDinamic(inky_.getPosition());
	if (IsUpdateClyde) eraseDinamic(clyde_.getPosition());
	if (IsUpdatePacMan) moveDinamic(pacMan_, pacMan_.getPosition(), pacMan_.getDirection());
	if (IsUpdateBlinky) moveDinamic(blinky_, blinky_.getPosition(), blinky_.getDirection());
	if (IsUpdatePinky) moveDinamic(pinky_, pinky_.getPosition(), pinky_.getDirection());
	if (IsUpdateInky) moveDinamic(inky_, inky_.getPosition(), inky_.getDirection());
	if (IsUpdateClyde) moveDinamic(clyde_, clyde_.getPosition(), clyde_.getDirection());
}
void Field::turnDinamic(DinamicSprite& sprite, const Direction direction)
{
	if (isEmpty(sprite.getPosition(), direction)) sprite.setDirection(direction);
}
void Field::turnPacMan(Direction const direction)
{
	turnDinamic(pacMan_, direction);
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
		POINT position = blinky_.getPosition();
		if (position.x % size == 0 && position.y % size == 0)
		{
			const int countDirections = getCountDirections();
			const Direction direction = blinky_.getDirection();
			const Direction left = (Direction)(((int)direction - 1 + countDirections) % countDirections);
			const Direction right = (Direction)(((int)direction + 1) % countDirections);
			if (!isEmpty(position, direction) || isEmpty(position, left) || isEmpty(position, right))
			{
				bool ways[4];
				for (int i = 0; i < 4; i++) ways[i] = isEmpty(position, (Direction)i);
				if (blinky_.getMode() == 0) blinky_.setDirectionPoint(pacMan_.getPosition());
				if (checkSpecial(position.x / size, position.y / size)) ways[0] = false;
				blinky_.choiseDirection(ways);
			}
		}
	}
	if (pinkyReady_)
	{
		POINT position = pinky_.getPosition();
		if (position.x % size == 0 && position.y % size == 0)
		{
			const int countDirections = getCountDirections();
			const Direction direction = pinky_.getDirection();
			const Direction left = (Direction)(((int)direction - 1 + countDirections) % countDirections);
			const Direction right = (Direction)(((int)direction + 1) % countDirections);
			if (!isEmpty(position, direction) || isEmpty(position, left) || isEmpty(position, right))
			{
				bool ways[4];
				for (int i = 0; i < 4; i++) ways[i] = isEmpty(position, (Direction)i);
				if (pinky_.getMode() == 0) pinky_.setDirectionPoint(pacMan_.getPosition(), pacMan_.getDirection());
				if (checkSpecial(position.x / size, position.y / size)) ways[0] = false;
				pinky_.choiseDirection(ways);
			}
		}
	}
	if (inkyReady_)
	{
		POINT position = inky_.getPosition();
		if (position.x % size == 0 && position.y % size == 0)
		{
			const int countDirections = getCountDirections();
			const Direction direction = inky_.getDirection();
			const Direction left = (Direction)(((int)direction - 1 + countDirections) % countDirections);
			const Direction right = (Direction)(((int)direction + 1) % countDirections);
			if (!isEmpty(position, direction) || isEmpty(position, left) || isEmpty(position, right))
			{
				bool ways[4];
				for (int i = 0; i < 4; i++) ways[i] = isEmpty(position, (Direction)i);
				if (inky_.getMode() == 0) inky_.setDirectionPoint(pacMan_.getPosition(), pacMan_.getDirection(), blinky_.getPosition());
				if (checkSpecial(position.x / size, position.y / size)) ways[0] = false;
				inky_.choiseDirection(ways);
			}
		}
	}
	if (clydeReady_)
	{
		POINT position = clyde_.getPosition();
		if (position.x % size == 0 && position.y % size == 0)
		{
			const int countDirections = getCountDirections();
			const Direction direction = clyde_.getDirection();
			const Direction left = (Direction)(((int)direction - 1 + countDirections) % countDirections);
			const Direction right = (Direction)(((int)direction + 1) % countDirections);
			if (!isEmpty(position, direction) || isEmpty(position, left) || isEmpty(position, right))
			{
				bool ways[4];
				for (int i = 0; i < 4; i++) ways[i] = isEmpty(position, (Direction)i);
				if (clyde_.getMode() == 0) clyde_.setDirectionPoint(pacMan_.getPosition());
				if (checkSpecial(position.x / size, position.y / size)) ways[0] = false;
				clyde_.choiseDirection(ways);
			}
		}
	}
}
void Field::changeCastMode(CastMode Mode)
{
	mode_ = Mode;
	blinky_.setMode(Mode);
	pinky_.setMode(Mode);
	inky_.setMode(Mode);
	clyde_.setMode(Mode);
}
const CastMode Field::getCastMode()
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
	mode_ = CastMode::ATTACK;
}
const SpriteType Field::getSpriteTypeAt(const int x, const int y)
{
	return level_[y][x]->getType();
}
void Field::setEmptyAt(const int x, const int y)
{
	level_[y][x] = &empty_;
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