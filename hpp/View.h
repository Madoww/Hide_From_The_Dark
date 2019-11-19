#ifndef VIEW_H
#define VIEW_H
#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Player;

class View
{
    public:
        View();
        virtual ~View();
    sf::View view;
    sf::Event event;
    sf::RectangleShape drawArea;
    void setViewPos(int x, int y);
    void viewFollow(int x, int y, float speed, sf::RectangleShape &drawing, int &lockr, int &lockl, int &locku, int &lockd, bool &plock);
    void screenShake(sf::View &v);

    sf::RectangleShape gpart;
    std::vector<sf::RectangleShape>gplace;
    int elevate = 0;
    int goright = 0;

    int zoomin = 0;
    protected:

    private:
        sf::Time deltaTime;
        sf::Clock deltaClock;
        sf::RectangleShape vs1;
        sf::RectangleShape vs2;

};

#endif // VIEW_H
