#ifndef H_MAP_CONSTANTS
#define H_MAP_CONSTANTS

#include <string>

enum SpriteType
{
	WALL,
	SCHORE_POINT,
	ENERGISER,
	EMPTY,
	PAC_MAN,
	GOST
};

enum GostMode
{
	ATTACK,
	RETREAT,
	FEAR
};
enum GostType
{
	BLINKY,
	PINKY,
	INKY,
	CLYDE
};

enum Direction
{
	UP,
	LEFT,
	DOWN,
	RIGHT
};
inline const int getDirectionCount()
{
	return 4;
}
const bool SPRITE_EMPTY[] = {		0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0 };

const bool WALL_VERTICAL[] = {		0, 0, 0, 1, 1, 0, 0, 0,
									0, 0, 0, 1, 1, 0, 0, 0,
									0, 0, 0, 1, 1, 0, 0, 0,
									0, 0, 0, 1, 1, 0, 0, 0,
									0, 0, 0, 1, 1, 0, 0, 0,
									0, 0, 0, 1, 1, 0, 0, 0,
									0, 0, 0, 1, 1, 0, 0, 0,
									0, 0, 0, 1, 1, 0, 0, 0 };

const bool WALL_HORIZONTAL[] = {	0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									1, 1, 1, 1, 1, 1, 1, 1,
									1, 1, 1, 1, 1, 1, 1, 1,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0 };

const bool WALL_LEFT_BOTTOM[] = {	0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									1, 1, 1, 1, 0, 0, 0, 0,
									1, 1, 1, 1, 1, 0, 0, 0,
									0, 0, 1, 1, 1, 0, 0, 0,
									0, 0, 0, 1, 1, 0, 0, 0,
									0, 0, 0, 1, 1, 0, 0, 0 };

const bool WALL_RIGHT_BOTTOM[] = {	0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 1, 1, 1, 1,
									0, 0, 0, 1, 1, 1, 1, 1,
									0, 0, 0, 1, 1, 1, 0, 0,
									0, 0, 0, 1, 1, 0, 0, 0,
									0, 0, 0, 1, 1, 0, 0, 0 };

const bool WALL_LEFT_TOP[] = {		0, 0, 0, 1, 1, 0, 0, 0,
									0, 0, 0, 1, 1, 0, 0, 0,
									0, 0, 1, 1, 1, 0, 0, 0,
									1, 1, 1, 1, 1, 0, 0, 0,
									1, 1, 1, 1, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0 };

const bool WALL_RIGHT_TOP[] = {		0, 0, 0, 1, 1, 0, 0, 0,
									0, 0, 0, 1, 1, 0, 0, 0,
									0, 0, 0, 1, 1, 1, 0, 0,
									0, 0, 0, 1, 1, 1, 1, 1,
									0, 0, 0, 0, 1, 1, 1, 1,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0 };

const bool SPRITE_PAC_MAN[] = {		0, 0, 0, 1, 1, 0, 0, 0,
									0, 1, 1, 1, 1, 1, 1, 0,
									0, 1, 1, 1, 1, 1, 1, 0,
									1, 1, 1, 1, 1, 1, 1, 1,
									1, 1, 1, 1, 1, 1, 1, 1,
									0, 1, 1, 1, 1, 1, 1, 0,
									0, 1, 1, 1, 1, 1, 1, 0,
									0, 0, 0, 1, 1, 0, 0, 0 };

const bool SPRITE_SCHORE_POINT[] ={	0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 1, 1, 0, 0, 0,
									0, 0, 0, 1, 1, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0 };

const bool SPRITE_ENERGISER[] = {	0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 1, 1, 0, 0, 0,
									0, 0, 1, 1, 1, 1, 0, 0,
									0, 1, 1, 1, 1, 1, 1, 0,
									0, 1, 1, 1, 1, 1, 1, 0,
									0, 0, 1, 1, 1, 1, 0, 0,
									0, 0, 0, 1, 1, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0 };

const bool SPRITE_GOST[] = {		0, 0, 0, 1, 1, 0, 0, 0,
									0, 0, 1, 1, 1, 1, 0, 0,
									0, 1, 1, 1, 1, 1, 1, 0,
									0, 1, 1, 1, 1, 1, 1, 0,
									1, 1, 1, 1, 1, 1, 1, 1,
									1, 1, 1, 1, 1, 1, 1, 1,
									1, 1, 1, 1, 1, 1, 1, 1,
									1, 0, 1, 1, 0, 1, 0, 1 };
const std::string MAP[] = {
					"                            ",
					"                            ",
					"                            ",
					"F------------TF------------T",
					"|............||............|",
					"|.F--T.F---T.||.F---T.F--T.|",
					"|O|  |.|   |.||.|   |.|  |O|",
					"|.L--J.L---J.LJ.L---J.L--J.|",
					"|..........................|",
					"|.F--T.FT.F------T.FT.F--T.|",
					"|.L--J.||.L--TF--J.||.L--J.|",
					"|......||....||....||......|",
					"L----T.|L--T || F--J|.F----J",
					"     |.|F--J LJ L--T|.|     ",
					"     |.||          ||.|     ",
					"     |.|| F--==--T ||.|     ",
					"-----J.LJ |      | LJ.L-----",
					"      .   |      |   .      ",
					"-----T.FT |      | FT.F-----",
					"     |.|| L------J ||.|     ",
					"     |.||          ||.|     ",
					"     |.|| F------T ||.|     ",
					"F----J.LJ L--TF--J LJ.L----T",
					"|............||............|",
					"|.F--T.F---T.||.F---T.F--T.|",
					"|.L-T|.L---J.LJ.L---J.|F-J.|",
					"|O..||.......  .......||..O|",
					"L-T.||.FT.F------T.FT.||.F-J",
					"F-J.LJ.||.L--TF--J.||.LJ.L-T",
					"|......||....||....||......|",
					"|.F----JL--T.||.F--JL----T.|",
					"|.L--------J.LJ.L--------J.|",
					"|..........................|",
					"L--------------------------J",
					"                            ",
					"                            " };
const char EMPTY_CHAR = ' ';
const char WALL_HORIZONTAL_CHAR = '-';
const char WALL_VERTICAL_CHAR = '|';
const char SCHORE_POINT_CHAR = '.';
const char ENERGISER_CHAR = 'O';
const char WALL_LEFT_TOP_CHAR = 'J';
const char WALL_LEFT_BOTTOM_CHAR = 'T';
const char WALL_RIGHT_TOP_CHAR = 'L';
const char WALL_RIGHT_BOTTOM_CHAR ='F';
const char DOOR_CHAR = '=';

inline const COLORREF getBackgroundColor()
{
	return RGB(0, 0, 0);
}
inline const COLORREF getBlue()
{
	return RGB(0, 0, 255);
}

inline const COLORREF getOrange()
{
	return RGB(255, 100, 0);
}

inline const COLORREF getCayan()
{
	return RGB(0, 255, 255);
}

inline const COLORREF getPink()
{
	return RGB(255, 190, 200);
}

inline const COLORREF getRed()
{
	return RGB(255, 0, 0);
}

inline const COLORREF getYellow()
{
	return RGB(255, 255, 0);
}

inline const COLORREF getWhite()
{
	return RGB(255, 255, 255);
}
#endif