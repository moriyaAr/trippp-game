#pragma once
#include "Factory.h"
#include "DriveMovement.h"
class MovedObject
{
public:
	MovedObject(){ m_movement = std::make_unique<DriveMovement>(); }	
	virtual ~MovedObject() {};
	virtual void draw() = 0;
	virtual void move() = 0;
	virtual sf::Vector2f getPos() = 0;
	virtual sf::FloatRect rect() = 0;
	virtual float getHight() = 0;
protected:
	std::unique_ptr<MoveStrategy> m_movement = nullptr;
}; 