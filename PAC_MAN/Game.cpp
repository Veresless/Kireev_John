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
				field_.fearCast();
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
const bool Game::checkPosition(const PacMan* pacMan, const Gost* cast) const
{
	POINT firstPoint = pacMan->getPosition();
	Direction firstDirection = pacMan->getDirection();
	int firstSpeed = pacMan->getSpeed();
	POINT secondPoint = cast->getPosition();
	Direction secondDirection = cast->getDirection();
	int secondSpeed = cast->getSpeed();
	POINT NewFirstPoint = { firstPoint.x, firstPoint.y };
	POINT NewSecondPoint = { secondPoint.x, secondPoint.y };
	switch (firstDirection)
	{
	case UP:
	{
		NewFirstPoint = { firstPoint.x, firstPoint.y + firstSpeed };
		break;
	}
	case LEFT:
	{
		NewFirstPoint = { firstPoint.x + firstSpeed, firstPoint.y };
		break;
	}
	case DOWN:
	{
		NewFirstPoint = { firstPoint.x, firstPoint.y - firstSpeed };
		break;
	}
	case RIGHT:
	{
		NewFirstPoint = { firstPoint.x - firstSpeed, firstPoint.y };
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
		NewSecondPoint = { secondPoint.x, secondPoint.y + secondSpeed };
		break;
	}
	case LEFT:
	{
		NewSecondPoint = { secondPoint.x + secondSpeed, secondPoint.y };
		break;
	}
	case DOWN:
	{
		NewSecondPoint = { secondPoint.x, secondPoint.y - secondSpeed };
		break;
	}
	case RIGHT:
	{
		NewSecondPoint = { secondPoint.x - secondSpeed, secondPoint.y };
		break;
	}
	default:
	{
		break;
	}
	}
	return	(NewFirstPoint.x == secondPoint.x && NewFirstPoint.y == secondPoint.y) ||
			(firstPoint.x == NewSecondPoint.x && firstPoint.y == NewSecondPoint.y) ||
			(NewFirstPoint.x == NewSecondPoint.x && NewFirstPoint.y == NewSecondPoint.y) ||
			(firstPoint.x == secondPoint.x && firstPoint.y == secondPoint.y);
}
void Game::modeTimer()
{
	int FearTime =getFearTime() - level_ * getFearDifferenseTime();
	int FirstWaveRetreat = ((level_ < getSecondChangeLevel()) ? getRetreatMaxTime() : getRetreatMinTime()) + getStartLate();
	int FirstWaveAttack = getAttackTime() + FirstWaveRetreat;
	int SecondWaveRetreat = ((level_ < getSecondChangeLevel()) ? getRetreatMaxTime() : getRetreatMinTime()) + FirstWaveAttack;
	int SecondWaveAttack = getAttackTime() + SecondWaveRetreat;
	int ThirdWaveRetreat = getRetreatMinTime() + SecondWaveAttack;
	int ThirdWaveAttack = ((level_ < getFirstChangeLevel())? getAttackTime() :
		(level_ < getSecondChangeLevel())? getLongAttackTime() : getLargeAttackTime()) + ThirdWaveRetreat;
	int FourthWaveRetreat = ((level_ < getSecondChangeLevel()) ? getRetreatMinTime() : getSmalestRetreatTime()) + ThirdWaveAttack;
	energiserTimeOn_ = true;
	ULONGLONG DeltaTime = 0;
	ULONGLONG StartTime = GetTickCount64();
	while (live_)
	{
		ULONGLONG Start = GetTickCount64();
		GostMode Mode = field_.getCastMode();
		if (!field_.blinkyReady_) field_.setBlinky();
		if (!field_.pinkyReady_ && GetTickCount64() - StartTime >= getPinkyStartTime()) field_.setPinky();
		if (!field_.inkyReady_  && countEatenPoints_ >= getInkyPointCountCondition() &&
			GetTickCount64() - StartTime >= getInkyStartTime()) field_.setInky();
		if (!field_.clydeReady_ && countEatenPoints_ >= getClydePointCountCondition() &&
			GetTickCount64() - StartTime >= getClydeStartTime()) field_.setClyde();
		if (Mode == GostMode::FEAR)
		{
			if (!energiserTimeOn_)
			{
				energiserTimeOn_ = true;
				StartTime += FearTime;
			}
			if (GetTickCount64() - energiserTime_ >= FearTime)
			{
				field_.normalCast();
			}
		}
		else
		{
			GostMode NewCastMode = GostMode::RETREAT;
			if (GetTickCount64() - StartTime >= FourthWaveRetreat) NewCastMode = GostMode::ATTACK;
			else if (GetTickCount64() - StartTime >= ThirdWaveAttack) NewCastMode = GostMode::RETREAT;
			else if (GetTickCount64() - StartTime >= ThirdWaveRetreat) NewCastMode = GostMode::ATTACK;
			else if (GetTickCount64() - StartTime >= SecondWaveAttack) NewCastMode = GostMode::RETREAT;
			else if (GetTickCount64() - StartTime >= SecondWaveRetreat) NewCastMode = GostMode::ATTACK;
			else if (GetTickCount64() - StartTime >= FirstWaveAttack) NewCastMode = GostMode::RETREAT;
			else if (GetTickCount64() - StartTime >= FirstWaveRetreat) NewCastMode = GostMode::ATTACK;
			if (NewCastMode != Mode) field_.changeCastMode(NewCastMode);
		}
		DeltaTime = GetTickCount64() - Start;
	}
}
void Game::die()
{
	if (checkPosition(field_.getPacMan(), field_.getBlinky()))
	{
		if (field_.getBlinky()->getMode() == GostMode::FEAR)
		{
				schore_ += getCastDieSchore() * castDieCount_ << 1;
				field_.normalBlinky();
				field_.setBlinky();
		}
		else pacManDie();
	}
	if (checkPosition(field_.getPacMan(), field_.getPinky()))
	{
		if (field_.getPinky()->getMode() == GostMode::FEAR)
		{
			schore_ += getCastDieSchore() * castDieCount_ << 1;
			field_.normalPinky();
			field_.setPinky();
		}
		else pacManDie();
	}
	if (checkPosition(field_.getPacMan(), field_.getInky()))
	{
		if (field_.getInky()->getMode() == GostMode::FEAR)
		{
			schore_ += getCastDieSchore() * castDieCount_ << 1;
			field_.normalInky();
			field_.setInky();
		}
		else pacManDie();
	}
	if (checkPosition(field_.getPacMan(), field_.getClyde()))
	{
		if (field_.getClyde()->getMode() == GostMode::FEAR)
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
				field_.blinkyReady_ = field_.pinkyReady_ = field_.inkyReady_ = field_.clydeReady_ = false;
			}
		}
		else
		{
			live_ = false;
			field_.normalCast();
			field_.resetLevel();
			field_.blinkyReady_ = field_.pinkyReady_ = field_.inkyReady_ = field_.clydeReady_ = false;
		}

	}
}
