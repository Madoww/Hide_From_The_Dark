#include "ItemPlacing.h"

ItemPlacing::ItemPlacing()
{
    rects.reserve(3);
    r1.setSize(sf::Vector2f(1,1));
    r2.setSize(sf::Vector2f(1,1));
    r1.setPosition(0,0);
    r2.setPosition(20,0);

    axetex.loadFromFile("Sources/Textures/axe.png");
    picktex.loadFromFile("Sources/Textures/pickaxe.png");
}

ItemPlacing::~ItemPlacing()
{
    //dtor
}

void ItemPlacing::ItemPlace(sf::RenderWindow &window, int ID, int craftStatus)
{
    if(placable == true && craftStatus == false)
    {
        rect.setPosition(worldPos);
        rect.setOrigin(propsize/2,propsize/2);
        rectspos.push_back(worldPos);
        rects.push_back(rect);
        itemID.push_back(ID);
        r1.setPosition(0,0);
        std::cout<<rects.size()<<std::endl;
    }
}

void ItemPlacing::drawObject(sf::RenderWindow &window)
{
    pixelPos = sf::Mouse::getPosition(window);
    worldPos = window.mapPixelToCoords(pixelPos);
}

void ItemPlacing::itemCheck()
{
    if(r1.getGlobalBounds().intersects(r2.getGlobalBounds()))
        placable = true;
    else
    {
        placable = false;
        r1.move(1,0);
    }
}
void ItemPlacing::itemRemove()
{

    for(int i = 0; i<rects.size(); i++)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
        if(worldPos.x>=rectspos[i].x -propsize/2  && worldPos.x <= rectspos[i].x+propsize/2 && worldPos.y>=rectspos[i].y - propsize/2&& worldPos.y <= rectspos[i].y+propsize/2)
        {
                rects.erase(rects.begin()+i);
                rectspos.erase(rectspos.begin()+i);
        }
        }
    }
}
int ItemPlacing::getID(int objectID)
{
    return objectID;
}
