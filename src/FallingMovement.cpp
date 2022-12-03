#include "FallingMovement.h"

float FALING_RATE = 4;

// ctor 
FallingMovement::FallingMovement() {}

//move ctor (becouse we have uniq_ptr in uniq_ptr)
FallingMovement::FallingMovement(FallingMovement&& other) :MoveStrategy(std::move(other)){}

//----------------------------------------------
// the func update the next step in falling down movement
// no return value no parameters
void FallingMovement::execute(sf::Sprite* pic)
{
	pic->move(0, FALING_RATE);
}
