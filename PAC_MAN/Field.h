#ifndef H_FIELD
#define H_FIELD

#include "StaticSprite.h"
#include "Gost.h"
#include "PacMan.h"

typedef std::unique_ptr<std::unique_ptr<std::shared_ptr<StaticSprite>[]>[]> SPRITE_MATRIX;

class Field 
{
public:
	Field();
	inline const std::shared_ptr<PacMan> const getPacMan() const;
	const std::shared_ptr<Gost> const getGost(const GostType type) const;
	void fearGost();
	void normalCast();
	void normalBlinky();
	void normalPinky();
	void normalInky();
	void normalClyde();
	void printAll();
	void resetLevel();
	void resetDinamic();
	const SpriteType getSpriteTypeAt(const int x, const int y);
	void setEmptyAt(const int x, const int y);
	const GostMode getCastMode();
	void changeCastMode(const GostMode mode);
	void setBlinky();
	void setPinky();
	void setInky();
	void setClyde();
	void setEasySpeed();
	void setMediumSpeed();
	void setHardSpeed();
	void castMovement();
	void turnPacMan(const Direction direction);
	void moveAllDinamic();
public:
	bool blinkyReady;
	bool pinkyReady;
	bool inkyReady;
	bool clydeReady;
private:
	void setSprites();
	void setStart();
	const bool isEmpty(const POINT& position, const Direction direction);
	void moveDinamic(std::shared_ptr<DinamicSprite> sprite, const POINT& position, const Direction direction);
	void eraseDinamic(const POINT& Position);
	bool checkSpecial(const int x, const int y);
private:
	HDC hdc_;
	HWND hwnd_;
	GostMode mode_;
	std::shared_ptr<StaticSprite> empty_;
	std::shared_ptr<StaticSprite> wallVertical_;
	std::shared_ptr<StaticSprite> wallHorizontal_;
	std::shared_ptr<StaticSprite> wallLeftBottom_;
	std::shared_ptr<StaticSprite> wallRightBottom_;
	std::shared_ptr<StaticSprite> wallLeftTop_;
	std::shared_ptr<StaticSprite> wallRightTop_;
	std::shared_ptr<StaticSprite> door_;
	std::shared_ptr<PacMan> pacMan_;
	std::shared_ptr<Gost> blinky_;
	std::shared_ptr<Gost> pinky_;
	std::shared_ptr<Gost> inky_;
	std::shared_ptr<Gost> clyde_;
	std::shared_ptr<StaticSprite> schorePoint_;
	std::shared_ptr<StaticSprite> energiser_;
	SPRITE_MATRIX level_;
};
inline const std::shared_ptr<PacMan> const Field::getPacMan() const
{
	return pacMan_;
}
#endif