#pragma once
#include "MoveStrategy.h"
class JumpingMovement : public MoveStrategy
{
public:
	JumpingMovement() = default;
	~JumpingMovement() {};
	JumpingMovement(JumpingMovement&& other);
	virtual void execute(sf::Sprite*) override;
};