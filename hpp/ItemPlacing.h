#ifndef ITEMPLACING_H
#define ITEMPLACING_H
#include <SFML/Graphics.hpp>
#include <iostream>


class ItemPlacing
{

    public:
        std::vector<sf::Sprite> rects;
        std::vector<sf::Vector2f>rectspos;
        sf::Vector2f rectpos;
        std::vector<int>itemID;
        void ItemPlace(sf::RenderWindow &window, int ID, int craftStatus);
        void itemRemove();
        void drawObject(sf::RenderWindow &window);
        void itemCheck();
        int getID(int objectID);
        int slot;
        sf::Sprite rect;

        ItemPlacing();
        ~ItemPlacing();

        bool placable = false;
        sf::Texture axetex;
        sf::Texture picktex;
        sf::Vector2f worldPos;
        sf::Vector2i pixelPos;
    private:
        int propsize = 64;
        sf::RectangleShape r1;
        sf::RectangleShape r2;



};

#endif // ITEMPLACING_H
