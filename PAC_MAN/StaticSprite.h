#ifndef H_STATIC_SPRITE
#define H_STATIC_SPRITE

#include "ISprite.h"

class StaticSprite : public ISprite
{
public:
	StaticSprite(const SpriteType type, const COLORREF mainColor, const bool sample[]);
	inline const SpriteType getType() const override;
	void printOn(const int x, const int y, const HDC hdc) const;
	const static std::shared_ptr<StaticSprite> const createSprite(const SpriteType type, const bool sample[]);
protected:
	virtual void initializeSample(const bool sample[]) override;
private:
	StaticSprite(StaticSprite const& sprite);
	StaticSprite(StaticSprite const&& sprite);
protected:
	const int size_;
	const SpriteType type_;
	COLOR_MATRIX sample_;
	const COLORREF mainColor_;
	const COLORREF backgroundColor_;
};
inline const SpriteType StaticSprite::getType() const
{
	return type_;
}
#endif