#pragma once
#include "Menu.h"
#include "Level.h"

class Game
{
public:
	void init();
	void run();
private:
	Menu m_menu;
	InformationDisplay m_inform;
};