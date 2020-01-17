#ifndef H_FIELD
#define H_FIELD

#include "StaticSprite.h"
#include "Gost.h"
#include "PacMan.h"

class Field 
{
public:
	inline const PacMan* getPacMan() const;
	inline const Gost* getBlinky() const;
	inline const Gost* getPinky() const;
	inline const Gost* getInky() const;
	inline const Gost* getClyde() const;
	Field();
	~Field();
	void fearCast();
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
	void turnDinamic(DinamicSprite* sprite, const Direction direction);
	void turnPacMan(Direction const direction);
	void moveAllDinamic();
public:
	bool blinkyReady_;
	bool pinkyReady_;
	bool inkyReady_;
	bool clydeReady_;
private:
	void setSprites();
	void setStart();
	const bool isEmpty(const POINT position, const Direction direction);
	void moveDinamic(DinamicSprite* sprite, const POINT position, const Direction direction);
	void eraseDinamic(const POINT Position);
	bool checkSpecial(const int x, const int y);
private:
	HDC hdc_;
	HWND hwnd_;
	GostMode mode_;
	StaticSprite* empty_;
	StaticSprite* wallVertical_;
	StaticSprite* wallHorizontal_;
	StaticSprite* wallLeftBottom_;
	StaticSprite* wallRightBottom_;
	StaticSprite* wallLeftTop_;
	StaticSprite* wallRightTop_;
	StaticSprite* door_;
	PacMan pacMan_;
	Gost* blinky_;
	Gost* pinky_;
	Gost* inky_;
	Gost* clyde_;
	StaticSprite* schorePoint_;
	StaticSprite* energiser_;
	StaticSprite*** level_;
};
inline const PacMan* Field::getPacMan() const
{
	return &pacMan_;
}
inline const Gost* Field::getBlinky() const
{
	return blinky_;
}
inline const Gost* Field::getPinky() const
{
	return pinky_;
}
inline const Gost* Field::getInky() const
{
	return inky_;
}
inline const Gost* Field::getClyde() const
{
	return clyde_;
}
#endif