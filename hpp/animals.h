#ifndef BEE_H
#define BEE_H
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "ItemCrafting.h"
class beeClass
{
    public:
        beeClass();
        virtual ~beeClass();
        sf::Texture beetex;
        sf::Sprite bee;
        float magnitude;
        sf::Vector2f unitVector;
        sf::Vector2f direction;
        void bmove();
        void setTarget(sf::Sprite flower, bool nighttime);
        bool hasTarget = false;
        int target;
        float bspeed = 5;
        float dx;
        float dy;
        float rotation;
        sf::Vector2f curpos;
        sf::Vector2i posit;

        bool countin = false;

        sf::RectangleShape r1;
        sf::RectangleShape r2;
    protected:

    private:
};

class deerSpawn
{
public:
    deerSpawn(float x, float y);
    virtual ~deerSpawn();
    sf::Texture dspawntex;
    sf::Sprite dspawn;
};

class meatClass
{
public:
    meatClass();
    sf::Texture meattex;
    sf::Sprite meat;
    std::vector<sf::Sprite>meats;
    std::vector<sf::Vector2f>moves;
    bool exited = false;
    void drop(float x, float y);
    void draw(sf::RenderTarget &window);
    int movex = 5;
    int movey = 3;
    void pickup(int x, int y, std::vector<int>&slotID, std::vector<int>&durability);
    ~meatClass();
};

class deerClass
{
public:
    deerClass();
    sf::Texture deertex;
    sf::Sprite deer;
        float magnitude;
        sf::Vector2f unitVector;
        sf::Vector2f direction;
    sf::RectangleShape deerDirection;

    float dx;
    float dy;
    float rotation;
    sf::Vector2f curpos;
    sf::Vector2i posit;
    sf::RectangleShape agro;
    float speed = 1;
    bool tocheck = false;
    bool wallcontact = false;
    void dmove(sf::RectangleShape direct,std::vector<sf::RectangleShape>&grass, float &x, float& y, int &slotID, sf::Sprite &dspawn, sf::Sprite &meat, std::vector<sf::Sprite>&meats
               ,std::vector<sf::Vector2f>&moves, sf::RectangleShape &prect, std::vector<sf::Sprite>&walls, sf::CircleShape& harv, int& durab);
    virtual ~deerClass();
};

#endif // BEE_H
