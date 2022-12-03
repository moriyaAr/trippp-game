#pragma once
#include "Obsticles.h"
#include "NewPlayer.h"
#include "Animation.h"
const int FONT_SIZE = 40;
//--------------------------
class Car :public Obsticles
{
public:
	Car();
	~Car() {};
	int getNumOfPlayer() { return m_numOfPlayer; }
	void explosion();
	void move();
	void draw();
private:
	void initText();
	std::unique_ptr<NewPlayer> m_player;
	int m_numOfPlayer;
	static bool m_registerit;
	bool isExplosion = true;
	sf::Text m_numPlayerText;
	sf::Font m_font;
	Animation m_bomb;
	sf::Clock m_clock;
};
