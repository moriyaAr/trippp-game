#pragma once
#include "Gift.h"

class Magnet :public Gift
{
public:
	Magnet();
	~Magnet() {};
	void stop();
	void move() override;
private:
	static bool m_registerit;
	bool m_isStoped = false;
	sf::Clock m_timer;
};
