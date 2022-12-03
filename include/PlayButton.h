#pragma once
#include "Button.h"
#include "Level.h"
class PlayButton :public Button
{
public:
	PlayButton(InformationDisplay* info);
	~PlayButton() {};
	virtual void execute() override;
private:
	InformationDisplay* m_inform;
};