#include "View.h"

View::View()
{
    view.setSize(1600,900);
    view.zoom(0.9);
    //view.zoom(9);
    //drawArea.setSize(sf::Vector2f(1600,900));
    drawArea.setSize(sf::Vector2f(1700,1000));
    drawArea.setOrigin(drawArea.getSize().x/2,drawArea.getSize().y/2);
    vs1.setPosition(0,0);
    vs2.setPosition(4,0);
    gpart.setSize(sf::Vector2f(1910,1070));
    /*for(int i = 0; i<14; i++)
        gplace.push_back(gpart);
    for(int i = 1; i<gplace.size(); i++)
    {
        gplace[i].setPosition(goright,elevate);
        goright += 1910;
        if(goright/1910 == 7)
        {
            elevate += 1070;
            goright = 0;
        }
    }*/
}

View::~View()
{
    //dtor
}
void View::setViewPos(int x, int y)
{
    view.setCenter(x,y);
    std::cout<<"view set"<<std::endl;
}

void View::viewFollow(int x , int y,float speed, sf::RectangleShape &drawing, int &lockr, int &lockl, int &locku, int &lockd, bool &plock)
{
    deltaTime = deltaClock.getElapsedTime();
    if(plock == false)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && lockl == 0)
    {
        view.move(-speed*deltaTime.asMilliseconds(),0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&lockr == 0)
    {
        view.move(speed*deltaTime.asMilliseconds(),0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&locku == 0)
    {
        view.move(0,-speed*deltaTime.asMilliseconds());
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)&&lockd == 0)
    {
        view.move(0,speed*deltaTime.asMilliseconds());
    }
    }
    drawing.setPosition(x,y);
    drawArea.setPosition(x,y);
    deltaClock.restart().asMilliseconds();
}

void View::screenShake(sf::View &v)
{
    //if(vs1.getPosition().x!=vs2.getPosition().x);
        v.move(100,0);
}
