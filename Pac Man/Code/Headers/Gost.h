#ifndef H_GOST
#define H_GOST

#include <vector>

#include "DinamicSprite.h"

class Gost : public DinamicSprite
{
public:
	Gost(const COLORREF mainColor, const COLORREF fearColor, const POINT& position, const POINT& retreatPoint);
	inline GostMode getMode() const;
	void setFear(const bool fear);
	void choiseDirection(bool ways[4]);
	virtual void setDirectionPoint(const POINT& Point, const Direction direction, const POINT& Blinky) = 0;
	void setMode(const GostMode mode);
	void updateSample();
	static const std::shared_ptr<Gost> createGost(const GostType type);
protected:
	int distanse (const POINT& position, const POINT& directionPoint);
private:
	POINT getPoint(const Direction direction) const;
	void decision(const std::vector<Direction>& directions, const POINT& directionPoint);
protected:
	bool fear_;
	GostMode mode_;
	const COLORREF fearColor_;
	const POINT retreatPoint_;
	POINT directionPoint_;
};
inline GostMode Gost::getMode() const
{
	return mode_;
}
#endif