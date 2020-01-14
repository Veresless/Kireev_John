#include <Windows.h>
#include "Field.h"

void Field::setSize()
{
	Horizontal_ = 28;
	Vertical_ = 36;
}
void Field::setSprites()
{
	COLORREF Red = RGB(255, 0, 0);
	COLORREF Blue = RGB(0, 0, 255);
	COLORREF Yellow = RGB(255, 255, 0);
	COLORREF White = RGB(255, 255, 255);
	COLORREF Black = RGB(0, 0, 0);

	Empty_.initializeSample(White, Black);
	WallVertical_.initializeSample(Blue, Black);
	WallHorizontal_.initializeSample(Blue, Black);
	WallLeftBottom_.initializeSample(Blue, Black);
	WallRightBottom_.initializeSample(Blue, Black);
	WallLeftTop_.initializeSample(Blue, Black);
	WallRightTop_.initializeSample(Blue, Black);
	Door_.initializeSample(Red, Black);
	PacMan_.initializeSample(Yellow, Black);
	normalCast();
	SchorePoint_.initializeSample(White, Black);
	Energiser_.initializeSample(White, Black);
}
void Field::normalCast()
{
	normalBlinky();
	normalPinky();
	normalInky();
	normalClyde();
	Mode_ = CastMode::Attack;
}
void Field::normalBlinky()
{
	COLORREF Black = RGB(0, 0, 0);
	COLORREF Red = RGB(255, 0, 0);
	Blinky_.initializeSample(Red, Black);
	Blinky_.changeMode(CastMode::Attack);
}
void Field::normalPinky()
{
	COLORREF Black = RGB(0, 0, 0);
	COLORREF Pink = RGB(255, 190, 200);
	Pinky_.initializeSample(Pink, Black);
	Pinky_.changeMode(CastMode::Attack);
}
void Field::normalInky()
{
	COLORREF Black = RGB(0, 0, 0);
	COLORREF Cayan = RGB(0, 255, 255);
	Inky_.initializeSample(Cayan, Black);
	Inky_.changeMode(CastMode::Attack);

}
void Field::normalClyde()
{
	COLORREF Black = RGB(0, 0, 0);
	COLORREF Orange = RGB(255, 100, 0);
	Clyde_.initializeSample(Orange, Black);
	Clyde_.changeMode(CastMode::Attack);
}
void Field::fearCast()
{
	COLORREF Black = RGB(0, 0, 0);
	COLORREF Blue = RGB(0, 0, 255);

	changeCastMode(CastMode::Fear);
	Blinky_.initializeSample(Blue, Black);
	Pinky_.initializeSample(Blue, Black);
	Inky_.initializeSample(Blue, Black);
	Clyde_.initializeSample(Blue, Black);
}
void Field::clearSprites()
{
	Empty_.clearSample();
	WallVertical_.clearSample();
	WallHorizontal_.clearSample();
	WallLeftBottom_.clearSample();
	WallRightBottom_.clearSample();
	WallLeftTop_.clearSample();
	WallRightTop_.clearSample();
	Door_.clearSample();
	PacMan_.clearSample();
	Blinky_.clearSample();
	Pinky_.clearSample();
	Inky_.clearSample();
	Clyde_.clearSample();
	SchorePoint_.clearSample();
	Energiser_.clearSample();
}
void Field::setStart()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < Horizontal_; j++)
			Level[i][j] = &Empty_;
	Level[3][0] = Level[3][14] = &WallRightBottom_;
	Level[3][Horizontal_ - 1] = Level[3][13] = &WallLeftBottom_;
	for (int i = 1; i < 13; i++) Level[3][i] = Level[3][Horizontal_ - 1 - i] = &WallHorizontal_;
	for (int i = 4; i < 12; i++) Level[i][0] = Level[i][Horizontal_ - 1] = &WallVertical_;
	for (int i = 1; i < 13; i++) Level[4][i] = Level[4][Horizontal_ - 1 - i] = &SchorePoint_;
	for (int i = 4; i < 7; i++) Level[i][13] = Level[i][14] = &WallVertical_;
	Level[5][1] = Level[5][6] = Level[5][12] = Level[5][Horizontal_ - 1 - 1] = Level[5][Horizontal_ - 1 - 6] = Level[5][Horizontal_ - 1 - 12] = &SchorePoint_;
	Level[5][2] = Level[5][7] =  Level[5][Horizontal_ - 1 - 5] = Level[5][Horizontal_ - 1 - 11] = &WallRightBottom_;
	Level[5][5] = Level[5][11] = Level[5][Horizontal_ - 1 - 2] = Level[5][Horizontal_ - 1 - 7] = &WallLeftBottom_;
	for (int i = 3; i < 5; i++) Level[5][i] = Level[5][Horizontal_ - 1 - i] = &WallHorizontal_;
	for (int i = 8; i < 11; i++)Level[5][i] = Level[5][Horizontal_ - 1 - i] = &WallHorizontal_;
	Level[6][6] = Level[6][12] = Level[6][Horizontal_ - 1 - 6] = Level[6][Horizontal_ - 1 - 12] = &SchorePoint_;
	Level[6][1] = Level[6][Horizontal_ - 1 - 1] = &Energiser_;
	Level[6][2] = Level[6][7] = Level[6][Horizontal_ - 1 - 5] = Level[6][Horizontal_ - 1 - 11] = Level[6][5] = Level[6][11] = Level[6][Horizontal_ - 1 - 2] = Level[6][Horizontal_ - 1 - 7] = &WallVertical_;
	for (int i = 3; i < 5; i++) Level[6][i] = Level[6][Horizontal_ - 1 - i] = &Empty_;
	for (int i = 8; i < 11; i++)Level[6][i] = Level[6][Horizontal_ - 1 - i] = &Empty_;
	Level[7][1] = Level[7][6] = Level[7][12] = Level[7][Horizontal_ - 1 - 1] = Level[7][Horizontal_ - 1 - 6] = Level[7][Horizontal_ - 1 - 12] = &SchorePoint_;
	Level[7][2] = Level[7][7] = Level[7][Horizontal_ - 1 - 5] = Level[7][Horizontal_ - 1 - 11] = Level[7][13] = &WallRightTop_;
	Level[7][5] = Level[7][11] = Level[7][Horizontal_ - 1 - 2] = Level[7][Horizontal_ - 1 - 7] = Level[7][14] = &WallLeftTop_;
	for (int i = 3; i < 5; i++) Level[7][i] = Level[7][Horizontal_ - 1 - i] = &WallHorizontal_;
	for (int i = 8; i < 11; i++)Level[7][i] = Level[7][Horizontal_ - 1 - i] = &WallHorizontal_;
	for (int i = 1; i < Horizontal_ - 1; i++) Level[8][i] = &SchorePoint_;
	Level[9][1] = Level[9][6] = Level[9][9] = Level[9][Horizontal_ - 1 - 1] = Level[9][Horizontal_ - 1 - 6] = Level[9][Horizontal_ - 1 - 9] = &SchorePoint_;
	Level[9][2] = Level[9][7] = Level[9][10] = Level[9][Horizontal_ - 1 - 5] = Level[9][Horizontal_ - 1 - 8] = &WallRightBottom_;
	Level[9][5] = Level[9][8] = Level[9][Horizontal_ - 1 - 10] = Level[9][Horizontal_ - 1 - 2] = Level[9][Horizontal_ - 1 - 7] = &WallLeftBottom_;
	Level[9][3] = Level[9][4] = Level[9][11] = Level[9][12] = Level[9][13] = Level[9][Horizontal_ - 1 - 3] = Level[9][Horizontal_ - 1 - 4] = Level[9][Horizontal_ - 1 - 11] = Level[9][Horizontal_ - 1 - 12] = Level[9][Horizontal_ - 1 - 13] = &WallHorizontal_;
	Level[10][1] = Level[10][6] = Level[10][9] = Level[10][Horizontal_ - 1 - 1] = Level[10][Horizontal_ - 1 - 6] = Level[10][Horizontal_ - 1 - 9] = &SchorePoint_;
	Level[10][2] = Level[10][10] = Level[10][Horizontal_ - 1 - 5] = &WallRightTop_;
	Level[10][5] = Level[10][Horizontal_ - 1 - 10] = Level[10][Horizontal_ - 1 - 2] = &WallLeftTop_;
	Level[10][3] = Level[10][4] = Level[10][11] = Level[10][12] = Level[10][Horizontal_ - 1 - 3] = Level[10][Horizontal_ - 1 - 4] = Level[10][Horizontal_ - 1 - 11] = Level[10][Horizontal_ - 1 - 12] = &WallHorizontal_;
	Level[10][7] = Level[10][8] = Level[10][Horizontal_ - 1 - 7] = Level[10][Horizontal_ - 1 - 8] = &WallVertical_;
	Level[10][13] = &WallLeftBottom_;  Level[10][14] = &WallRightBottom_;
	for (int i = 1; i < 7; i++) Level[11][i] = Level[11][Horizontal_ - 1 - i] = &SchorePoint_;
	for (int i = 9; i < 13; i++) Level[11][i] = Level[11][Horizontal_ - 1 - i] = &SchorePoint_;
	Level[11][7] = Level[11][8] = Level[11][13] = Level[11][Horizontal_ - 1 - 7] = Level[11][Horizontal_ - 1 - 8] = Level[11][Horizontal_ - 1 - 13] = &WallVertical_;
	Level[12][0] = Level[12][8] = &WallRightTop_;
	Level[12][Horizontal_ - 1] = Level[12][Horizontal_ - 1 - 8] = &WallLeftTop_;
	Level[12][5] = Level[12][11] = &WallLeftBottom_;
	Level[12][Horizontal_ - 1 - 5] = Level[12][Horizontal_ - 1 - 11] = &WallRightBottom_;
	for (int i = 1; i < 5; i++) Level[12][i] = Level[12][Horizontal_ - 1 - i] = &WallHorizontal_;
	for (int i = 9; i < 11; i++) Level[12][i] = Level[12][Horizontal_ - 1 - i] = &WallHorizontal_;
	Level[12][7] = Level[12][13] = Level[12][Horizontal_ - 1 - 7] = Level[12][Horizontal_ - 1 - 13] = &WallVertical_;
	Level[12][6] = Level[12][Horizontal_ - 1 - 6] = &SchorePoint_;
	Level[12][12] = Level[12][Horizontal_ - 1 - 12] = &Empty_;
	Level[13][8] = &WallRightBottom_;
	Level[13][Horizontal_ - 1 - 8] = &WallLeftBottom_;
	Level[13][11] = Level[13][14] = &WallLeftTop_;
	Level[13][Horizontal_ - 1 - 11] = Level[13][13] = &WallRightTop_;
	for (int i = 0; i < 5; i++) Level[13][i] = Level[13][Horizontal_ - 1 - i] = &Empty_;
	for (int i = 9; i < 11; i++) Level[13][i] = Level[13][Horizontal_ - 1 - i] = &WallHorizontal_;
	Level[13][5] = Level[13][7] = Level[13][Horizontal_ - 1 - 5] = Level[13][Horizontal_ - 1 - 7] = &WallVertical_;
	Level[13][6] = Level[13][Horizontal_ - 1 - 6] = &SchorePoint_;
	Level[13][12] = Level[13][Horizontal_ - 1 - 12] = &Empty_;
	for (int i = 0; i < 5; i++) Level[14][i] = Level[14][Horizontal_ - 1 - i] = &Empty_;
	for (int i = 9; i < 14; i++) Level[14][i] = Level[14][Horizontal_ - 1 - i] = &Empty_;
	Level[14][5] = Level[14][7] = Level[14][8] = Level[14][Horizontal_ - 1 - 5] = Level[14][Horizontal_ - 1 - 7] = Level[14][Horizontal_ - 1 - 8] = &WallVertical_;
	Level[14][6] = Level[14][Horizontal_ - 1 - 6] = &SchorePoint_;
	for (int i = 0; i < 5; i++) Level[15][i] = Level[15][Horizontal_ - 1 - i] = &Empty_;
	Level[15][9] = Level[15][Horizontal_ - 10] = &Empty_;
	Level[15][5] = Level[15][7] = Level[15][8] = Level[15][Horizontal_ - 1 - 5] = Level[15][Horizontal_ - 1 - 7] = Level[15][Horizontal_ - 1 - 8] = &WallVertical_;
	Level[15][6] = Level[15][Horizontal_ - 1 - 6] = &SchorePoint_;
	Level[15][10] = &WallRightBottom_;
	Level[15] [Horizontal_ - 1 - 10]= &WallLeftBottom_;
	for (int i = 11; i < 13; i++) Level[15][i] = Level[15][Horizontal_ - 1 - i] = &WallHorizontal_;
	Level[15][13] = Level[15][14] = &Door_;
	for (int i = 0; i < 5; i++) Level[16][i] = Level[16][Horizontal_ - 1 - i] = &WallHorizontal_;
	Level[16][6] = Level[16][Horizontal_ - 1 - 6] = &SchorePoint_;
	Level[16][9] = Level[16][Horizontal_ - 10] = &Empty_;
	Level[16][5] = Level[16][8] = Level[16][20] = &WallLeftTop_;
	Level[16][Horizontal_ - 1 - 5] = Level[16][Horizontal_ - 1 - 8] = Level[16][Horizontal_ - 1 - 20] = &WallRightTop_;
	Level[16][10] = Level[16][Horizontal_ - 1 - 10] = &WallVertical_;
	for (int i = 11; i < 17; i++) Level[16][i] = &Empty_;
	for (int i = 0; i < Horizontal_; i++) Level[17][i] = &Empty_;
	Level[17][6] = Level[17][Horizontal_ - 1 - 6] = &SchorePoint_;
	Level[17][10] = Level[17][Horizontal_ - 1 - 10] = &WallVertical_;
	for (int i = 0; i < 5; i++) Level[18][i] = Level[18][Horizontal_ - 1 - i] = &WallHorizontal_;
	Level[18][6] = Level[18][Horizontal_ - 1 - 6] = &SchorePoint_;
	Level[18][9] = Level[18][Horizontal_ - 10] = &Empty_;
	Level[18][5] = Level[18][8] = Level[18][20] = &WallLeftBottom_;
	Level[18][Horizontal_ - 1 - 5] = Level[18][Horizontal_ - 1 - 8] = Level[18][Horizontal_ - 1 - 20] = &WallRightBottom_;
	Level[18][10] = Level[18][Horizontal_ - 1 - 10] = &WallVertical_;
	for (int i = 11; i < 17; i++) Level[18][i] = &Empty_;
	for (int i = 0; i < 5; i++) Level[19][i] = Level[19][Horizontal_ - 1 - i] = &Empty_;
	Level[19][9] = Level[19][Horizontal_ - 10] = &Empty_;
	Level[19][5] = Level[19][7] = Level[19][8] = Level[19][Horizontal_ - 1 - 5] = Level[19][Horizontal_ - 1 - 7] = Level[19][Horizontal_ - 1 - 8] = &WallVertical_;
	Level[19][6] = Level[19][Horizontal_ - 1 - 6] = &SchorePoint_;
	Level[19][10] = &WallRightTop_;
	Level[19][Horizontal_ - 1 - 10] = &WallLeftTop_;
	for (int i = 11; i < 14; i++) Level[19][i] = Level[19][Horizontal_ - 1 - i] = &WallHorizontal_;
	for (int i = 0; i < Horizontal_; i++) Level[21][i] = Level[20][i] = Level[14][i];
	for (int i = 11; i < 17; i++) Level[21][i] = &WallHorizontal_;
	Level[21][10] = &WallRightBottom_; Level[21][17] = &WallLeftBottom_; 
	Level[22][0] = &WallRightBottom_; Level[22][Horizontal_ - 1] = &WallLeftBottom_;
	for (int i = 1; i < Horizontal_ - 1; i++) Level[22][i] = Level[16][i];
	for (int i = 10; i < 18; i++) Level[22][i] = Level[10][i];
	for (int i = 0; i < Horizontal_; i++) Level[23][i] = Level[4][i];
	for (int i = 0; i < Horizontal_; i++) Level[24][i] = Level[5][i];
	for (int i = 0; i < Horizontal_; i++) Level[25][i] = Level[7][i];
	Level[25][5] = Level[25][Horizontal_ - 1 - 5] = &WallVertical_;
	Level[25][4] = &WallLeftBottom_; Level[25][23] = &WallRightBottom_;
	for (int i = 0; i < Horizontal_; i++) Level[26][i] = Level[8][i];
	Level[26][13] = Level[26][14] = &Empty_;
	Level[26][1] = Level[26][26] = &Energiser_;
	Level[26][4] = Level[26][5] = Level[26][Horizontal_ - 1 - 4] = Level[26][Horizontal_ - 1 - 5] = &WallVertical_;
	for (int i = 3; i < Horizontal_-3; i++) Level[27][i] = Level[26][i];
	for (int i = 7; i < 21; i++) Level[27][i] = Level[9][i];
	Level[27][0] = &WallRightTop_; Level[27][Horizontal_ - 1] = &WallLeftTop_;
	Level[27][2] = &WallLeftBottom_; Level[27][Horizontal_ - 3] = &WallRightBottom_;
	Level[27][1] = Level[27][Horizontal_ - 2] = &WallHorizontal_;
	for (int i = 5; i < Horizontal_ - 5; i++) Level[28][i] = Level[10][i];
	Level[28][0] = &WallRightBottom_; Level[28][Horizontal_ - 1] = &WallLeftBottom_;
	Level[28][2] = &WallLeftTop_; Level[28][Horizontal_ - 3] = &WallRightTop_;
	Level[28][1] = Level[28][Horizontal_ - 2] = &WallHorizontal_;
	Level[28][3] = Level[28][Horizontal_ - 4] = &SchorePoint_;
	Level[28][4] = &WallRightTop_; Level[28][Horizontal_ - 5] = &WallLeftTop_;
	for (int i = 0; i < Horizontal_; i++) Level[29][i] = Level[11][i];
	for (int i = 8; i < Horizontal_-8; i++) Level[30][i] = Level[12][i];
	for (int i = 0; i < 4; i++) Level[30][i] = Level[9][i];
	for (int i = Horizontal_ - 5; i < Horizontal_; i++) Level[30][i] = Level[9][i];
	for (int i = 4; i < 7; i++) Level[30][i] = Level[30][Horizontal_ - 1 - i] = &WallHorizontal_;
	Level[30][7] = &WallLeftTop_; Level[30][Horizontal_ - 8] = &WallRightTop_;
	Level[30][12] = Level[30][Horizontal_ - 13] = &SchorePoint_;
	for (int i = 0; i < Horizontal_; i++) Level[31][i] = Level[7][i];
	for (int i = 5; i < 8; i++) Level[31][i] = Level[31][Horizontal_ - 1 - i] = &WallHorizontal_;
	for (int i = 0; i < Horizontal_; i++) Level[32][i] = Level[8][i];
	for (int i = 1; i < Horizontal_-1; i++) Level[33][i] = Level[3][i];
	Level[33][0] = &WallRightTop_; Level[33][Horizontal_ - 1] = &WallLeftTop_;
	Level[33][13] = Level[33][14] = &WallHorizontal_;
	for (int i = 34; i < Vertical_; i++)
		for (int j = 0; j < Horizontal_; j++)
			Level[i][j] = &Empty_;
}
void Field::printAll()
{
	for (int i = 0; i < Vertical_; i++)
		for (int j = 0; j < Horizontal_; j++)
			Level[i][j]->printOn(j, i, Hdc_);
	PacMan_.print(Horizontal_, Vertical_, Hdc_);
	Blinky_.print(Horizontal_, Vertical_, Hdc_);
	Pinky_.print(Horizontal_, Vertical_, Hdc_);
	Inky_.print(Horizontal_, Vertical_, Hdc_);
	Clyde_.print(Horizontal_, Vertical_, Hdc_);
}
void Field::resetDinamic()
{
	std::pair<int, int> PositionPacMan = PacMan_.getPoint(), PositionBlinky = Blinky_.DinamicSprite::getPoint(), PositionPinky = Pinky_.DinamicSprite::getPoint(), PositionInky = Inky_.DinamicSprite::getPoint(), PositionClyde = Clyde_.DinamicSprite::getPoint();
	int SizePacMan = PacMan_.getSize(), SizeBlinky = Blinky_.getSize(), SizePinky = Pinky_.getSize(), SizeInky = Inky_.getSize(), SizeClyde = Clyde_.getSize();
	
	eraseDinamic(&PacMan_, PositionPacMan, SizePacMan);
	eraseDinamic(&Blinky_, PositionBlinky, SizeBlinky);
	eraseDinamic(&Pinky_, PositionPinky, SizePinky);
	eraseDinamic(&Inky_, PositionInky, SizeInky);
	eraseDinamic(&Clyde_, PositionClyde, SizeClyde);

	PacMan_.setStartPosition();
	Blinky_.setStartPosition();
	Pinky_.setStartPosition();
	Inky_.setStartPosition();
	Clyde_.setStartPosition();

	PacMan_.print(Horizontal_, Vertical_, Hdc_);
	Blinky_.print(Horizontal_, Vertical_, Hdc_);
	Pinky_.print(Horizontal_, Vertical_, Hdc_);
	Inky_.print(Horizontal_, Vertical_, Hdc_);
	Clyde_.print(Horizontal_, Vertical_, Hdc_);
}
void Field::resetLevel()
{
	setStart();
	resetDinamic();
	printAll();
}
void Field::eraseDinamic(DinamicSprite *Sprite, std::pair<int, int> Point, int Size)
{
	int XFirst = Point.first / Size;
	int XSecond = XFirst + ((Point.first % Size != 0) ? 1 : 0);
	XSecond %= Horizontal_;
	int YFirst = Point.second / Size;
	int YSecond = YFirst + ((Point.second % Size != 0) ? 1 : 0);
	YSecond %= Vertical_;
	for (int i = YFirst; i <= YSecond; i++)
	{
		if (XFirst != XSecond)
		{
			Level[i][XFirst]->printOn(XFirst, i, Hdc_);
			Level[i][XSecond]->printOn(XSecond, i, Hdc_);
		}
		else 
			Level[i][XFirst]->printOn(XFirst, i, Hdc_);
	}
}
PacMan* Field::getPacMan()
{
	return &PacMan_;
}
Blinky* Field::getBlinky()
{
	return &Blinky_;
}
Pinky* Field::getPinky()
{
	return &Pinky_;
}
Inky* Field::getInky()
{
	return &Inky_;
}
Clyde* Field::getClyde()
{
	return &Clyde_;
}
void Field::setBlinky()
{
	Blinky_.preparePosition();
	BlinkyReady_ = true;
}
void Field::setPinky()
{
	std::pair<int, int> Point = Pinky_.DinamicSprite::getPoint();
	int Size = Pinky_.getSize();
	eraseDinamic(&Pinky_, Point, Size);
	Pinky_.preparePosition();
	PinkyReady_ = true;
}
void Field::setInky()
{
	std::pair<int, int> Point = Inky_.DinamicSprite::getPoint();
	int Size = Inky_.getSize();
	eraseDinamic(&Inky_, Point, Size);
	Inky_.preparePosition();
	InkyReady_ = true;
}
void Field::setClyde()
{
	std::pair<int, int> Point = Clyde_.DinamicSprite::getPoint();
	int Size = Clyde_.getSize();
	eraseDinamic(&Clyde_, Point, Size);
	Clyde_.preparePosition();
	ClydeReady_ = true;
}
bool Field::isEmpty(std::pair<int, int> Position, int Direction, int Size)
{
	int Y = Position.second / Size;
	int X = Position.first / Size;
	switch (Direction)
	{
	case 0:
	{
		Y += ((Position.second % Size != 0) ? 0 : - 1) + Vertical_;
		Y %= Vertical_;
		SpriteType Type = Level[Y][X]->getType();
		return ((Position.first % Size == 0 && (Type == SpriteType::TEmpty || Type == SpriteType::TSchorePoint || Type == SpriteType::TEnergiser)) ? true : false);
	}
	case 3:
	{
		X += 1;
		X %= Horizontal_;
		SpriteType Type = Level[Y][X]->getType();
		return ((Position.second % Size == 0 && (Type == SpriteType::TEmpty || Type == SpriteType::TSchorePoint || Type == SpriteType::TEnergiser)) ? true : false);
	}
	case 2:
	{
		Y += 1;
		Y %= Vertical_;
		SpriteType Type = Level[Y][X]->getType();
		return ((Position.first % Size == 0 && (Type == SpriteType::TEmpty || Type == SpriteType::TSchorePoint || Type == SpriteType::TEnergiser)) ? true : false);
	}
	case 1:
	{
		X += ((Position.first % Size != 0) ? 0 : -1) + Horizontal_;
		X %= Horizontal_;
		SpriteType Type = Level[Y][X]->getType();
		return ((Position.second % Size == 0 && (Type == SpriteType::TEmpty || Type == SpriteType::TSchorePoint || Type == SpriteType::TEnergiser)) ? true : false);
	}
	default:
		return false;
	}
}
void Field::getPositionDirectionSize(DinamicSprite* Sprite, std::pair<int, int>& Position, int& Direction, int& Size)
{
	Position = Sprite->getPoint();
	Direction = Sprite->getDirection();
	Size = Sprite->getSize();
}
void Field::moveDinamic(DinamicSprite* Sprite, std::pair<int, int> Position, int Direction, int Size)
{
	if (isEmpty(Position, Direction, Size))
	{
		Sprite->changePosition(Horizontal_, Vertical_);
		Sprite->print(Horizontal_, Vertical_, Hdc_);
	}
}
void Field::moveAllDinamic()
{
	std::pair<int, int> PositionPacMan, PositionBlinky, PositionPinky, PositionInky, PositionClyde;
	int DirectionPacMan, DirectionBlinky, DirectionPinky, DirectionInky, DirectionClyde;
	int SizePacMan, SizeBlinky, SizePinky, SizeInky, SizeClyde;
	bool IsUpdatePacMan, IsUpdateBlinky, IsUpdatePinky, IsUpdateInky, IsUpdateClyde;
	getPositionDirectionSize(&PacMan_, PositionPacMan, DirectionPacMan, SizePacMan);
	IsUpdatePacMan = isEmpty(PositionPacMan, DirectionPacMan, SizePacMan);
	getPositionDirectionSize(&Blinky_, PositionBlinky, DirectionBlinky, SizeBlinky);
	IsUpdateBlinky = isEmpty(PositionBlinky, DirectionBlinky, SizeBlinky);
	getPositionDirectionSize(&Pinky_, PositionPinky, DirectionPinky, SizePinky);
	IsUpdatePinky = isEmpty(PositionPinky, DirectionPinky, SizePinky);
	getPositionDirectionSize(&Inky_, PositionInky, DirectionInky, SizeInky);
	IsUpdateInky = isEmpty(PositionInky, DirectionInky, SizeInky);
	getPositionDirectionSize(&Clyde_, PositionClyde, DirectionClyde, SizeClyde);
	IsUpdateClyde = isEmpty(PositionClyde, DirectionClyde, SizeClyde);
	
	if (IsUpdatePacMan) eraseDinamic(&PacMan_, PositionPacMan, SizePacMan);
	if (IsUpdateBlinky) eraseDinamic(&Blinky_, PositionBlinky, SizeBlinky);
	if (IsUpdatePinky) eraseDinamic(&Pinky_, PositionPinky, SizePinky);
	if (IsUpdateInky) eraseDinamic(&Inky_, PositionInky, SizeInky);
	if (IsUpdateClyde) eraseDinamic(&Clyde_, PositionClyde, SizeClyde);
	if (IsUpdatePacMan) moveDinamic(&PacMan_, PositionPacMan, DirectionPacMan, SizePacMan);
	if (IsUpdateBlinky) moveDinamic(&Blinky_, PositionBlinky, DirectionBlinky, SizeBlinky);
	if (IsUpdatePinky) moveDinamic(&Pinky_, PositionPinky, DirectionPinky, SizePinky);
	if (IsUpdateInky) moveDinamic(&Inky_, PositionInky, DirectionInky, SizeInky);
	if (IsUpdateClyde) moveDinamic(&Clyde_, PositionClyde, DirectionClyde, SizeClyde);
}
void Field::turnDinamic(DinamicSprite* Sprite, int Direction)
{
	std::pair<int, int> Position = Sprite->getPoint();
	int Size = Sprite->getSize();
	if (isEmpty(Position, Direction, Size)) Sprite->changeDirection(Direction);
}
bool Field::checkSpecial(int x, int y)
{
	return (y == 14) && (x == 12) || (y == 14) && (x == 15) || (y == 26) && (x == 12) || (y == 26) && (x == 15);
}
void Field::castMovement()
{
	if (BlinkyReady_)
	{
		std::pair<int, int> Position = Blinky_.DinamicSprite::getPoint();
		int Size = Blinky_.getSize();
		if (Position.first % Size == 0 && Position.second % Size == 0)
		{
			int Direction = Blinky_.getDirection();
			if (!isEmpty(Position, Direction, Size) || isEmpty(Position, (Direction - 1 + 4) % 4, Size) || isEmpty(Position, (Direction + 1) % 4, Size))
			{
				bool Ways[4];
				for (int i = 0; i < 4; i++) Ways[i] = isEmpty(Position, i, Size);
				if (Blinky_.getMode() == 0) Blinky_.setDirectionPoint(PacMan_.getPoint());
				if (checkSpecial(Position.first / Size, Position.second / Size)) Ways[0] = false;
				Blinky_.choiseDirection(Ways);
			}
		}
	}
	if (PinkyReady_)
	{
		std::pair<int, int> Position = Pinky_.DinamicSprite::getPoint();
		int Size = Pinky_.getSize();
		if (Position.first % Size == 0 && Position.second % Size == 0)
		{
			int Direction = Pinky_.getDirection();
			if (!isEmpty(Position, Direction, Size) || isEmpty(Position, (Direction - 1 + 4) % 4, Size) || isEmpty(Position, (Direction + 1) % 4, Size))
			{
				bool Ways[4];
				for (int i = 0; i < 4; i++) Ways[i] = isEmpty(Position, i, Size);
				if (Pinky_.getMode() == 0) Pinky_.setDirectionPoint(PacMan_.getPoint(), Direction);
				if (checkSpecial(Position.first / Size, Position.second / Size)) Ways[0] = false;
				Pinky_.choiseDirection(Ways);
			}
		}
	}
	if (InkyReady_)
	{
		std::pair<int, int> Position = Inky_.DinamicSprite::getPoint();
		int Size = Inky_.getSize();
		if (Position.first % Size == 0 && Position.second % Size == 0)
		{
			int Direction = Inky_.getDirection();
			if (!isEmpty(Position, Direction, Size) || isEmpty(Position, (Direction - 1 + 4) % 4, Size) || isEmpty(Position, (Direction + 1) % 4, Size))
			{
				bool Ways[4];
				for (int i = 0; i < 4; i++) Ways[i] = isEmpty(Position, i, Size);
				if (Inky_.getMode() == 0) Inky_.setDirectionPoint(PacMan_.getPoint(), Direction, Blinky_.DinamicSprite::getPoint());
				if (checkSpecial(Position.first / Size, Position.second / Size)) Ways[0] = false;
				Inky_.choiseDirection(Ways);
			}
		}
	}
	if (ClydeReady_)
	{
		std::pair<int, int> Position = Clyde_.DinamicSprite::getPoint();
		int Size = Clyde_.getSize();
		if (Position.first % Size == 0 && Position.second % Size == 0)
		{
			int Direction = Clyde_.getDirection();
			if (!isEmpty(Position, Direction, Size) || isEmpty(Position, (Direction - 1 + 4) % 4, Size) || isEmpty(Position, (Direction + 1) % 4, Size))
			{
				bool Ways[4];
				for (int i = 0; i < 4; i++) Ways[i] = isEmpty(Position, i, Size);
				if (Clyde_.getMode() == 0) Clyde_.setDirectionPoint(PacMan_.getPoint());
				if (checkSpecial(Position.first / Size, Position.second / Size)) Ways[0] = false;
				Clyde_.choiseDirection(Ways);
			}
		}
	}
}
void Field::changeCastMode(CastMode Mode)
{
	Mode_ = Mode;
	Blinky_.changeMode(Mode);
	Pinky_.changeMode(Mode);
	Inky_.changeMode(Mode);
	Clyde_.changeMode(Mode);
}
CastMode Field::getCastMode()
{
	return Mode_;
}
Field::Field()
{
	setSize();
	Hwnd_ = GetConsoleWindow();
	Hdc_ = GetDC(Hwnd_);
	setSprites();
	Level = new StaticSprite** [Vertical_];
	for (int i = 0; i < Vertical_; i++) Level[i] = new StaticSprite*[Horizontal_];
	setStart();
	BlinkyReady_ = PinkyReady_ = InkyReady_ = ClydeReady_ = false;
	Mode_ = CastMode::Attack;
}
SpriteType Field::getSpriteTypeAt(int x, int y)
{
	return Level[y][x]->getType();
}
void Field::setEmptyAt(int x, int y)
{
	Level[y][x] = &Empty_;
}
void Field::clear()
{
	clearSprites();
	for (int i = 0; i < Vertical_; i++)
	{
		delete [] Level[i];
	}
	delete[] Level;
	ReleaseDC(Hwnd_, Hdc_);
}