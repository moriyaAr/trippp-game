#pragma once
#include "Player.h"
#include "MovedObject.h"
#include "InformationDisplay.h"
#include "Background.h"
#include <deque>
class Colider;
class Level
{
	friend class Colider;
public:
	Level() = default;
	void run();
	void init(InformationDisplay* inform);
	void draw() const;
	void updateNextStep();
	void checkEvent();
	void starter();
	void deleteSpare();
	void newElementControl();
	void chekColision() ;
private:
	Background m_background;
	std::deque<std::unique_ptr<Player>> m_player;
	std::deque<std::unique_ptr<MovedObject>> m_object;
	std::deque<std::unique_ptr<MovedObject>> m_Coins;
	std::deque<std::unique_ptr<MovedObject>> m_tendToDie;
	InformationDisplay* m_inform;
	Factory m_factory;
	sf::Clock m_objectTimer,m_coinsTimer, m_playersTimer,m_tendToTimer,m_gameClock;
	int m_curPlayer=0,m_coins=0, m_lotElement, m_lotCoin;
	bool m_eventPressed = false;
	sf::Event m_event;
};