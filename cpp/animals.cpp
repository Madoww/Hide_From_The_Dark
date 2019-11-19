#include "animals.h"

beeClass::beeClass()
{
    beetex.loadFromFile("Sources/Textures/bee.png");
    bee.setTexture(beetex);
    bee.setOrigin(8,8);
    r1.setPosition(0,0);
    r2.setPosition(500,0);
    //bee.setScale(30,30);
    //bee.setPosition(rand()%+2000, rand()%+2000);
}

beeClass::~beeClass()
{
    //dtor
}

void beeClass::setTarget(sf::Sprite flower, bool nighttime)
{
    direction = sf::Vector2f(bee.getPosition().x-flower.getPosition().x-26,bee.getPosition().y-flower.getPosition().y+38);
    magnitude = sqrt((direction.x*direction.x)+(direction.y*direction.y));
    unitVector = sf::Vector2f(direction.x/magnitude,direction.y/magnitude);
    curpos = bee.getPosition();
    posit = sf::Vector2i(flower.getPosition());
    dx = curpos.x - posit.x;
    dy = curpos.y - posit.y;
    rotation = (atan2(dx,dy))*180/3.14;
    bee.setRotation(-rotation);
    bee.move(-unitVector);
    if(bee.getGlobalBounds().intersects(flower.getGlobalBounds()))
    {
        r1.move(1,0);
    }
    if(r1.getPosition().x==r2.getPosition().x && nighttime == false)
    {
        r1.setPosition(0,0);
        hasTarget = false;
    }
}

void beeClass::bmove()
{
    bee.move(-unitVector);
}

deerSpawn::deerSpawn(float x, float y)
{
    dspawntex.loadFromFile("Sources/Textures/dhouse.png");
    dspawn.setTexture(dspawntex);
    dspawn.setScale(4,4);
    dspawn.setPosition(x,y);
}
deerSpawn::~deerSpawn()
{

}
meatClass::meatClass()
{
    meattex.loadFromFile("Sources/Textures/meat.png");
    meat.setTexture(meattex);
    meat.setScale(4,4);
}
meatClass::~meatClass()
{

}
void meatClass::drop(float x, float y)
{
    meat.setPosition(x,y);
    meats.push_back(meat);
}
void meatClass::pickup(int x, int y, std::vector<int>&slotID, std::vector<int>&durability)
{
    for(int j = 0; j<meats.size(); j++)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && x > meats[j].getPosition().x && x < meats[j].getPosition().x+meats[j].getGlobalBounds().width && y > meats[j].getPosition().y && y < meats[j].getPosition().y + meats[j].getGlobalBounds().height && moves[j].x == 0)
        for(int i = 1; i<slotID.size(); i++)
        {
            if(slotID[i] == 0 || (slotID[i]==6&&durability[i]<4))
            {
                durability[i] += 1;
                slotID[i] = 6;
                meats.erase(meats.begin()+j);
                moves.erase(moves.begin()+j);
                exited = true;
                goto bpoint;
            }
        }
    }

    if(meats.size()>5)
    {
        meats.erase(meats.begin());
        moves.erase(moves.begin());
    }
    if(exited == true)
    {
        bpoint:
            exited = false;
    }
    for(int i = 1; i<slotID.size(); i++)
        {
            if(slotID[i] == 7)
            {
                for(int g = 1; g<slotID.size(); g++)
                {
                    if(g!=i)
                    {
                        if(slotID[g]==7 && durability[g]+durability[i]<=4)
                        {
                            durability[i]+=durability[g];
                            durability[g] = 0;
                            slotID[g] = 0;
                            break;
                        }
                        if(slotID[g] == 7 && durability[g] == 3)
                        {
                            durability[i]-=1;
                            durability[g] += 1;
                            break;
                        }
                    }
                }
            }
        }
}
void meatClass::draw(sf::RenderTarget &window)
{
    for(int i = 0; i<meats.size(); i++)
    {
        if(moves[i].x>0)
        moves[i].x-=0.5;
        if(moves[i].y<0)
        moves[i].y+=0.5;
        meats[i].move(moves[i]);
        window.draw(meats[i]);
    }
}



deerClass::deerClass()
{
    deertex.loadFromFile("Sources/Textures/deer.png");
    deer.setTexture(deertex);
    deer.setOrigin(8,8);
    deer.setScale(8,8);
    deerDirection.setSize(sf::Vector2f(10,10));
    agro.setSize(sf::Vector2f(200,200));
}

