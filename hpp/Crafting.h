#ifndef CRAFTING_H
#define CRAFTING_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Crafting
{
    public:
        Crafting(sf::RenderWindow &window);
        virtual ~Crafting();

    bool craftStatus = false;
    std::fstream file;
    int nrline = 1;
    std::string line;

    void save();

    sf::Texture frametex;
    std::vector<sf::Sprite> frames;
    std::vector<sf::Sprite> walls;
    std::vector<sf::Vector2f> wallspos;
    std::vector<int>wallshp;
    std::vector<int>wallstype;
    int buildnumber = 0;

    void placeCrafting(sf::RenderWindow &window);
    void deleteObject(int x, int y, int &woodAm, int &stoneAm);
    void wallTreeCollision(std::vector<sf::Sprite>&trees, std::vector<sf::Vector2f>&treespos, std::vector<sf::Sprite>&wall, std::vector<sf::Sprite>&treeshadows, std::vector<sf::Sprite>&chimneys,
                           std::vector<sf::Sprite>&irons, std::vector<sf::Sprite>&oils, std::vector<sf::Sprite>&ironshadows);
    void wallStoneCollision(std::vector<sf::Sprite>&stones, std::vector<sf::Vector2f>&stonespos, std::vector<sf::Sprite>&wall, std::vector<sf::Sprite>&stoneshadows, std::vector<sf::Sprite>&irons
                            , std::vector<sf::Sprite>&ironshadows);
    void enemyCollision(std::vector<sf::Sprite>&enemy, std::vector<float> &espeed);

    void build(sf::Sprite &object, std::vector<sf::RectangleShape> &ground, int x, int y, sf::RenderWindow &window, std::vector<sf::Vector2f>&exwalls,
               sf::Sprite &framebuild, bool &furstat, std::vector<sf::Sprite>&trees, std::vector<sf::Sprite>&treeshadows, std::vector<sf::Vector2f> &treespos,
               std::vector<sf::Sprite>&stones, std::vector<sf::Sprite>&stoneshadows, std::vector<sf::Vector2f>&stonepos, std::vector<sf::Sprite>&irons, std::vector<sf::Sprite>&oils
               , bool benchstat, std::vector<sf::Sprite>&ironshadows, std::vector<sf::Sprite>&bottomtrees, bool hivestat, bool& fstat);
    sf::Sprite rectobject;

    int woodAmount = 0;
    int stoneAmount = 0;
    float oilAmount = 0;
    int uncookedIron = 0;
    int ironAmount = 0;

    bool matsused = false;
    int imatsused = 0;
    int matstype = 0;

    private:
        sf::RectangleShape craftcheck;
        sf::RectangleShape craftbase;
        sf::RectangleShape buildcheck;
        sf::RectangleShape buildbase;
        sf::Texture woodwalltex;
        sf::Texture stonewalltex;
        sf::Texture ironwalltex;
        sf::Sprite woodwall;
        sf::Sprite stonewall;
        sf::Sprite ironwall;
        int woodreq = 5;
        int stonereq = 5;
        int ironreq = 5;
};

#endif // CRAFTING_H
