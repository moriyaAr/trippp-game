#pragma once
#include "Resources.h"
using std::vector;
//------------------------
const int WIN_X = 1900;
const int WIN_Y = 1060;
const int N_OF_BACK_PICS = 6;
const int BACK1_PIC = 0;
const int BACK2_PIC = 1;
const int BACK3_PIC = 2;
const int BACK4_PIC = 3;
const int BACK5_PIC = 4;
const int BACK6_PIC = 5;
const int PLAYER_PIC = 6;
const int OBS_PIC = 7;
const int HIGH_SCORE_PIC = 8;
const int LOT_RANGE = 400;
const int LOT_BASIC = 300;
const float ULTRA_SPEED = 4;
const auto AnimationTime = sf::seconds(0.05f);
//----------------------------
typedef enum
{
	e_stone,
	e_plane,
	e_lose,
	e_jumpSound,
	e_coinSak,
	e_coinSound,
	e_car,
	e_bump,
	e_bottun,
	e_fallToRoad,
}Sound;
//--------------------------
typedef enum
{
	e_Stone,
	e_Car,
	e_BrokenRoad,
	e_Plane,
	e_CoinSak,
	e_Magnet,
	e_WayJumping,
	e_Missile,
	e_NewPlayer,
	e_Coins,
	e_maxObject,
}MyObject;
//--------------------