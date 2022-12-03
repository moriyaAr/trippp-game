#include "Menu.h"
#include "ExitButton.h"
#include "PlayButton.h"
#include "HighScoreButton.h"

const sf::Vector2i SIZE = { WIN_X, WIN_Y };
const sf::Vector2i CUR_START = { 0,0 };
const sf::Vector2f POSITION = { 0,0 };
const sf::Vector2f ORIGEN = { 0,0 };
const sf::Vector2f PLAYER_POSTION = { 185,945 };
const sf::Vector2f PLAYER_ORIGEN = { 0,230 };
const float PLAYER_RATE = 1;
const float X_SCALE = -1;
const float Y_SCALE = 1;
const int NUM_OF_DISPLAY_SCORE = 10;
//------------------------------
// the func init the menu datas
void Menu::init(InformationDisplay* inform)
{
    m_inform = inform;
    m_menuBackg.init(SIZE, CUR_START, POSITION, ORIGEN,OBS_PIC);
    m_playerImage.init(e_ride, PLAYER_PIC, PLAYER_ORIGEN, PLAYER_POSTION);
    m_Button.emplace_back(std::make_unique <ExitButton>());
    m_Button.emplace_back(std::make_unique <HighScoreButton>(m_highScore));
    m_Button.emplace_back(std::make_unique <PlayButton>(inform));
    m_playerRate = PLAYER_RATE;
}
//------------------------------
// the func run the mane menu loop to end catch command from user
void Menu::run()
{
    sf::Clock clock;
    while (Resources::resources().getWin().isOpen())
    {
        Resources::resources().getWin().clear();
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
                Resources::resources().playSound(e_bottun);
                handelClick(event);
                clock.restart();
            }
            }
        }
        auto delta = clock.restart();
        MovePlayer(delta);
    }
}
//---------------------------------------
// the func draw the menu datas
void Menu::draw() const
{
    m_menuBackg.draw();
    m_playerImage.draw();
    std::ranges::for_each(m_Button, &Button::draw);
    m_inform->drawToMenu();
}
//---------------------------------------
// the func decided what to do with mouse click
void Menu::handelClick(const sf::Event event)
{
    sf::Vector2f location = Resources::resources().getWin().mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
    for (int i = 0; i < m_Button.size(); i++)
    {
        if (m_Button[i]->getGlobalBounds().contains(location))
        {
            m_Button[i]->execute();
            if (m_inform->getCoin() != 0)
            {
                m_highScore.insert(m_inform->getCoin());
                saveLastScore();
            }
        }
    }
}
//---------------------------------------
// the func calc the next location of the player
void Menu::MovePlayer(sf::Time delta)
{
    if (m_playerImage.getPosition().x < 0 || m_playerImage.getPosition().x > WIN_X)
    {
        //oposit directin
        m_playerRate *= -1;
        m_playerImage.scale(X_SCALE, Y_SCALE);
    }
    m_playerImage.update(delta, e_ride);
    m_playerImage.move({ m_playerRate, 0 });
}
//--------------------------
void Menu::saveLastScore()
{
    int i = NUM_OF_DISPLAY_SCORE;
    while (m_highScore.size() > i)
    {
        m_highScore.erase(m_highScore.begin());
        i--;
    }
}
