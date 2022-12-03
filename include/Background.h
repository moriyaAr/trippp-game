#pragma once
#include "Helper.h"
#include "Pic.h"

class Background
{
public:
	void init();
	void move();
	void draw() const;
	void moveEach(int i, int move_rate);
private:
	vector<Pic> m_pics;
};