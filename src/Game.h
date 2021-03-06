#ifndef H_GAME
#define H_GAME

#include "Field.h"
#include "WaveTime.h"

class Game {
public:
	Game();
	int run();
private:
	void goToXY(const int x, const int y) const;
	void clearConsole(const int x, const int y) const;
	bool exit() const;
	bool checkPosition(const std::shared_ptr<PacMan> pacMan, const std::shared_ptr<Gost> gost) const;
	void updateStatistic()const;
	void pacManMovement();
	void gostMovement();
	void pacManEat();
	void pacManDie();
	void die();
	void modeTimer(const WaveTime& waveTime, ULONGLONG& startTime);
	void loadLevel();
	bool levelUp();
private:
	int schore_;
	int lifes_;
	int level_;
	const ULONGLONG deltaTime_;
	ULONGLONG energiserTime_;
	bool energiserTimeOn_;
	short gostDieCount_;
	int countEatenPoints_;
	bool live_;
	Field field_;
};
#endif