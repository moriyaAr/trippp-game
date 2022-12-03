#include "Level.h"
#include <algorithm>
#include "Colider.h"
#include <cassert>
#include <utility>
const int NUM_OF_PLAYER = 4;
const int TIME_LEFT_PLAYER = 50;
const double TIME_TENT_TO_DIE = 0.8;
const int LOTTRY_COIN = 1500;
const int LOTTRY_ELEMNT = 500;
const int NEW_LOT_COIN = 500;
const int NEW_LOT_ELEMENT = 800;
const int BASE_NEW_LOT_COIN = 1000;
const int BASE_NEW_LOT_ELEMENT = 2000;
//------------------------------------
// the func run the main level loop and hold the hole level
//no parameters no return value
void Level::run()
{
	starter();
	while (Resources::resources().getWin().isOpen()&& m_player.size()>0)
	{	
		draw();
		checkEvent();
		updateNextStep();
		chekColision();
	}
}
//------------------------------
// the func init the level datas
//no parameters no return value
void Level::init(InformationDisplay* inform)
{
	m_inform = inform;
	m_background.init();
	for (int i = 0; i < NUM_OF_PLAYER; i++)
	{
		m_player.emplace_back(std::make_unique<Player>(i));
	}
	m_lotCoin = rand() % LOTTRY_COIN + LOTTRY_COIN;
	m_lotElement = rand() % LOTTRY_ELEMNT + LOTTRY_ELEMNT;
}

//------------------------------
// the func draw the level datas
//no parameters no return value
void Level::draw() const
{
	Resources::resources().getWin().clear();
	m_background.draw();
	std::ranges::for_each(m_Coins, &MovedObject::draw);
	std::ranges::for_each(m_object, &MovedObject::draw);
	std::ranges::for_each(m_tendToDie, &MovedObject::draw);
	std::ranges::for_each(m_player, &Player::draw);
	m_inform->draw();
	Resources::resources().getWin().display();
}

//------------------------------
// the func calculate the next step of the game
//no parameters no return value
void Level::updateNextStep()
{
	m_background.move();
	std::ranges::for_each(m_object, &MovedObject::move);
	std::ranges::for_each(m_Coins, &MovedObject::move);
	std::ranges::for_each(m_tendToDie, &MovedObject::move);
	auto delta = m_gameClock.restart();
	for (int i = 0; i < m_player.size(); i++)
		m_player[i]->update(delta);
	newElementControl();
	m_inform->update(m_coins, m_player.size());
}
//--------------------------------
// the func cach event and treet them
//no parameters no return value
void Level::checkEvent()
{	
	while (Resources::resources().getWin().pollEvent(m_event))
	{
		if ((m_event.type == sf::Event::Closed) ||
			((m_event.type == sf::Event::KeyPressed) && (m_event.key.code == sf::Keyboard::Escape)))
			exit(EXIT_SUCCESS);
		if (m_event.type == sf::Event::KeyPressed)
			m_eventPressed = true;
	}
	if (m_eventPressed && m_playersTimer.getElapsedTime().asMilliseconds() > TIME_LEFT_PLAYER)
	{
		if (m_curPlayer < m_player.size())
			m_player[m_curPlayer]->handleInput(m_event.key.code);
		m_curPlayer++;
		m_playersTimer.restart();
		if (m_curPlayer == m_player.size())
		{
			m_curPlayer = 0;
			m_eventPressed = false;
		}
	}
}
//--------------------------------
// the func restatrt all level clocks
//no parameters no return value
void Level::starter()
{
	m_gameClock.restart();
	m_objectTimer.restart();
	m_coinsTimer.restart();
	m_playersTimer.restart();
}

//--------------------------------
// the func delete all the object that get out of screen
//no parameters no return value
void Level::deleteSpare()
{
	if (m_object.size() > 0)
		if (m_object[0]->getPos().x < 0- m_object[0]->getHight())
			m_object.pop_front();
	if (m_Coins.size() > 0)
		if (m_Coins[0]->getPos().x < 0 - m_Coins[0]->getHight())
			m_Coins.pop_front();
	if (m_tendToDie.size() > 0)
		if (m_tendToTimer.getElapsedTime().asSeconds() > TIME_TENT_TO_DIE)
			m_tendToDie.pop_front();
	for (int i = 0; i < m_player.size(); i++)
	{
		if (m_player[i]->GetPostion().y > WIN_Y + m_player[i]->getHight())
			m_player.erase(m_player.begin() + i);
	}
}
//--------------------------------
// the func responsed on creating new element to the level 
// every random (in a range) time
//no parameters no return value
void Level::newElementControl()
{
	if (m_objectTimer.getElapsedTime().asMilliseconds() > m_lotElement)
	{
		m_object.emplace_back(std::move(m_factory.lottery()));
		m_objectTimer.restart();
		m_lotElement = rand() % NEW_LOT_ELEMENT + BASE_NEW_LOT_ELEMENT;
	}
	if (m_coinsTimer.getElapsedTime().asMilliseconds() > m_lotCoin)
	{
		m_Coins.emplace_back(std::move(m_factory.create(e_Coins)));
		m_coinsTimer.restart();
		m_lotCoin = rand() % NEW_LOT_COIN + BASE_NEW_LOT_COIN;
	}
	deleteSpare();
}
//--------------------------------
// the func chek if was a colision and if so send in to the colider to treet
//no parameters no return value
void Level::chekColision()
{
	for (int j = 0; j < m_player.size(); j++)
	{
		for (int i = 0; i < m_object.size(); i++)
			if (j < m_player.size() && m_player[j]->intersects(m_object[i]->rect()))
				processCollision(*m_player[j], *m_object[i], this, i);
		for (int i = 0; i < m_Coins.size(); i++)
			if (j < m_player.size() && m_player[j]->intersects(m_Coins[i]->rect()))
				processCollision(*m_player[j], *m_Coins[i], this, i);
	}
}