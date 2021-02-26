#ifndef H_STATIC_SPRITE
#define H_STATIC_SPRITE

#include <windows.h>
#include <memory>

#include "Constants.h"
#include "MapConstants.h"

typedef std::unique_ptr<std::unique_ptr<COLORREF[]>[]> COLOR_MATRIX;

class StaticSprite
{
public:
	StaticSprite(const StaticSpriteType type, const COLORREF mainColor, const bool sample[]);
	inline StaticSpriteType getType() const;
	inline COLORREF getColorAt(const POINT& point) const;
	void printOn(const int x, const int y, const HDC hdc) const;
	const static std::shared_ptr<StaticSprite> createSprite(const StaticSpriteType type, const bool sample[]);
	virtual ~StaticSprite() {};
private:
	StaticSprite(StaticSprite const& sprite);
	StaticSprite(StaticSprite const&& sprite);
protected:
	const int size_;
	const StaticSpriteType type_;
	COLOR_MATRIX sample_;
	const COLORREF mainColor_;
	const COLORREF backgroundColor_;
};
inline StaticSpriteType StaticSprite::getType() const
{
	return type_;
}
inline COLORREF StaticSprite::getColorAt(const POINT& point) const
{
	return sample_[point.y][point.x];
}
#endif