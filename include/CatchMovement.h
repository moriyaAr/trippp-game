#pragma once
#include "MoveStrategy.h"
class CatchMovement : public MoveStrategy
{
public:
	CatchMovement();
	~CatchMovement() {};
	CatchMovement(CatchMovement&& other);
	virtual void execute(sf::Sprite*) override;
private:
};