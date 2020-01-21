#include <iostream>
#include <string>

#include "../Headers/Game.h"

Game::Game(): lifes_(getStartLifes()), deltaTime_(getDefaultDeltaTime()), level_(getStartLevel()),
schore_(0), gostDieCount_(0), countEatenPoints_(0), energiserTime_(0), energiserTimeOn_(true), live_(true){}
int Game::run()
{
	bool run = true;
	loadLevel();
	while (run)
	{
		const int fearTime = getFearTime() - level_ * getFearDifferenseTime();
		const int firstWaveRetreat = ((level_ < getSecondChangeLevel()) ? getRetreatMaxTime() : getRetreatMinTime());
		const int firstWaveAttack = getAttackTime() + firstWaveRetreat;
		const int secondWaveRetreat = ((level_ < getSecondChangeLevel()) ? getRetreatMaxTime() : getRetreatMinTime()) + firstWaveAttack;
		const int secondWaveAttack = getAttackTime() + secondWaveRetreat;
		const int thirdWaveRetreat = getRetreatMinTime() + secondWaveAttack;
		const int thirdWaveAttack = ((level_ < getFirstChangeLevel()) ? getAttackTime() :
			(level_ < getSecondChangeLevel()) ? getLongAttackTime() : getLargeAttackTime()) + thirdWaveRetreat;
		const int fourthWaveRetreat = ((level_ < getSecondChangeLevel()) ? getRetreatMinTime() : getSmalestRetreatTime()) + thirdWaveAttack;
		WaveTime waveTime(fearTime, firstWaveRetreat, firstWaveAttack, secondWaveRetreat, secondWaveAttack, thirdWaveRetreat, thirdWaveAttack, fourthWaveRetreat);
		if (level_ < getSecondChangeLevel())
		{
			field_.setEasySpeed();
		}
		else if (level_ < getLastChangeLevel())
		{
			field_.setMediumSpeed();
		}
		else
		{
			field_.setHardSpeed();
		}
		clearConsole(getHorizontal(), getCountStatisticStrings());
		std::cout << "Press 'Enter' to play...";
		while (0 == (GetKeyState(getEnterKey()) & getBinaryToBool()));
		clearConsole(getHorizontal(), 1);
		std::cout << "3";
		Sleep(getOneSecond());
		std::cout << ", 2";
		Sleep(getOneSecond());
		std::cout << ", 1...\r";
		Sleep(getOneSecond());
		std::cout << "Level:\tLifes:\tSchore:\n";
		ULONGLONG startTime = GetTickCount64();
		while (live_ && run)
		{
			ULONGLONG start = GetTickCount64();
			live_ = run = exit();
			die();
			modeTimer(waveTime, startTime);
			pacManEat();
			updateStatistic();
			if (true == levelUp())
			{
				break;
			}
			pacManMovement();
			gostMovement();
			field_.moveAllDinamic();
			ULONGLONG stop = GetTickCount64();
			ULONGLONG time = (((stop - start) > deltaTime_)? 0 : deltaTime_ - (stop - start));
			Sleep(time);
		}
		if (!live_) 
		{
			if (0 >= lifes_--)
			{
				run = false;
			}
			else
			{
				live_ = true;
				field_.blinkyReady = field_.pinkyReady = field_.inkyReady = field_.clydeReady = false;
			}
		}
		else
		{
			field_.normalGost();
			field_.resetLevel();
			field_.blinkyReady = field_.pinkyReady = field_.inkyReady = field_.clydeReady = false;
		}
	}
	return schore_;
}
void Game::goToXY(const int x, const int y) const {
	HANDLE hConsole;
	COORD cursorLoc;
	std::cout.flush();
	cursorLoc.X = x;
	cursorLoc.Y = y;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, cursorLoc);
}
void Game::clearConsole(const int x, const int y) const
{
	goToXY(0, 0);
	std::string spase(x, ' ');
	for (int i = 0; i < y; i++)
	{
		std::cout << spase;
	}
	goToXY(0, 0);
}
bool Game::exit() const
{
	return ((GetKeyState(getEscKey()) & getBinaryToBool()) == 0);
}
bool Game::checkPosition(const std::shared_ptr<PacMan> const pacMan, const std::shared_ptr<Gost> const gost) const
{
	POINT firstPoint = pacMan->getPosition();
	Direction firstDirection = pacMan->getDirection();
	int firstSpeed = pacMan->getSpeed();
	POINT secondPoint = gost->getPosition();
	Direction secondDirection = gost->getDirection();
	int secondSpeed = gost->getSpeed();
	POINT newFirstPoint = { firstPoint.x, firstPoint.y };
	POINT newSecondPoint = { secondPoint.x, secondPoint.y };
	switch (firstDirection)
	{
	case UP:
	{
		newFirstPoint = { firstPoint.x, firstPoint.y + firstSpeed };
		break;
	}
	case LEFT:
	{
		newFirstPoint = { firstPoint.x + firstSpeed, firstPoint.y };
		break;
	}
	case DOWN:
	{
		newFirstPoint = { firstPoint.x, firstPoint.y - firstSpeed };
		break;
	}
	case RIGHT:
	{
		newFirstPoint = { firstPoint.x - firstSpeed, firstPoint.y };
		break;
	}
	default:
	{
		break;
	}
	}
	switch (secondDirection)
	{
	case UP:
	{
		newSecondPoint = { secondPoint.x, secondPoint.y + secondSpeed };
		break;
	}
	case LEFT:
	{
		newSecondPoint = { secondPoint.x + secondSpeed, secondPoint.y };
		break;
	}
	case DOWN:
	{
		newSecondPoint = { secondPoint.x, secondPoint.y - secondSpeed };
		break;
	}
	case RIGHT:
	{
		newSecondPoint = { secondPoint.x - secondSpeed, secondPoint.y };
		break;
	}
	default:
	{
		break;
	}
	}
	return	(newFirstPoint.x == secondPoint.x && newFirstPoint.y == secondPoint.y) ||
			(firstPoint.x == newSecondPoint.x && firstPoint.y == newSecondPoint.y) ||
			(newFirstPoint.x == newSecondPoint.x && newFirstPoint.y == newSecondPoint.y) ||
			(firstPoint.x == secondPoint.x && firstPoint.y == secondPoint.y);
}
void Game::updateStatistic() const
{
	std::cout <<  level_ << '\t' << lifes_ << '\t' << schore_ << '\r';
}
void Game::pacManMovement()
{
	if ((GetKeyState(getWKey()) & getBinaryToBool()) || (GetKeyState(getUpKey()) & getBinaryToBool()))
	{
		field_.turnPacMan(UP);
	}
	else if ((GetKeyState(getDKey()) & getBinaryToBool()) || (GetKeyState(getRightKey()) & getBinaryToBool()))
	{
		field_.turnPacMan(RIGHT);
	}
	else if ((GetKeyState(getSKey()) & getBinaryToBool()) || (GetKeyState(getDownKey()) & getBinaryToBool()))
	{
		field_.turnPacMan(DOWN);
	}
	else if ((GetKeyState(getAKey()) & getBinaryToBool()) || (GetKeyState(getLeftKey()) & getBinaryToBool()))
	{
		field_.turnPacMan(LEFT);
	}
}
void Game::gostMovement()
{
	field_.gostMovement();
}
void Game::pacManEat()
{
	POINT position = field_.getPacMan()->getPosition();
	int size = getSize();
	if (position.x % size == 0 && position.y % size == 0)
	{
		if (field_.getSpriteTypeAt(position.x / size, position.y / size) == StaticSpriteType::SCHORE_POINT)
		{
			schore_ += getPointSchore();
			countEatenPoints_++;
			field_.setEmptyAt(position.x / size, position.y / size);
		}
		if (field_.getSpriteTypeAt(position.x / size, position.y / size) == StaticSpriteType::ENERGISER)
		{
			schore_ += getEnergiserSchore();
			countEatenPoints_++;
			if (level_ < getLevelWhereCastNotFear())
			{
				energiserTime_ = GetTickCount64();
				energiserTimeOn_ = false;
				field_.fearGost();
				gostDieCount_ = 1;
			}
			field_.setEmptyAt(position.x / size, position.y / size);
		}
	}
}
void Game::pacManDie()
{
	live_ = false;
	Sleep(getOneSecond());
	field_.normalGost();
	field_.resetDinamic();
}
void Game::die()
{
	std::shared_ptr<PacMan> pacMan = field_.getPacMan();
	std::shared_ptr<Gost> blinky = field_.getGost(GostType::BLINKY);
	std::shared_ptr<Gost> pinky = field_.getGost(GostType::PINKY);
	std::shared_ptr<Gost> inky = field_.getGost(GostType::INKY);
	std::shared_ptr<Gost> clyde = field_.getGost(GostType::CLYDE);

	if (checkPosition(pacMan, blinky))
	{
		if (blinky->getMode() == GostMode::FEAR)
		{
				schore_ += getCastDieSchore() * gostDieCount_ << 1;
				field_.normalBlinky();
				field_.setBlinkyReady();
		}
		else pacManDie();
	}
	if (checkPosition(pacMan, pinky))
	{
		if (pinky->getMode() == GostMode::FEAR)
		{
			schore_ += getCastDieSchore() * gostDieCount_ << 1;
			field_.normalPinky();
			field_.setPinkyReady();
		}
		else pacManDie();
	}
	if (checkPosition(pacMan, inky))
	{
		if (inky->getMode() == GostMode::FEAR)
		{
			schore_ += getCastDieSchore() * gostDieCount_ << 1;
			field_.normalInky();
			field_.setInkyReady();
		}
		else pacManDie();
	}
	if (checkPosition(pacMan, clyde))
	{
		if (clyde->getMode() == GostMode::FEAR)
		{
			schore_ += getCastDieSchore() * gostDieCount_ << 1;
			field_.normalClyde();
			field_.setClydeReady();
		}
		else pacManDie();
	}
}
void Game::modeTimer(const WaveTime& waveTime, ULONGLONG& startTime )
{
		GostMode mode = field_.getGostMode();
		if (true != field_.blinkyReady)
		{
			field_.setBlinkyReady();
		}
		if (true != field_.pinkyReady && GetTickCount64() - startTime >= getPinkyStartTime())
		{
			field_.setPinkyReady();
		}
		if (true != field_.inkyReady && countEatenPoints_ >= getInkyPointCountCondition() &&
			GetTickCount64() - startTime >= getInkyStartTime())
		{
			field_.setInkyReady();
		}
		if (true != field_.clydeReady && countEatenPoints_ >= getClydePointCountCondition() &&
			GetTickCount64() - startTime >= getClydeStartTime())
		{
			field_.setClydeReady();
		}
		if (mode == GostMode::FEAR)
		{
			if (true != energiserTimeOn_)
			{
				energiserTimeOn_ = true;
				startTime += waveTime.fearTime;
			}
			if (GetTickCount64() - energiserTime_ >= waveTime.fearTime)
			{
				field_.normalGost();
			}
		}
		else
		{
			GostMode NewCastMode = GostMode::RETREAT;
			if (GetTickCount64() - startTime >= waveTime.fourthWaveRetreat)
			{
				NewCastMode = GostMode::ATTACK;
			}
			else if (GetTickCount64() - startTime >= waveTime.thirdWaveAttack)
			{
				NewCastMode = GostMode::RETREAT;
			}
			else if (GetTickCount64() - startTime >= waveTime.thirdWaveRetreat)
			{
				NewCastMode = GostMode::ATTACK;
			}
			else if (GetTickCount64() - startTime >= waveTime.secondWaveAttack)
			{
				NewCastMode = GostMode::RETREAT;
			}
			else if (GetTickCount64() - startTime >= waveTime.secondWaveRetreat)
			{
				NewCastMode = GostMode::ATTACK;
			}
			else if (GetTickCount64() - startTime >= waveTime.firstWaveAttack)
			{
				NewCastMode = GostMode::RETREAT;
			}
			else if (GetTickCount64() - startTime >= waveTime.firstWaveRetreat)
			{
				NewCastMode = GostMode::ATTACK;
			}
			if (NewCastMode != mode)
			{
				field_.setGostMode(NewCastMode);
			}
	}
}
void Game::loadLevel()
{
	field_.printAll();
}
bool Game::levelUp()
{
	bool rezult = false;
	if (countEatenPoints_ == getMaxCountPoints())
	{
		level_++;
		countEatenPoints_ = 0;
		rezult = true;
	}
	return rezult;
}

