#ifndef UI_H
#define UI_H
#include "fonts.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <ItemCrafting.h>
#include <fstream>

class UI : public fonts
{
    public:
        UI(sf::RenderWindow &window);
        virtual ~UI();

    sf::Text woodtext;
    sf::Text stonetext;
    sf::Text irontext;

    sf::String woodstring;
    sf::String stonestring;
    sf::String ironstring;

    std::stringstream ws;
    std::stringstream ss;
    std::stringstream is;



    sf::Texture woodtex;
    sf::Sprite wood;

    sf::Texture rocktex;
    sf::Sprite rock;

    sf::Texture irontex;
    sf::Sprite iron;

    std::vector<int>::iterator it;

    void displayResAmount(int woodAm, int stoneAm, int ironAm, std::vector<sf::Sprite>&frames, sf::RenderWindow &window, float &darkness, int unIron, bool &matsused, int &imatsused, int &matstype
                          , bool &matsgath, int &matsgtype, float &oilAm, int &iflamp, std::vector<int>&slotID, std::vector<hiveClass> &hives, float& timeneeded);

    void draw(sf::RenderWindow &window);


    sf::Clock clock;
    sf::Time time;

    int minutes = 0;
    int seconds = 7;

    int oldwood;

    bool tonight = false;
    bool today = false;

    sf::Text timetext;
    std::stringstream tl;

    std::vector<sf::Text>matstext;
    std::ostringstream mats;
    sf::Text mat;
    std::string matstring;

    bool growwood = false;
    bool growstone = false;
    bool growiron = false;

    int mins = 0;

    bool nighttime = false;

    sf::Texture lamptex;
    sf::Sprite lamp;

    std::stringstream oilstream;
    sf::Text oil;
    sf::Sprite oildrop;
    sf::Texture oildroptex;

    protected:

    private:
};

#endif // UI_H
