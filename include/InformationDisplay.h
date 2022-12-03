#pragma once
#include "Helper.h"

class InformationDisplay
{
public:
	InformationDisplay();
	void draw() const;
	void drawToMenu()const;
	void update(int m_coins, int numOfPlayer);
	int getWay() const { return m_clock.getElapsedTime().asSeconds() * (Resources::resources().MOVE_RATE / 2); }
	int getCoin() const;
private:
	sf::Clock m_clock;
	sf::Text m_wayText, m_coinText, m_playersText;
	sf::Font m_font;
};
