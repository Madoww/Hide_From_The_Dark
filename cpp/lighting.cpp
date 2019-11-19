#include "lighting.h"


void lighting::runlight(sf::RenderWindow &window, float &dark, float &oilAm, sf::RectangleShape &prect, int slotID, int &durability, std::vector<sf::Sprite> &fires, sf::Vector2f& unitvector
                        ,sf::Sprite& player, bool& ismoving, float& windspeed, bool& nighttime)
{
    if(fsprites.size() < m_fire.size())
    {
        upfire.setOrigin(8,8);
        upfire.setPosition(fires[fires.size()-1].getPosition().x, fires[fires.size()-1].getPosition().y);
        upfire.setScale(7,7);
        fsprites.push_back(upfire);
        sounds.push_back(sound);
    }
        time = clock.getElapsedTime();
            m_layer.clear(sf::Color(0,0,0,darkness_level));
            m_flashlight.setPosition(800,450);
            m_flashlight.setScale(5,5);
            m_flashlight.setColor(sf::Color(128,64,0,darkness_level));
            m_sprite.setPosition(prect.getPosition());
            m_torch.setColor(sf::Color(128,64,0,darkness_level));

            for(int i = 0; i<m_fire.size(); i++)
            {
                direction = sf::Vector2f(fires[i].getPosition() - prect.getPosition());
                magnitude = sqrt((direction.x*direction.x)+(direction.y*direction.y));
                if(20-(magnitude/12)-firefuel[i]*3 > 0)
                    sounds[i].setVolume(20-(magnitude/12)-firefuel[i]*3);
                else
                    sounds[i].setVolume(0);
                if(sounds[i].getStatus()==0)
                    sounds[i].play();
                firefuel[i]+=0.001;
                if(m_fire[i].getGlobalBounds().intersects(m_torch.getGlobalBounds()))
                    torchon = false;
                if(m_fire[i].getGlobalBounds().intersects(m_flashlight.getGlobalBounds()))
                    flashon = false;
                fscale = rand()%10;
                fscale /= 100;
                if(upscale[i] == true)
                {
                    m_fire[i].setScale(m_fire[i].getScale().x+fscale,m_fire[i].getScale().y+fscale);
                }
                else
                {
                    m_fire[i].setScale(m_fire[i].getScale().x-fscale,m_fire[i].getScale().y-fscale);
                }
                fsprites[i].setScale(m_fire[i].getScale().x*1.2,m_fire[i].getScale().y*1.2);

                if(m_fire[i].getScale().x >= 6.2-firefuel[i])
                {
                    upscale[i] = false;
                }

                if(m_fire[i].getScale().x <= 5.8-firefuel[i])
                {
                    upscale[i] = true;
                }

                m_fire[i].setColor(sf::Color(128,64,0,darkness_level));
                m_fire[i].setPosition(fires[i].getPosition().x-prect.getPosition().x+800,fires[i].getPosition().y-prect.getPosition().y+450);

                //PARTICLES
                part.setPosition(fires[i].getPosition().x+rand()%8-4,fires[i].getPosition().y-38+firefuel[i]*10);
                part.setOrigin(0,0);
                part.setRotation(0);
                if(rand()%2==1)
                    part.setFillColor(sf::Color::Red);
                else
                    part.setFillColor(sf::Color::Yellow);
                if(firefuel[i]<2)
                fireparticles.push_back(part);
                if(firefuel[i]>2 && firefuel[i]<3)
                {
                    if(rand()%2==1)
                        fireparticles.push_back(part);
                }
                if(firefuel[i]>3 && firefuel[i]<4)
                {
                    if(rand()%3==1)
                        fireparticles.push_back(part);
                }
                if(firefuel[i]>4 && firefuel[i]<5)
                {
                    if(rand()%4==1)
                        fireparticles.push_back(part);
                }
                if(m_fire[i].getScale().x<= 0.3)
                {
                    fires[i].setTexture(burnt);
                    m_fire[i].setScale(0,0);
                    fsprites[i].setScale(0,0);
                    onfire[i] = false;
                    sounds[i].stop();
                }

                m_layer.draw(m_fire[i], sf::BlendNone);

            }


            if(flashon == true && oilAm > 0)
            {
                m_layer.draw(m_flashlight, sf::BlendNone);
                if(time.asSeconds()>=1)
                {
                    oilAm -=1;
                }
            }
            if(torchon == true)
            {
                if(unitvector.x != 0 || unitvector.y != 0)
                {
                    if(rand()%2==0)
                        part.setFillColor(sf::Color::Yellow);
                    else
                        part.setFillColor(sf::Color::Red);
                    part.setPosition(prect.getPosition());
                    part.setOrigin(-26,26);
                    part.setRotation(player.getRotation());
                    if(ismoving == true)
                        units.push_back(unitvector);
                    if(ismoving==false)
                        units.push_back(sf::Vector2f(rand()%6, -rand()%5));
                        particles.push_back(part);

                }
                if(fire == true)
                {
                    scale = rand()%10;
                    scale /= 100;
                    m_torch.setScale(m_torch.getScale().x+scale,m_torch.getScale().y+scale);
                }
                if(fire == false)
                {
                    m_torch.setScale(m_torch.getScale().x-0.02,m_torch.getScale().y-0.02);
                }

                if(m_torch.getScale().x >= 4.1-(torchoff/2.5))
                    fire = false;
                if(m_torch.getScale().x <= 3.9-(torchoff/2.5))
                    fire = true;
                if(time.asSeconds()>=1)
                {
                    if(durability<10)
                    torchoff++;
                    durability--;
                }
                if(durability >=10)
                    torchoff = 0;
            }
            for(int i = 0; i<particles.size(); i++)
                {
                    particles[i].move(units[i].x+(windspeed*10),units[i].y+(windspeed*10));
                    particles[i].setFillColor(sf::Color(particles[i].getFillColor().r,particles[i].getFillColor().g,particles[i].getFillColor().b,particles[i].getFillColor().a-15));
                    if(particles[i].getFillColor().a <= 15)
                    {
                        particles.erase(particles.begin()+i);
                        units.erase(units.begin()+i);
                    }
                    if(ismoving==false)
                    {
                        units[i].x-=0.4;
                    }
                }
            m_layer.draw(m_torch, sf::BlendNone);
            if(torchon == false)
            {
                if(m_torch.getScale().x > 0)
                {
                    m_torch.setScale(m_torch.getScale().x-0.5,m_torch.getScale().y-0.5);
                }
                if(m_torch.getScale().x<0)
                m_torch.setScale(0,0);
            }
            if(time.asSeconds()>=1)
            {
                clock.restart();
            }
            m_layer.display();
            window.draw(m_sprite);
        for(int i = 0; i<m_fire.size(); i++)
        if(nighttime == true && m_torch.getScale().x<=0.1 && flashon == false && !prect.getGlobalBounds().intersects(m_fire[i].getGlobalBounds()))
        {
            r1.move(1,0);
            //if(r1.getPosition().x>=r2.getPosition().x)
              //  std::cout<<"DEAD"<<std::endl;
        }
}

