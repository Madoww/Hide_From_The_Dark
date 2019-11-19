#include "Trees.h"

Trees::Trees()
{
    file.open("Sources/Saves/save.txt",std::ios::in);
    trees.reserve(2);
    treetex.loadFromFile("Sources/Textures/treepix.png");
    treeshadowtex.loadFromFile("Sources/Textures/treeshadowtex.png");
    stonetex.loadFromFile("Sources/Textures/stonestand.png");
    harv.setRadius(treedist);
    harv.setOrigin(treedist,treedist);
    oiltex.loadFromFile("Sources/Textures/oil.png");
    irontex.loadFromFile("Sources/Textures/ironstand.png");
    woodlog.loadFromFile("Sources/Textures/woodlog.png");
    rock.loadFromFile("Sources/Textures/rock.png");
    shroomtex.loadFromFile("Sources/Textures/mushroom.png");

    harv1.setSize(sf::Vector2f(1,1));
    harv2.setSize(sf::Vector2f(1,1));
    harv1.setPosition(0,0);
    harv2.setPosition(30,0);

    buffer.loadFromFile("Sources/Sounds/tree.wav");
    treechop.setVolume(10);
    treechop.setBuffer(buffer);

    rockbuffer.loadFromFile("Sources/Sounds/rock.wav");
    rockhit.setBuffer(rockbuffer);
    rockhit.setVolume(10);

    part.setSize(sf::Vector2f(5,5));
    treestandtex.loadFromFile("Sources/Textures/treestand.png");

    trees.reserve(2530);
    stones.reserve(450);
    irons.reserve(200);
    woodlogs.reserve(300);
    rocks.reserve(300);
    windsound.openFromFile("Sources/Sounds/wind.wav");
    crickets.openFromFile("Sources/Sounds/crickets.wav");
    srand(time(NULL));
}

Trees::~Trees()
{
    //dtor
}

