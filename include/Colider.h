#pragma once
#include <iostream>
#include <typeinfo>
#include "Level.h"
#include "Missile.h"
//----------------------------------struct definition---------------------------------

void processCollision(Player& player, MovedObject& object,Level* level,int obj_index);

class Colider
{
public:
	void init(Level* l) { m_level = l; }
	void addPlayer();
	void tendToDie(const int i);
	void coinTendToDie(const int i);
	void deletePlayer();
	void deleteObject(const int i) { m_level->m_object.erase(m_level->m_object.begin() + i); }
	void addCoins(const int i) { m_level->m_coins += i; };
	int getNumOfPlayer() const { return m_level->m_player.size(); }
	void makeCoinTarget();
	void returnCoinstraghit();
	void handleMisseleClick(const sf::Vector2f location,Missile& missle);
	void coliderMissle(Missile&, int i);
	void colisenConsequences();
	bool m_anableColide = true, m_magnetTime = false,m_inMissile=false;
	sf::Clock m_speedClock, m_magnetClock;
	sf::Vector2f m_magnetPos;
	Level* m_level;
};