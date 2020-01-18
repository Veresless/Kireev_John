#ifndef H_I_SPRITE
#define H_I_SPRITE

#include <windows.h>
#include <memory>

#include "Constants.h"
#include "MapConstants.h"

typedef std::unique_ptr<std::unique_ptr<COLORREF[]>[]> COLOR_MATRIX;

class ISprite 
{
public:
	inline virtual const SpriteType getType() const = 0;
	virtual ~ISprite() {};
protected:
	virtual void initializeSample(const bool sample[]) = 0;
};
#endif