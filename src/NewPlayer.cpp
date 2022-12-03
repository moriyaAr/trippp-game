#include "NewPlayer.h"

const sf::Vector2i SIZE = { 50,60 };
const sf::Vector2i CUR_START = { 950,1177 };
const sf::Vector2f ORIGEN = { 0,60 };

//-------------------------------------
//ctor of coin sak call to father Ctor
NewPlayer::NewPlayer() :Gift()
{
	init(SIZE, CUR_START, ORIGEN);
}

// regist to Factory to Allow Factory to produce him
bool NewPlayer::m_registerit = Factory::registerit(e_NewPlayer,
	[]() -> std::unique_ptr<MovedObject> { return std::make_unique<NewPlayer>(); });