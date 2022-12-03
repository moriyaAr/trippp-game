#include "Background.h"

const int NUM_OF_LAYER = 4;
const int RATE_DIFF = 2;
//----------------------------
// the func initialise the game background
// no return value no prameters
//------------------------------
void Background::init()
{
	m_pics.resize(N_OF_BACK_PICS);
	for (int i = 0; i < N_OF_BACK_PICS;i++)
		m_pics[i].init(i);
}
//------------------------------

// the func move all the background
// no return value no prameters
void Background::move()
{
	//each layer in diffrent rate
	for (int i = 1, j = NUM_OF_LAYER* RATE_DIFF; i <= NUM_OF_LAYER; i++, j /= RATE_DIFF)
		moveEach(i, -(Resources::resources().MOVE_RATE / j));
}
//------------------------------

//the func draw the backg
// no return value no prameters
void Background::draw() const
{
	for (int i = 0; i < m_pics.size();i++)
		Resources::resources().getWin().draw(m_pics[i]);
}

// the func decided about the next place of each layer in the backg
void Background::moveEach(int i, int move_rate)
{
	if (m_pics[i].getPosition().x <= -(m_pics[i].getGlobalBounds().width-WIN_X- move_rate))
		m_pics[i].setPosition(0, WIN_Y);
	else
		m_pics[i].move(move_rate, 0);
}