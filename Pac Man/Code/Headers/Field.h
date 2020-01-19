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
	inline GostMode getGostMode() const;
	void setGostMode(const GostMode mode);
	const std::shared_ptr<Gost> const getGost(const GostType type) const;
	inline const std::shared_ptr<PacMan> const getPacMan() const;
	void setBlinkyReady();
	void setPinkyReady();
	void setInkyReady();
	void setClydeReady();
	void setEasySpeed();
	void setMediumSpeed();
	void setHardSpeed();
	void setEmptyAt(const int x, const int y);
	StaticSpriteType getSpriteTypeAt(const int x, const int y);
	void fearGost();
	void normalGost();
	void normalBlinky();
	void normalPinky();
	void normalInky();
	void normalClyde();
	void printAll();
	void resetLevel();
	void resetDinamic();
	void gostMovement();
	void moveAllDinamic();
	void turnPacMan(const Direction direction);
public:
	bool blinkyReady;
	bool pinkyReady;
	bool inkyReady;
	bool clydeReady;
private:
	void resetMap();
	bool checkEmpty(const POINT& position, const Direction direction) const;
	void moveDinamic(std::shared_ptr<DinamicSprite> sprite, const POINT& position, const Direction direction);
	void eraseDinamic(const POINT& Position);
	bool checkSpecial(const int x, const int y);
private:
	const HWND hwnd_;
	const HDC hdc_;
	GostMode mode_;
	const std::shared_ptr<StaticSprite> empty_;
	const std::shared_ptr<StaticSprite> wallVertical_;
	const std::shared_ptr<StaticSprite> wallHorizontal_;
	const std::shared_ptr<StaticSprite> wallLeftBottom_;
	const std::shared_ptr<StaticSprite> wallRightBottom_;
	const std::shared_ptr<StaticSprite> wallLeftTop_;
	const std::shared_ptr<StaticSprite> wallRightTop_;
	const std::shared_ptr<StaticSprite> door_;
	const std::shared_ptr<PacMan> pacMan_;
	const std::shared_ptr<Gost> blinky_;
	const std::shared_ptr<Gost> pinky_;
	const std::shared_ptr<Gost> inky_;
	const std::shared_ptr<Gost> clyde_;
	const std::shared_ptr<StaticSprite> schorePoint_;
	const std::shared_ptr<StaticSprite> energiser_;
	SPRITE_MATRIX level_;
};
inline GostMode Field::getGostMode() const
{
	return mode_;
}
inline const std::shared_ptr<PacMan> const Field::getPacMan() const
{
	return pacMan_;
}
#endif