#pragma once
#include <windows.h>
#include <utility>

enum SpriteType
{
	TWall,
	TDoor,
	TSchorePoint,
	TEnergiser,
	TEmpty,
	TPacMan,
	TCast
};

class BaseSprite 
{
protected:
	int Size_;
	SpriteType Type_;
	COLORREF** Sample_;
	void setDefaultSize();
	void setDefaultType();
	void createSample();
public:
	BaseSprite();
	int getSize();
	SpriteType getType();
	void initializeSample(COLORREF Color, COLORREF Background);
	void clearSample();
};