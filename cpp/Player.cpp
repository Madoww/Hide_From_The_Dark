#include "Player.h"

Player::Player()
{
    frect.setSize(sf::Vector2f(300,300));
}

Player::~Player()
{
    //dtor
}

void Player::drawPlayer(sf::RenderWindow &window, int &slotID, std::vector<sf::Sprite>&tools, std::vector<sf::Sprite> &oils, std::vector<sf::RectangleShape>&water, std::vector<sf::RectangleShape>&sand, bool& torchon)
{
    inlight.setPosition(prect.getPosition());
    pright.setPosition(prect.getPosition().x+prect.getSize().x/2+pspeed,prect.getPosition().y-prect.getSize().y/2+2);
    pleft.setPosition(prect.getPosition().x-prect.getSize().x/2-pspeed,prect.getPosition().y-prect.getSize().y/2+2);
    pup.setPosition(prect.getPosition().x-prect.getSize().x/2+2,prect.getPosition().y-prect.getSize().y/2-pspeed);
    pdown.setPosition(prect.getPosition().x-prect.getSize().x/2+2,prect.getPosition().y+prect.getSize().y-prect.getSize().y/2+pspeed);
    /*window.draw(prect);
    window.draw(pright);
    window.draw(pleft);
    window.draw(pup);
    window.draw(pdown);*/
    player.setPosition(prect.getPosition());
    for(int i = 0; i<particles.size(); i++)
    {
        window.draw(particles[i]);
    }
    tool.setOrigin(4,10);
    tool.setPosition(prect.getPosition().x,prect.getPosition().y);
    if(slotID != 0 && slotID <= 3 || slotID == 5 || slotID == 8 || torchon == true)
    {
        if(slotID != 8)
            tool.setTexture(*tools[slotID-1].getTexture());
        if(slotID == 8 || (torchon==true))
            tool.setTexture(*tools[slotID].getTexture());


        tool.setColor(sf::Color(255,255,255,255));
    }
    else
        tool.setColor(sf::Color(255,255,255,0));
    window.draw(tool);
    window.draw(player);

    if(toPrectRotation == true)
    {
        tool.setRotation(player.getRotation());
        lockrot = false;
    }
    if(harvestAnim == false)
    {
        if(change == false)
        {
            if(tool.getRotation()<player.getRotation())
            {
                tool.setRotation(tool.getRotation()+5);
            }
            if(tool.getRotation()>=player.getRotation())
            {
                toPrectRotation = true;
            }
        }
        if(change == true)
        {
            if(toolrot<player.getRotation())
            {
                tool.setRotation(toolrot+5);
                toolrot += 5;
            }
            if(toolrot>=player.getRotation())
            {
                toPrectRotation = true;
                change = false;
            }
        }

    }
    if(harvestAnim == true)
    {
        lockrot = true;
        toPrectRotation = false;
        goalRotation = player.getRotation()-45;
        if(goalRotation <= 0)
        {
            //goalRotation += 360;
            change = true;
        }
        if(change == false)
        {
            if(tool.getRotation()>=goalRotation)
            {
                tool.setRotation(tool.getRotation()-5);
            }
            if(tool.getRotation()<=goalRotation)
            {
                harvestAnim = false;
            }
        }
        if(change == true)
        {
            if(toolrot >= goalRotation)
            {
                if(toolrot>=goalRotation)
                {
                tool.setRotation(toolrot-5);
                toolrot = toolrot - 5;
                }
                if(toolrot<=goalRotation)
                {
                    harvestAnim = false;
                }
            }
        }
    }
    if(oldppos.x <= prect.getPosition().x-60 || oldppos.x >= prect.getPosition().x+60 || oldppos.y <= prect.getPosition().y-60 || oldppos.y >= prect.getPosition().y+60)
    {
        pitch = rand()%5+10;
        pitch = pitch/10;
        step.setPitch(pitch);
        step.play();
        oldppos = prect.getPosition();
    }
    if(oldvec.x <= prect.getPosition().x-10 || oldvec.x >= prect.getPosition().x+20 || oldvec.y <= prect.getPosition().y-20 || oldvec.y >= prect.getPosition().y + 20)
    {
        oldvec = prect.getPosition();
    }

    if(ismoving == true)
    {
        /*if(player.getScale().x < toscale && toscale >= 1.2)
        {
            player.setScale(player.getScale().x+0.01,player.getScale().y+0.01);
        }
        if(player.getScale().x > toscale && toscale <= 1.0)
        {
            player.setScale(player.getScale().x-0.01,player.getScale().y-0.01);
        }
        if(player.getScale().x >= toscale && toscale >= 1.2)
        {
            toscale = 1;
        }
        if(player.getScale().x <= toscale && toscale <= 1)
        {
            toscale = 1.2;
        }*/
        if(player.getScale().x < upperscale && getbigger == true)
        {
            player.setScale(player.getScale().x+gobackspeed,player.getScale().y+gobackspeed);
            tool.setScale(tool.getScale().x+gobackspeed, tool.getScale().y+gobackspeed);
        }
        if(player.getScale().x > lowerscale && getsmaller == true)
        {
            player.setScale(player.getScale().x-gobackspeed,player.getScale().y-gobackspeed);
            tool.setScale(tool.getScale().x-gobackspeed,tool.getScale().y-gobackspeed);
        }

        if(getbigger == true && player.getScale().x >= upperscale)
        {
            getsmaller = true;
            getbigger = false;
        }
        if(getsmaller == true && player.getScale().x <= lowerscale)
        {
            getsmaller = false;
            getbigger = true;
        }

        direction = sf::Vector2f(oldvec - prect.getPosition());
        magnitude = sqrt((direction.x*direction.x)+(direction.y*direction.y));
        unitVector = sf::Vector2f(direction.x/magnitude,direction.y/magnitude);
        unitVector = sf::Vector2f(unitVector.x-1+rand()%3,unitVector.y-1+rand()%3);
        posx = prect.getPosition().x;
        posy = prect.getPosition().y;
        part.setPosition(posx-10+rand()%20,posy-10+rand()%20);
        part.setFillColor(sf::Color(139,69,19,255));
        for(int i = 0; i<sand.size(); i++)
        {
            if(prect.getGlobalBounds().intersects(sand[i].getGlobalBounds()))
            {
                part.setFillColor(sf::Color(208, 255, 0,255));
            }
        }
        for(int j = 0; j<oils.size(); j++)
        {
            if(prect.getGlobalBounds().intersects(oils[j].getGlobalBounds()))
            {
                part.setFillColor(sf::Color(0,0,0,255));
                break;
            }
        }
        for(int i = 0; i<water.size(); i++)
    {
        if(prect.getGlobalBounds().intersects(water[i].getGlobalBounds()))
        {
            part.setFillColor(sf::Color(70,70,255,255));
            if(slotID == 5 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                slotID = 8;
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && slotID != 5)
            {
                thirst+=0.1;
            }
        }
    }
        if(unitVector.x != 0 || unitVector.y != 0)
        {
            units.push_back(unitVector);
            particles.push_back(part);
        }
    }
    for(int i = 0; i<particles.size(); i++)
        {
            particles[i].move(units[i]);
            particles[i].setFillColor(sf::Color(particles[i].getFillColor().r,particles[i].getFillColor().g,particles[i].getFillColor().b,particles[i].getFillColor().a-15));
            if(particles[i].getFillColor().a <= 15)
            {
                particles.erase(particles.begin()+i);
                units.erase(units.begin()+i);
            }
        }

    if(ismoving == false)
    {
        if(player.getScale().x < 1.1*6)
        {
            player.setScale(player.getScale().x+gobackspeed, player.getScale().y+gobackspeed);
            tool.setScale(tool.getScale().x+gobackspeed, tool.getScale().y+gobackspeed);
        }
        if(player.getScale().x > 1.1*6)
        {
            player.setScale(player.getScale().x-gobackspeed, player.getScale().y-gobackspeed);
            tool.setScale(tool.getScale().x-gobackspeed,tool.getScale().y-gobackspeed);
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        ismoving = true;
    }
    else
        ismoving = false;
}
void Player::moveDown()
{
    deltaTime = deltaClock.getElapsedTime();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)&&lockdown == 0 && lockwalk == false)
    {
        pdirection = 2;
        prect.move(0,pspeed*deltaTime.asMilliseconds());
        movingdown = true;
    }
}
void Player::moveUp()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&lockup == 0 && lockwalk == false)
    {
        pdirection = 1;
        prect.move(0,-pspeed*deltaTime.asMilliseconds());
        movingup = true;
    }
}
void Player::moveRight()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&lockright == 0 && lockwalk == false)
    {
        pdirection = 1;
        prect.move(pspeed*deltaTime.asMilliseconds(),0);
        movingright = true;
    }

}
void Player::moveLeft()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&lockleft == 0 && lockwalk == false)
    {
        pdirection = 2;
        prect.move(-pspeed*deltaTime.asMilliseconds(),0);
        movingleft = true;
    }
    deltaClock.restart().asMilliseconds();
}
void Player::playerCollision(std::vector<sf::Sprite>&wall, std::vector<sf::Sprite>&benches, std::vector<sf::RectangleShape>&water, std::vector<int>&watercol, std::vector<sf::Sprite>&furnances, bool &cmenu, bool &fmenu)
{
    if(cmenu == true || fmenu == true)
    {
        lockwalk = true;
    }
    if(fmenu == false && cmenu == false)
        lockwalk = false;
        for(int i = 0; i<wall.size(); i++)
        {
            //if(pup.getPosition().x>=wall[i].getPosition().x -32 && pup.getPosition().x<=wall[i].getPosition().x+32 && pup.getPosition().y>=wall[i].getPosition().y-32&&pup.getPosition().y<=wall[i].getPosition().y+32){lockup = 1;}
            if(pup.getGlobalBounds().intersects(wall[i].getGlobalBounds())){wup = true;std::cout<<"?"<<std::endl;}
            else wup = false;
            if(pdown.getGlobalBounds().intersects(wall[i].getGlobalBounds())){wdown = 1;}
            else wdown = 0;
            if(pright.getGlobalBounds().intersects(wall[i].getGlobalBounds())){wright = 1;}
            else wright = 0;
            if(pleft.getGlobalBounds().intersects(wall[i].getGlobalBounds())){wleft = 1;}
            else wleft = 0;
            if(prect.getGlobalBounds().intersects(wall[i].getGlobalBounds())){break;}
        }
        for(int i = 0; i<benches.size(); i++)
        {
            if(pup.getGlobalBounds().intersects(benches[i].getGlobalBounds()))
            {
                bup = true;
            }
            else
                bup = false;
            if(pdown.getGlobalBounds().intersects(benches[i].getGlobalBounds()))
            {
                bdown = 1;
            }
            else
                bdown = 0;
            if(pleft.getGlobalBounds().intersects(benches[i].getGlobalBounds()))
            {
                bleft = 1;
            }
            else
                bleft = 0;
            if(pright.getGlobalBounds().intersects(benches[i].getGlobalBounds()))
            {
                bright = 1;
            }
            else
            {
                bright = 0;
            }
            if(prect.getGlobalBounds().intersects(benches[i].getGlobalBounds()))
            {
                break;
            }

        }
        for(int i = 0; i<furnances.size(); i++)
        {
            if(pup.getGlobalBounds().intersects(furnances[i].getGlobalBounds()))
            {
                fup = true;
            }
            else
                fup = false;
            if(pdown.getGlobalBounds().intersects(furnances[i].getGlobalBounds()))
            {
                fdown = 1;
            }
            else
                fdown = 0;
                if(pleft.getGlobalBounds().intersects(furnances[i].getGlobalBounds()))
            {
                fleft = 1;
            }
            else
                fleft = 0;
                if(pright.getGlobalBounds().intersects(furnances[i].getGlobalBounds()))
            {
                fright = 1;
            }
            else
                fright = 0;
            if(prect.getGlobalBounds().intersects(furnances[i].getGlobalBounds()))
            {
                break;
            }
        }
        if(fup == true || bup == true || wup == true)
        {
            lockup = 1;
            ismoving =false;
        }
        else
            lockup = 0;
        if(fdown == true || bdown == true || wdown == true)
        {
            lockdown = 1;
            ismoving = false;
        }
        else
            lockdown = 0;
        if(fright == true || bright == true || wright == true)
        {
            lockright = 1;
            ismoving = false;
        }
        else
            lockright = 0;
        if(fleft == true || bleft == true || wleft == true)
        {
            lockleft = 1;
            ismoving = false;
        }
        else
            lockleft = 0;
        it = std::find(watercol.begin(),watercol.end(),1);
        for(int i = 0; i<water.size();i++)
        {
            if(prect.getGlobalBounds().intersects(water[i].getGlobalBounds()))
            {
                watercol[i] = 1;
            }
            else
            {
                watercol[i] = 0;
            }
        }
        if(*it == 1)
        {
            pspeed = 0.06;
                if(stepwater == false)
                {
                    step.resetBuffer();
                    step.setBuffer(waterbuf);
                    stepwater = true;
                    stepgrass = false;
                    oldppos = sf::Vector2f(prect.getPosition().x-61,oldppos.y);
                }
        }
        if(*it != 1)
        {
            //pspeed = 2;
            pspeed = 0.1;
            if(stepgrass == false)
            {
                step.resetBuffer();
                step.setBuffer(buffer);
                oldppos = prect.getPosition();
                stepgrass = true;
                stepwater = false;
                oldppos = sf::Vector2f(prect.getPosition().x-61,oldppos.y);
            }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                {
                    pspeed = 0.2;
                    hungerlevel-=0.01;
                    thirst-=0.005;
                    gobackspeed = 0.01*6;
                }
                else
                    gobackspeed = 0.005*6;
        }

}

