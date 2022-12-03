#include "Animation.h"

const int ROUND_FINISHED = 1;
const int INDEX_ANIMATION = -1;
//------------------------------------------------
// the ctor conect the animation pic data from Resources
Animation::Animation()
{
    m_data = &Resources::resources().animationData();
}

//---------------------------------------------
//move ctor (becouse we have uniq_ptr in uniq_ptr)
Animation::Animation(Animation&& other) :sf::Sprite(std::move(other))
{
    if (&other != this)
    {
        m_data = other.m_data;
        m_elapsed = other.m_elapsed;
        m_AnimAct = other.m_AnimAct;
        m_index = other.m_index;
        m_roundCounter = other.m_roundCounter;

        other.m_data = nullptr;
        other.m_elapsed.Zero;
        other.m_AnimAct;
        other.m_index = INDEX_ANIMATION;
        other.m_roundCounter = 0;
    }
}

//------------------------------------
//the func initialize animation variable
// no return value 
// parameters are: spesific animation , the specific pic origen and position of the sprite
void Animation::init(AnimOption act, int texNum, sf::Vector2f ori, sf::Vector2f pos)
{
    m_AnimAct = act;
    setTexture(Resources::resources().getPic(texNum));
    nextRect();
    setOrigin(ori);
    setPosition(pos);
}

//------------------------------
// the func update the next pic
// trturn boolian to know if one animation iteration finished
// parameters: the time that over,and wich animation have to go on
bool Animation::update(sf::Time delta, AnimOption act)
{
    m_elapsed += delta;
    if (m_elapsed >= AnimationTime)
    {
        m_elapsed -= AnimationTime;
        ++m_index;
        m_index %= m_data->m_animationData[int(act)].size();
        nextRect();
        if (m_index == 0)
            m_roundCounter++;
        if (m_roundCounter == ROUND_FINISHED)
        {
            m_roundCounter = 0;
            return true;
        }
    }
    return false;
}

//------------------------------
// the func change the picture rect
//no prameters no return value
void Animation::nextRect()
{
    if (m_data != nullptr)
        setTextureRect(m_data->m_animationData[int(m_AnimAct)][m_index]);
}