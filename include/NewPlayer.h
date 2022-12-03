#pragma once
#include "Gift.h"
class NewPlayer :public Gift
{
public:
	NewPlayer();
private:
	static bool m_registerit;
};
