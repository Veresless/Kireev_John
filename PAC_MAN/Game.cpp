#include <iostream>
#include <string>
#include <future>

#include "Game.h"
#include "Constants.h"

void Game::setStartParams()
{
	schore_ = 0;
	lifes_ = getStartLifes();
	level_ = 1;
	deltaTime_ = getDefaultDeltaTime();
}
Game::Game()
{
	setStartParams();
}
void Game::loadLevel()
{
	field_.printAll();
}
const bool Game::levelUp()
{
	if (countEatenPoints_ == getMaxCountPoints())
	{
		level_++;
		countEatenPoints_ = 0;
		return true;
	}
	return false;
}
void Game::updateStatistic() const
{
	std::cout <<  level_ << '\t' << lifes_ << '\t' << schore_ << '\r';
}
void Game::pacManMovement()
{
	if ((GetKeyState(getWKey()) & getBinaryToBool()) || (GetKeyState(getUpKey()) & getBinaryToBool())) // W w and UP
	{
		field_.turnPacMan(UP);
	}
	else if ((GetKeyState(getDKey()) & getBinaryToBool()) || (GetKeyState(getRightKey()) & getBinaryToBool())) // D d and RIGHT
	{
		field_.turnPacMan(RIGHT);
	}
	else if ((GetKeyState(getSKey()) & getBinaryToBool()) || (GetKeyState(getDownKey()) & getBinaryToBool())) // S s and DOWN
	{
		field_.turnPacMan(DOWN);
	}
	else if ((GetKeyState(getAKey()) & getBinaryToBool()) || (GetKeyState(getLeftKey()) & getBinaryToBool())) // A a and LEFT
	{
		field_.turnPacMan(LEFT);
	}
}
void Game::castMovement()
{
	field_.castMovement();
}
void Game::pacManEat()
{
	POINT position = field_.getPacMan()->getPosition();
	int size = getSize();
	if (position.x % size == 0 && position.y % size == 0)
	{
		if (field_.getSpriteTypeAt(position.x / size, position.y / size) == SpriteType::SCHORE_POINT)
		{
			schore_ += getPointSchore();
			countEatenPoints_++;
			field_.setEmptyAt(position.x / size, position.y / size);
		}
		if (field_.getSpriteTypeAt(position.x / size, position.y / size) == SpriteType::ENERGISER)
		{
			schore_ += getEnergiserSchore();
			countEatenPoints_++;
			if (level_ < getLevelWhereCastNotFear())
			{
				energiserTime_ = GetTickCount64();
				energiserTimeOn_ = false;
				field_.fearGost();
				castDieCount_ = 1;
			}
			field_.setEmptyAt(position.x / size, position.y / size);
		}
	}
}
void Game::pacManDie()
{
	live_ = false;
	Sleep(getOneSecond());
	field_.normalCast();
	field_.resetDinamic();
}
const bool Game::checkPosition(const std::shared_ptr<PacMan> const pacMan, const std::shared_ptr<Gost> const gost) const
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
void Game::modeTimer()
{
	int fearTime =getFearTime() - level_ * getFearDifferenseTime();
	int firstWaveRetreat = ((level_ < getSecondChangeLevel()) ? getRetreatMaxTime() : getRetreatMinTime()) + getStartLate();
	int firstWaveAttack = getAttackTime() + firstWaveRetreat;
	int secondWaveRetreat = ((level_ < getSecondChangeLevel()) ? getRetreatMaxTime() : getRetreatMinTime()) + firstWaveAttack;
	int secondWaveAttack = getAttackTime() + secondWaveRetreat;
	int thirdWaveRetreat = getRetreatMinTime() + secondWaveAttack;
	int thirdWaveAttack = ((level_ < getFirstChangeLevel())? getAttackTime() :
		(level_ < getSecondChangeLevel())? getLongAttackTime() : getLargeAttackTime()) + thirdWaveRetreat;
	int fourthWaveRetreat = ((level_ < getSecondChangeLevel()) ? getRetreatMinTime() : getSmalestRetreatTime()) + thirdWaveAttack;
	energiserTimeOn_ = true;
	ULONGLONG deltaTime = 0;
	ULONGLONG startTime = GetTickCount64();
	while (live_)
	{
		ULONGLONG start = GetTickCount64();
		GostMode mode = field_.getCastMode();
		if (!field_.blinkyReady) field_.setBlinky();
		if (!field_.pinkyReady && GetTickCount64() - startTime >= getPinkyStartTime()) field_.setPinky();
		if (!field_.inkyReady && countEatenPoints_ >= getInkyPointCountCondition() &&
			GetTickCount64() - startTime >= getInkyStartTime()) field_.setInky();
		if (!field_.clydeReady && countEatenPoints_ >= getClydePointCountCondition() &&
			GetTickCount64() - startTime >= getClydeStartTime()) field_.setClyde();
		if (mode == GostMode::FEAR)
		{
			if (!energiserTimeOn_)
			{
				energiserTimeOn_ = true;
				startTime += fearTime;
			}
			if (GetTickCount64() - energiserTime_ >= fearTime)
			{
				field_.normalCast();
			}
		}
		else
		{
			GostMode NewCastMode = GostMode::RETREAT;
			if (GetTickCount64() - startTime >= fourthWaveRetreat) NewCastMode = GostMode::ATTACK;
			else if (GetTickCount64() - startTime >= thirdWaveAttack) NewCastMode = GostMode::RETREAT;
			else if (GetTickCount64() - startTime >= thirdWaveRetreat) NewCastMode = GostMode::ATTACK;
			else if (GetTickCount64() - startTime >= secondWaveAttack) NewCastMode = GostMode::RETREAT;
			else if (GetTickCount64() - startTime >= secondWaveRetreat) NewCastMode = GostMode::ATTACK;
			else if (GetTickCount64() - startTime >= firstWaveAttack) NewCastMode = GostMode::RETREAT;
			else if (GetTickCount64() - startTime >= firstWaveRetreat) NewCastMode = GostMode::ATTACK;
			if (NewCastMode != mode) field_.changeCastMode(NewCastMode);
		}
		deltaTime = GetTickCount64() - start;
	}
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
				schore_ += getCastDieSchore() * castDieCount_ << 1;
				field_.normalBlinky();
				field_.setBlinky();
		}
		else pacManDie();
	}
	if (checkPosition(pacMan, pinky))
	{
		if (pinky->getMode() == GostMode::FEAR)
		{
			schore_ += getCastDieSchore() * castDieCount_ << 1;
			field_.normalPinky();
			field_.setPinky();
		}
		else pacManDie();
	}
	if (checkPosition(pacMan, inky))
	{
		if (inky->getMode() == GostMode::FEAR)
		{
			schore_ += getCastDieSchore() * castDieCount_ << 1;
			field_.normalInky();
			field_.setInky();
		}
		else pacManDie();
	}
	if (checkPosition(pacMan, clyde))
	{
		if (clyde->getMode() == GostMode::FEAR)
		{
			schore_ += getCastDieSchore() * castDieCount_ << 1;
			field_.normalClyde();
			field_.setClyde();
		}
		else pacManDie();
	}
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
		std::cout << spase << '\n';
	}
	goToXY(0, 0);
}
const bool Game::exit() const
{
	return ((GetKeyState(getEscKey()) & getBinaryToBool()) == 0);
}
void Game::run()
{
	bool run = true;
	loadLevel();
	while (run)
	{
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
		live_ = true;
		clearConsole(getHorizontal(), getCountStatisticStrings());
		std::cout << "Press 'Enter' to continue...";
		while ((GetKeyState(getEnterKey()) & getBinaryToBool()) == 0);
		clearConsole(getHorizontal(), 1);
		auto future = std::async(std::launch::async, [&] {modeTimer(); });
		std::cout << "3";
		Sleep(getOneSecond());
		std::cout << ", 2";
		Sleep(getOneSecond());
		std::cout << ", 1...\r";
		Sleep(getOneSecond());
		std::cout << "Level:\tLifes:\tSchore:\n";
		while (live_ && run)
		{
			live_ = run = exit();
			ULONGLONG StartTime = GetTickCount64();
			pacManEat();
			updateStatistic();
			if (levelUp()) break;
			pacManMovement();
			castMovement();
			field_.moveAllDinamic();
			die();
			ULONGLONG StopTime = GetTickCount64();
			ULONGLONG Time = deltaTime_ - (StopTime - StartTime) % deltaTime_;
			Sleep(Time);
		}
		if (!live_) 
		{
			if (lifes_-- <= 0)
			{
				run = false;
				system("cls");
				std::cout << "Game Over!\nYour Schore:" << schore_ << "\nPress 'Esc' to exit";
				while ((GetKeyState(getEscKey()) & getBinaryToBool()) == 0);
			}
			else
			{
				field_.blinkyReady = field_.pinkyReady = field_.inkyReady = field_.clydeReady = false;
			}
		}
		else
		{
			live_ = false;
			field_.normalCast();
			field_.resetLevel();
			field_.blinkyReady = field_.pinkyReady = field_.inkyReady = field_.clydeReady = false;
		}

	}
}
