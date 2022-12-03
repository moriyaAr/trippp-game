#include "BrokenRoad.h"

const sf::Vector2i SIZE = { 340,253 };
const sf::Vector2i CUR_START= { 1434,WIN_Y };
const sf::Vector2f POSITION = { WIN_X,WIN_Y };
const sf::Vector2f ORIGEN = { 0,253 };

//ctor of broken road
BrokenRoad::BrokenRoad() :Obsticles()
{
	init(SIZE, CUR_START, POSITION, ORIGEN, OBS_PIC);
}

// regist to Factory to Allow Factory to produce him
bool BrokenRoad::m_registerit = Factory::registerit(e_BrokenRoad,
	[]() -> std::unique_ptr<MovedObject> { return std::make_unique<BrokenRoad>(); });