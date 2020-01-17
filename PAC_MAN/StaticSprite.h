#ifndef H_STATIC_SPRITE
#define H_STATIC_SPRITE

#include "ISprite.h"

class StaticSprite : public ISprite
{
public:
	StaticSprite();
	inline const SpriteType getType() const override;
	virtual void setType(const SpriteType type) override;
	void printOn(int x, int y, HDC hdc);
	virtual void initializeSample(const bool sample[]) override;
	static StaticSprite* createSprite(const SpriteType type);
	void setMainColor(const COLORREF color);
	~StaticSprite();
protected:
	virtual void createSample() override;
protected:
	const int size_;
	SpriteType type_;
	COLORREF** sample_;
	COLORREF mainColor_;
	const COLORREF backgroundColor_;
};
inline const SpriteType StaticSprite::getType() const
{
	return type_;
}
#endif