void Player::hpbar(sf::RenderWindow &window)
{
    //hprep.setSize(sf::Vector2f(hp*3,40));
    //hprep.setTextureRect(sf::IntRect(0,0,hp*3,50));
    if(hungerlevel >100)
        hungerlevel = 100;
    if(thirst > 100)
        thirst = 100;
    if(hp > 100)
        hp = 100;
    hungerback.setPosition(hpback.getPosition().x,hunger.getPosition().y);
    waterback.setPosition(hpback.getPosition().x,water.getPosition().y);
    if(hprep.getSize().x/3!=hp)
    {
        if(hprep.getSize().x/3>hp)
            hprep.setSize(sf::Vector2f(hprep.getSize().x-1,hprep.getSize().y));
        if(hprep.getSize().x/3<hp)
            hprep.setSize(sf::Vector2f(hprep.getSize().x+1,hprep.getSize().y));
        hprep.setTextureRect(sf::IntRect(0,0,hprep.getSize().x,40));
    }
    if(hunger.getSize().x/3>hungerlevel && hunger.getSize().x>0)
    {
        hunger.setSize(sf::Vector2f(hunger.getSize().x-1,hunger.getSize().y));
        hunger.setTextureRect(sf::IntRect(0,0,hunger.getSize().x,40));
    }
    if(hunger.getSize().x/3<hungerlevel)
    {
        hunger.setSize(sf::Vector2f(hunger.getSize().x+2,hunger.getSize().y));
        hunger.setTextureRect(sf::IntRect(0,0,hunger.getSize().x,40));
    }

    if(water.getSize().x/3>thirst && water.getSize().x>0)
    {
        water.setSize(sf::Vector2f(water.getSize().x-1,water.getSize().y));
        water.setTextureRect(sf::IntRect(0,0,water.getSize().x,40));
    }
    if(water.getSize().x/3<thirst)
    {
        water.setSize(sf::Vector2f(water.getSize().x+1,water.getSize().y));
        water.setTextureRect(sf::IntRect(0,0,water.getSize().x,40));
    }
    if(h1.getPosition().x!=h2.getPosition().x)
        h1.move(1,0);
    if(hungerlevel>0 && h1.getPosition().x==h2.getPosition().x)
    {
        std::cout<<"HPBAR"<<std::endl;
        hungerlevel--;
        thirst--;
        h1.setPosition(0,0);
    }
    if((hungerlevel <= 0 || thirst<=0) && hp>0)
    {
        if(h1.getPosition().x==h2.getPosition().x)
        {
            hp-=1;
            h1.setPosition(0,0);
        }
    }
    hprep.setFillColor(sf::Color::Red);
    //hprep.setPosition(window.getSize().x/12.3,window.getSize().y/1.1);//130,820
    window.draw(hprep);
    window.draw(hpback);
    window.draw(hunger);
    window.draw(hungerback);
    window.draw(water);
    window.draw(waterback);
}

int Player::getPositionX()
{
    return playerPositionX;
}
int Player::getPositionY()
{
    return playerPositionY;
}
void Player::save()
{
    file.close();
    file.open("Sources/Saves/player.txt", std::ios::out);
    file<<player.getPosition().x<<std::endl;
    file<<player.getPosition().y<<std::endl;
    file<<hungerlevel<<std::endl;
    file<<thirst<<std::endl;
}
