#pragma once
#include "Button.h"

class BackButton :public Button
{
public:
	BackButton();
	~BackButton() {};
	virtual void execute() override{};
};