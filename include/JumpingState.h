#pragma once
#include "State.h"
//-------------------------------
class JumpingState : public State
{
public:
	JumpingState(const int);
	~JumpingState() {};	
	JumpingState(JumpingState&& other);
	JumpingState& operator=(JumpingState&&);
	virtual std::unique_ptr<State> handleInput(sf::Keyboard::Key key)  override {return nullptr;};
	virtual std::unique_ptr<State> update(sf::Time delta) override;
private:
	sf::Clock m_timer;
};