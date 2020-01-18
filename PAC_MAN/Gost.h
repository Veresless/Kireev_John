#ifndef H_GOST
#define H_GOST

#include <vector>

#include "DinamicSprite.h"

class Gost : public DinamicSprite
{
public:
	Gost(COLORREF mainColor, COLORREF fearColor, const POINT& retreatPoint);
	inline const GostMode getMode() const;
	void setFear(const bool fear);
	void setReadyPosition();
	void choiseDirection(bool ways[4]);
	virtual void setDirectionPoint(const POINT& Point, const Direction direction, const POINT& Blinky) = 0;
	void setMode(const GostMode mode);
	void updateSample();
	static std::shared_ptr<Gost> createGost(const GostType type);
protected:
	const int distanse (const POINT& position, const POINT& directionPoint);
	virtual void initializeSample(const bool sample[]) override;
private:
	const POINT getPoint(const Direction direction) const;
	void decision(const std::vector<Direction>& directions, const POINT& directionPoint);
protected:
	bool fear_;
	GostMode mode_;
	const COLORREF fearColor_;
	const POINT retreatPoint_;
	POINT directionPoint_;
};
inline const GostMode Gost::getMode() const
{
	return mode_;
}
#endif