#ifndef H_CONSTANTS
#define H_CONSTANTS

#include <windows.h>

inline int getHorizontal() 
{
	return 28;
}
inline int getVertical()
{
	return 36;
}
inline int getSize() 
{
	 return 8;
}
inline int getLowSpeed()
{
	return 1;
}
inline int getMiddleSpeed()
{
	return 2;
}
inline int getHighSpeed()
{
	return 4;
}
inline POINT getCastReadyPosition()
{
	return { 13 * getSize() + getSize() / 2, 14 * getSize() };
}
inline POINT getBlinkyStartPosition()
{
	return { 13 * getSize() + getSize() / 2, 14 * getSize() };
}
inline POINT getPinkyStartPosition()
{
	return { 13 * getSize() + getSize() / 2, 17 * getSize() };
}
inline POINT getInkyStartPosition()
{
	return { 11 * getSize() + getSize() / 2, 17 * getSize() };
}
inline POINT getClydeStartPosition()
{
	return { 15 * getSize() + getSize() / 2, 17 * getSize() };
}
inline int getInkyDistanse()
{
	return 2;
}
inline int getPinkyDistanse()
{
	return 4;
}
inline int getClydeDistanse()
{
	return 8;
}
inline POINT getBlinkyRetreatPoint()
{
	return { 25 * getSize(), 0 };
}
inline POINT getPinkyRetreatPoint()
{
	return { 2 * getSize(), 0 };
}
inline POINT getInkyRetreatPoint()
{
	return { 27 * getSize(), 35 * getSize() };
}
inline POINT getClydeRetreatPoint()
{
	return { 0, 35 * getSize() };
}
inline POINT getPacManStartPosition()
{

	return { 13 * getSize() + getSize() / 2, 26 * getSize() };
}
inline int getCountDirections()
{
	return 4;
}
inline int getMaxCountPoints()
{
	return 244;
}
inline int getStartLifes()
{
	return 2;
}
inline int getStartLevel()
{
	return 1;
}
inline int getDefaultDeltaTime()
{
	return 50;
}
inline int getOneSecond()
{
	return 1000;
}
inline int getPointSchore()
{
	return 10;
}
inline int getEnergiserSchore()
{
	return 50;
}
inline int getLevelWhereCastNotFear()
{
	return 19;
}
inline int getCastDieSchore()
{
	return 200;
}
inline int getBinaryToBool()
{
	return 0x8000;
}
inline int getWKey()
{
	return 87;
}
inline int getSKey()
{
	return 83;
}
inline int getDKey()
{
	return 68;
}
inline int getAKey()
{
	return 65;
}
inline int getUpKey()
{
	return 38;
}
inline int getDownKey()
{
	return 40;
}
inline int getRightKey()
{
	return 39;
}
inline int getLeftKey()
{
	return 37;
}
inline int getEnterKey()
{
	return 13;
}
inline int getEscKey()
{
	return 27;
}
inline int getTabKey()
{
	return 9;
}
inline int getFearTime()
{
	return 10000;
}
inline int getFearDifferenseTime()
{
	return 50;
}
inline int getStartLate()
{
	return 5000;
}
inline int getRetreatMaxTime()
{
	return 7000;
}
inline int getRetreatMinTime()
{
	return 5000;
}
inline int getAttackTime()
{
	return 20000;
}
inline int getFirstChangeLevel()
{
	return 2;
}
inline int getSecondChangeLevel()
{
	return 5;
}
inline int getThirdChangeLevel()
{
	return 19;
}
inline int getLastChangeLevel()
{
	return 21;
}
inline int getLongAttackTime()
{
	return 1033000;
}
inline int getLargeAttackTime()
{
	return 1037000;
}
inline int getSmalestRetreatTime()
{
	return 100 / 6;
}
inline int getPinkyStartTime()
{
	return 5000;
}
inline int getInkyStartTime()
{
	return 7000;
}
inline int getClydeStartTime()
{
	return 9000;
}
inline int getInkyPointCountCondition()
{
	return 30;
}
inline int getClydePointCountCondition()
{
	return getMaxCountPoints() / 3;
}
inline int getCountStatisticStrings()
{
	return 2;
}
inline POINT getFirstSpecialPoint()
{
	return {12, 14};
}
inline POINT getSecondSpecialPoint()
{
	return {15, 14};
}
inline POINT getThirdSpecialPoint()
{
	return {12 , 26};
}
inline POINT getFourthSpecialPoint()
{
	return {15 , 26};
}
inline const char* getPath()
{
	return "SchoreList.txt";
}
inline int getDelay()
{
	return 500;
}
#endif

