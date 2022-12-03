#pragma once
#include "Animation.h"
#include "MovedObject.h"
#include "CatchMovement.h"
class Coins : public Animation, public MovedObject
{
public:
	Coins();
	~Coins() {};
	void draw() override { Animation::draw(); };
	void move() override;
	virtual sf::FloatRect rect() override { return Animation::getGlobalBounds(); };
	virtual sf::Vector2f getPos()override { return Animation::getPosition(); };
	virtual float getHight() override { return getGlobalBounds().width; }
	void coinCatch() { m_movement = std::make_unique< CatchMovement>();};
	bool moveToMagnet(const sf::Vector2f magnetPos);
	void regularMovment() {m_movement = std::make_unique< DriveMovement>();};
private:
	sf::Clock m_time;
	static bool m_registerit;
	bool m_moveCondition = false;
};