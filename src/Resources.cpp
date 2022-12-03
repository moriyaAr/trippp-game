#include "Resources.h"
#include "Helper.h"

//------------------------------
// the func init each animation seria in a dedicated place
void Resources::initSpesificAnimation(sf::Vector2i size, sf::Vector2i space, int vectorSize, AnimOption act)
{
	sf::Vector2i currentStart = space;
	auto nextStart = [&]()
	{
		currentStart.x += size.x;
		return currentStart;
	};
	m_data.m_animationData[act].emplace_back(currentStart, size);
	for (int i = 1; i < vectorSize; i++)
		m_data.m_animationData[act].emplace_back(nextStart(), size);
}

//------------------------------------------------------------------------------
//הפונקציה מאתחלת את גרפיקת המשחק
Resources::Resources()
{
	m_window.create(sf::VideoMode(WIN_X, WIN_Y, 32), "Trip game", sf::Style::Titlebar | sf::Style::Close);
	LoadingPic();
	LoadinSound();
	m_font.loadFromFile("never.ttf");
	initData();
	MOVE_RATE = RATE;
}
//------------------------------
//the func init all the animation in the game
void Resources::initData()
{
	m_data.m_animationData.resize(e_max_act);
	initSpesificAnimation(RIDE_SIZE, RIDE_SPACE, RIDE, e_ride);
	initSpesificAnimation(BEND_SIZE, BEND_SPACE, BEND, e_bend);
	initSpesificAnimation(JUMP_SIZE, JUMP_SPACE, JUMP, e_jump);
	initSpesificAnimation(COIN_SIZE, COIN_SPACE, COIN, e_coin);
	initSpesificAnimation(BOMB_SIZE, BOMB_SPACE, BOMB, e_bomb);
}
//------------------------------------
//הפונקציה מאפשרת מופע יחיד של המחלקה
Resources& Resources::resources()
{
	static Resources m_reasourceManagare;
	return m_reasourceManagare;
}

//------------------------------------------------------------------------------
//הפונקציה מחזירה את התמונה הרצויה 
sf::Texture& Resources::getPic(const int index)
{
	return m_texture[index];
}

//------------------------------------------------------------------------------
//הפונקציה מחזירה את הפונט הרצוי
sf::Font& Resources::getFont()
{
	return m_font;
}

//------------------------------------------------------------------------------
//הפונקציה מחזירה את חלון המשחק
sf::RenderWindow& Resources::getWin()
{
	return m_window;
}
//------------------------------------------------------------------------------
// the func return the animation data stucture
AnimationData& Resources::animationData()
{
	return m_data;
}
//------------------------------------------------------------------------------
//the func return asked sound
sf::SoundBuffer& Resources::getSound(const int index) 
{
	return m_soundBuffer[index];
}
//------------------------------------------------------------------------------
//the func play asked sound
void Resources::playSound(const int& i) 
{
	m_sound.setBuffer(Resources::resources().getSound(i));
	m_sound.play();
}
void Resources::setTextStyle(sf::Text& text, const sf::Vector2f& pos,int fontSize) const
{
	text.setFont(m_font);
	text.setCharacterSize(fontSize);
	text.setColor(sf::Color::White);
	text.setPosition(pos);
}
//------------------------------------------------------------------------------
//הפונקציה טוענת תמונות למשחק
void Resources::LoadingPic()
{
	auto tex = sf::Texture();
	tex.loadFromFile("back1.jpg");
	m_texture.push_back(tex);
	tex.loadFromFile("back2.png");
	m_texture.push_back(tex);
	tex.loadFromFile("back3.png");
	m_texture.push_back(tex);
	tex.loadFromFile("back4.png");
	m_texture.push_back(tex);
	tex.loadFromFile("back5.png");
	m_texture.push_back(tex);
	tex.loadFromFile("back6.png");
	m_texture.push_back(tex);
	tex.loadFromFile("playerRide.png");
	m_texture.push_back(tex);
	tex.loadFromFile("obs.png");
	m_texture.push_back(tex);
	tex.loadFromFile("menu.png");
	m_texture.push_back(tex);
}

//-------------------------------------------
//הפונקציה טוענת מוזיקות למשחק
void Resources::LoadinSound()
{
	auto sound = sf::SoundBuffer();
	sound.loadFromFile("stone.wav");
	m_soundBuffer.push_back(sound);
	sound.loadFromFile("plane.mp3");
	m_soundBuffer.push_back(sound);
	sound.loadFromFile("lose.mp3");
	m_soundBuffer.push_back(sound);
	sound.loadFromFile("jump.wav");
	m_soundBuffer.push_back(sound);
	sound.loadFromFile("coinSak.wav");
	m_soundBuffer.push_back(sound);
	sound.loadFromFile("coin.mp3");
	m_soundBuffer.push_back(sound);
	sound.loadFromFile("car.wav");
	m_soundBuffer.push_back(sound);
	sound.loadFromFile("bump.wav");
	m_soundBuffer.push_back(sound);
	sound.loadFromFile("bottun.wav");
	m_soundBuffer.push_back(sound);
	sound.loadFromFile("allToRoad.mp3");
	m_soundBuffer.push_back(sound);
}