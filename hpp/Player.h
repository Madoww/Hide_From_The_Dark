#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "View.h"
#include <time.h>
#include <fstream>

class Player
{
    public:
        Player();
        Player(int x, int y, sf::RenderWindow &window)
        :playersizeX(x),playersizeY(y)
        {
            prect.setSize(sf::Vector2f(playersizeX,playersizeY));
            prect.setPosition(playerPositionX,playerPositionY);
            prect.setOrigin(playersizeX/2,playersizeY/2);
            pup.setSize(sf::Vector2f(x-4,1));
            pdown.setSize(sf::Vector2f(x-4,1));
            pleft.setSize(sf::Vector2f(1,y-4));
            pright.setSize(sf::Vector2f(1,y-4));
            pup.setFillColor(sf::Color::Red);
            pdown.setFillColor(sf::Color::Red);
            pleft.setFillColor(sf::Color::Red);
            pright.setFillColor(sf::Color::Red);
            //player.setScale(1.4,1.4);
            player.setScale(1.1*6,1.1*6);
            playertex.loadFromFile("Sources/Textures/player.png");
            healthbar.loadFromFile("Sources/Textures/healthbar2.png");
            hunbar.loadFromFile("Sources/Textures/hungerbar.png");
            waterbar.loadFromFile("Sources/Textures/waterbar.png");
            player.setTexture(playertex);
            player.setOrigin(8,8);

            player.setRotation(15);

            hpback.setFillColor(sf::Color(0,0,0,80));
            hpback.setOutlineColor(sf::Color::Black);
            hpback.setOutlineThickness(5);
            hpback.setSize(sf::Vector2f(300,40));
            hpback.setPosition(130,820);
            hprep.setTexture(hpTex, false);
            hunger.setTexture(hbarTex);
            water.setTexture(waterBarTex);

            hungerback = hpback;
            hungerback.setOutlineThickness(4);
            hungerback.setSize(sf::Vector2f(300,20));
            //hungerback.setPosition(hpback.getPosition().x,hpback.getPosition().y+55);

            waterback = hungerback;


            hprep.setSize(sf::Vector2f(300,40));
            buffer.loadFromFile("Sources/Sounds/footstep.wav");
            waterbuf.loadFromFile("Sources/Sounds/water.wav");
            tiletex.loadFromFile("tilemap.png");
            step.setBuffer(buffer);
            step.setRelativeToListener(true);
            step.setVolume(50);
            oldppos = prect.getPosition();
            /*part.setTexture(tile);
            part.setTextureRect(sf::IntRect(0,0,64,64));*/
            part.setSize(sf::Vector2f(5*3,5*3));
            tool.setScale(0.5*6,0.5*6);
            hprep.setPosition(window.getSize().x/12.3,window.getSize().y/1.15);//130,820
            hpback.setPosition(hprep.getPosition());

            hunger.setSize(sf::Vector2f(300,20));
            hunger.setPosition(hprep.getPosition().x,hprep.getPosition().y+55);
            water.setSize(sf::Vector2f(300,20));
            water.setPosition(hunger.getPosition().x,hprep.getPosition().y+90);
            srand(time(NULL));

            h1.setSize(sf::Vector2f(1,1));
            h2.setSize(sf::Vector2f(1,1));
            h2.setPosition(200,0);

            file.open("Sources/Saves/player.txt", std::ios::in);
            if(file.good()==true)
            {
                while(std::getline(file,line))
                {
                    switch(line_nr)
                    {
                        case 0: pposx = atoi(line.c_str());
                        break;
                        case 1: pposy = atoi(line.c_str());
                        break;
                        case 2: hungerlevel = atoi(line.c_str());
                        break;
                        case 3: thirst = atoi(line.c_str());
                    }
                    line_nr++;
                }
                prect.setPosition(pposx,pposy);
                std::cout<<pposx<<", "<<pposy<<std::endl;
            }
            inlight.setSize(sf::Vector2f(300,300));
            inlight.setOrigin(150,150);
        }
        void drawPlayer(sf::RenderWindow &window, int &slotID, std::vector<sf::Sprite>&tools, std::vector<sf::Sprite> &oils, std::vector<sf::RectangleShape>&water,
                        std::vector<sf::RectangleShape>&sand, bool& torchon);
        void moveRight();
        void moveLeft();
        void moveUp();
        void moveDown();
        void movement();
        bool harvestAnim = false;
        bool toPrectRotation = false;
        bool grothigh = false;
        bool change = false;
        float currot;
        float toolrot;
        float goalRotation;
        int getPositionX();
        int getPositionY();
        void hpbar(sf::RenderWindow &window);
        sf::RectangleShape prect;
        sf::RectangleShape pup,pdown,pleft,pright;
        void playerCollision(std::vector<sf::Sprite>&wall, std::vector<sf::Sprite>&benches, std::vector<sf::RectangleShape>&water, std::vector<int>&watercol, std::vector<sf::Sprite>&furnances
                             , bool& cmenu, bool &fmenu);
        bool collision = false;
        bool lockwalk = false;
        bool lockrot = false;
        virtual ~Player();
        sf::RectangleShape frect;
        sf::Sprite tool;
        sf::Time deltaTime;
        sf::Clock deltaClock;
        float pspeed = 0.1;
        sf::Texture playertex;
        sf::Sprite player;
        int posx;
        int posy;

        int pposx;
        int pposy;

        std::fstream file;
        int line_nr;
        std::string line;
        void save();

        int pdirection = 0;

        bool wup = false;
        bool wdown = false;
        bool wright = false;
        bool wleft = false;

        bool bup = false;
        bool bdown = false;
        bool bright = false;
        bool bleft = false;

        bool fup = false;
        bool fdown = false;
        bool fright = false;
        bool fleft = false;

        sf::Texture tiletex;
        sf::Texture* tile = &tiletex;

        std::vector<int>::iterator it;

        sf::RectangleShape part;
        std::vector<sf::RectangleShape>particles;

        sf::Vector2f oldppos;

        bool stepwater = false;

        bool ismoving = false;
        float upperscale = 1.15*6;
        float lowerscale = 1.05*6;
        float gobackspeed = 5*60;

        bool getsmaller = false;
        bool getbigger = true;

        bool stepgrass = false;

        float pitch;

        int lockup=0,lockdown=0,lockleft=0,lockright=0;
        int stepsound_delay = 60;

        float hp = 100;
        sf::RectangleShape hprep;
        sf::RectangleShape hpback;

        float hungerlevel = 100;
        sf::RectangleShape hunger;
        sf::RectangleShape hungerback;

        float thirst = 100;
        sf::RectangleShape water;
        sf::RectangleShape waterback;


        sf::Texture healthbar;
        const sf::Texture* hpTex = &healthbar;
        sf::Texture hunbar;
        const sf::Texture* hbarTex = &hunbar;
        sf::Texture waterbar;
        const sf::Texture* waterBarTex = &waterbar;

        sf::SoundBuffer buffer;
        sf::SoundBuffer waterbuf;
        sf::Sound step;

        sf::Vector2f oldvec;
        float magnitude;
        sf::Vector2f direction;
        sf::Vector2f unitVector;

        std::vector<sf::Vector2f>units;

        bool movingup = false;
        bool movingdown = false;
        bool movingleft = false;
        bool movingright = false;

        sf::RectangleShape h1;
        sf::RectangleShape h2;

        sf::RectangleShape inlight;

    protected:

    private:
        int playerPositionX=1400;
        int playerPositionY=500;
        int agroDist=400;

        int playersizeX;
        int playersizeY;

};

#endif // PLAYER_H
