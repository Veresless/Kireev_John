#ifndef H_GAME
#define H_GAME

#include "Field.h"

class Game {
public:
	Game();
	void run();
private:
	int schore_;
	int lifes_;
	int level_;
	ULONGLONG deltaTime_;
	unsigned long long energiserTime_;
	bool energiserTimeOn_;
	short castDieCount_;
	int countEatenPoints_;
	bool live_;
	Field field_;
	void goToXY(const int x, const int y) const;
	void clearConsole(const int x, const int y) const;
	const bool exit() const;
	const bool checkPosition(const PacMan* PacMan, const Gost* Gost)const;
	void setStartParams();
	void updateStatistic()const;
	void pacManMovement();
	void castMovement();
	void pacManEat();
	void pacManDie();
	void die();
	void modeTimer();
	void loadLevel();
	const bool levelUp();
};
#endif