#include "Crafting.h"

Crafting::Crafting(sf::RenderWindow &window)
{
    file.open("Sources/Saves/res.txt", std::ios::in);
    /*if(file.good()==false)
    {
        file<<0<<std::endl;
        file<<0<<std::endl;
        file<<0<<std::endl;
        file<<0<<std::endl;
        file<<0<<std::endl;
    }*/
    if(file.good()==true)
    {
        while(std::getline(file,line))
        {
            switch(nrline)
            {
                case 1: woodAmount = atoi(line.c_str());
                break;
                case 2: stoneAmount = atoi(line.c_str());
                break;
                case 3: ironAmount = atoi(line.c_str());
                break;
                case 4: uncookedIron = atoi(line.c_str());
                break;
                case 5: oilAmount = atoi(line.c_str());
                break;
            }
            nrline++;
        }
    }
    if(file.good()==false)
    {
    file.close();
    file.open("Sources/Saves/res.txt", std::ios::out);

        file<<0<<std::endl;
        file<<0<<std::endl;
        file<<0<<std::endl;
        file<<0<<std::endl;
        file<<0<<std::endl;
    }
    frametex.loadFromFile("Sources/Textures/frame.png");
    for(int i=0;i<3;i++)
    {
        sf::Sprite frame;
        frame.setTexture(frametex);
        frame.setScale(1.5*4,1.5*4);
        frames.push_back(frame);
    }
    frames[0].setPosition(window.getSize().x,window.getSize().y/3);

    craftbase.setSize(sf::Vector2f(1,1));
    craftbase.setPosition(40,0);
    craftcheck.setSize(sf::Vector2f(1,1));
    craftcheck.setPosition(0,0);

    woodwalltex.loadFromFile("Sources/Textures/woodwall.png");
    woodwall.setTexture(woodwalltex);
    woodwall.setScale(1.1,1.1);

    stonewalltex.loadFromFile("Sources/Textures/stonewall.png");
    stonewall.setTexture(stonewalltex);
    stonewall.setScale(1.1,1.1);

    ironwalltex.loadFromFile("Sources/Textures/ironwall.png");
    ironwall.setTexture(ironwalltex);
    ironwall.setScale(1.1,1.1);


    buildcheck.setPosition(0,0);
    buildbase.setPosition(10,0);
    buildcheck.setSize(sf::Vector2f(1,1));
    buildbase.setSize(sf::Vector2f(1,1));

    rectobject.setTexture(woodwalltex);
    rectobject.setScale(1.5,1.5);
    //rectobject.setOrigin(rectobject.getGlobalBounds().width/2,rectobject.getGlobalBounds().height/2);
    rectobject.setColor(sf::Color(255,255,255,180));

}

void Crafting::save()
{
    file.close();
    file.open("Sources/Saves/res.txt",std::ios::out);
    file<<woodAmount<<std::endl;
    file<<stoneAmount<<std::endl;
    file<<ironAmount<<std::endl;
    file<<uncookedIron<<std::endl;
    file<<oilAmount<<std::endl;
}

void Crafting::placeCrafting(sf::RenderWindow &window)
{
    window.draw(frames[0]);
    for(int i = 1; i<3; i++)
    {
        frames[i].setPosition(frames[i-1].getPosition().x,frames[i-1].getPosition().y+frames[i-1].getGlobalBounds().height);
        window.draw(frames[i]);
    }
    window.draw(woodwall);
    window.draw(stonewall);
    window.draw(ironwall);
    if(craftcheck.getPosition().x!=craftbase.getPosition().x)
    {
        craftcheck.move(1,0);
    }
    woodwall.setPosition(frames[0].getPosition().x+13,frames[0].getPosition().y+13);
    stonewall.setPosition(frames[1].getPosition().x+13,frames[1].getPosition().y+13);
    ironwall.setPosition(frames[2].getPosition().x+13,frames[2].getPosition().y+13);

    /*if(frames[0].getPosition().x==1600)
    {
        craftStatus = false;
    }
    if(frames[0].getPosition().x==1500)
    {
        craftStatus = true;
    }*/
    if(craftStatus == true)
    {
        if(buildcheck.getPosition().x!=buildbase.getPosition().x)
        buildcheck.move(1,0);
        if(frames[0].getPosition().x>window.getSize().x-100)
        frames[0].move(-10,0);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::X) && craftcheck.getPosition().x==craftbase.getPosition().x)
        {
            craftcheck.setPosition(0,0);
            craftStatus = false;
        }
    }
    if(craftStatus == false)
    {
        if(frames[0].getPosition().x<window.getSize().x)
        frames[0].move(10,0);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::X) && craftcheck.getPosition().x==craftbase.getPosition().x)
        {
            craftcheck.setPosition(0,0);
            //craftStatus = true;
        }
    }
}

