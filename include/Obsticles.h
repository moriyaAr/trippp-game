#pragma once
#include "MovedObject.h"
#include "RectPic.h"
class Obsticles :public MovedObject , public RectPic
{
public:
	Obsticles();
	~Obsticles() {};
	virtual void draw() override { RectPic::draw(); };
	virtual void move() override{ m_movement->execute(this); };
	virtual sf::FloatRect rect() override{ return RectPic::getGlobalBounds(); };
	virtual sf::Vector2f getPos()override { return RectPic::getPosition(); };
	virtual float getHight() override { return getGlobalBounds().width; }
};
