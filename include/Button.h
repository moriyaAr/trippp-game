#pragma once
#include "RectPic.h"
class Button :public RectPic
{
public:
	Button() {};
	virtual void execute() = 0;
	void draw() const { RectPic::draw(); };
};