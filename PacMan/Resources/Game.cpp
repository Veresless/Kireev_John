#include "Game.h"
#include <iostream>
#include <conio.h>
#include <future>

void Game::setStartParams()
{
	Schore_ = 0;
	Lifes_ = 2;
	Level_ = 1;
	DeltaTime_ = 50;
}
Game::Game()
{
	setStartParams();
}
void Game::loadLevel()
{
	Field_.printAll();
	PacMan_ = Field_.getPacMan();
	Blinky_ = Field_.getBlinky();
	Pinky_ = Field_.getPinky();
	Inky_ = Field_.getInky();
	Clyde_ = Field_.getClyde();
}
bool Game::levelUp()
{
	if (CountEatenPoints_ == 244)
	{
		Level_++;
		CountEatenPoints_ = 0;
		return true;
	}
	return false;
}
void Game::start()
{
	loadLevel();
}
void Game::updateStat()
{
	system("cls");
	std::cout << "Level:" << Level_ << '\t' << "Lifes:" << Lifes_ << "\nScore:" << Schore_ << "\tB:" << Blinky_->getMode() << "\tP:" << Pinky_->getMode() << "\tI:" << Inky_->getMode() << "\tC:" << Clyde_->getMode();
}
void Game::pacManMovement()
{
	if ((GetKeyState(87) & 0x8000) || (GetKeyState(38) & 0x8000)) // W w and UP
	{
		Field_.turnDinamic(PacMan_, 0);
	}
	else if ((GetKeyState(68) & 0x8000) || (GetKeyState(39) & 0x8000)) // D d and RIGHT
	{
		Field_.turnDinamic(PacMan_, 3);
	}
	else if ((GetKeyState(83) & 0x8000) || (GetKeyState(40) & 0x8000)) // S s and DOWN
	{
		Field_.turnDinamic(PacMan_, 2);
	}
	else if ((GetKeyState(65) & 0x8000) || (GetKeyState(37) & 0x8000)) // A a and LEFT
	{
		Field_.turnDinamic(PacMan_, 1);
	}
}
void Game::castMovement()
{
	Field_.castMovement();
}
void Game::pacManEat()
{
	std::pair<int, int> Position = PacMan_->getPoint();
	int Size = PacMan_->getSize();
	if (Position.first % Size == 0 && Position.second % Size == 0)
	{
		if (Field_.getSpriteTypeAt(Position.first / Size, Position.second / Size) == SpriteType::TSchorePoint)
		{
			Schore_ += 10;
			CountEatenPoints_++;
			Field_.setEmptyAt(Position.first / Size, Position.second / Size);
		}
		if (Field_.getSpriteTypeAt(Position.first / Size, Position.second / Size) == SpriteType::TEnergiser)
		{
			Schore_ += 50;
			CountEatenPoints_++;
			if (Level_ < 19)
			{
				EnergiserTime_ = GetTickCount64();
				EnergiserTimeOn_ = false;
				Field_.fearCast();
				CastDieCount_ = 1;
			}
			Field_.setEmptyAt(Position.first / Size, Position.second / Size);
		}
	}
}
void Game::pacManDie()
{
	Live_ = false;
	Sleep(1000);
	Field_.normalCast();
	Field_.resetDinamic();
}
bool Game::checkPosition(PacMan* PacMan, Cast* Cast)
{
	std::pair<int, int> FirstPoint = PacMan->getPoint();;
	int FirstDirection = PacMan->getDirection();
	int FirstSpeed = PacMan->getSpeed();
	std::pair<int, int> SecondPoint = Cast->DinamicSprite::getPoint();
	int SecondDirection = Cast->getDirection();
	int SecondSpeed = Cast->getSpeed();
	switch (FirstDirection)
	{
	case 0:
	{
		std::pair<int, int> NewFirstPoint = { FirstPoint.first, FirstPoint.second + FirstSpeed };
		switch (SecondDirection)
		{
		case 0:
		{
			return FirstPoint == SecondPoint;
		}
		case 1:
		{
			std::pair<int, int> NewSecondPoint = { SecondPoint.first + SecondSpeed, SecondPoint.second };
			return NewFirstPoint == SecondPoint || FirstPoint == NewSecondPoint || NewFirstPoint == NewSecondPoint || FirstPoint == SecondPoint;
		}
		case 2:
		{
			std::pair<int, int> NewSecondPoint = { SecondPoint.first, SecondPoint.second - SecondSpeed };
			return NewFirstPoint == SecondPoint || FirstPoint == NewSecondPoint || NewFirstPoint == NewSecondPoint || FirstPoint == SecondPoint;
		}
		case 3:
		{
			std::pair<int, int> NewSecondPoint = { SecondPoint.first - SecondSpeed, SecondPoint.second };
			return NewFirstPoint == SecondPoint || FirstPoint == NewSecondPoint || NewFirstPoint == NewSecondPoint || FirstPoint == SecondPoint;
		}
		default:
			return false;
		}
	}
	case 1:
	{
		std::pair<int, int> NewFirstPoint = { FirstPoint.first + FirstSpeed, FirstPoint.second };
		switch (SecondDirection)
		{
		case 0:
		{
			std::pair<int, int> NewSecondPoint = { SecondPoint.first, SecondPoint.second + SecondSpeed };
			return NewFirstPoint == SecondPoint || FirstPoint == NewSecondPoint || NewFirstPoint == NewSecondPoint || FirstPoint == SecondPoint;
		}
		case 1:
		{
			return FirstPoint == SecondPoint;
		}
		case 2:
		{
			std::pair<int, int> NewSecondPoint = { SecondPoint.first, SecondPoint.second - SecondSpeed };
			return NewFirstPoint == SecondPoint || FirstPoint == NewSecondPoint || NewFirstPoint == NewSecondPoint || FirstPoint == SecondPoint;
		}
		case 3:
		{
			std::pair<int, int> NewSecondPoint = { SecondPoint.first - SecondSpeed, SecondPoint.second };
			return NewFirstPoint == SecondPoint || FirstPoint == NewSecondPoint || NewFirstPoint == NewSecondPoint || FirstPoint == SecondPoint;
		}
		default:
			return false;
		}
	}
	case 2:
	{
		std::pair<int, int> NewFirstPoint = { FirstPoint.first, FirstPoint.second - FirstSpeed };
		switch (SecondDirection)
		{
		case 0:
		{
			std::pair<int, int> NewSecondPoint = { SecondPoint.first, SecondPoint.second + SecondSpeed };
			return NewFirstPoint == SecondPoint || FirstPoint == NewSecondPoint || NewFirstPoint == NewSecondPoint || FirstPoint == SecondPoint;
		}
		case 1:
		{
			std::pair<int, int> NewSecondPoint = { SecondPoint.first + SecondSpeed, SecondPoint.second };
			return NewFirstPoint == SecondPoint || FirstPoint == NewSecondPoint || NewFirstPoint == NewSecondPoint || FirstPoint == SecondPoint;
		}
		case 2:
		{
			return FirstPoint == SecondPoint;
			
		}
		case 3:
		{
			std::pair<int, int> NewSecondPoint = { SecondPoint.first - SecondSpeed, SecondPoint.second };
			return NewFirstPoint == SecondPoint || FirstPoint == NewSecondPoint || NewFirstPoint == NewSecondPoint || FirstPoint == SecondPoint;
		}
		default:
			return false;
		}
	}
	case 3:
	{
		std::pair<int, int> NewFirstPoint = { FirstPoint.first - FirstSpeed, FirstPoint.second };
		switch (SecondDirection)
		{
		case 0:
		{
			std::pair<int, int> NewSecondPoint = { SecondPoint.first, SecondPoint.second + SecondSpeed };
			return NewFirstPoint == SecondPoint || FirstPoint == NewSecondPoint || NewFirstPoint == NewSecondPoint || FirstPoint == SecondPoint;
		}
		case 1:
		{
			std::pair<int, int> NewSecondPoint = { SecondPoint.first + SecondSpeed, SecondPoint.second };
			return NewFirstPoint == SecondPoint || FirstPoint == NewSecondPoint || NewFirstPoint == NewSecondPoint || FirstPoint == SecondPoint;
		}
		case 2:
		{
			std::pair<int, int> NewSecondPoint = { SecondPoint.first, SecondPoint.second - SecondSpeed };
			return NewFirstPoint == SecondPoint || FirstPoint == NewSecondPoint || NewFirstPoint == NewSecondPoint || FirstPoint == SecondPoint;
		}
		case 3:
		{
			return FirstPoint == SecondPoint;
		}
		default:
			return false;
		}
	}
	default:
		return false;
	}
}
void Game::Die()
{
	if (checkPosition(PacMan_, Blinky_))
	{
		if (Blinky_->getMode() == CastMode::Fear)
		{
			Schore_ += 200 * CastDieCount_++;
			Field_.normalBlinky();
			Field_.setBlinky();
		}
		else pacManDie();
	}
	if (checkPosition(PacMan_, Pinky_))
	{
		if (Pinky_->getMode() == CastMode::Fear)
		{
			Schore_ += 200 * CastDieCount_++;
			Field_.normalPinky();
			Field_.setPinky();
		}
		else pacManDie();
	}
	if (checkPosition(PacMan_, Inky_))
	{
		if (Inky_->getMode() == CastMode::Fear)
		{
			Schore_ += 200 * CastDieCount_++;
			Field_.normalInky();
			Field_.setInky();
		}
		else pacManDie();
	}
	if (checkPosition(PacMan_, Clyde_))
	{
		if (Clyde_->getMode() == CastMode::Fear)
		{
			Schore_ += 200 * CastDieCount_++;
			Field_.normalClyde();
			Field_.setClyde();
		}
		else pacManDie();
	}
}
void Game::modeTimer()
{
	int FearTime = 10000 - Level_ * 50;
	int FirstWaveRetreat = ((Level_ < 5) ? 7000 : 5000) + 5000;
	int FirstWaveAttack = 20000 + FirstWaveRetreat;
	int SecondWaveRetreat = ((Level_ < 5) ? 7000 : 5000) + FirstWaveAttack;
	int SecondWaveAttack = 20000 + SecondWaveRetreat;
	int ThirdWaveRetreat = 5000 + SecondWaveAttack;
	int ThirdWaveAttack = ((Level_ < 2)? 20000 : (Level_ < 5)? 1033000 : 1037000) + ThirdWaveRetreat;
	int FourthWaveRetreat = ((Level_ < 5) ? 5000 : 100/6) + ThirdWaveAttack;
	EnergiserTimeOn_ = true;
	ULONGLONG DeltaTime = 0;
	ULONGLONG StartTime = GetTickCount64();
	while (Live_)
	{
		ULONGLONG Start = GetTickCount64();
		CastMode Mode = Field_.getCastMode();
		if (!Field_.BlinkyReady_) Field_.setBlinky();
		if (!Field_.PinkyReady_ && GetTickCount64() - StartTime >= 5000) Field_.setPinky();
		if (!Field_.InkyReady_  && CountEatenPoints_ >= 30 && GetTickCount64() - StartTime >= 7000) Field_.setInky();
		if (!Field_.ClydeReady_ && CountEatenPoints_ >= 244/3 && GetTickCount64() - StartTime >= 9000) Field_.setClyde();
		if (Mode == CastMode::Fear)
		{
			if (!EnergiserTimeOn_)
			{
				EnergiserTimeOn_ = true;
				StartTime += FearTime;
			}
			if (GetTickCount64() - EnergiserTime_ >= FearTime)
			{
				Field_.normalCast();
			}
		}
		else
		{
			CastMode NewCastMode = CastMode::Retreat;
			if (GetTickCount64() - StartTime >= FourthWaveRetreat) NewCastMode = CastMode::Attack;
			else if (GetTickCount64() - StartTime >= ThirdWaveAttack) NewCastMode = CastMode::Retreat;
			else if (GetTickCount64() - StartTime >= ThirdWaveRetreat) NewCastMode = CastMode::Attack;
			else if (GetTickCount64() - StartTime >= SecondWaveAttack) NewCastMode = CastMode::Retreat;
			else if (GetTickCount64() - StartTime >= SecondWaveRetreat) NewCastMode = CastMode::Attack;
			else if (GetTickCount64() - StartTime >= FirstWaveAttack) NewCastMode = CastMode::Retreat;
			else if (GetTickCount64() - StartTime >= FirstWaveRetreat) NewCastMode = CastMode::Attack;
			if (NewCastMode != Mode) Field_.changeCastMode(NewCastMode);
		}
		DeltaTime = GetTickCount64() - Start;
	}
}
void Game::run()
{
	bool Run = true;
	while (Run)
	{
		if (Level_ < 5)
		{
			PacMan_->setMiddleSpeed();
			Blinky_->setLowSpeed();
			Pinky_->setLowSpeed();
			Inky_->setLowSpeed();
			Clyde_->setLowSpeed();
		}
		else if (Level_ < 21)
		{
			PacMan_->setHigthSpeed();
			Blinky_->setMiddleSpeed();
			Pinky_->setMiddleSpeed();
			Inky_->setMiddleSpeed();
			Clyde_->setMiddleSpeed();
		}
		else
		{
			PacMan_->setMiddleSpeed();
			Blinky_->setHigthSpeed();
			Pinky_->setHigthSpeed();
			Inky_->setHigthSpeed();
			Clyde_->setHigthSpeed();
		}
		Live_ = true;
		system("cls");
		std::cout << "Press any key to start!";
		_getch();
		auto future = std::async(std::launch::async, [&] {modeTimer(); });
		system("cls");
		std::cout << "3";
		Sleep(1000);
		std::cout << ", 2";
		Sleep(1000);
		std::cout << ", 1...";
		Sleep(1000);
		updateStat();
		while (Live_ && Run)
		{
			ULONGLONG StartTime = GetTickCount64();
			pacManEat();
			updateStat();
			if (levelUp()) break;
			pacManMovement();
			castMovement();
			Field_.moveAllDinamic();
			Die();
			ULONGLONG StopTime = GetTickCount64();
			ULONGLONG Time = DeltaTime_ - (StopTime - StartTime) % DeltaTime_;
			Sleep(Time);
		}
		if (!Live_) 
		{
			if (Lifes_-- <= 0) Run = false;
			else
			{
				Field_.BlinkyReady_ = Field_.PinkyReady_ = Field_.InkyReady_ = Field_.ClydeReady_ = false;
			}
		}
		else
		{
			Live_ = false;
			Field_.normalCast();
			Field_.resetLevel();
			Field_.BlinkyReady_ = Field_.PinkyReady_ = Field_.InkyReady_ = Field_.ClydeReady_ = false;
		}

	}
}
void Game::stop() 
{
	system("cls");
	std::cout << "Game Over!\nYour Schore:" << Schore_;
	Sleep(3000);
	_getch();
	Field_.clear();
}
