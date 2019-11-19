#ifndef GRASS_H
#define GRASS_H
#include <SFML/Graphics.hpp>

class grassClass
{
    public:
        grassClass();
        virtual ~grassClass();
        sf::Texture grasstex;
        sf::Sprite grassSp;
        int moved = 0;
        bool wind = true;
    protected:

    private:
};

class pileClass
{
public:
    pileClass();
    sf::Texture piletex;
    sf::Sprite pile;
    int moved = 0;
    ~pileClass();
};

class lilyClass
{
public:
    lilyClass();
    sf::Texture lilytex;
    sf::Sprite lily;
    ~lilyClass();
};

#endif // GRASS_H
