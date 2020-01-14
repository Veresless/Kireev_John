#pragma once
#include "Field.h"

class Game {
private:
	int Schore_, Lifes_, Level_;
	ULONGLONG DeltaTime_;
	unsigned long long EnergiserTime_;
	bool EnergiserTimeOn_;
	short CastDieCount_;
	int CountEatenPoints_;
	bool Live_;
	Field Field_;
	PacMan* PacMan_;
	Blinky* Blinky_;
	Pinky* Pinky_;
	Inky* Inky_;
	Clyde* Clyde_;
	inline bool checkPosition(PacMan* PacMan, Cast* Cast);
	void setStartParams();
	void updateStat();
	void pacManMovement();
	void castMovement();
	void pacManEat();
	void pacManDie();
	void Die();
	void modeTimer();
	void loadLevel();
	void pause();
	inline bool levelUp();
public:
	Game();
	void start();
	void run();
	void stop();
};