void Trees::placeResources(int treesAm, int stonesAm, int ironsAm, int logsAm, int rocksAm, std::vector<sf::RectangleShape>&water, std::vector<sf::RectangleShape>&grass, std::vector<sf::RectangleShape>&sand)
{
    if(resplacedone == false && file.good()==false)
    {
        file.open("Sources/Saves/save.txt", std::ios::out);
    for(int i = 0; i<treesAm; i++)
    {
        sf::Sprite treesprite;
        sf::Sprite bottomtree;
        treesprite.setTexture(treetex);
        bottomtree.setTexture(treestandtex);
        treesprite.setScale(1.6*6,1.6*6);
        bottomtree.setScale(1.6*6,1.6*6);
        posvec.x = rand()%xplace+1;
        posvec.y = rand()%yplace+1;
        treesprite.setOrigin(8,19);
        bottomtree.setOrigin(8,19);
        posvec.x -= 8;
        posvec.y -= 16;
        treesprite.setPosition(posvec.x,posvec.y);
        bottomtree.setPosition(posvec.x,posvec.y);
        for(int j = 0; j<water.size();j++)
        {
            if(treesprite.getGlobalBounds().intersects(water[j].getGlobalBounds()))
            {
                goto dont;
            }
        }
        wind.push_back(true);
        treesprite.setRotation(rand()%10);
        trees.emplace_back(treesprite);
        bottomtrees.emplace_back(bottomtree);
        treeshp.push_back(treehp);
        treepos.push_back(posvec);
        dont:
            char throwaway;
    }
    for(int i = 0; i<stonesAm; i++)
    {
        sf::Sprite stonesprite;
        stonesprite.setTexture(stonetex);
        stonesprite.setScale(1.2*6,1.2*6);
        posvec.x = rand()%xplace+1;
        posvec.y = rand()%yplace+1;
        stonesprite.setPosition(posvec.x,posvec.y);
        for(int j = 0; j<water.size();j++)
        {
            if(stonesprite.getGlobalBounds().intersects(water[j].getGlobalBounds()))
            {
                goto dont2;
            }
        }
        stones.push_back(stonesprite);
        stonepos.push_back(posvec);
        stoneshp.push_back(stonehp);
        dont2:
            char throwaway;
    }
    for(int i = 0; i < oilAm; i++)
    {
        sf::Sprite oil;
        oil.setTexture(oiltex);
        oil.setScale(6,6);
        goback:
        posvec.x = rand()%xplace+1;
        posvec.y = rand()%yplace+1;
        oil.setPosition(posvec.x,posvec.y);
        for(int j = 0; j<water.size();j++)
        {
            if(oil.getGlobalBounds().intersects(water[j].getGlobalBounds()))
            {
                goto dont3;
            }
        }
        for(int j = 0; j<grass.size(); j++)
        {
            if(oil.getGlobalBounds().intersects(grass[j].getGlobalBounds()))
            {
                goto goback;
            }
        }
        oils.push_back(oil);
        dont3:
            char throwaway;
    }
    for(int i = 0; i<ironsAm; i++)
    {
        sf::Sprite iron;
        iron.setTexture(irontex);
        iron.setScale(1.2*6,1.2*6);
        posvec.x = rand()%xplace+1;
        posvec.y = rand()%yplace+1;
        iron.setPosition(posvec.x,posvec.y);
        for(int j = 0; j<water.size();j++)
        {
            if(iron.getGlobalBounds().intersects(water[j].getGlobalBounds()))
            {
                goto dont4;
            }
        }
        irons.push_back(iron);
        ironshp.push_back(ironhp);
        dont4:
            char throwaway;
    }

    for(int i = 0; i<logsAm; i++)
    {
        sf::Sprite log;
        log.setTexture(woodlog);
        log.setScale(0.6*4,0.6*4);
        posvec.x = rand()%xplace+1;
        posvec.y = rand()%yplace+1;
        log.setPosition(posvec.x,posvec.y);
        for(int j = 0; j<water.size(); j++)
        {
            if(log.getGlobalBounds().intersects(water[j].getGlobalBounds()))
            {
                goto dont5;
            }
        }
        woodlogs.push_back(log);
        dont5:
            char throwaway;
    }
    for(int i = 0; i<shroomsam; i++)
    {
        sf::Sprite mush;
        mush.setTexture(shroomtex);
        mush.setScale(0.6*4,0.6*4);
        mush.setPosition(rand()%xplace,rand()%yplace);
        for(int j = 0; j<water.size(); j++)
        {
            if(mush.getGlobalBounds().intersects(water[j].getGlobalBounds()))
            {
                //goto noshroom;
            }
        }
        shrooms.push_back(mush);
        noshroom:
           char throwaway;
    }
    for(int i = 0; i<rocksAm; i++)
    {
        sf::Sprite rocksp;
        rocksp.setTexture(rock);
        rocksp.setScale(0.6*4,0.6*4);
        posvec.x = rand()%xplace+1;
        posvec.y = rand()%yplace+1;
        rocksp.setPosition(posvec.x, posvec.y);
        for(int j = 0; j<water.size(); j++)
        {
            if(rocksp.getGlobalBounds().intersects(water[j].getGlobalBounds()))
            {
                goto dont6;
            }
        }
        rocks.push_back(rocksp);
        dont6:
        char throwaway;
    }

    for(int j = 0; j<trees.size();j++)
    {
        for(int i = 0; i<trees.size(); i++)
        {
            if(trees[j].getGlobalBounds().intersects(trees[i].getGlobalBounds()))
            {
                trees.erase(trees.begin()+i);
                treepos.erase(treepos.begin()+i);
                treeshp.erase(treeshp.begin()+i);
                bottomtrees.erase(bottomtrees.begin()+i);
            }
        }
        for(int i = 0; i<stones.size();i++)
        {
            if(trees[j].getGlobalBounds().intersects(stones[i].getGlobalBounds()))
            {
                stones.erase(stones.begin()+i);
                stonepos.erase(stonepos.begin()+i);
                stoneshp.erase(stoneshp.begin()+i);
            }
        }
    }

    for(int i = 0; i<trees.size(); i++)
    {
        for(int j = 0; j<sand.size(); j++)
        {
            if(bottomtrees[i].getGlobalBounds().intersects(sand[j].getGlobalBounds()))
            {
                trees.erase(trees.begin()+i);
                treepos.erase(treepos.begin()+i);
                treeshp.erase(treeshp.begin()+i);
                bottomtrees.erase(bottomtrees.begin()+i);
            }
        }
    }
    for(int j = 0; j < oils.size(); j++)
    {
        for(int i = 0; i<trees.size();i++)
        {
            if(oils[j].getGlobalBounds().intersects(trees[i].getGlobalBounds()))
            {
                trees.erase(trees.begin()+i);
                treepos.erase(treepos.begin()+i);
                treeshp.erase(treeshp.begin()+i);
                bottomtrees.erase(bottomtrees.begin()+i);
            }
        }
        for(int i = 0; i<stones.size(); i++)
        {
            if(oils[j].getGlobalBounds().intersects(stones[i].getGlobalBounds()))
            {
                stones.erase(stones.begin()+i);
                stonepos.erase(stonepos.begin()+i);
                stoneshp.erase(stoneshp.begin()+i);
            }
        }
        for(int i = 0; i<irons.size(); i++)
        {
            if(oils[j].getGlobalBounds().intersects(irons[i].getGlobalBounds()))
            {
                irons.erase(irons.begin()+i);
                ironshp.erase(ironshp.begin()+i);
            }
        }
    }


    for(int j = 0; j<stones.size(); j++)
    {
        for(int i = 0; i<stones.size();i++)
        {
            if(stones[j].getGlobalBounds().intersects(stones[i].getGlobalBounds()))
            {
                stones.erase(stones.begin()+i);
                stonepos.erase(stonepos.begin()+i);
                stoneshp.erase(stoneshp.begin()+i);
            }
        }
    }


    for(int j = 0; j<irons.size(); j++)
    {
        for(int i = 0; i<irons.size(); i++)
        {
            if(irons[j].getGlobalBounds().intersects(irons[i].getGlobalBounds()))
            {
                irons.erase(irons.begin()+i);
                ironshp.erase(ironshp.begin()+i);
            }
        }
        for(int i = 0; i<trees.size(); i++)
        {
            if(irons[j].getGlobalBounds().intersects(trees[i].getGlobalBounds()))
            {
                trees.erase(trees.begin()+i);
                treepos.erase(treepos.begin()+i);
                treeshp.erase(treeshp.begin()+i);
                bottomtrees.erase(bottomtrees.begin()+i);
            }
        }
        for(int i = 0; i<stones.size(); i++)
        {
            if(irons[j].getGlobalBounds().intersects(stones[i].getGlobalBounds()))
            {
                stones.erase(stones.begin()+i);
                stonepos.erase(stonepos.begin()+i);
                stoneshp.erase(stoneshp.begin()+i);
            }
        }
    }

    for(int i = 0; i<trees.size();i++)
    {
        sf::Sprite treeshadow;
        treeshadow.setTexture(treeshadowtex);
        treeshadow.setColor(sf::Color(1,1,1,130));
        treeshadow.setOrigin(treeshadow.getGlobalBounds().width/2,treeshadow.getGlobalBounds().height+2);
        treeshadow.setPosition(trees[i].getPosition().x,trees[i].getPosition().y-8);
        treeshadow.setRotation(0);
        treeshadow.setScale(trees[0].getScale());
        treeshadows.push_back(treeshadow);
    }
    for(int i = 0; i<stones.size();i++)
    {
        sf::Sprite stoneshadow;
        stoneshadow.setTexture(stonetex);
        stoneshadow.setColor(sf::Color(1,1,1,130));
        stoneshadow.setOrigin(stoneshadow.getGlobalBounds().width/2,stoneshadow.getGlobalBounds().height);
        stoneshadow.setPosition(stones[i].getPosition().x+stones[i].getGlobalBounds().width/2,stones[i].getPosition().y+stones[i].getGlobalBounds().height-18-10);
        stoneshadow.setRotation(0);
        stoneshadow.setScale(stones[0].getScale());
        stoneshadows.push_back(stoneshadow);
    }
    for(int i = 0; i<irons.size(); i++)
    {
        sf::Sprite ironshadow;
        ironshadow.setTexture(irontex);
        ironshadow.setColor(sf::Color(1,1,1,130));
        ironshadow.setOrigin(ironshadow.getGlobalBounds().width/2,ironshadow.getGlobalBounds().height);
        ironshadow.setPosition(irons[i].getPosition().x+irons[i].getGlobalBounds().width/2,irons[i].getPosition().y+irons[i].getGlobalBounds().height-28);
        ironshadow.setRotation(0);
        ironshadow.setScale(irons[0].getScale());
        ironshadows.push_back(ironshadow);
    }
    for(int i = 0; i<trees.size(); i++)
    {
        file<<trees[i].getPosition().x<<std::endl;
        file<<trees[i].getPosition().y<<std::endl;
    }
    file<<">>>0<<<"<<std::endl;
    for(int i = 0; i<stones.size();i++)
    {
        file<<stones[i].getPosition().x<<std::endl;
        file<<stones[i].getPosition().y<<std::endl;
    }
    file<<">>>1<<<"<<std::endl;
    for(int i = 0; i<irons.size(); i++)
    {
        file<<irons[i].getPosition().x<<std::endl;
        file<<irons[i].getPosition().y<<std::endl;
    }
    resplacedone = true;
    }
    else if(resplacedone == false && file.good()==true)
    {
        while(std::getline(file,line))
        {
            if(line==">>>0<<<" || line==">>>1<<<")
                loadlevel++;
            if(loadlevel == 0)
                tsize++;
            if(loadlevel == 1)
                ssize++;
            if(loadlevel == 2)
                isize++;
        }
        std::cout<<"size: "<<isize<<std::endl;
        int* positions = new int[tsize];
        int* spositions = new int[ssize];
        int* ipositions = new int[isize];
        int loadline = 0;
        file.clear();
        file.seekg(0);
        loadlevel = 0;
        while(std::getline(file,line))
        {
            if(loadline>=tsize && loadlevel == 0)
            {
                loadline = 0;
                loadlevel = 1;
                goto skip;
            }
            if(loadline>=ssize && loadlevel == 1)
            {
                loadline = 0;
                loadlevel = 2;
                goto skip;
            }
            if(loadline<tsize && loadlevel == 0)
            {
                if(line != ">>>0<<<" && line != ">>>1<<<" && line!=">>>2<<<")
                {
                    positions[loadline] = atoi(line.c_str());
                    loadline++;
                }

            }
            if(loadline < ssize && loadlevel == 1)
            {
                if(line != ">>>0<<<" && line != ">>>1<<<" && line!=">>>2<<<")
                {
                    spositions[loadline] = atoi(line.c_str());
                    loadline++;
                }

            }
            if(loadline < isize && loadlevel == 2)
            {
                if(line != ">>>0<<<" && line != ">>>1<<<" && line!=">>>2<<<")
                {
                    ipositions[loadline] = atoi(line.c_str());
                    loadline++;
                }

            }
            skip:
                char throwaway;
        }
        for(int i = 0; i<tsize/2;i++)
        {
                    sf::Sprite treesprite;
                    sf::Sprite bottomtree;
                    treesprite.setTexture(treetex);
                    bottomtree.setTexture(treestandtex);
                    treesprite.setScale(1.6*6,1.6*6);
                    bottomtree.setScale(1.6*6,1.6*6);
                    treesprite.setOrigin(8,19);
                    bottomtree.setOrigin(8,19);
                    //treesprite.setPosition(posvec.x,posvec.y);
                    //bottomtree.setPosition(posvec.x,posvec.y);
                    treesprite.setRotation(rand()%10);
                    wind.push_back(true);
                    trees.emplace_back(treesprite);
                    bottomtrees.emplace_back(bottomtree);
                    treeshp.push_back(treehp);
                    treepos.push_back(posvec);
                    sf::Sprite treeshadow;
                    treeshadow.setTexture(treeshadowtex);
                    treeshadow.setColor(sf::Color(1,1,1,130));
                    treeshadow.setOrigin(treeshadow.getGlobalBounds().width/2,treeshadow.getGlobalBounds().height+2);
                    treeshadow.setPosition(treesprite.getPosition().x,treesprite.getPosition().y-8);
                    treeshadow.setRotation(0);
                    treeshadow.setScale(trees[0].getScale());
                    treeshadows.push_back(treeshadow);
        }

        for(int i = 0; i<ssize/2;i++)
        {
            sf::Sprite stonesprite;
            stonesprite.setTexture(stonetex);
            stonesprite.setScale(1.2*6,1.2*6);
            sf::Sprite stoneshadow;
            stoneshadow.setTexture(stonetex);
            stoneshadow.setColor(sf::Color(1,1,1,130));
            stoneshadow.setOrigin(stoneshadow.getGlobalBounds().width/2,stoneshadow.getGlobalBounds().height);
            //stoneshadow.setPosition(stones[i].getPosition().x+stones[i].getGlobalBounds().width/2,stones[i].getPosition().y+stones[i].getGlobalBounds().height-18-10);
            stoneshadow.setRotation(0);
            stoneshadow.setScale(1.2*6,1.2*6);
            stoneshadows.push_back(stoneshadow);
            stones.push_back(stonesprite);
            stonepos.push_back(posvec);
            stoneshp.push_back(stonehp);
        }

        for(int i = 0; i<isize/2;i++)
        {
            sf::Sprite iron;
            iron.setTexture(irontex);
            iron.setScale(1.2*6,1.2*6);
            sf::Sprite ironshadow;
            ironshadow.setTexture(irontex);
            ironshadow.setColor(sf::Color(1,1,1,130));
            ironshadow.setOrigin(ironshadow.getGlobalBounds().width/2,ironshadow.getGlobalBounds().height);
            ironshadow.setRotation(0);
            ironshadow.setScale(1.2*6,1.2*6);
            ironshadows.push_back(ironshadow);
            irons.push_back(iron);
            ironshp.push_back(ironhp);
        }
        for(int i = 0; i<logsAm; i++)
    {
        sf::Sprite log;
        log.setTexture(woodlog);
        log.setScale(0.6*4,0.6*4);
        posvec.x = rand()%xplace+1;
        posvec.y = rand()%yplace+1;
        log.setPosition(posvec.x,posvec.y);
        for(int j = 0; j<water.size(); j++)
        {
            if(log.getGlobalBounds().intersects(water[j].getGlobalBounds()))
            {
                goto dont15;
            }
        }
        woodlogs.push_back(log);
        dont15:
            char throwaway;
    }

    for(int i = 0; i<rocksAm; i++)
    {
        sf::Sprite rocksp;
        rocksp.setTexture(rock);
        rocksp.setScale(0.6*4,0.6*4);
        posvec.x = rand()%xplace+1;
        posvec.y = rand()%yplace+1;
        rocksp.setPosition(posvec.x, posvec.y);
        for(int j = 0; j<water.size(); j++)
        {
            if(rocksp.getGlobalBounds().intersects(water[j].getGlobalBounds()))
            {
                goto dont16;
            }
        }
        rocks.push_back(rocksp);
        dont16:
        char throwaway;
    }
        int linetouse = 0;
        for(int i = 0; i<trees.size(); i++)
        {
            trees[i].setPosition(positions[linetouse],positions[linetouse+1]);
            bottomtrees[i].setPosition(trees[i].getPosition());
            treeshadows[i].setPosition(trees[i].getPosition().x,trees[i].getPosition().y-8);
            linetouse+=2;
        }
        linetouse = 0;
        for(int i = 0; i<stones.size(); i++)
        {
            stones[i].setPosition(spositions[linetouse], spositions[linetouse+1]);
            stoneshadows[i].setPosition(stones[i].getPosition().x+stones[i].getGlobalBounds().width/2,stones[i].getPosition().y+stones[i].getGlobalBounds().height-18-10);
            linetouse+=2;
        }
        linetouse=0;
        for(int i = 0; i<irons.size();i++)
        {
            irons[i].setPosition(ipositions[linetouse],ipositions[linetouse+1]);
            ironshadows[i].setPosition(irons[i].getPosition().x+irons[i].getGlobalBounds().width/2,irons[i].getPosition().y+irons[i].getGlobalBounds().height-28);
            linetouse+=2;
        }
        for(int i = 0; i < oilAm; i++)
    {
        sf::Sprite oil;
        oil.setTexture(oiltex);
        oil.setScale(6,6);
        posvec.x = rand()%xplace+1;
        posvec.y = rand()%yplace+1;
        oil.setPosition(posvec.x,posvec.y);
        for(int j = 0; j<water.size();j++)
        {
            if(oil.getGlobalBounds().intersects(water[j].getGlobalBounds()))
            {
                goto goback2;
            }
        }
        for(int j = 0; j<grass.size(); j++)
        {
            if(!oil.getGlobalBounds().intersects(grass[j].getGlobalBounds()))
            {
                goto goback2;
            }
        }
        //if(grass.size()!=0)
        //oil.setPosition(grass[rand()%grass.size()].getPosition());
        oils.push_back(oil);
        goback2:
            char throwaway;
    }
    for(int i = 0; i<shroomsam; i++)
    {
        sf::Sprite mush;
        mush.setTexture(shroomtex);
        mush.setScale(0.6*4,0.6*4);
        mush.setPosition(rand()%xplace,rand()%yplace);
        for(int j = 0; j<water.size(); j++)
        {
            if(mush.getGlobalBounds().intersects(water[j].getGlobalBounds()))
            {
                goto noshroom2;
            }
        }
        shrooms.push_back(mush);
        noshroom2:
            char throwaway;
    }
        resplacedone = true;
    }
}
void Trees::save()
{
    file.close();
    file.open("Sources/Saves/save.txt",std::ios::out);
    for(int i = 0; i<trees.size();i++)
    {
        file<<trees[i].getPosition().x<<std::endl;
        file<<trees[i].getPosition().y<<std::endl;
    }
    file<<">>>0<<<"<<std::endl;
    for(int i = 0; i<stones.size();i++)
    {
        file<<stones[i].getPosition().x<<std::endl;
        file<<stones[i].getPosition().y<<std::endl;
    }
    file<<">>>1<<<"<<std::endl;
    for(int i = 0; i<irons.size();i++)
    {
        file<<irons[i].getPosition().x<<std::endl;
        file<<irons[i].getPosition().y<<std::endl;
    }
}

