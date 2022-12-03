#pragma once
#include "MoveStrategy.h"
class FallingMovement : public MoveStrategy
{
public:
	FallingMovement();
	~FallingMovement() {};
	FallingMovement(FallingMovement&& other);
	virtual void execute(sf::Sprite*) override;
private:
};