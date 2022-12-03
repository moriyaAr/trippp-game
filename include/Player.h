#pragma once
#include "Animation.h"
#include "State.h"

const sf::Vector2f START_POS = { 220,900 };
const sf::Vector2f CONTINU_POS = { -50,0};
//-------------------------------------------
class Player
{
public:
	Player(const int);
	~Player() {};
	void draw();
	void update(sf::Time delta);
	bool intersects(const sf::FloatRect) const;
	bool isBendState()const;
	sf::Vector2f GetPostion() const { return m_state->getPosition(); }
	float getHight() const { return m_state->getGlobalBounds().height; }
	void fallDown();
	virtual void handleInput(sf::Keyboard::Key key);
private:
	bool m_die = false;
	std::unique_ptr<State> m_state;
};