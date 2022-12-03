#include "Colider.h"
#include <typeinfo>
#include <typeindex>
#include <memory>
#include "Car.h"
#include "Coins.h"
#include "plane.h"
#include "Magnet.h"
#include "wayJumping.h"
#include "Stone.h"
#include "NewPlayer.h"
#include "coinSak.h"
#include "BrokenRoad.h"

const float GIFT_TIME = 5;
//-----------------------------------------------------
namespace
{ 
    static Colider colider;
    //------------------------------------------
    // treet player and car colision
    void carColissen(Player& player, MovedObject& object, int obj_index)
    {
        Car& car = dynamic_cast<Car&>(object);
        if (colider.getNumOfPlayer() >= car.getNumOfPlayer())
        {
            Resources::resources().playSound(e_bump);
            car.explosion();
            colider.addPlayer();
        } 
        else
            colider.deletePlayer();
        colider.tendToDie(obj_index);
    }
    //------------------------------------------------
    // treet player and plane colision
    void planeColissen(Player& player, MovedObject& object, int obj_index)
    {
        if (!player.isBendState())
        {
            Resources::resources().playSound(e_plane);
            colider.deletePlayer();
            colider.tendToDie(obj_index);
        }
    }
    //--------------------------------------------
    // treet player and magnet colision
    void magnetColissen(Player& player, MovedObject& object, int obj_index)
    {
        if (colider.m_magnetTime)
            return;
        colider.m_magnetClock.restart();
        Magnet& magnet = dynamic_cast<Magnet&>(object);
        colider.m_magnetPos = magnet.getPosition();
        magnet.stop();
        colider.m_magnetTime = true;
    }
    //--------------------------------------------
    // treet player and adding player gift colision
    void addPlayerColissen(Player& player, MovedObject& object, int obj_index)
    {
        colider.addPlayer();
        colider.deleteObject(obj_index);
    }
    //---------------------------------------------
    // treet player and stone colision
    void stoneColissen(Player& player, MovedObject& object, int obj_index)
    {
        Resources::resources().playSound(e_stone);
        colider.deletePlayer();
        colider.tendToDie(obj_index);
    }
    //----------------------------------------------------
    // treet player and coin colision
    void coinsColissen(Player& player, MovedObject& object, int obj_index)
    {
        Resources::resources().playSound(e_coinSound);
        int amount = rand() % 6 + 1;
        colider.addCoins(amount);
        Coins& con = dynamic_cast<Coins&>(object);
        con.coinCatch();
        colider.coinTendToDie(obj_index);
    }
    //--------------------------------------------
    // treet player and speeder gift colision
    void speedColissen(Player& player, MovedObject& object, int obj_index)
    {
        colider.m_speedClock.restart();
        colider.m_anableColide = false;
        Resources::resources().MOVE_RATE *= ULTRA_SPEED;
    }
    //--------------------------------------------
    // treet player and coin sak gift colision
    void coinSakColissen(Player& player, MovedObject& object, int obj_index)
    {
        Resources::resources().playSound(e_CoinSak);
        int amount = (rand() % 4 + 1)*50;
        colider.addCoins(amount);
        colider.deleteObject(obj_index);
    }
    //------------------------------------------------------
    // treet player and broken road colision
    void brokenRoadColissen(Player& player, MovedObject& object, int obj_index)
    {
        player.fallDown();
    }
    //------------------------------------------
    // treet player and missle gift colision
    void MissileColissen(Player& player, MovedObject& object, int obj_index)
    {
        colider.m_inMissile = true;
        Missile& missle = dynamic_cast<Missile&>(object);
        missle.holdMovement();
        colider.coliderMissle(missle, obj_index);
        colider.tendToDie(obj_index);
        colider.m_inMissile = false;
    }

    // this function for option to treet difrenet every colider
    // right now we realization them the same becouse lack of time
    //the func treet missele and car colision
    void MissleCarColissen(Missile& missle, Obsticles& object, int obj_index)
    {
        colider.deleteObject(obj_index);
    }
    //the func treet missele and plane colision
    void MisslePlaneColissen(Missile& missle, Obsticles& object, int obj_index)
    {
        colider.deleteObject(obj_index);
    }
    //the func treet missele and broken road colision
    void MissleBrokenRoadColissen(Missile& missle, Obsticles& object, int obj_index)
    {
        colider.deleteObject(obj_index);
    }
    //the func treet missele and stone colision
    void MissleStoneColissen(Missile& missle, Obsticles& object, int obj_index)
    {
        colider.deleteObject(obj_index);
    }
    // ======================================================================================
    using CollisionFunctionPtr = void (*)(Player& player, MovedObject& object, int obj_index);
    using ColideMissleFunctionPtr = void (*)(Missile& missle, Obsticles& object, int obj_index);
    using Key = std::pair<std::type_index, std::type_index>;
    using CollisionMap = std::map<Key, CollisionFunctionPtr>;
    using MissleMap = std::map<Key, ColideMissleFunctionPtr>;
    //======================================================================================
    // the func fit between input to corect function
    CollisionMap initializeCollisionMap()
    {
        CollisionMap collisionMap;
        collisionMap[Key(typeid(Player), typeid(Car))] = &carColissen;
        collisionMap[Key(typeid(Player), typeid(Plane))] = &planeColissen;
        collisionMap[Key(typeid(Player), typeid(Coins))] = &coinsColissen;
        collisionMap[Key(typeid(Player), typeid(Stone))] = &stoneColissen;
        collisionMap[Key(typeid(Player), typeid(Magnet))] = &magnetColissen;
        collisionMap[Key(typeid(Player), typeid(WayJumping))] = &speedColissen;
        collisionMap[Key(typeid(Player), typeid(NewPlayer))] = &addPlayerColissen;
        collisionMap[Key(typeid(Player), typeid(coinSak))] = &coinSakColissen;
        collisionMap[Key(typeid(Player), typeid(BrokenRoad))] = &brokenRoadColissen;
        collisionMap[Key(typeid(Player), typeid(Missile))] = &MissileColissen;
        return collisionMap;
    }
    // the func fit between input to corect function
    MissleMap initializeMissleMap()
    {
        MissleMap missleMap;
        missleMap[Key(typeid(Missile), typeid(Car))] = &MissleCarColissen;
        missleMap[Key(typeid(Missile), typeid(Car))] = &MisslePlaneColissen;
        missleMap[Key(typeid(Missile), typeid(Car))] = &MissleBrokenRoadColissen;
        missleMap[Key(typeid(Missile), typeid(Car))] = &MissleStoneColissen;
        return missleMap;
    }
    //------------------------------------------------
    // the func look for spesific Key in the map to run the right function
    CollisionFunctionPtr lookup(const std::type_index& player, const std::type_index& object)
    {
        static CollisionMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(player, object));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }
    //--------------------------------------------------
    // the func look for spesific Key in the map to run the right function
    ColideMissleFunctionPtr missleLookup(const std::type_index& missle, const std::type_index& object)
    {
        static MissleMap collisionMap = initializeMissleMap();
        auto mapEntry = collisionMap.find(std::make_pair(missle, object));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }
}
//============================end namespace====================

