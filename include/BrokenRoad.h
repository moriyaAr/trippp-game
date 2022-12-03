#pragma once
#include "Obsticles.h"
//--------------------------------
class BrokenRoad :public Obsticles
{
public:
	BrokenRoad();
	~BrokenRoad() {};
private:
		static bool m_registerit;
};

