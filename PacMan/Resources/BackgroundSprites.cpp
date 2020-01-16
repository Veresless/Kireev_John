#include "BackgroundSprites.h"


 void Empty::setDefaultType()
{
	 type_ = SpriteType::EMPTY;
}
 Empty::Empty()
 {
	 setDefaultType();
 }
 void Wall::setDefaultType()
 {
	 type_ = SpriteType::WALL;
 }
 Wall::Wall()
 {
	 setDefaultType();
 }
 void SchorePoint::setDefaultType()
 {
	 type_ = SpriteType::SHOREPOINT;
 }
 SchorePoint::SchorePoint()
 {
	 setDefaultType();
 }
 void Energiser::setDefaultType()
 {
	 type_ = SpriteType::ENERGISER;
 }
 Energiser::Energiser()
 {
	 setDefaultType();
 }
