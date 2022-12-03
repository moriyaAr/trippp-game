#pragma once
#include "State.h"
//-------------------------------

class RideState : public State
{
public:
	RideState(const int);
	~RideState() {};
	RideState(RideState&& other);
	RideState& operator=(RideState&&);
	virtual std::unique_ptr<State> update(sf::Time delta) override;
	virtual std::unique_ptr<State> handleInput(sf::Keyboard::Key key)  override;
};