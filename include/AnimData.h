#pragma once
using std::vector;
//------------------
// animation option
typedef enum
{
	e_ride,
	e_jump,
	e_bend,
	e_coin,
	e_bomb,
	e_max_act,
} AnimOption;
//------------------

struct AnimationData
{
	vector <vector <sf::IntRect>> m_animationData;
};
//------------------