void lighting::drawFire(sf::RenderTarget& window, const float& windspeed)
{
    for(int i = 0; i<particles.size(); i++)
        window.draw(particles[i]);
    for(int i = 0; i<fireparticles.size(); i++)
    {
        window.draw(fireparticles[i]);
        fireparticles[i].move(rand()%6-3+windspeed*10,-rand()%4);
        fireparticles[i].setFillColor(sf::Color(fireparticles[i].getFillColor().r,fireparticles[i].getFillColor().g,fireparticles[i].getFillColor().b,fireparticles[i].getFillColor().a-5));
        if(fireparticles[i].getFillColor().a <= 5)
        {
            fireparticles.erase(fireparticles.begin()+i);
        }
    }
}

void lighting::save(float rotation, float alpha, float scale)
{
    file.close();
    file.open("Sources/Saves/time.txt", std::ios::out);
    file<<darkness_level<<std::endl;
    file<<rotation<<std::endl;
    file<<alpha<<std::endl;
    file<<scale<<std::endl;
}
void lighting::load(std::vector<sf::Sprite>&treeshadows, std::vector<sf::Sprite>&stoneshadows, std::vector<sf::Sprite>&ironshadows)
{
    for(int i = 0; i<treeshadows.size(); i++)
    {
        treeshadows[i].setRotation(rotation);
        treeshadows[i].setColor(sf::Color(0,0,0,alpha));
        treeshadows[i].setScale(1.6*6,scale_load);
    }
    for(int i = 0; i<stoneshadows.size(); i++)
    {
        stoneshadows[i].setRotation(rotation);
        stoneshadows[i].setColor(sf::Color(0,0,0,alpha));
        stoneshadows[i].setScale(1.6*6,scale_load);
    }
    for(int i = 0; i<ironshadows.size(); i++)
    {
        ironshadows[i].setRotation(rotation);
        ironshadows[i].setColor(sf::Color(0,0,0,alpha));
        ironshadows[i].setScale(1.6*6,scale_load);
    }
}

