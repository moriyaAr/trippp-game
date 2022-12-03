#pragma once
#include "Resources.h"
class MoveStrategy
{
public:
	MoveStrategy() { m_timer.restart(); };
	MoveStrategy(MoveStrategy&& other) {m_timer = other.m_timer;};
	virtual ~MoveStrategy() {};
	virtual void execute(sf::Sprite*) = 0;
protected:
	sf::Clock m_timer;
};