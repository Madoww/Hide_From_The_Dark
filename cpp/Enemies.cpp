#include "Enemies.h"

Enemies::Enemies()
{
    enemytexture.loadFromFile("Sources/Textures/player.png");
    enemysprite.setTexture(enemytexture);
    agroCircle.setFillColor(sf::Color(111,111,111,128));
    agroCircle.setRadius(agroDist);
    srand(time(NULL));
    enemysprite.setOrigin(32,32);
    frect.setSize(sf::Vector2f(90,40));
    frect.setOrigin(0,frect.getSize().y/2);
    frect.setFillColor(sf::Color::Magenta);
    vs1.setPosition(0,0);
    vs2.setPosition(10,0);
    ewait1base.setPosition(0,0);
    ewait2base.setPosition(10,0);
    ewait1base.setSize(sf::Vector2f(1,1));
    ewait2base.setSize(sf::Vector2f(1,1));

    bloodpart.setFillColor(sf::Color::Red);
    bloodpart.setSize(sf::Vector2f(5,5));
    bloodpart.setOrigin(bloodpart.getSize().x/2,bloodpart.getSize().y/2);

    prot = 0;
}

Enemies::~Enemies()
{
    //dtor
}
void Enemies::spawnEnemy(int posX, int posY, bool nighttime)
{
    //if(nighttime == true&&enemies.size()<4)
    /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && enemies.size()<4)
    {
        //enemysprite.setPosition(posX-rand()%1920*2,posY-rand()%2160*2);
        //enemysprite.setPosition(posX-rand()%(-1920*4-1920*2)+1920*2, posY-rand()%(-2160*4-2160*2)+2160*2);
        enemysprite.setPosition(posX-rand()%200, posY-rand()%200);
        enemies.push_back(enemysprite);
        direction.push_back(sf::Vector2f(0,0));
        magnitude.push_back(0.0f);
        unitVector.push_back(sf::Vector2f(0,0));
        enemySpeed.push_back(180.0f);
        contact.push_back(0);
        ewait1.push_back(ewait1base);
        ewait2.push_back(ewait2base);
        erotation.emplace_back(0);
        edx.push_back(0);
        edy.push_back(0);
        curpos.push_back(sf::Vector2f(0,0));
        posit.push_back(sf::Vector2i(0,0));
    }*/
}
void Enemies::drawEnemies(sf::RenderWindow &window)
{
    for(int i = 0; i<enemies.size();i++)
    {
        window.draw(enemies[i]);
    }
}
void Enemies::agroing(sf::RenderWindow &window, sf::Vector2f ppos)
{
    agroCircle.setOrigin(agroDist,agroDist);
    agroCircle.setPosition(ppos);
    //window.draw(agroCircle);
}
void Enemies::follow(sf::Vector2f ppos, sf::RectangleShape prect, int &hp, std::vector<sf::RectangleShape>&water)
{
    deltaTime = deltaClock.getElapsedTime();

    for(int i = 0; i<ewait1.size(); i++)
    {
        if(ewait1[i].getPosition().x!=ewait2[i].getPosition().x)
            ewait1[i].move(1,0);
    }


    for(int i = 0; i<enemies.size();i++)
    {
        //if(enemies[i].getGlobalBounds().intersects(agroCircle.getGlobalBounds()) && contact[i]==0 && ewait1[i].getPosition().x==ewait2[i].getPosition().x)
        if(contact[i]==0 && ewait1[i].getPosition().x==ewait2[i].getPosition().x)
        {
            enemySpeed[i]= 250.f;

            direction[i] = sf::Vector2f(ppos-enemies[i].getPosition());
            magnitude[i] = sqrt((direction[i].x*direction[i].x)+(direction[i].y*direction[i].y));
            unitVector[i] = sf::Vector2f(direction[i].x/magnitude[i],direction[i].y/magnitude[i]);
            enemies[i].move(unitVector[i]*enemySpeed[i]*deltaTime.asSeconds());
        }
    }
    for(int j = 0; j<enemies.size();j++)
    {
        for(int i = 0; i<enemies.size();i++)
        {
            if(j!=i)
            {
                if(enemies[j].getGlobalBounds().intersects(enemies[i].getGlobalBounds()) && ewait1[i].getPosition().x==ewait2[i].getPosition().x)
                {
                    unitVector[j] = sf::Vector2f(-unitVector[i].x,-unitVector[i].y);
                    enemies[j].move(unitVector[j]*enemySpeed[j]*deltaTime.asSeconds());
                    contact[j]=1;
                }
                else
                    contact[j]=0;
            }
            if(contact.size()==1)
            {
                contact[0]=0;
            }
        }
        if(enemies[j].getGlobalBounds().intersects(prect.getGlobalBounds()))
        {
            if(ewait1[j].getPosition().x==ewait2[j].getPosition().x && hp>0)
            {
                hp-=10;
                ewait1[j].setPosition(-50,0);
            }
        }
        for(int i = 0; i<water.size(); i++)
        {
            if(enemies[j].getGlobalBounds().intersects(water[i].getGlobalBounds()))
            {
                enemySpeed[j] = 60.f;
                break;
            }
            else
                enemySpeed[j] = 100.f;
        }

    }
    deltaClock.restart().asSeconds();
}

