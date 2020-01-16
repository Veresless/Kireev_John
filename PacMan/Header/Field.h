#ifndef H_FIELD
#define H_FIELD

#include "BackgroundSprites.h"
#include "Cast.h"
#include "PacMan.h"

class Field 
{
public:
	bool blinkyReady_;
	bool pinkyReady_;
	bool inkyReady_;
	bool clydeReady_;
	inline const PacMan& getPacMan() const
	{
		return pacMan_;
	}
	inline const Cast& getBlinky() const
	{
		return blinky_;
	}
	inline const Cast& getPinky() const
	{
		return pinky_;
	}
	inline const Cast& getInky() const
	{
		return inky_;
	}
	inline const Cast& getClyde() const
	{
		return clyde_;
	}
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
	const CastMode getCastMode();
	void changeCastMode(const CastMode mode);
	void setBlinky();
	void setPinky();
	void setInky();
	void setClyde();
	void setEasySpeed();
	void setMediumSpeed();
	void setHardSpeed();
	void castMovement();
	void turnDinamic(DinamicSprite& sprite, const Direction direction);
	void turnPacMan(Direction const direction);
	void moveAllDinamic();
private:
	HDC hdc_;
	HWND hwnd_;
	CastMode mode_;
	Empty empty_;
	Wall wallVertical_;
	Wall wallHorizontal_;
	Wall wallLeftBottom_;
	Wall wallRightBottom_;
	Wall wallLeftTop_;
	Wall wallRightTop_;
	Wall door_;
	PacMan pacMan_;
	Blinky blinky_;
	Pinky pinky_;
	Inky inky_;
	Clyde clyde_;
	SchorePoint schorePoint_;
	Energiser energiser_;
	StaticSprite*** level_;
	void setSprites();
	void setStart();
	const bool isEmpty(const POINT position, const Direction direction);
	void moveDinamic(DinamicSprite& sprite, const POINT position, const Direction direction);
	void eraseDinamic(const POINT Position);
	bool checkSpecial(const int x, const int y);
};
#endif