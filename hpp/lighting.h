#ifndef LIGHTING_H
#define LIGHTING_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>

class lighting
{
public:
    bool fire = false;
    float scale = 0;
    lighting(std::vector<sf::Sprite>&treeshadows) :
        m_layer()
    {
        burnt.loadFromFile("Sources/Textures/burnt.png");
        m_layer.create(1600, 900);
        m_flashlightTexture.create(100, 100);

        // We want to have semi-transparent edges.
        generateSpot();

        m_flashlight.setTexture(m_flashlightTexture.getTexture(), true);
        m_flashlight.setPosition(150.f, 150.f);
        m_flashlight.setOrigin(50.f, 50.f);

        m_torch.setTexture(m_flashlightTexture.getTexture(),true);
        m_torch.setPosition(150.f,150.f);
        m_torch.setOrigin(50.f,50.f);
        m_torch.setScale(4,4);
        m_torch.setPosition(800,450);

        m_sprite.setTexture(m_layer.getTexture());
        m_sprite.setOrigin(m_sprite.getGlobalBounds().width/2,m_sprite.getGlobalBounds().height/2);
        for(int i = 0; i<m_fire.size(); i++)
            m_fire[i] = m_torch;
        upfiretex.loadFromFile("Sources/Textures/topfire.png");
        upfire.setTexture(upfiretex);

        part.setSize(sf::Vector2f(3,3));
        buffer.loadFromFile("Sources/Sounds/fire.ogg");
        sound.setBuffer(buffer);
        sound.stop();

        r1.setPosition(0,0);
        r1.setSize(sf::Vector2f(1,1));
        r2.setSize(sf::Vector2f(1,1));
        r2.setPosition(40,0);
        file.open("Sources/Saves/time.txt", std::ios::in);
        if(file.good()==true)
        {
            while(std::getline(file,line))
            {
                switch(linenr)
                {
                    case 0: darkness_level = atoi(line.c_str());
                    break;
                    case 1: rotation = atoi(line.c_str());
                    break;
                    case 2: alpha = atoi(line.c_str());
                    break;
                    case 3: scale_load = atoi(line.c_str());
                    break;
                }
                linenr++;
            }
            loadup = true;
            std::cout<<"SCALE: "<<scale_load<<std::endl;
        }
    }
    sf::FloatRect getGlobalBounds(int i){return m_fire[i].getGlobalBounds();}
    std::fstream file;
    int linenr = 0;
    std::string line;
    int rotation;
    int alpha = 0;
    float scale_load = 0;
    bool loadup = false;

    sf::SoundBuffer buffer;
    sf::Sound sound;
    std::vector<sf::Sound>sounds;
    sf::Vector2f direction;
    float magnitude;

    void drawFire(sf::RenderTarget& window, const float& windspeed);

    void save(float rotation, float alpha, float scale);
    void load(std::vector<sf::Sprite>&treeshadows, std::vector<sf::Sprite>&stoneshadows, std::vector<sf::Sprite>&ironshadows);

    void generateSpot()
    {
        m_flashlightTexture.clear();

        // Draw 6 circles with increasing transparency
        for(unsigned int i = 0; i < 6; ++i)
        {
            sf::CircleShape temp(50.f-(i*2.f));
            temp.setOrigin(sf::Vector2f(50.f-(i*2.f), 50.f-(i*4.f)));
            temp.setFillColor(sf::Color(100, 250, 250, 61-(i*6)));
            temp.setPosition(sf::Vector2f(50.f, 50.f));

            m_flashlightTexture.draw(temp, sf::BlendNone);
        }

        m_flashlightTexture.display();
    }

    void runlight(sf::RenderWindow &window, float &dark, float &oilAm, sf::RectangleShape &prect, int slotID, int &durability, std::vector<sf::Sprite> &fires, sf::Vector2f& unitvector
                  ,sf::Sprite& player, bool& ismoving, float& windspeed, bool& nighttime);

    float darkness_level = 0;//100
    float torchoff = 0;
    bool flashon = false;
    bool torchon = false;

    bool infire = false;

    std::vector<sf::Sprite> m_fire;
    std::vector<float>firefuel;
    std::vector<bool>upscale;
    std::vector<bool>onfire;
    std::vector<sf::Sprite>fsprites;
    sf::Sprite upfire;
    sf::Texture upfiretex;
    //bool upscale = true;
    float fscale;
    sf::Sprite m_torch;

private:
    sf::RenderTexture m_flashlightTexture;
    sf::RenderTexture m_layer;
    sf::Sprite m_flashlight;
    sf::Texture burnt;

    sf::Sprite m_sprite;

    sf::CircleShape circle;

    sf::RectangleShape part;
    std::vector<sf::Vector2f>units;
    std::vector<sf::RectangleShape>particles;

    std::vector<sf::RectangleShape>fireparticles;

    sf::RectangleShape r1;
    sf::RectangleShape r2;

    sf::Time time;
    sf::Clock clock;
};


#endif // LIGHTING_H
