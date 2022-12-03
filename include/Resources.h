#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "AnimData.h"
#include <iostream>
const sf::Vector2i RIDE_SIZE = { 240, 230 };
const sf::Vector2i RIDE_SPACE = { 0, 0 };
const int RIDE = 55;
const sf::Vector2i JUMP_SIZE = { 160, 250 };
const sf::Vector2i JUMP_SPACE = { 4800, 430 };
const int JUMP = 23;
const sf::Vector2i BEND_SIZE = { 150, 195 };
const sf::Vector2i BEND_SPACE = { 0, 230 };
const int BEND = 52;
const sf::Vector2i COIN_SIZE = { 40, 40 };
const sf::Vector2i COIN_SPACE = { 0,425 };
const int COIN = 11;
const sf::Vector2i BOMB_SIZE = { 200, 160 };
const sf::Vector2i BOMB_SPACE = { 0,520 };
const int BOMB = 17;
const int RATE = 4;
//-------------------------------------
class Resources
{
public:
	float MOVE_RATE;
	static Resources& resources();
	sf::Texture& getPic(const int index);
	sf::Font& getFont();
	sf::RenderWindow& getWin();
	AnimationData& animationData();
	sf::SoundBuffer& getSound(const int index);
	void playSound(const int& i);
	void setTextStyle (sf::Text& text,const sf::Vector2f& pos,const int) const;
private:
	void initSpesificAnimation(sf::Vector2i size, sf::Vector2i space, int vectorSize, AnimOption act);
	Resources();
	void initData();
	void LoadingPic();
	void LoadinSound();
	std::vector <sf::Texture> m_texture;
	sf::RenderWindow m_window;
	sf::Font m_font;
	AnimationData m_data;
	sf::Sound m_sound;
	std::vector <sf::SoundBuffer> m_soundBuffer;
};