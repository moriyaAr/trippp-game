#pragma once
#include "Button.h"
#include "Pic.h"
#include "BackButton.h"
class HighScoreButton :public Button
{
public:
	HighScoreButton(std::set<int>& highScore) ;
	~HighScoreButton() {};
	virtual void execute() override;
	void initText();
	void draw()const;
private:
	std::unique_ptr<BackButton> m_backButton;
	std::set<int>& m_highScore;
	std::vector<sf::Text > m_scoreText;
	RectPic m_BackgroundPic;
};