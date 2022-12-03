#include "coinSak.h"

const sf::Vector2i SIZE = { 43,60 };
const sf::Vector2i CUR_START = { 1034,1120 };
const sf::Vector2f ORIGEN = { 0,60 };

//-------------------------------------
//ctor of coin sak call to father Ctor
coinSak::coinSak():Gift()
{
	init(SIZE, CUR_START, ORIGEN);
}

// regist to Factory to Allow Factory to produce him
bool coinSak::m_registerit = Factory::registerit(e_CoinSak,
	[]() -> std::unique_ptr<MovedObject> { return std::make_unique<coinSak>(); });