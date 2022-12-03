#pragma once
#include "State.h"
//-------------------------------
class BendState : public State
{
public:
	BendState(const int i);
	BendState(BendState&& other);
	BendState& operator=(BendState&&);
	~BendState() {};
	virtual std::unique_ptr<State> handleInput(sf::Keyboard::Key key)  override;
	virtual std::unique_ptr<State> update(sf::Time delta) override;
};