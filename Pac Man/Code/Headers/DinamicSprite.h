#ifndef H_DINAMIC_SPRITE
#define H_DINAMIC_SPRITE

#include "ISprite.h"

class DinamicSprite : public ISprite
{
public:
	DinamicSprite(const SpriteType type, const COLORREF mainColor, const bool sample[]);
	inline const SpriteType getType() const override;
	inline const POINT& getPosition() const;
	inline const Direction getDirection() const;
	void setDirection(const Direction direction);
	inline const int getSpeed() const;
	void setSpeed(const int speed);
	virtual void setStartPosition() = 0;
	void move();
	const void print(const HDC hdc) const;
protected:
	virtual void initializeSample(const bool sample[]) override;
protected:
	const int size_;
	const SpriteType type_;
	COLOR_MATRIX sample_;
	const COLORREF mainColor_;
	const COLORREF backgroundColor_;
	POINT point_;
	Direction direction_;
	int speed_;
};
inline const SpriteType DinamicSprite::getType() const
{
	return type_;
}
inline const POINT& DinamicSprite::getPosition() const
{
	return point_;
}
inline const Direction DinamicSprite::getDirection() const
{
	return direction_;
}
inline const int DinamicSprite::getSpeed() const
{
	return speed_;
}
#endif