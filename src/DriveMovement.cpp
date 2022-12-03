#include "DriveMovement.h"

//move Ctor (becouse we have uniq_ptr in uniq_ptr) calling father move ctor
DriveMovement::DriveMovement(DriveMovement && other) :MoveStrategy(std::move(other)) {}

//the func update the next step of movefawerd movment
void DriveMovement::execute(sf::Sprite* pic)
{
	pic->move(-Resources::resources().MOVE_RATE, 0);
}