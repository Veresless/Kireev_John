#ifndef H_DINAMIC_SPRITE
#define H_DINAMIC_SPRITE

#include <windows.h>
#include <memory>

#include "Constants.h"
#include "MapConstants.h"

typedef std::unique_ptr<std::unique_ptr<COLORREF[]>[]> COLOR_MATRIX;

class DinamicSprite
{
public:
	DinamicSprite(const COLORREF mainColor, const POINT& position, const bool sample[]);
	inline const POINT& getPosition() const;
	inline Direction getDirection() const;
	void setDirection(const Direction direction);
	inline int getSpeed() const;
	void setSpeed(const int speed);
	void setPosition(const POINT& position);
	void move();
	void print(const HDC hdc) const;
	virtual ~DinamicSprite(){};
protected:
	const int size_;
	COLOR_MATRIX sample_;
	const COLORREF mainColor_;
	const COLORREF backgroundColor_;
	POINT point_;
	Direction direction_;
	int speed_;
private:
	DinamicSprite(DinamicSprite const& sprite);
	DinamicSprite(DinamicSprite const&& sprite);
	
};
inline const POINT& DinamicSprite::getPosition() const
{
	return point_;
}
inline Direction DinamicSprite::getDirection() const
{
	return direction_;
}
inline int DinamicSprite::getSpeed() const
{
	return speed_;
}
#endif