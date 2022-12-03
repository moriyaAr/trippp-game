#include "Stone.h"

const sf::Vector2i SIZE = { 95,45 };
const sf::Vector2i CUR_START = { 600,WIN_Y };
const sf::Vector2f POSITION = { WIN_X,900 };
const sf::Vector2f ORIGEN = { 0,45 };

//ctor of stone
Stone::Stone() :Obsticles()
{
	init(SIZE, CUR_START, POSITION, ORIGEN, OBS_PIC);
}

// regist to Factory to Allow Factory to produce him
bool Stone::m_registerit = Factory::registerit(e_Stone,
	[]() -> std::unique_ptr<MovedObject> { return std::make_unique<Stone>(); });