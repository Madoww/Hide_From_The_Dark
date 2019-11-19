#include "Tile.h"

Tile::Tile()
{
    water.setSize(sf::Vector2f(64,64));
    water.setOutlineColor(sf::Color::Blue);
    water.setOutlineThickness(4);
    water.setScale(1.4,1.4);
    sand.setSize(sf::Vector2f(64,64));
    sand.setScale(1.4,1.4);
    flowerbtex.loadFromFile("Sources/Textures/flowerbase.png");
    flowerttex.loadFromFile("Sources/Textures/flowertop.png");
    flowerbase.setTexture(flowerbtex);
    flowerbase.setColor(sf::Color(10,255,10));
    flower.setTexture(flowerttex);
    flower.setScale(4,4);
    flowerbase.setScale(4,4);
    flowerbase.setOrigin(5,14);
    flower.setOrigin(flowerbase.getOrigin());
    srand(time(NULL));
}