void Crafting::build(sf::Sprite &object, std::vector<sf::RectangleShape> &ground, int x, int y, sf::RenderWindow &window, std::vector<sf::Vector2f>&exwalls, sf::Sprite &framebuild, bool &furstat, std::vector<sf::Sprite>&trees, std::vector<sf::Sprite>&treeshadows,
                     std::vector<sf::Vector2f> &treespos, std::vector<sf::Sprite>&stones, std::vector<sf::Sprite>&stoneshadows, std::vector<sf::Vector2f>&stonepos, std::vector<sf::Sprite>&irons,
                     std::vector<sf::Sprite>&oils, bool benchstat, std::vector<sf::Sprite>&ironshadows, std::vector<sf::Sprite>&bottomtrees, bool hivestat, bool& fstat)
{
    for(int i=0;i<ground.size();i++)
    {
        if(x>=ground[i].getPosition().x && x<=ground[i].getPosition().x+64*1.5 && y >= ground[i].getPosition().y && y<=ground[i].getPosition().y+64*1.5 && (craftStatus == true|| furstat == true || benchstat == true || hivestat == true || fstat == true))
        {
            object.setPosition(ground[i].getPosition().x,ground[i].getPosition().y);
        }
    }
        if(craftStatus == true)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            buildnumber = 0;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            buildnumber = 1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            buildnumber = 2;
        framebuild.setPosition(frames[buildnumber].getPosition());
        window.draw(object);
        if(buildnumber == 0)
                {
                    object.setTexture(woodwalltex);
                }
                if(buildnumber == 1)
                {
                    object.setTexture(stonewalltex);
                }
                if(buildnumber == 2)
                {
                    object.setTexture(ironwalltex);
                }

    if(buildcheck.getPosition().x==buildbase.getPosition().x)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Sprite wallsprite;
                wallsprite.setScale(1.5,1.5);
                if(buildnumber == 0)
                {
                    wallsprite.setTexture(woodwalltex);
                    matstype = 1;
                }
                if(buildnumber == 1)
                {
                    wallsprite.setTexture(stonewalltex);
                    matstype = 2;
                }
                if(buildnumber == 2)
                {
                    wallsprite.setTexture(ironwalltex);
                    matstype = 3;
                }
                //wallsprite.setOrigin(32,32);
                wallsprite.setPosition(object.getPosition().x,object.getPosition().y);
                sf::Vector2f wallpos(wallsprite.getPosition().x,wallsprite.getPosition().y);

                for(int i = 0;i<walls.size();i++)
                {
                    if(wallpos.x == wallspos[i].x && wallpos.y == wallspos[i].y)
                    {
                        if(buildnumber == 0 && woodAmount >= woodreq)
                        {
                            woodAmount = woodAmount+woodreq;
                        }
                        if(buildnumber == 1 && stoneAmount >= stonereq)
                        {
                            stoneAmount = stoneAmount +stonereq;
                        }
                        if(buildnumber == 2 && ironAmount >= ironreq)
                        {
                            ironAmount += ironreq;
                        }
                        break;
                    }
                }
                for(int i = 0; i<trees.size(); i++)
                {
                    if(wallsprite.getGlobalBounds().intersects(trees[i].getGlobalBounds()))
                    {
                        trees.erase(trees.begin()+i);
                        treespos.erase(treespos.begin()+i);
                        treeshadows.erase(treeshadows.begin()+i);
                        bottomtrees.erase(bottomtrees.begin()+i);
                    }
                }
                for(int i = 0; i<stones.size(); i++)
                {
                    if(wallsprite.getGlobalBounds().intersects(stones[i].getGlobalBounds()))
                    {
                        stones.erase(stones.begin()+i);
                        stonepos.erase(stonepos.begin()+i);
                        stoneshadows.erase(stoneshadows.begin()+i);
                    }
                }
                for(int i = 0; i<irons.size(); i++)
                {
                    if(wallsprite.getGlobalBounds().intersects(irons[i].getGlobalBounds()))
                    {
                        irons.erase(irons.begin()+3);
                        ironshadows.erase(ironshadows.begin()+3);
                    }
                }
                for(int i = 0; i<oils.size(); i++)
                {
                    if(wallsprite.getGlobalBounds().intersects(oils[i].getGlobalBounds()))
                    {
                        oils.erase(oils.begin()+i);
                    }
                }

                if(buildnumber == 0 && woodAmount >= woodreq)
                {
                    woodAmount = woodAmount - woodreq;
                    imatsused = woodreq;
                    walls.push_back(wallsprite);
                    wallspos.push_back(wallpos);
                    wallstype.push_back(1);
                    wallshp.push_back(50);
                    matsused = true;
                }
                if(buildnumber == 1 && stoneAmount >= stonereq)
                {
                    stoneAmount = stoneAmount -stonereq;
                    imatsused = stonereq;
                    walls.push_back(wallsprite);
                    wallspos.push_back(wallpos);
                    wallstype.push_back(2);
                    wallshp.push_back(100);
                    matsused = true;
                }
                if(buildnumber == 2 && ironAmount >= ironreq)
                {
                    ironAmount -= ironreq;
                    imatsused = ironreq;
                    walls.push_back(wallsprite);
                    wallspos.push_back(wallpos);
                    wallstype.push_back(3);
                    wallshp.push_back(200);
                    matsused = true;
                }
                for(int j = 0;j<walls.size();j++)
                {
                    for(int i = 0;i<walls.size();i++)
                    {
                        if(j!=i)
                        {
                            if(wallspos[j].x == wallspos[i].x && wallspos[j].y == wallspos[i].y)
                            {
                                matsused = false;
                                if(buildnumber == 0 && wallstype[j]!=wallstype[i])
                                {
                                    woodAmount -= woodreq;
                                }
                                if(buildnumber == 1 && wallstype[j]!=wallstype[i])
                                {
                                    stoneAmount -= stonereq;
                                    matsused = true;
                                }
                                if(buildnumber == 2 && wallstype[j]!=wallstype[i])
                                {
                                    ironAmount -= ironreq;
                                    matsused = true;
                                }
                                walls.erase(walls.begin()+j);
                                wallspos.erase(wallspos.begin()+j);
                                wallshp.erase(wallshp.begin()+j);
                                wallstype.erase(wallstype.begin()+j);
                            }
                        }
                        /*if(j==walls.size()&&i==walls.size() && i==j)
                        {
                            walls.erase(walls.begin()+j);
                                wallspos.erase(wallspos.begin()+j);
                                wallshp.erase(wallshp.begin()+j);
                                wallstype.erase(wallstype.begin()+j);
                                if(buildnumber == 0 && wallstype[j]!=wallstype[i])
                                {
                                    woodAmount -= woodreq;
                                }
                                if(buildnumber == 1 && wallstype[j]!=wallstype[i])
                                {
                                    stoneAmount -= stonereq;
                                }
                        }*/
                    }
                }
                buildcheck.setPosition(0,0);
                //std::cout<<"stoneAmount: "<<stoneAmount<<std::endl;
                //std::cout<<"woodAmount: "<<woodAmount<<std::endl;
        }
    }
}
}