// the func treet all the colision and send it to the right treet func
void processCollision(Player& player, MovedObject& object, Level* level, int obj_index)
{
    colider.init(level);
    colider.colisenConsequences();
    if (colider.m_anableColide || typeid(object)== typeid(Magnet) || typeid(object) == typeid(Coins))
    {
        auto collision = lookup(typeid(player), typeid(object));
        if (!collision)//לא נמצאה פונקציית התנגשות
            throw;
        collision(player, object, obj_index);
    }
}
//------------------------------------------------------------

// the func add player
void Colider::addPlayer()
{
    m_level->m_player.emplace_back(std::make_unique<Player>(m_level->m_player.size()));
}

// the func move object from object deque to only show deque
void Colider::tendToDie(const int i)
{
    if (i < m_level->m_object.size())
    {
        m_level->m_tendToDie.emplace_back(std::move(m_level->m_object[i]));
        m_level->m_object.erase(m_level->m_object.begin() + i);
        m_level->m_tendToTimer.restart();
    }
}

// the func move coin from coin deque to only show deque
void Colider::coinTendToDie(const int i)
{
    if (i < m_level->m_Coins.size())
    {
        m_level->m_tendToDie.emplace_back(std::move(m_level->m_Coins[i]));
        m_level->m_Coins.erase(m_level->m_Coins.begin() + i);
        m_level->m_tendToTimer.restart();
    }
}

// the func delete player
void Colider::deletePlayer()
{
    if (m_level->m_player.size() > 0)
    {
        m_level->m_player.pop_back();
        m_level->m_curPlayer--;
    }
}

//-------------------------------------------------------
// the func makes all the coins in time range to be targeted to the magnet
void Colider::makeCoinTarget()
{
    for (int i = 0; i < m_level->m_Coins.size(); i++)
    {
        Coins& coin = dynamic_cast<Coins&>(*m_level->m_Coins[i]);
        if (coin.moveToMagnet(colider.m_magnetPos))
        {
            coinTendToDie (i);
            addCoins(1);
        }
    }
}
//----------------------------------------
// the func relese all the coins inthe deque from being targeted
void Colider::returnCoinstraghit()
{
    for (int i = 0; i < m_level->m_Coins.size(); i++)
    {
        Coins& coin = dynamic_cast<Coins&>(*m_level->m_Coins[i]);
        coin.regularMovment();
    }
}
//---------------------------------------
// the func chek if there is a colision with the missele
// and if so treet it 
void Colider::handleMisseleClick(const sf::Vector2f location, Missile& missle)
{
    for (int i = 0; i < m_level->m_object.size(); i++)
    {
        if (typeid(m_level->m_object[i]) == typeid(Obsticles))
        {
            Obsticles& obsticle = dynamic_cast<Obsticles&>(*m_level->m_object[i]);
            if (obsticle.getGlobalBounds().contains(location))
            {
                auto collision = missleLookup(typeid(missle), typeid(obsticle));
                if (!collision)//לא נמצאה פונקציית התנגשות
                    throw;
                collision(missle, obsticle, i);
            }
        }
    }
}
//--------------------------------------------
// the func treet colision between player and missele
void Colider::coliderMissle(Missile& missle,const int i)
{
    sf::Event event;
    while (true)
    {
        while (Resources::resources().getWin().pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonReleased)
            {
                sf::Vector2f location = Resources::resources().getWin().
                    mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                missle.moveToTarget(location);
                handleMisseleClick(location, missle);
                tendToDie(i);
                return;
            }
        }
        m_level->draw();
        m_level->updateNextStep();
    }
}

// the func treet Consequences for long term of colisions
void Colider::colisenConsequences()
{
    if (!m_anableColide && m_speedClock.getElapsedTime().asSeconds() > GIFT_TIME)
    {
        m_anableColide = true;
        Resources::resources().MOVE_RATE /= ULTRA_SPEED;
    }
    if (m_magnetTime)
    {
        makeCoinTarget();
        if (m_magnetClock.getElapsedTime().asSeconds() > GIFT_TIME)
        {
           m_magnetTime = false;
           returnCoinstraghit();
        }
    }
}
