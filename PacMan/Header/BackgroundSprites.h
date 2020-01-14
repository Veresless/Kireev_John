#pragma once
#include "StaticSprite.h"

class Empty : public StaticSprite 
{
protected:
	void setDefaultType();
public:
	Empty();
	void initializeSample(COLORREF Color, COLORREF Background);
};
class WallHorizontal : public StaticSprite
{
protected:
	void setDefaultType();
public:
	WallHorizontal();
	void initializeSample(COLORREF Color, COLORREF Background);
};
class WallVertical : public StaticSprite
{
protected:
	void setDefaultType();
public:
	WallVertical();
	void initializeSample(COLORREF Color, COLORREF Background);
};
class WallLeftBottom : public StaticSprite
{
protected:
	void setDefaultType();
public:
	WallLeftBottom();
	void initializeSample(COLORREF Color, COLORREF Background);
};
class WallRightBottom : public StaticSprite
{
protected:
	void setDefaultType();
public:
	WallRightBottom();
	void initializeSample(COLORREF Color, COLORREF Background);
};
class WallLeftTop : public StaticSprite
{
protected:
	void setDefaultType();
public:
	WallLeftTop();
	void initializeSample(COLORREF Color, COLORREF Background);
};
class WallRightTop : public StaticSprite
{
protected:
	void setDefaultType();
public:
	WallRightTop();
	void initializeSample(COLORREF Color, COLORREF Background);
};
class Door : public StaticSprite
{
protected:
	void setDefaultType();
public:
	Door();
	void initializeSample(COLORREF Color, COLORREF Background);
};
class SchorePoint : public StaticSprite
{
protected:
	void setDefaultType();
public:
	SchorePoint();
	void initializeSample(COLORREF Color, COLORREF Background);
};
class Energiser : public StaticSprite
{
protected:
	void setDefaultType();
public:
	Energiser();
	void initializeSample(COLORREF Color, COLORREF Background);
};