void Crafting::deleteObject(int x, int y, int &woodAm, int &stoneAm)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
    for(int i=0;i<walls.size();i++)
    {
        if(x>wallspos[i].x-32&&x<wallspos[i].x+32&&y>wallspos[i].y-32&&y<wallspos[i].y+32 && craftStatus == true)
        {
                if(wallstype[i]==1)
                woodAm = woodAm+3;
                if(wallstype[i]==2)
                stoneAm = stoneAm +3;
                walls.erase(walls.begin()+i);
                wallspos.erase(wallspos.begin()+i);
                wallshp.erase(wallshp.begin()+i);
                wallstype.erase(wallstype.begin()+i);
        }
        if(wallshp[i] <= 0)
        {
            walls.erase(walls.begin()+i);
            wallspos.erase(wallspos.begin()+i);
            wallshp.erase(wallshp.begin()+i);
            wallstype.erase(wallstype.begin()+i);
        }
    }
    }
}
void Crafting::wallTreeCollision(std::vector<sf::Sprite>&trees, std::vector<sf::Vector2f>&treespos, std::vector<sf::Sprite>&wall, std::vector<sf::Sprite>&treeshadows, std::vector<sf::Sprite>&chimneys,
                                 std::vector<sf::Sprite>&irons, std::vector<sf::Sprite>&oils, std::vector<sf::Sprite>&ironshadows)
{
    /*    for(int i = 0; i<trees.size(); i++)
        {
            for(int j = 0; j<wall.size(); j++)
            {
                if(trees[i].getGlobalBounds().intersects(wall[j].getGlobalBounds()))
                {
                    trees.erase(trees.begin()+i);
                    treespos.erase(treespos.begin()+i);
                    treeshadows.erase(treeshadows.begin()+i);
                }
            }
        }

    for(int i = 0; i<wall.size();i++)
    {
        for(int j = 0; j<irons.size(); j++)
        {
            if(walls[i].getGlobalBounds().intersects(irons[j].getGlobalBounds()))
            {
                irons.erase(irons.begin()+j);
            }
        }
        for(int j = 0; j<oils.size(); j++)
        {
            if(walls[i].getGlobalBounds().intersects(oils[j].getGlobalBounds()))
            {
                oils.erase(oils.begin()+j);
            }
        }
        for(int j = 0; j<chimneys.size(); j++)
        {
            if(walls[i].getGlobalBounds().intersects(chimneys[j].getGlobalBounds()))
            {
                chimneys.erase(chimneys.begin()+j);
            }
        }
    }

    for(int i = 0; i<trees.size();i++)
    {
        for(int j = 0; j<chimneys.size();j++)
        {
            if(trees[i].getGlobalBounds().intersects(chimneys[j].getGlobalBounds()))
            {
                trees.erase(trees.begin()+i);
                treeshadows.erase(treeshadows.begin()+i);
                treespos.erase(treespos.begin()+i);
            }
        }
    }*/
}
void Crafting::wallStoneCollision(std::vector<sf::Sprite>&stones, std::vector<sf::Vector2f>&stonespos, std::vector<sf::Sprite>&wall, std::vector<sf::Sprite>&stoneshadows
                                  , std::vector<sf::Sprite>&irons, std::vector<sf::Sprite>&ironshadows)
{
    if(stones.size()>=1 && wall.size()>=1)
    {
        for(int j = 0; j<wall.size();++j)
        {
            for(int i = 0; i<stones.size();++i)
            {
                if(wall[j].getGlobalBounds().intersects(stones[i].getGlobalBounds()))
                {
                    stones.erase(stones.begin()+i);
                    stonespos.erase(stonespos.begin()+i);
                    stoneshadows.erase(stoneshadows.begin()+i);
                    break;
                }

            }
            for(int i = 0; i<irons.size(); i++)
            {
                if(wall[j].getGlobalBounds().intersects(irons[i].getGlobalBounds()))
                {
                    irons.erase(irons.begin()+i);
                    ironshadows.erase(ironshadows.begin()+i);
                    break;
                }
            }
        }

    }
}

void Crafting::enemyCollision(std::vector<sf::Sprite>&enemy, std::vector<float> &espeed)
{
    for(int i = 0; i<enemy.size();i++)
    {
        for(int j = 0; j<walls.size();j++)
        {
            if(enemy[i].getGlobalBounds().intersects(walls[j].getGlobalBounds()))
            {
                espeed[i] = 0;
                wallshp[j] -= 1;
                if(wallshp[j]<=0)
                {
                    espeed[i]=160.f;
                }
                break;
            }
            else if(!enemy[i].getGlobalBounds().intersects(walls[j].getGlobalBounds()))
            {
                espeed[i] = 100.0f;
            }
        }
    }
    if(enemy.size()==1)
    {
            espeed[0] = 160.0f;
    }
}
Crafting::~Crafting()
{
    //dtor
}