void Trees::drawBelow(sf::RenderWindow &window, sf::RectangleShape &area)
{
    for(int i = 0; i<rocks.size(); i++)
    {
        if(rocks[i].getGlobalBounds().intersects(area.getGlobalBounds()))
        window.draw(rocks[i]);
    }
    for(int i = 0; i<oils.size();i++)
    {
        //if(oils[i].getGlobalBounds().intersects(area.getGlobalBounds()))
        window.draw(oils[i]);
    }
    for(int i = 0; i<woodlogs.size(); i++)
    {
        if(woodlogs[i].getGlobalBounds().intersects(area.getGlobalBounds()))
        window.draw(woodlogs[i]);
    }
    for(int i = 0; i<shrooms.size(); i++)
    {
        //if(shrooms[i].getGlobalBounds().intersects(area.getGlobalBounds()))
        window.draw(shrooms[i]);
    }
}

void Trees::drawTrees(sf::RenderWindow &window, sf::RectangleShape &area, sf::Time &time, float& darkness, bool& nighttime, float& volumeAm)
{
    if(volumeSet == false)
    {
        windsound.setVolume(volumeAm);
        crickets.setVolume(volumeAm);
        volumeSet=true;
    }
    if(windsound.getStatus() == sf::Music::Stopped && windspeed > 0.14)
        windsound.play();
    if(windsound.getStatus()==sf::Music::Playing && windspeed <= 0.14)
    {
        if(windsound.getVolume()>0.001)
            windsound.setVolume(windsound.getVolume()-0.1);
        if(windsound.getVolume()<1)
        {
            windsound.setVolume(volumeAm);
            windsound.stop();
        }
    }
    if(darkness >110)
    {
        if(crickets.getStatus()==sf::Music::Stopped)
            crickets.play();
    }
    if(darkness<210 && crickets.getStatus()==sf::Music::Playing)
    {
        if(crickets.getVolume()>0.01)
            crickets.setVolume(crickets.getVolume()-0.01);
        if(crickets.getVolume()<1)
        {
            crickets.setVolume(volumeAm);
            crickets.stop();
        }
    }

    //std::cout<<((float)(rand()%10)/10)<<std::endl;
    /*if(nighttime == true)
    {
        windchance = 2;
    }
    else
        windchance = 3;*/

    for(int i = 0; i<trees.size();i++)
    {
        if(wind[i] == true && windspeed >= 0.06)
        {
            trees[i].setRotation(trees[i].getRotation()+(windspeed-0.05));
            //treeshadows[i].setScale(treeshadows[i].getScale().x+0.003,treeshadows[i].getScale().y+0.003);
        }
        else if (windspeed >= 0.06)
        {
            trees[i].setRotation(trees[i].getRotation()-(windspeed-0.05)*2);
            //treeshadows[i].setScale(treeshadows[i].getScale().x-0.003,treeshadows[i].getScale().y-0.003);
        }

        if(trees[i].getRotation()>10)
            wind[i] = false;
        if(trees[i].getRotation()>345)
            wind[i] = true;
    if(time.asSeconds() >= timeneeded)
    {
        if(treeshadows[i].getColor().a>0 && treeshadows[i].getRotation()<180 && treeshadows[i].getRotation()>90)
        treeshadows[i].setColor(sf::Color(0,0,0,treeshadows[i].getColor().a-1));
        if(treeshadows[i].getRotation() > 260 && treeshadows[i].getColor().a<160)//240
        treeshadows[i].setColor(sf::Color(0,0,0,treeshadows[i].getColor().a+1));
        treeshadows[i].setRotation(treeshadows[i].getRotation()+nspeed);
        if(treeshadows[i].getRotation()>45 && treeshadows[i].getRotation()<180)
        treeshadows[i].setScale(treeshadows[i].getScale().x,treeshadows[i].getScale().y+0.005);
        if(treeshadows[i].getRotation()>225)
            treeshadows[i].setScale(treeshadows[i].getScale().x,treeshadows[i].getScale().y-0.005);
        if(treeshadows[i].getRotation()<180 && treeshadows[i].getRotation()>90 && darkness < 254)
        {
            darkness += 0.00060;
        }
        if(treeshadows[i].getRotation()>190 && darkness > 0 )
        {
            darkness -=0.00030;
        }
    }
    if(trees[i].getGlobalBounds().intersects(area.getGlobalBounds()))
        {
            window.draw(trees[i]);
        }
    }
    for(int i = 0; i<stones.size();i++)
    {
        if(time.asSeconds()>=timeneeded)
        {
            if(stoneshadows[i].getColor().a>0 && stoneshadows[i].getRotation()<180 && stoneshadows[i].getRotation()>90)
            stoneshadows[i].setColor(sf::Color(0,0,0,stoneshadows[i].getColor().a-1));
            if(stoneshadows[i].getRotation() > 260 && stoneshadows[i].getColor().a<160)
            stoneshadows[i].setColor(sf::Color(0,0,0,stoneshadows[i].getColor().a+1));
            stoneshadows[i].setRotation(stoneshadows[i].getRotation()+nspeed);
            if(stoneshadows[i].getRotation()>45 && stoneshadows[i].getRotation()<180)
            stoneshadows[i].setScale(stoneshadows[i].getScale().x,stoneshadows[i].getScale().y+0.005);
            if(stoneshadows[i].getRotation()>225)
            stoneshadows[i].setScale(stoneshadows[i].getScale().x,stoneshadows[i].getScale().y-0.005);
        }
        //stoneshadows[i].setRotation(stoneshadows[i].getRotation()+0.01);
        //stoneshadows[i].setScale(stoneshadows[i].getScale().x,stoneshadows[i].getScale().y+0.0001);
    if(stones[i].getGlobalBounds().intersects(area.getGlobalBounds()))
        {
            window.draw(stoneshadows[i]);
            window.draw(stones[i]);
        }
    }
    for(int i = 0; i<irons.size(); i++)
    {
        if(time.asSeconds()>=timeneeded)
        {
        if(ironshadows[i].getColor().a>0 && ironshadows[i].getRotation()<180 && ironshadows[i].getRotation()>90)
            ironshadows[i].setColor(sf::Color(0,0,0,ironshadows[i].getColor().a-1));
            if(ironshadows[i].getRotation() > 260 && ironshadows[i].getColor().a<160)
            ironshadows[i].setColor(sf::Color(0,0,0,ironshadows[i].getColor().a+1));
            ironshadows[i].setRotation(ironshadows[i].getRotation()+nspeed);
            if(ironshadows[i].getRotation()>45 && ironshadows[i].getRotation()<180)
            ironshadows[i].setScale(ironshadows[i].getScale().x,ironshadows[i].getScale().y+0.005);
            if(ironshadows[i].getRotation()>225)
            ironshadows[i].setScale(ironshadows[i].getScale().x,ironshadows[i].getScale().y-0.005);
        }
        if(irons[i].getGlobalBounds().intersects(area.getGlobalBounds()))
        {
            window.draw(ironshadows[i]);
            window.draw(irons[i]);
        }
    }
    if(time.asSeconds()>=timeneeded)
    {
        ticks++;
        if(rand()%windchance==1 && windspeed < 0.25 && ticks >= ticksneeded)
        {
            if(nighttime == false)
                windspeed+=0.01;
            if(nighttime == true)
                windspeed+=0.02;
            std::cout<<windspeed<<std::endl;
            calc++;
            ticks = 0;
        }
        else if(windspeed >0 && ticks >= ticksneeded)
        {
            if(nighttime == false)
                windspeed-=0.01;
            if(nighttime == true)
                windspeed-=0.02;
            std::cout<<windspeed<<std::endl;
            calc++;
            ticks = 0;
        }
        avwind+=windspeed;
        //std::cout<<"Average: "<<avwind/calc<<std::endl;
        if(windspeed<=0)
            windspeed = 0;
    }
}

