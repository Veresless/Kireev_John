#ifndef H_BASE_SPRITE
#define H_BASE_SPRITE

#include <windows.h>

enum SpriteType
{
	WALL,
	SHOREPOINT,
	ENERGISER,
	EMPTY,
	PACMAN,
	CAST
};

class BaseSprite 
{
public:
	BaseSprite();
	inline const SpriteType getType() const
	{
		return type_;
	}
	inline COLORREF** getSample() const
	{
		return sample_;
	}
	void initializeSample(bool sample[], COLORREF color, COLORREF background);
	~BaseSprite();
protected:
	int size_;
	SpriteType type_;
	COLORREF** sample_;
	virtual void setDefaultType() = 0;
private:
	void createSample();
};
#endif