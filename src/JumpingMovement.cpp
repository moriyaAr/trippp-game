#include "JumpingMovement.h"

const float JUMP_RATE = 4;
const float RECESSION = 2;
const float EXTRIM_POINT = 0.4;

//move Ctor (becouse we have uniq_ptr in uniq_ptr) calling father move ctor
JumpingMovement::JumpingMovement(JumpingMovement && other):MoveStrategy(std::move(other)){}

//the func update the next step of jump movment
void JumpingMovement::execute(sf::Sprite* pic)
{
	if (m_timer.getElapsedTime().asSeconds() < EXTRIM_POINT)
		pic->move(0, -JUMP_RATE);
	else
		pic->move(0, JUMP_RATE / RECESSION);
}