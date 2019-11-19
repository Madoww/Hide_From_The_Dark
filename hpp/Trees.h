#ifndef TREES_H
#define TREES_H
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <tile.h>

class Trees
{
    public:
        std::fstream file;
        std::string line;
        int tsize = 0;
        int ssize = -1;
        int isize = -1;
        int loadlevel = 0;
        Trees();
        virtual ~Trees();
    std::vector<sf::Sprite>trees;
    std::vector<sf::Vector2f>treepos;
    std::vector<int>treeshp;
    std::vector<sf::Sprite>treeshadows;
    std::vector<sf::Sprite>bottomtrees;

    std::vector<sf::Sprite>stones;
    std::vector<sf::Vector2f>stonepos;
    std::vector<sf::Sprite>stoneshadows;
    std::vector<int>stoneshp;

    std::vector<sf::Sprite>irons;
    std::vector<sf::Vector2f>ironspos;
    std::vector<sf::Sprite>ironshadows;
    std::vector<int>ironshp;

    std::vector<sf::RectangleShape>particles;
    float pmove;
    float pmovey;
    std::vector<float>partmove;
    std::vector<float>partmovey;
    sf::RectangleShape part;

    void createParticles();
    void displayParticles(sf::RenderWindow &window);

    sf::SoundBuffer buffer;
    sf::Sound treechop;

    sf::SoundBuffer rockbuffer;
    sf::Sound rockhit;
    float pitch;


    sf::Texture woodlog;
    sf::Texture rock;
    sf::Texture shroomtex;
    std::vector<sf::Sprite>woodlogs;
    std::vector<sf::Sprite>rocks;
    std::vector<sf::Sprite>shrooms;
    int shroomsam = 200;

    std::vector<sf::Sprite>oils;

    bool shake = false;
    bool shake2 = false;

    void pickwood(sf::RenderWindow &window, int x, int y, int slotID, bool craftStatus, int &woodAm, int pposx, int pposy, int &durability, int &stoneAm, sf::View &view, sf::RectangleShape &prect
                  ,bool& harvestAnim, float &currot, sf::Sprite& player, sf::Sprite& plrect);
    void placeResources(int treesAm, int stonesAm, int ironsAm, int logsAm, int rocksAm, std::vector<sf::RectangleShape>&water, std::vector<sf::RectangleShape>&grass, std::vector<sf::RectangleShape>&sand);
    bool resplacedone = false;
    void drawTrees(sf::RenderWindow &window, sf::RectangleShape &area, sf::Time &time, float& darkness, bool& nighttime, float& volumeAm);
    void drawBelow(sf::RenderWindow &window, sf::RectangleShape &area);

    void pickStone(sf::RenderWindow &window, int x, int y, int &slotID, bool craftStatus, int pposx, int pposy, int &stoneAm, float &oilAmount, int &ironAmount, int &durability, bool& harvAnim, sf::Sprite &player, float &currot);

    sf::Event event;

    int treehp = 80;
    int treedamage = 20;

    int stonehp = 100;
    int stonedamage = 20;

    int ironhp = 120;
    int irondamage = 20;

    sf::CircleShape harv;

    int treedist = 100;
    float oilAm = 30;

    bool matsgath = false;
    int matsgam = 0;
    enum {_WOOD = 1, _STONE, _IRON};
    int matsgtype = 0;

    sf::RectangleShape harv1;
    sf::RectangleShape harv2;

    int xplace = 10600;
    int yplace = 12300;

    sf::Texture treestandtex;
    sf::Sprite treestand;

    void save();
    float windspeed = 0.03;
    float timeneeded = 0;
    int windchance = 2;
    int ticks = 0;
    int ticksneeded = 4;

    sf::Music windsound;
    sf::Music crickets;

    private:
    sf::Texture treetex;
    sf::Texture stonetex;
    sf::Texture oiltex;
    sf::Texture irontex;
    sf::Vector2f worldPos;
    sf::Vector2i pixelPos;
    sf::Vector2f posvec;
    sf::Texture treeshadowtex;
    float avwind = 0;
    int calc = 0;

    float nspeed = 0.1;

    std::vector<bool>wind;
    bool volumeSet = false;
};

#endif // TREES_H
