#pragma once
#include "MovedObject.h"
#include "RectPic.h"
class Gift :public MovedObject, public RectPic
{
public:
	Gift();
	~Gift() {};
	void init(const sf::Vector2i size,const sf::Vector2i currentStart,const sf::Vector2f origin);
	virtual void draw() override{ RectPic::draw(); };
	virtual void move() override { m_movement->execute(this); };
	virtual sf::FloatRect rect() override{ return RectPic::getGlobalBounds(); };
	virtual sf::Vector2f getPos()override { return RectPic::getPosition(); };
	virtual float getHight() override { return getGlobalBounds().width; }
};