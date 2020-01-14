#pragma once
#include "BackgroundSprites.h"
#include "MoveAbleSprites.h"

class Field {
private:
	HDC Hdc_;
	HWND Hwnd_;
	PAINTSTRUCT Ps_;
	CastMode Mode_;
	int Horizontal_, Vertical_;
	Empty Empty_;
	WallVertical WallVertical_;
	WallHorizontal WallHorizontal_;
	WallLeftBottom WallLeftBottom_;
	WallRightBottom WallRightBottom_;
	WallLeftTop WallLeftTop_;
	WallRightTop WallRightTop_;
	Door Door_;
	PacMan PacMan_;
	Blinky Blinky_;
	Pinky Pinky_;
	Inky Inky_;
	Clyde Clyde_;
	SchorePoint SchorePoint_;
	Energiser Energiser_;
	StaticSprite*** Level;
	void setSize();
	void setSprites();
	void clearSprites();
	void setStart();
	inline bool isEmpty(std::pair<int, int> Position, int Direction, int Size);
	inline void getPositionDirectionSize(DinamicSprite* Sprite, std::pair<int, int> &Position, int &Direction, int &Size);
	void moveDinamic(DinamicSprite* Sprite, std::pair<int, int> Position, int Direction, int Size);
	void eraseDinamic(DinamicSprite* Sprite, std::pair<int, int> Position, int Size);
	inline bool checkSpecial(int x, int y);
public:
	bool BlinkyReady_, PinkyReady_, InkyReady_, ClydeReady_;
	Field();
	void fearCast();
	void normalCast();
	void normalBlinky();
	void normalPinky();
	void normalInky();
	void normalClyde();
	void clear();
	void printAll();
	void resetLevel();
	void resetDinamic();
	SpriteType getSpriteTypeAt(int x, int y);
	void setEmptyAt(int x, int y);
	PacMan* getPacMan();
	Blinky* getBlinky();
	Pinky* getPinky();
	Inky* getInky();
	Clyde* getClyde();
	CastMode getCastMode();
	void changeCastMode(CastMode Mode);
	void setBlinky();
	void setPinky();
	void setInky();
	void setClyde();
	void castMovement();
	void turnDinamic(DinamicSprite* Sprite, int Direction);
	void moveAllDinamic();
};