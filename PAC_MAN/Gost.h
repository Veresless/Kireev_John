#ifndef H_GOST
#define H_GOST

#include <vector>

#include "DinamicSprite.h"



class Gost : public DinamicSprite
{
public:
	Gost();
	inline const GostMode getMode() const;
	virtual void setType(const SpriteType type) override;
	void setReadyPosition();
	void choiseDirection(bool ways[4]);
	virtual void setDirectionPoint(const POINT Point, const Direction direction, const POINT Blinky) = 0;
	void setMode(const GostMode mode);
	static Gost* createGost(const GostType type);
	virtual void setMainColor(const COLORREF color)override;
protected:
	GostMode mode_;
	POINT retreatPoint_;
	POINT directionPoint_;
	const int distanse (const POINT position, const POINT directionPoint);
private:
	const POINT getPoint(const Direction direction);
	void decision(std::vector<Direction>& directions, const POINT directionPoint);
};
inline const GostMode Gost::getMode() const
{
	return mode_;
}
#endif