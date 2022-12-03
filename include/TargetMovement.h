#pragma once
#include "MoveStrategy.h"
class TargetMovement : public MoveStrategy
{
public:
	TargetMovement(const sf::Vector2f magnetPos, const sf::Vector2f myPos);
	~TargetMovement() {};
	TargetMovement(TargetMovement&& other);
	virtual void execute(sf::Sprite*) override;
private:
	sf::Vector2f m_magnetMoveRate;
	int m_index = 1;
};