void Trees::pickwood(sf::RenderWindow &window, int x, int y, int slotID, bool craftStatus, int &woodAm, int pposx, int pposy, int &durability, int &stoneAm, sf::View &view,
                     sf::RectangleShape &prect, bool& harvestAnim, float &currot, sf::Sprite& player, sf::Sprite& plrect)
{

    if(shake == true)
    {
        if(view.getCenter().x > prect.getPosition().x-10)
        view.move(-5,0);
        if(view.getCenter().x <= prect.getPosition().x-10)
        {
            shake2 = true;
            shake = false;
        }
    }
    if(shake2 == true)
    {
        view.move(5,0);
    }
    if(view.getCenter().x >= prect.getPosition().x && shake2 == true)
    {
        shake2 = false;
    }
    if(harv1.getPosition().x!=harv2.getPosition().x)
    {
        harv1.move(1,0);
    }
    harv.setPosition(pposx,pposy);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && craftStatus == false)
    {
    for(int i=0;i<trees.size();i++)
    {
        if(slotID == 1)
        {
            if(harv.getGlobalBounds().intersects(trees[i].getGlobalBounds()) && harv1.getPosition().x==harv2.getPosition().x)
            {
                if(x >= trees[i].getPosition().x-8*trees[i].getScale().x && x <= trees[i].getPosition().x+8*trees[i].getScale().x && y >= trees[i].getPosition().y-19*trees[i].getScale().y && y <= trees[i].getPosition().y)
                {
                    harvestAnim = true;
                    shake = true;
                    part.setFillColor(sf::Color(159,99,49));
                    part.setPosition(treepos[i].x,treepos[i].y-20);
                    createParticles();
                    trees[i].setRotation(trees[i].getRotation()+3);
                    treeshadows[i].setRotation(treeshadows[i].getRotation()+3);
                    treeshadows[i].setScale(treeshadows[i].getScale().x,treeshadows[i].getScale().y+0.5);
                    if(treeshp[i] <= 0)
                    {
                        matsgath = true;
                        matsgtype = _WOOD;
                        woodAm = woodAm+15;
                        std::cout<<woodAm<<std::endl;
                        trees.erase(trees.begin()+i);
                        //bottomtrees.erase(bottomtrees.begin()+i);
                        treepos.erase(treepos.begin()+i);
                        treeshadows.erase(treeshadows.begin()+i);
                        durability -= rand()%3+1;
                    }
                    else
                    {
                        durability -=rand()%3+1;
                        treeshp[i]-=treedamage;
                    }
                    pitch = rand()%5+10;
                    pitch = pitch/10;
                    treechop.setPitch(pitch);
                    treechop.play();
                   harv1.setPosition(0,0);
                }
            }

        }
    }
    for(int i = 0; i<woodlogs.size(); i++)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && craftStatus == false)
        {
            if(x >= woodlogs[i].getPosition().x && x<= woodlogs[i].getPosition().x+woodlogs[i].getGlobalBounds().width && y >= woodlogs[i].getPosition().y &&
               y <= woodlogs[i].getPosition().y+woodlogs[i].getGlobalBounds().height && woodlogs[i].getGlobalBounds().intersects(harv.getGlobalBounds()))
            {
                woodAm += 3;
                woodlogs.erase(woodlogs.begin()+i);
                matsgtype = _WOOD;
                //plrect.setScale(6,6);
                matsgath = true;
            }
        }
    }
    for(int i = 0; i<rocks.size(); i++)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && craftStatus == false)
        {
            if(x >= rocks[i].getPosition().x && x <= rocks[i].getPosition().x+rocks[i].getGlobalBounds().width && y >= rocks[i].getPosition().y && y <= rocks[i].getPosition().y
                + rocks[i].getGlobalBounds().height && harv.getGlobalBounds().intersects(rocks[i].getGlobalBounds()))
            {
                stoneAm += 6;
                matsgtype = _STONE;
                //plrect.setScale(6,6);
                matsgath = true;
                rocks.erase(rocks.begin()+i);
            }
        }
    }
    }
    displayParticles(window);
}

