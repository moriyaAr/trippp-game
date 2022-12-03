#pragma once
#include "Helper.h"
class Animation : public sf::Sprite
{
public:
    ~Animation() = default;
    Animation();
    Animation(Animation&& other);
    void init(AnimOption act, int texNum,sf::Vector2f ori,sf::Vector2f pos);
    bool update(sf::Time delta, AnimOption act);
    void draw() const { Resources::resources().getWin().draw(*this); }
protected:
    sf::Clock m_animationTimer;
private:
    void nextRect();
    AnimationData* m_data;
    sf::Time m_elapsed = {};
    AnimOption m_AnimAct = e_ride;
    int m_index = 0, m_roundCounter=0;
};