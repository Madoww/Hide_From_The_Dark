#ifndef SLOTMANAGER_H
#define SLOTMANAGER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ItemPlacing.h"
#include <fstream>
#include <string>

class SlotManager
{
    public:
        SlotManager(sf::RenderWindow &window);
        std::fstream file;
        std::fstream file2;
        std::string line;
        int linenr =1;
        void save();

        std::vector<int>slotID;
        void slotChange();
        sf::Texture slottex;
        sf::Texture frame;
        void loadFrame(sf::RenderWindow &window,std::vector<int>&slot, std::vector<sf::Sprite>&framesp, std::vector<sf::Texture>&frameits);
        std::vector<sf::Sprite>frames;
        std::vector<sf::Texture>frameitems;
        sf::Texture framepicktex;
        sf::Sprite framepick;
        sf::Texture swordtex;
        virtual ~SlotManager();
        int slotnumber = 1;

        sf::Sprite Texture(sf::Sprite sprite);

        sf::Sprite framespear;
        sf::Sprite framefire;
        sf::Sprite framesword;

        std::vector<sf::Sprite>framesprites;

        sf::Texture axetex;
        sf::Texture picktex;
        sf::Texture frameswordtex;
        sf::Texture lanterntex;
        sf::Texture buckettex;
        sf::Texture meattex;
        sf::Texture cmeattex;
        sf::Texture waterbucket;
        sf::Texture oilbucket;
        sf::Texture shroom;
        sf::Texture jar;
        sf::Texture torch;
        sf::Texture cooked;

        sf::Sprite item;
        std::vector<sf::Sprite>items;
        std::vector<int>id;
        std::vector<int>durab;
        void drop(sf::RenderTarget &window, int x, int y, std::vector<int>&durability, sf::Vector2f mousepos, float& hunger, float& water, int& hp);

        sf::RectangleShape e1;
        sf::RectangleShape e2;

    private:
        int axeID = 1;
        int pickID = 2;
        int swordID = 3;
        sf::Texture emptyTex;

};

#endif // SLOTMANAGER_H
