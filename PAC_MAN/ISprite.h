#ifndef H_I_SPRITE
#define H_I_SPRITE

#include <windows.h>
#include "Constants.h"


class ISprite 
{
public:
	inline virtual const SpriteType getType() const = 0;
	virtual void setType(const SpriteType type) = 0;
	virtual void initializeSample(const bool sample[]) = 0;
protected:
	virtual void createSample() = 0;
};
#endif