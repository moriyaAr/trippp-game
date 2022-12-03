#include "BackButton.h"
#include <Helper.h>

const sf::Vector2i SIZE = { 117,117 };
const sf::Vector2i CUR_START = { 917,WIN_Y };
const sf::Vector2f POSITION = { 20,140 };
const sf::Vector2f ORIGEN = { 0,0 };
//------------------------------
//ctor
BackButton::BackButton()
{
	init(SIZE, CUR_START, POSITION, ORIGEN, OBS_PIC);
}