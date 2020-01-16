#pragma once
#include "StaticSprite.h"

class Empty : public StaticSprite 
{
protected:
	virtual void setDefaultType() override;
public:
	Empty();
};
class Wall : public StaticSprite
{
protected:
	virtual void setDefaultType() override;
public:
	Wall();
};
class SchorePoint : public StaticSprite
{
protected:
	virtual void setDefaultType() override;
public:
	SchorePoint();
};
class Energiser : public StaticSprite
{
protected:
	virtual void setDefaultType() override;
public:
	Energiser();
};