void Trees::pickStone(sf::RenderWindow &window, int x, int y, int &slotID, bool craftStatus, int pposx, int pposy, int &stoneAm, float &oilAmount, int &ironAmount,
                      int &durability, bool& harvAnim, sf::Sprite &player, float &currot)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && craftStatus == false)
    {
    for(int i = 0; i<stones.size(); i++)
    {
        if(slotID == 2)
        {
            if(harv.getGlobalBounds().intersects(stones[i].getGlobalBounds()) && harv1.getPosition().x == harv2.getPosition().x)
                {
                    if(x >= stones[i].getPosition().x && x <= stones[i].getPosition().x+16*stones[i].getScale().x && y >= stones[i].getPosition().y && y <= stones[i].getPosition().y+16*stones[i].getScale().y)
                    {
                        harvAnim = true;
                        currot = player.getRotation();
                        pitch = rand()%5+4;
                        pitch /= 10;
                        rockhit.setPitch(pitch);
                        rockhit.play();
                        part.setPosition(stones[i].getPosition().x+32,stones[i].getPosition().y+32);
                        part.setFillColor(sf::Color(159,157,150,255));
                        createParticles();
                        shake = true;
                        if(stoneshp[i]<=0)
                        {
                            matsgtype = _STONE;
                            matsgath = true;
                            stoneAm = stoneAm +20;
                            stoneshadows.erase(stoneshadows.begin()+i);
                            stones.erase(stones.begin()+i);
                            stonepos.erase(stonepos.begin()+i);
                            durability -= rand()%3+1;
                        }
                        else
                        {
                            durability -= rand()%3+1;
                            stoneshp[i]-=stonedamage;
                            harv1.setPosition(0,0);
                        }
                    }
                }

        }
    }
    for(int i = 0; i<oils.size();i++)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&& craftStatus == false)
        {
            if(harv.getGlobalBounds().intersects(oils[i].getGlobalBounds()) && slotID == 5)
            {
                if(x >= oils[i].getPosition().x && x <= oils[i].getPosition().x+64 && y >=oils[i].getPosition().y && y <= oils[i].getPosition().y+64)
                {
                    oilAmount += 50;
                    oils.erase(oils.begin()+i);
                }
            }
        }
    }
    for(int i = 0; i<irons.size();i++)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&& craftStatus == false)
        {
            if(harv.getGlobalBounds().intersects(irons[i].getGlobalBounds()) && slotID == 2 && harv1.getPosition().x == harv2.getPosition().x)
            {
                if(x >= irons[i].getPosition().x && x <= irons[i].getPosition().x+16*irons[i].getScale().x && y >=irons[i].getPosition().y && y <= irons[i].getPosition().y+16*irons[i].getScale().y)
                {
                    harvAnim = true;
                    currot = player.getRotation();
                    pitch = rand()%5+4;
                        pitch /= 10;
                        rockhit.setPitch(pitch);
                        rockhit.play();
                    shake = true;
                    part.setFillColor(sf::Color(159,187,150,255));//167
                        part.setPosition(irons[i].getPosition().x+38,irons[i].getPosition().y+32);
                        createParticles();
                    if(ironshp[i]<=0)
                    {
                        matsgtype = _IRON;
                        matsgath = true;
                        ironAmount += 10;
                        stoneAm += 5;
                        durability -= rand()%3+1;
                        irons.erase(irons.begin()+i);
                        ironshadows.erase(ironshadows.begin()+i);
                    }
                    else
                    {
                        ironshp[i]-=irondamage;
                        durability-=rand()%3+1;
                        harv1.setPosition(0,0);
                    }
                }
            }
        }
    }
    }
}

void Trees::createParticles()
{
    for(int i = 0; i<20; i++)
    {
        particles.push_back(part);
        pmove = -30+rand()%+60;
        pmovey = rand()%7+1;
        partmove.push_back(pmove/10);
        partmovey.push_back(-pmovey);

    }
}
void Trees::displayParticles(sf::RenderWindow &window)
{
    for(int i = 0; i<particles.size(); i++)
    {
        particles[i].move(partmove[i],partmovey[i]);
        particles[i].setFillColor(sf::Color(particles[i].getFillColor().r,particles[i].getFillColor().g,particles[i].getFillColor().b, particles[i].getFillColor().a-7));
        window.draw(particles[i]);
        if(partmovey[i]<3)
        {
            partmovey[i]+=0.5;
        }
        if(particles[i].getFillColor().a <= 7)
        {
            particles.erase(particles.begin()+i);
            partmove.erase(partmove.begin()+i);
            partmovey.erase(partmovey.begin()+i);
        }
    }
}
