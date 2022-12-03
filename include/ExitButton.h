#pragma once
#include "Button.h"
#include "Game.h"
class ExitButton :public Button
{
public:
	ExitButton();
	~ExitButton() {};
	virtual void execute() override;
};