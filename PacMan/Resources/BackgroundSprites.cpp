#include "BackgroundSprites.h"

 void Empty::setDefaultType()
{
	 Type_ = SpriteType::TEmpty;
}
 void Empty::initializeSample(COLORREF Color, COLORREF Background)
 {
	 for (int i = 0; i < Size_; i++)
	 {
		 for (int j = 0; j < Size_; j++)
			 Sample_[i][j] = Background;
	 }
 } Empty::Empty()
 {
	 setDefaultType();
 }
 void WallHorizontal::setDefaultType()
 {
	 Type_ = SpriteType::TWall;
 }
 void WallHorizontal::initializeSample(COLORREF Color, COLORREF Background)
 {
	 for (int i = 0; i < Size_; i++)
	 {
		 for (int j = 0; j < Size_; j++)
		 {
			 Sample_[i][j] = ((i <= Size_ / 2 && i >= Size_ / 2 - 1) ? Color : Background);
		 }
	 }
 }
 WallHorizontal::WallHorizontal()
 {
	 setDefaultType();
 }
 void WallVertical::setDefaultType()
 {
	 Type_ = SpriteType::TWall;
 }
 void WallVertical::initializeSample(COLORREF Color, COLORREF Background)
 {
	 for (int i = 0; i < Size_; i++)
	 {
		 for (int j = 0; j < Size_; j++)
		 {
			 Sample_[i][j] = ((j <= Size_ / 2 && j >= Size_ / 2 - 1) ? Color : Background);
		 }
	 }
 }
 WallVertical:: WallVertical()
 {
	 setDefaultType();
 }
 void WallLeftBottom::setDefaultType()
 {
	 Type_ = SpriteType::TWall;
 }
 void WallLeftBottom::initializeSample(COLORREF Color, COLORREF Background)
 {
	 for (int i = 0; i < Size_; i++)
	 {
		 for (int j = 0; j < Size_; j++)
		 {
			 Sample_[i][j] = (((i <= Size_ / 2 && i >= Size_ / 2 - 1 && j <= Size_ / 2)
				 ||
				 (j <= Size_ / 2 && j >= Size_ / 2 - 1 && i >= Size_ / 2)) ?
				 Color : Background);
		 }
	 }
 }
WallLeftBottom::WallLeftBottom()
{
	setDefaultType();
}
 void WallRightBottom::setDefaultType()
 {
	 Type_ = SpriteType::TWall;
 }
 void WallRightBottom::initializeSample(COLORREF Color, COLORREF Background)
 {
	 for (int i = 0; i < Size_; i++)
	 {
		 for (int j = 0; j < Size_; j++)
		 {
			 Sample_[i][j] = (((i <= Size_ / 2 && i >= Size_ / 2 - 1 && j >= Size_ / 2)
				 ||
				 (j <= Size_ / 2 && j >= Size_ / 2 - 1 && i >= Size_ / 2)) ?
				 Color : Background);
		 }
	 }
 }
WallRightBottom::WallRightBottom()
{
	setDefaultType();
}
 void WallLeftTop::setDefaultType()
 {
	 Type_ = SpriteType::TWall;
 }
 void WallLeftTop::initializeSample(COLORREF Color, COLORREF Background)
 {
	 for (int i = 0; i < Size_; i++)
	 {
		 for (int j = 0; j < Size_; j++)
		 {
			 Sample_[i][j] = (((i <= Size_ / 2 && i >= Size_ / 2 - 1 && j <= Size_ / 2)
				 ||
				 (j <= Size_ / 2 && j >= Size_ / 2 - 1 && i <= Size_ / 2)) ?
				 Color : Background);
		 }
	 }
 }
WallLeftTop::WallLeftTop()
{
	setDefaultType();
}
 void WallRightTop::setDefaultType()
 {
	 Type_ = SpriteType::TWall;
 }
 void WallRightTop::initializeSample(COLORREF Color, COLORREF Background)
 {
	 for (int i = 0; i < Size_; i++)
	 {
		 for (int j = 0; j < Size_; j++)
		 {
			 Sample_[i][j] = (((i <= Size_ / 2 && i >= Size_ / 2 - 1 && j >= Size_ / 2)
				 ||
				 (j <= Size_ / 2 && j >= Size_ / 2 - 1 && i <= Size_ / 2)) ?
				 Color : Background);
		 }
	 }
 }
WallRightTop::WallRightTop()
{
	 setDefaultType();
 }
 void Door::setDefaultType()
 {
	 Type_ = SpriteType::TDoor;
 }
 void Door::initializeSample(COLORREF Color, COLORREF Background)
 {
	 for (int i = 0; i < Size_; i++)
	 {
		 for (int j = 0; j < Size_; j++)
		 {
			 Sample_[i][j] = ((i <= Size_ / 2 && i >= Size_ / 2 - 1) ? Color : Background);
		 }
	 }
 }
Door::Door()
{
	setDefaultType();
}
 void SchorePoint::setDefaultType()
 {
	 Type_ = SpriteType::TSchorePoint;
 }
 void SchorePoint::initializeSample(COLORREF Color, COLORREF Background)
 {
	 for (int i = 0; i < Size_; i++)
	 {
		 for (int j = 0; j < Size_; j++)
			 Sample_[i][j] = ((
			 (i <= Size_ / 2 && i >= Size_ / 2 - 1)
			&&
			 (j <= Size_ / 2 && j >= Size_ / 2 - 1)
				 ) ? Color : Background);
	 }
 }
SchorePoint::SchorePoint()
{
	setDefaultType();
}
 void Energiser::setDefaultType()
 {
	 Type_ = SpriteType::TEnergiser;
 }
 void Energiser::initializeSample(COLORREF Color, COLORREF Background)
 {
	 for (int i = 0; i < Size_; i++)
	 {
		 for (int j = 0; j < Size_; j++)
			 Sample_[i][j] = ((
			 (i <= Size_ / 2 + 1 && i >= Size_ / 2 - 2)
				 &&
				 (j <= Size_ / 2 + 1 && j >= Size_ / 2 - 2)
				 ) ? Color : Background);
	 }
 }
Energiser::Energiser()
{
	setDefaultType();
}