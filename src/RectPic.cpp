#include "RectPic.h"
#include "Helper.h"

//------------------------------
// the func init varible from RectPic type
void RectPic::init(const sf::Vector2i size, const sf::Vector2i currentStart, const sf::Vector2f pos, const sf::Vector2f origin, const int numOfPic)
{
	setTexture(Resources::resources().getPic(numOfPic));
	m_rect = sf::IntRect(currentStart, size);
	setTextureRect(m_rect);
	setOrigin(origin);
	setPosition(pos);
}
//------------------------------
//the func draw RectPic varible
void RectPic::draw() const
{
	Resources::resources().getWin().draw(*this);
}
//------------------------------
//the func move RectPic varible
void RectPic::move() 
{
	sf::Sprite::move(-Resources::resources().MOVE_RATE* ELEMENT_SPEED, 0);
}