void Enemies::fight(int x, int y, sf::RectangleShape &prect, std::vector<int>&slotID, int &slotnumber, sf::Sprite &player, sf::View &vv, int pposx, int pposy, std::vector<int>&durability,
                    bool& lockrot, sf::RenderWindow &window)
{
    curPos = prect.getPosition();
    position = sf::Vector2i(x,y);
    dx = curPos.x - position.x;
    dy = curPos.y - position.y;
    rotation = (atan2(dy,dx))*180/pi;
    frect.setPosition(prect.getPosition());
    frect.setRotation(rotation+180);
    if(lockrot == false)
    {
        player.setRotation(rotation-90);
    }



    if(vs1.getPosition().x != vs2.getPosition().x)
    {
        vs1.move(1,0);
    }

    if(prect.getPosition().x-vv.getCenter().x>=7 && prect.getPosition().x-vv.getCenter().x<=-7)
        {
            vv.setCenter(prect.getPosition());
        }
    for(int i = 0; i<enemies.size();i++)
    {
        curpos[i] = prect.getPosition();
        posit[i] = sf::Vector2i(enemies[i].getPosition());
        edx[i] = curpos[i].x - posit[i].x;
        edy[i] = curpos[i].y - posit[i].y;
        erotation[i] = (atan2(edx[i],edy[i]))*180/pi;
        enemies[i].setRotation(-erotation[i]+180);


        if(frect.getGlobalBounds().intersects(enemies[i].getGlobalBounds()) && frect.getGlobalBounds().intersects(prect.getGlobalBounds()))
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && slotID[slotnumber]==3 && vv.getCenter().x>=prect.getPosition().x-7&&vv.getCenter().x<=prect.getPosition().x+7)
            {
                shakeam = 5;
                bloodpart.setPosition(enemies[i].getPosition());
                for(int i = 0; i<20; i++)
                {
                    color = rand()%3+1;
                    if(color == 1 || color == 2)
                    {
                        bloodpart.setFillColor(sf::Color::Red);
                    }
                    if(color == 3)
                    {
                        bloodpart.setFillColor(sf::Color(40,40,40));
                    }
                    blood.push_back(bloodpart);
                    brec = -30+rand()%50+10;
                    brec = brec/10;
                    bdirec.push_back(brec);
                    upforce = -30+rand()%20+10;
                    upforce /= 10;
                    upword.push_back(upforce);
                }
                durability[slotnumber] -= 10;
                vs1.setPosition(0,0);
                shakeway = rand()%2;
                if(vs1.getPosition().x != vs2.getPosition().x)
                {
                    if(shakeway == 1)
                    vv.move(30,0);
                    else if(shakeway == 0)
                    {
                        vv.move(-30,0);
                    }
                }
                enemies.erase(enemies.begin()+i);
                enemySpeed.erase(enemySpeed.begin()+i);
                contact.erase(contact.begin()+i);
                isshaking = true;
                break;
            }
        }
    }
    for(int i = 0; i<blood.size(); i++)
        {
            window.draw(blood[i]);
            blood[i].move(bdirec[i],upword[i]);
            upword[i] += 0.1;
            blood[i].setFillColor(sf::Color(blood[i].getFillColor().r,blood[i].getFillColor().g,blood[i].getFillColor().b,blood[i].getFillColor().a-7));
            if(blood[i].getFillColor().a<=7)
            {
                blood.erase(blood.begin()+i);
                upword.erase(upword.begin()+i);
                bdirec.erase(bdirec.begin()+i);
            }
        }
    if(vs1.getPosition().x == vs2.getPosition().x && isshaking == true && shakeam > 0)
    {
        if(vv.getCenter().x >= pposx+6)
        {
            vv.move(-6,0);
            shakeam -=1;
        }
        if(vv.getCenter().x <= pposx-6)
        {
            vv.move(6,0);
            shakeam -=1;
        }
    }
    if(vv.getCenter().x>=prect.getPosition().x-1 && vv.getCenter().x<=prect.getPosition().x+1)
    {
        isshaking = false;
    }
}
