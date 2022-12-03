#include "Gift.h"

//Ctor calling to fater Ctor
Gift::Gift():MovedObject(){}

// the func init gift varaible
void Gift::init(const sf::Vector2i size, const sf::Vector2i currentStart, const sf::Vector2f origin)
{
	float y = rand() % LOT_RANGE + LOT_BASIC;
	RectPic::init(size, currentStart, { WIN_X,y }, origin, OBS_PIC);
}
