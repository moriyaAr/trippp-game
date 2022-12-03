#include "InformationDisplay.h"
int const FONT_SIZE = 50;
const sf::Vector2f WAY_POSITION = { 1560, 30 };
const sf::Vector2f COIN_POSITION = { 1710, 130 };
const sf::Vector2f PLAYERS_POSITION = { 932, 75 };
//-------------------------------
//הבנאי מאתחל נתונים
InformationDisplay::InformationDisplay()
{
	m_font = Resources::resources().getFont();
	m_clock.restart();
	Resources::resources().setTextStyle(m_wayText, WAY_POSITION, FONT_SIZE);
	Resources::resources().setTextStyle(m_coinText, COIN_POSITION, FONT_SIZE);
	Resources::resources().setTextStyle(m_playersText, PLAYERS_POSITION, FONT_SIZE);
}
////----------------------------------------------------
////אינפורמציה חשובה על שחקנים
void InformationDisplay::update(int coin, int numOfPlayer)
{
	m_coinText.setString(std::to_string(coin));
	m_playersText.setString(std::to_string(numOfPlayer));
	m_wayText.setString(std::to_string(m_clock.getElapsedTime().asSeconds() * (Resources::resources().MOVE_RATE / 2)));
}
//------------------------------------------------------
//הפונקציה מחזירה את כמות המטבעות שנצברה
int InformationDisplay::getCoin() const
{
	if(!m_coinText.getString().isEmpty())
	{
		std::string s = m_coinText.getString();
		return(std::stoi(s));
	}
	return 0;
}
//--------------------------------------------------------
//הפונקציה מציירת את תצוגת המידע
void InformationDisplay::draw() const
{
	drawToMenu();
	Resources::resources().getWin().draw(m_playersText);
}
//----------------------------------------------------
//the func draw datas for menu
void InformationDisplay::drawToMenu() const
{
	Resources::resources().getWin().draw(m_coinText);
	Resources::resources().getWin().draw(m_wayText);
}