void deerClass::dmove(sf::RectangleShape direct,std::vector<sf::RectangleShape>&grass, float &x, float& y, int &slotID, sf::Sprite& dspawn, sf::Sprite &meat, std::vector<sf::Sprite>&meats
                      ,std::vector<sf::Vector2f>&moves, sf::RectangleShape &prect, std::vector<sf::Sprite>&walls, sf::CircleShape& harv, int& durab)
{
    agro.setOrigin(agro.getGlobalBounds().width/2,agro.getGlobalBounds().height/2);
    agro.setPosition(deer.getPosition());
    direction = sf::Vector2f(deer.getPosition().x-direct.getPosition().x-26,deer.getPosition().y-direct.getPosition().y+38);
    magnitude = sqrt((direction.x*direction.x)+(direction.y*direction.y));
    unitVector = sf::Vector2f(direction.x/magnitude,direction.y/magnitude);
    curpos = deer.getPosition();
    posit = sf::Vector2i(deerDirection.getPosition());
    dx = curpos.x - posit.x;
    dy = curpos.y - posit.y;
    rotation = (atan2(dx,dy))*180/3.14;
    if(prect.getGlobalBounds().intersects(agro.getGlobalBounds()))
    {
        speed = 3;
        agro.setSize(sf::Vector2f(700,700));
    }
    else
    {
        speed = 1;
        agro.setSize(sf::Vector2f(400,400));
    }
    for(int i = 0; i<walls.size(); i++)
    {
        if(deer.getGlobalBounds().intersects(walls[i].getGlobalBounds()) && wallcontact == false)
        {
            //deerDirection.setPosition(sf::Vector2f(deer.getPosition().x-sqrt(pow(deerDirection.getPosition().x-deer.getPosition().x,2)+pow(deerDirection.getPosition().y-deer.getPosition().y,2)),deer.getPosition().y));
            //deerDirection.setPosition(deerDirection.getPosition().x-deer.getPosition().x,deerDirection.getPosition().y-deer.getPosition().y);
            if(deer.getPosition().x > deerDirection.getPosition().x)
            {
                deerDirection.setPosition(deer.getPosition().x+800,deer.getPosition().y+rand()%800-400);
                deer.setPosition(deer.getPosition().x+10,deer.getPosition().y);
                //break;
            }
            else if(deer.getPosition().x <= deerDirection.getPosition().x)
            {
                deerDirection.setPosition(deer.getPosition().x-800,deer.getPosition().y+rand()%800-400);
                deer.setPosition(deer.getPosition().x-10,deer.getPosition().y);
                //break;
            }
            if(deer.getPosition().y > deerDirection.getPosition().y)
            {
                deerDirection.setPosition(deer.getPosition().x+rand()%800-400,deer.getPosition().y-800);
                deer.setPosition(deer.getPosition().x,deer.getPosition().y-20);
            }
            if(deer.getPosition().y < deerDirection.getPosition().y)
            {
                deerDirection.setPosition(deer.getPosition().x+rand()%800-400,deer.getPosition().y+800);
                deer.setPosition(deer.getPosition().x,deer.getPosition().y+20);
            }
            wallcontact = true;
        }
        else if(!deer.getGlobalBounds().intersects(walls[i].getGlobalBounds()))
            wallcontact = false;
    }

    if(tocheck == false)
    {
        deer.move(-unitVector*speed);
        deer.setRotation(-rotation-90);
    }
    if(deer.getGlobalBounds().intersects(deerDirection.getGlobalBounds()))
    {
        tocheck = true;
    }
    if(tocheck == true)
    {
        deerDirection.setPosition(deer.getPosition().x-1000+rand()%2000,deer.getPosition().y-1000+rand()%2000);
        for(int i = 0; i<grass.size(); i++)
        {
            if(deerDirection.getPosition().x >= grass[i].getPosition().x && deerDirection.getPosition().x <= grass[i].getPosition().x+64 && deerDirection.getPosition().y >= grass[i].getPosition().y && deerDirection.getPosition().y <= grass[i].getPosition().y+64)
            {
                tocheck = false;
                break;
            }
        }
    }
    if(x > deer.getPosition().x  - deer.getGlobalBounds().width/2&& x < deer.getPosition().x + deer.getGlobalBounds().width/2 && y> deer.getPosition().y - deer.getGlobalBounds().height/2 && y < deer.getPosition().y+deer.getGlobalBounds().height/2)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && slotID == 3 && deer.getGlobalBounds().intersects(harv.getGlobalBounds()))
        {
            meat.setPosition(deer.getPosition());
            meats.push_back(meat);
            moves.push_back(sf::Vector2f(9,-5));
            deer.setPosition(dspawn.getPosition());
            durab-=rand()%10+10;
        }
    }
}

deerClass::~deerClass()
{
    //dtor
}











