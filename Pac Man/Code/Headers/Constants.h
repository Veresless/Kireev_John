#ifndef H_CONSTANTS
#define H_CONSTANTS

#include <windows.h>

inline const char* getPath()
{
	return "SchoreList.txt";
}
inline int getFontSizeX()
{
	return 8;
}
inline int getFontSizeY()
{
	return 12;
}
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
inline int getDirectionCount()
{
	return 4;
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
	return 1000;
}
inline int getInkyStartTime()
{
	return 3000;
}
inline int getClydeStartTime()
{
	return 5000;
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
inline int getDelay()
{
	return 500;
}
#endif

