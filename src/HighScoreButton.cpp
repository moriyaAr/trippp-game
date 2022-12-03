#include "HighScoreButton.h"
//------------------------------------
const int FONT_SCORE_SIZE = 50;
const sf::Vector2i SIZE = { 117,117 };
const sf::Vector2i CUR_START = { 600,1105 };
const sf::Vector2f POSITION = { 20,140 };
const sf::Vector2f ORIGEN = { 0,0 };
const sf::Vector2i WIN_SIZE = { WIN_X, WIN_Y };
const sf::Vector2i BACK_POSITION = { 0,0 };
const float SPACE_FOR_TEXT = 50;
const float Y_POSITION_TEXT = 300;
//------------------------------
// the func init the butten datas
HighScoreButton::HighScoreButton(std::set<int>& highScore) :m_highScore(highScore)
{
	m_backButton = std::make_unique <BackButton>();
	init(SIZE, CUR_START, POSITION, ORIGEN, OBS_PIC);
	m_BackgroundPic.init(WIN_SIZE, BACK_POSITION, ORIGEN, ORIGEN, HIGH_SCORE_PIC);
}
//--------------------------------------------------
//the func display the high score
void HighScoreButton::execute()
{
	initText();
	sf::Vector2f location;
	while (Resources::resources().getWin().isOpen())
	{
		draw();
		Resources::resources().getWin().display();
		auto event = sf::Event{};
		if (Resources::resources().getWin().pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				Resources::resources().getWin().close();
				break;
			case sf::Event::MouseButtonReleased:
			{
				location = Resources::resources().getWin().mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
				if (m_backButton->getGlobalBounds().contains(location))
				{
					m_scoreText.clear();
					return;
				}		
			}
			}
		}
	}
	
}
//--------------------------------------------------
//the func init the style and position fo the high score text 
void HighScoreButton::initText()
{
	float y_space = Y_POSITION_TEXT;
	sf::Vector2f pos = { WIN_X / 2 ,y_space };
	std::set<int>::reverse_iterator it;
	sf::Text text;
	for (it = m_highScore.rbegin(); it != m_highScore.rend(); it++)
	{
		text.setString(std::to_string(*it));
		Resources::resources().setTextStyle(text, pos, FONT_SCORE_SIZE);
		m_scoreText.emplace_back(text);
		pos.y += SPACE_FOR_TEXT;
	}
}
//--------------------------------------------------
//the func draw the butten datas
void HighScoreButton::draw() const
{
	m_BackgroundPic.draw();
	for(int i=0; i<m_scoreText.size();i++)
		Resources::resources().getWin().draw(m_scoreText[i]);
	m_backButton->draw();
}
