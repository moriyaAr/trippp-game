#pragma once
#include "Gift.h"
class WayJumping :public Gift
{
public:
	WayJumping();
	~WayJumping() {};
private:
	static bool m_registerit;
};
