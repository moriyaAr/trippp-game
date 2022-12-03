#include "Car.h"

const int BASE_LOT = 2;
const int LOT_RANG = 4;
const int NUM_OF_CAR_PICS = 2;
const sf::Vector2i SIZE = { 300,155 };
const sf::Vector2i CUR_START_ONE = { 0,WIN_Y };
const sf::Vector2i CUR_START_TWO = { 1094,WIN_Y };
const sf::Vector2f POSITION = { WIN_X,900 };
const sf::Vector2f ORIGEN = { 0,155 };
const sf::Vector2f NUM_OF_PLAYER_POS = { WIN_X + 147,800 };
const int BOMB_POSITION_Y = 900;
//------------------------------
//ctor of broken road
Car::Car():Obsticles()
{
	int num = rand() % NUM_OF_CAR_PICS;
	if (num == 0)
		init(SIZE, CUR_START_ONE, POSITION, ORIGEN, OBS_PIC);
	else
		init(SIZE, CUR_START_TWO, POSITION, ORIGEN, OBS_PIC);
	initText();
	Resources::resources().playSound(e_car);
}
//------------------------------------------------------
// the func init the text of num of player that bomb the car
void Car::initText()
{
	m_font = Resources::resources().getFont();
	m_numPlayerText.setFont(m_font);
	m_numPlayerText.setCharacterSize(FONT_SIZE);
	m_numPlayerText.setColor(sf::Color::White);
	m_numPlayerText.setPosition({ WIN_X + 147,800 });
	m_numOfPlayer = rand() % LOT_RANG + BASE_LOT;
	m_numPlayerText.setString(std::to_string(m_numOfPlayer));
}
//-------------------------
// the func handle explosion case
// no return value no parameters
void Car::explosion()
{
	m_clock.restart();
	m_player = std::make_unique<NewPlayer>();
	m_bomb.init(e_bomb, PLAYER_PIC, { 160,200 }, { getPosition().x + getGlobalBounds().width/2, 900 });
	isExplosion = false;
}
//--------------------------
// the func treet the car movement and stop it when need
// no return value no parameters
void Car::move()
{
	if (isExplosion)
	{
		RectPic::move();
		m_numPlayerText.move(-Resources::resources().MOVE_RATE * ELEMENT_SPEED, 0);
	}
	else
	{
		auto delta = m_clock.restart();
		m_bomb.update(delta, e_bomb);
	}
}

//---------------------------
// the func draw the right part in each iteration
// no return value no parameters
void Car::draw()
{
	if (isExplosion)
	{
		RectPic::draw();
		Resources::resources().getWin().draw(m_numPlayerText);
	}
	else
	{
		m_player->draw();
		m_bomb.draw();
	}
}
// regist to Factory to Allow Factory to produce him
bool Car::m_registerit = Factory::registerit(e_Car,
	[]() -> std::unique_ptr<MovedObject> { return std::make_unique<Car>(); });