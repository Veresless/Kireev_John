#ifndef H_DINAMIC_SPRITE
#define H_DINAMIC_SPRITE

#include "ISprite.h"


class DinamicSprite : public ISprite
{
public:
	DinamicSprite();
	inline const SpriteType getType() const override;
	inline const POINT getPosition() const;
	inline const Direction getDirection() const;
	void setDirection(const Direction direction);
	inline const int getSpeed() const;
	void setSpeed(const int speed);
	virtual void setStartPosition() = 0;
	void move();
	virtual void initializeSample(const bool sample[]) override;
	virtual void setMainColor(const COLORREF color) = 0;
	const void print(const HDC hdc) const;
	virtual ~DinamicSprite();
protected:
	virtual void createSample() override;
protected:
	const int size_;
	SpriteType type_;
	COLORREF** sample_;
	COLORREF mainColor_;
	const COLORREF backgroundColor_;
	POINT point_;
	Direction direction_;
	int speed_;
};
inline const SpriteType DinamicSprite::getType() const
{
	return type_;
}
inline const POINT DinamicSprite::getPosition() const
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