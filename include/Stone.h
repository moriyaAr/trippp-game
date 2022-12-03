#pragma once
#include "Obsticles.h"
class Stone :public Obsticles
{
public:
	Stone();
	~Stone() {};
private:
	static bool m_registerit;
};
