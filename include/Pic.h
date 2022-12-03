#pragma once
#include "Helper.h"

class Pic : public sf::Sprite
{
public:
	void init(const int i)
	{
		m_tex = Resources::resources().getPic(i);
		setTexture(m_tex);
		setOrigin(0, (getLocalBounds().height));
		setPosition(0, WIN_Y);
	}
	void repeat() { m_tex.setRepeated(true); }
private:
	sf::Texture m_tex;
};