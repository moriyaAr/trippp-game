#pragma once
#include "MoveStrategy.h"
class HoldMovement : public MoveStrategy
{
public:
	HoldMovement();
	~HoldMovement() {};
	HoldMovement(HoldMovement&& other);
	virtual void execute(sf::Sprite*) override;
};