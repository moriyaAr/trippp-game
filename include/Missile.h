#pragma once
#include "Gift.h"
class Missile :public  Gift
{
public:
	Missile();
	void moveToTarget(const sf::Vector2f location);
	void holdMovement();
private:
	static bool m_registerit;
};