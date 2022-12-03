#pragma once
#include "Resources.h"
const float ELEMENT_SPEED = 1.5;
//----------------------------------
class RectPic :public sf::Sprite
{
public:
	~RectPic() {};
	void init(const sf::Vector2i size, const sf::Vector2i currentStart, const sf::Vector2f pos, const sf::Vector2f origin, const int numOfPic);
	void draw() const;
	void move();
private:
	sf::IntRect m_rect;
	sf::Texture m_tex;
};