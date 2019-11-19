#ifndef ITEMCRAFTING_H
#define ITEMCRAFTING_H
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "fonts.h"
#include <string>
#include <fstream>
#include <string>

class hiveClass
{
public:
    hiveClass();

    sf::Texture hivetex;
    sf::Sprite hive;
    sf::RectangleShape hiveArea;
    void draw(sf::RenderWindow &window);

    int beesam = 0;
    float honey = 0;

    sf::Texture* hivetexptr = &hivetex;

    sf::RectangleShape h1;
    sf::RectangleShape h2;

    sf::RectangleShape hrect;

    ~hiveClass();
};

class ItemCrafting: public fonts
{
    public:
        ItemCrafting(sf::RenderWindow &window);
        virtual ~ItemCrafting();
        std::vector<hiveClass>hives;
        hiveClass bhive;

        std::fstream file;
        std::string line;
        int nrline = 1;

        std::fstream file2;
        std::string line2;
        int nrline2 = 1;
        int loadlevel = 0;
        int fsize = 0;
        int bsize = 0;
        int hsize = 0;
        void save();

        sf::Sprite sprite;

        sf::CircleShape arrow;
        sf::CircleShape arrowleft;

        void menuOpenCheck(sf::RenderWindow &window, bool &lockstatus, std::vector<int>&slotID, int &woodAm, int &stoneAm, int &ironAm, bool &craftstatus, int slotnumber, bool nighttime, float& oilAm);
        void placeFurnance(int x, int y, sf::RenderWindow &window, std::vector<sf::RectangleShape>&grass, std::vector<sf::Sprite>&walls, float &worldx, float &worldy, int &stoneAm,
                           int& woodAm, sf::RectangleShape &drawarea, std::vector<sf::Sprite>&light, sf::Sprite torch, std::vector<float>&firefuel, std::vector<bool>&upscale,
                           std::vector<bool>&onfire, std::vector<sf::Sprite>&firetops);
        sf::Sprite furnanceplacing;
        sf::RectangleShape cooking;
        bool furstat = false;
        bool benchstat = false;
        bool hivestat = false;
        bool fstat = false;
        void useFurnance(int x, int y, int &uncookedIron, int &cookedIron, int &woodAmount, bool &buildstatus, sf::RectangleShape &prect, int &slotID, std::vector<bool>&onfire);
        void drawFurMenu(sf::RenderWindow &window);
        bool cookingstat = false;
        void checkForInput(sf::Event keyrel);
        std::vector<sf::Sprite>furnances;
        std::vector<sf::Sprite>benches;
        std::vector<sf::RectangleShape>benchrect;
        std::vector<sf::Sprite>fires;
        std::vector<int>durability{0,0,0,0,0,0};
        void updateDur(std::vector<int>&slot, std::vector<sf::Sprite>&frames);
        sf::RectangleShape dist;

        int pnumber = 1;

        bool havelamp = false;
        sf::Sprite lamp;

        int mats_for_axe[1] = {30};
        int mats_for_pick[2] = {30, 30};
        int mats_for_sword[2] = {20,30};
        int mats_for_lamp[1] = {40};
        int mats_for_bucket[1] = {60};
        int mats_for_furnance[1] = {200};
        int mats_for_bench[1] = {200};

        int mats_changed[9];
        int mats_unchanged[9];
        std::ostringstream convert[9];

        void furBenchCollision(std::vector<sf::Sprite>&trees, std::vector<sf::Sprite>&stones,std::vector<sf::Sprite>&irons, std::vector<sf::Sprite>&walls, int &stoneAm, int &woodAm);

        double discount = 0.8;

        std::vector<sf::Sprite> craftingitems;

        bool craftingMenuStatus = false;

        sf::RectangleShape mouse;

    protected:

    private:
        sf::RectangleShape r1;
        sf::RectangleShape r2;
        sf::RectangleShape menuBack;
        sf::Texture axetex;
        sf::Texture picktex;
        sf::Texture swordtex;
        sf::Texture lanterntex;
        sf::Texture buckettex;
        sf::Texture furnancetex;
        sf::Texture benchtex;
        sf::Texture waterbucket;
        sf::Texture oilbucket;
        sf::Texture shroom;
        sf::Texture jar;
        sf::Texture torch;
        sf::Texture fire;
        sf::Sprite emptysprite;
        int craftingitemsamount = 14;
        std::vector<sf::Text> craftstrings;
        sf::Text emptytext;
        sf::RectangleShape c1;
        sf::RectangleShape c2;
        sf::Texture menubacktex;
        sf::Texture* menubackptr = &menubacktex;

        sf::Texture upfiretex;
        sf::Sprite upfire;

        sf::Text penter;

        sf::Texture furnanceback;
        sf::Texture* furnancebackptr = &furnanceback;

        sf::Text uncookedIronText;
        std::stringstream ui;
        sf::String uncookedIronString;
        std::string unIronString;
        int ironToCook;

        sf::Text durtext[6];
        std::stringstream dr[6];

        sf::Text woodNeededText;
        std::stringstream wn;
        int woodneeded;

        sf::Texture* furDirecPtr = &furnancetex;
        sf::Texture* benDirecPtr = &benchtex;

        std::vector<sf::RectangleShape>furDirections;
        std::vector<sf::RectangleShape>benDirections;
        std::vector<sf::RectangleShape>hiveDirections;
        std::vector<float>frotation;
        std::vector<float>brotation;
        std::vector<float>hrotation;
        std::vector<float>firerotation;
        sf::RectangleShape direction;

        sf::Vector2f curPos;
        sf::Vector2f position;
        sf::Vector2f rotation;
        float dx;
        float dy;
        float pi = 3.14;

        sf::Event keyrel;

};

#endif // ITEMCRAFTING_H
