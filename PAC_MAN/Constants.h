#ifndef H_CONSTANTS
#define H_CONSTANTS

#include <windows.h>

inline const int getHorizontal() 
{
	return 28;
}
inline const int getVertical()
{
	return 36;
}
inline const int getSize() 
{
	 return 8;
}

inline const int getLowSpeed()
{
	return 1;
}
inline const int getMiddleSpeed()
{
	return 2;
}
inline const int getHighSpeed()
{
	return 4;
}
inline const POINT getCastReadyPosition()
{
	return { 13 * getSize() + getSize() / 2, 14 * getSize() };
}
inline const POINT getBlinkyStartPosition()
{
	return { 13 * getSize() + getSize() / 2, 14 * getSize() };
}
inline const POINT getPinkyStartPosition()
{
	return { 13 * getSize() + getSize() / 2, 17 * getSize() };
}
inline const POINT getInkyStartPosition()
{
	return { 11 * getSize() + getSize() / 2, 17 * getSize() };
}
inline const POINT getClydeStartPosition()
{
	return { 15 * getSize() + getSize() / 2, 17 * getSize() };
}
inline const int getPinkyDistanse()
{
	return 4;
}
inline const int getClydeDistanse()
{
	return 8;
}
inline const POINT getBlinkyRetreatPoint()
{
	return { 25 * getSize(), 0 };
}
inline const POINT getPinkyRetreatPoint()
{
	return { 2 * getSize(), 0 };
}
inline const POINT getInkyRetreatPoint()
{
	return { 27 * getSize(), 35 * getSize() };
}
inline const POINT getClydeRetreatPoint()
{
	return { 0, 35 * getSize() };
}
inline const POINT getPacManStartPosition()
{

	return { 13 * getSize() + getSize() / 2, 26 * getSize() };
}
inline const int getCountDirections()
{
	return 4;
}
inline const int getMaxCountPoints()
{
	return 244;
}
inline const int getStartLifes()
{
	return 2;
}
inline const int getDefaultDeltaTime()
{
	return 50;
}
inline const int getOneSecond()
{
	return 1000;
}
inline const int getPointSchore()
{
	return 10;
}
inline const int getEnergiserSchore()
{
	return 50;
}
inline const int getLevelWhereCastNotFear()
{
	return 19;
}
inline const int getCastDieSchore()
{
	return 200;
}
inline const int getBinaryToBool()
{
	return 0x8000;
}
inline const int getWKey()
{
	return 87;
}
inline const int getSKey()
{
	return 83;
}
inline const int getDKey()
{
	return 68;
}
inline const int getAKey()
{
	return 65;
}
inline const int getUpKey()
{
	return 38;
}
inline const int getDownKey()
{
	return 40;
}
inline const int getRightKey()
{
	return 39;
}
inline const int getLeftKey()
{
	return 37;
}
inline const int getEnterKey()
{
	return 13;
}
inline const int getEscKey()
{
	return 27;
}
inline const int getFearTime()
{
	return 10000;
}
inline const int getFearDifferenseTime()
{
	return 50;
}
inline const int getStartLate()
{
	return 5000;
}
inline const int getRetreatMaxTime()
{
	return 7000;
}
inline const int getRetreatMinTime()
{
	return 5000;
}
inline const int getAttackTime()
{
	return 20000;
}
inline const int getFirstChangeLevel()
{
	return 2;
}
inline const int getSecondChangeLevel()
{
	return 5;
}
inline const int getThirdChangeLevel()
{
	return 19;
}
inline const int getLastChangeLevel()
{
	return 21;
}
inline const int getLongAttackTime()
{
	return 1033000;
}
inline const int getLargeAttackTime()
{
	return 1037000;
}
inline const int getSmalestRetreatTime()
{
	return 100 / 6;
}
inline const int getPinkyStartTime()
{
	return 5000;
}
inline const int getInkyStartTime()
{
	return 7000;
}
inline const int getClydeStartTime()
{
	return 9000;
}
inline const int getInkyPointCountCondition()
{
	return 30;
}
inline const int getClydePointCountCondition()
{
	return getMaxCountPoints() / 3;
}
inline const int getCountStatisticStrings()
{
	return 2;
}
inline const POINT getFirstSpecialPoint()
{
	return {12, 14};
}
inline const POINT getSecondSpecialPoint()
{
	return {15, 14};
}
inline const POINT getThirdSpecialPoint()
{
	return {12 , 26};
}
inline const POINT getFourthSpecialPoint()
{
	return {15 , 26};
}
#endif

