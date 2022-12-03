#pragma once
#include <iostream>
#include <vector>
#include "Button.h"
#include "Level.h"
class Menu
{
public:
	void init(InformationDisplay* inform);
	void run();
	void draw() const;
	void handelClick(const sf::Event event);
	void MovePlayer(sf::Time delta);
	void saveLastScore();
private:
	std::set<int> m_highScore;
	std::vector<std::unique_ptr<Button>> m_Button;
	RectPic m_menuBackg;
	Animation m_playerImage;
	float m_playerRate;
	int m_coin = 0, m_way = 0;
	InformationDisplay* m_inform;
};