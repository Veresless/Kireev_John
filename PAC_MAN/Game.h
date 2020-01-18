#ifndef H_GAME
#define H_GAME

#include "Field.h"

class Game {
public:
	Game();
	void run();
private:
	void goToXY(const int x, const int y) const;
	void clearConsole(const int x, const int y) const;
	const bool exit() const;
	const bool checkPosition(const std::shared_ptr<PacMan> const pacMan, const std::shared_ptr<Gost> const gost) const;
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
};
#endif