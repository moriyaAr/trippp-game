#include "PlayButton.h"

const sf::Vector2i SIZE = { 200,200 };
const sf::Vector2i CUR_START = { 717,WIN_Y };
const sf::Vector2f POSITION = { WIN_X / 2,WIN_Y / 2 };
const sf::Vector2f ORIGEN = { 100,100 };

//------------------------------
//Ctor
PlayButton::PlayButton(InformationDisplay* info)
{
	m_inform = info;
	init(SIZE, CUR_START, POSITION, ORIGEN, OBS_PIC);
}
//------------------------------
// the func run the butten job
void PlayButton::execute()
{
	Level level;
	level.init(m_inform);
	level.run();
}