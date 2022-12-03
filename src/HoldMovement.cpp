#include "HoldMovement.h"

const sf::Vector2f HOLD = { 0,0 };

//Ctor calling to fater Ctor
HoldMovement::HoldMovement() : MoveStrategy() {}

//move Ctor (becouse we have uniq_ptr in uniq_ptr) calling father move ctor
HoldMovement::HoldMovement(HoldMovement&& other):MoveStrategy(std::move(other)) {}

//the func update the next step of hold movment
void HoldMovement::execute(sf::Sprite* pic)
{
	pic->move(HOLD);
}
