#ifndef ENEMIES_H
#define ENEMIES_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "math.h"

class Enemies
{
    public:
        Enemies();
        virtual ~Enemies();
    std::vector<sf::Sprite>enemies;
    void spawnEnemy(int posX, int posY, bool nighttime);
    void drawEnemies(sf::RenderWindow &window);
    sf::CircleShape agroCircle;
    void agroing(sf::RenderWindow &window, sf::Vector2f ppos);
    void follow(sf::Vector2f ppos, sf::RectangleShape prect, int &hp, std::vector<sf::RectangleShape>&water);
    std::vector<float> enemySpeed;
    std::vector<int>contact;
sf::RectangleShape frect;
    void fight(int x, int y, sf::RectangleShape &prect, std::vector<int>&slotID, int &slotnumber, sf::Sprite &player, sf::View &vv, int pposx, int pposy, std::vector<int>&durability,
               bool& lockrot, sf::RenderWindow &window);

    sf::Clock deltaClock;
    sf::Time deltaTime;
    sf::RectangleShape vs1;
    sf::RectangleShape vs2;
    float prot;
    bool lower;

    sf::RectangleShape bloodpart;
    std::vector<sf::RectangleShape>blood;
    std::vector<float>bdirec;
    std::vector<float>upword;
    float brec;

    int shakeway = 0;

    bool isshaking = false;
    int shakeam = 5;
    float upforce;
    int color;

    protected:

    private:
        int agroDist = 1;
        sf::Texture enemytexture;
        sf::Sprite enemysprite;
        std::vector<float> magnitude;
        std::vector<sf::Vector2f> unitVector;
        std::vector<sf::Vector2f> direction;
        sf::Vector2f curPos;
        sf::Vector2i position;
        const float pi = 3.14;
        float dx;
        float dy;
        float rotation;

        std::vector<float>edx;
        std::vector<float>edy;
        std::vector<float>erotation;
        std::vector<sf::Vector2f>curpos;
        std::vector<sf::Vector2i>posit;

        sf::RectangleShape ewait1base;
        sf::RectangleShape ewait2base;

        std::vector<sf::RectangleShape> ewait1;
        std::vector<sf::RectangleShape> ewait2;

};

#endif // ENEMIES_H
