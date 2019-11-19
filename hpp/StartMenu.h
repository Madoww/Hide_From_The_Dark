#ifndef STARTMENU_H
#define STARTMENU_H
#include "fonts.h"
#include <fstream>
#include <SFML/Audio.hpp>
#include <iostream>


class StartMenu : public fonts
{
    public:
        StartMenu(sf::RenderWindow &window);
        virtual ~StartMenu();
    sf::RectangleShape menubackrect;
    sf::Text start;
    sf::Text quit;
    sf::Text settings;
    sf::Text how2play;
    sf::Text instr;

    int window_style_menu = 7;

    std::fstream file;

    void displayMenu(sf::RenderWindow &window);
    void settingsControl(sf::Sound &wood, sf::Sound &stone, sf::Music &theme, sf::Sound &step, bool& ifwater, sf::RenderWindow &window);

    bool todraw = true; //true
    bool startgame = false; //false
    bool loading = false; //false

    sf::Texture menubacktex;
    sf::Sprite menuback;


    bool instruction = false;
    bool options = false;

    bool togamemenu = false;
    bool ingameMenu = false;
    bool restart = false;

    bool drawgrass = true;

    sf::Text grass;
    sf::Text grasson;
    sf::Text grassoff;

    sf::RectangleShape click;

    sf::RectangleShape volume;
    sf::RectangleShape volumeback;

    sf::Text volumetext;

    sf::Text vsync;
    sf::Text vsyncon;
    sf::Text vsyncoff;

    int sizex;
    int sizey;
    int status;

    bool changed = false;
    bool no_res_changed = false;

    sf::Text resText;

    sf::Text fscreen;
    sf::Text wscreen;

    sf::Text apply;
    sf::Text restartText;

    sf::Text resolutiontext;
    std::vector<sf::Text>resolution;

    sf::Texture firetex;

    void fire(sf::RenderTarget &window);
    std::vector<sf::RectangleShape>particles;
    std::vector<sf::Vector2f>directions;
    sf::RectangleShape part;
    std::vector<sf::RectangleShape>triangles;
    sf::RectangleShape p1;
    sf::RectangleShape p2;
    sf::Texture ftex;
    sf::Texture* firepart;
    std::vector<bool>goup;
    std::vector<bool>colup;

    float volumeAm;

    protected:

    private:
};

#endif // STARTMENU_H
