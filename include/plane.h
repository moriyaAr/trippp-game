#pragma once
#include "Obsticles.h"

class Plane :public Obsticles
{
public:
	Plane();
	~Plane() {};
	virtual void move() override;
private:
	static bool m_registerit;
	sf::Clock m_timer;
};