#include "SlotManager.h"
SlotManager::SlotManager(sf::RenderWindow &window)
{
    framepicktex.loadFromFile("Sources/Textures/framepick.png");
    framepick.setTexture(framepicktex);
    framepick.setScale(1.5*4,1.5*4);
    frame.loadFromFile("Sources/Textures/frame.png");
    frameswordtex.loadFromFile("Sources/Textures/sword.png");
    framesword.setTexture(frameswordtex);
    swordtex.loadFromFile("Sources/Textures/sword.png");
    emptyTex.loadFromFile("Sources/Textures/emp.png");
    lanterntex.loadFromFile("Sources/Textures/lantern.png");
    buckettex.loadFromFile("Sources/Textures/bucket.png");
    meattex.loadFromFile("Sources/Textures/meat.png");
    cmeattex.loadFromFile("Sources/Textures/cookedmeat.png");
    waterbucket.loadFromFile("Sources/Textures/bucketwater.png");
    oilbucket.loadFromFile("Sources/Textures/oilbucket.png");
    shroom.loadFromFile("Sources/Textures/mushroom.png");
    jar.loadFromFile("Sources/Textures/jar.png");
    torch.loadFromFile("Sources/Textures/torch.png");
    cooked.loadFromFile("Sources/Textures/cookedmushroom.png");
    for(int i=0;i<5;i++)
    {
        sf::Sprite frame;
        frame.setTexture(this->frame);
        frame.setScale(1.5*4,1.5*4);
        frames.push_back(frame);
    }
    frames[0].setPosition(window.getSize().x/2.85,window.getSize().y-100);
    axetex.loadFromFile("Sources/Textures/axe.png");
    picktex.loadFromFile("Sources/Textures/pickaxe.png");

    for(int i = 0;i<5;i++)
    {
        sf::Sprite framesprite;
        framesprite.setScale(1.1*4,1.1*4);
        framesprites.push_back(framesprite);
    }
    framesprites[0].setPosition(frames[0].getPosition().x+12,frames[0].getPosition().y+12);

    for(int i=0;i<6;i++)
    {
        slotID.push_back(0);
    }
    e1.setSize(sf::Vector2f(1,1));
    e2.setSize(sf::Vector2f(1,1));
    e2.setPosition(20,0);

    frameitems.push_back(emptyTex);
    frameitems.push_back(axetex);
    frameitems.push_back(picktex);
    frameitems.push_back(swordtex);
    frameitems.push_back(lanterntex);
    frameitems.push_back(buckettex);
    frameitems.push_back(meattex);
    frameitems.push_back(cmeattex);
    frameitems.push_back(waterbucket);
    frameitems.push_back(oilbucket);
    frameitems.push_back(shroom);
    frameitems.push_back(jar);
    frameitems.push_back(torch);
    frameitems.push_back(cooked);
    file.open("Sources/Saves/inventory.txt",std::ios::in);
    file2.open("Sources/Saves/dropped.txt",std::ios::in);
    if(file.good()==true)
    {
        while(std::getline(file,line))
        {
            switch(linenr)
            {
                case 1: slotID[1] = atoi(line.c_str());
                break;
                case 2: slotID[2] = atoi(line.c_str());
                break;
                case 3: slotID[3] = atoi(line.c_str());
                break;
                case 4: slotID[4] = atoi(line.c_str());
                break;
                case 5: slotID[5] = atoi(line.c_str());
                break;
            }
            linenr++;
        }
    }
    std::vector<int>temp_items;
    if(file2.good())
    {
        while(std::getline(file2,line))
        {
            temp_items.push_back(atoi(line.c_str()));
        }
    }

    for(int i = 0; i<temp_items.size(); i++)
    {
        durab.push_back(temp_items[i]);
        id.push_back(temp_items[i+1]);
        item.setPosition(sf::Vector2f(temp_items[i+2],temp_items[i+3]));
        item.setScale(4,4);
        items.push_back(item);
        i+=3;
    }
    for(int i = 0; i<items.size(); i++)
    {
        items[i].setTexture(frameitems[id[i]]);
    }
    file2.close();
}

SlotManager::~SlotManager()
{
    //dtor
}

void SlotManager::save()
{
    file.close();
    file.open("Sources/Saves/inventory.txt", std::ios::out);
    file<<slotID[1]<<std::endl;
    file<<slotID[2]<<std::endl;
    file<<slotID[3]<<std::endl;
    file<<slotID[4]<<std::endl;
    file<<slotID[5]<<std::endl;
    file2.open("Sources/Saves/dropped.txt",std::ios::out);
    for(int i = 0; i<items.size(); i++)
    {
        file2<<durab[i]<<std::endl;
        file2<<id[i]<<std::endl;
        file2<<items[i].getPosition().x<<std::endl;
        file2<<items[i].getPosition().y<<std::endl;
    }
}

void SlotManager::slotChange()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
    {
        slotnumber = 1;
        //slottex = firetex;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    {
        slotnumber = 2;
        //slottex = speartex;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
    {
        slotnumber = 3;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
    {
        slotnumber = 4;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
    {
        slotnumber = 5;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
    {
        slotnumber = 0;
    }
    framepick.setPosition(frames[slotnumber-1].getPosition());
}
void SlotManager::loadFrame(sf::RenderWindow &window, std::vector<int>&slot, std::vector<sf::Sprite>&framesp, std::vector<sf::Texture>&frameits)
{
    window.draw(frames[0]);
    for(int i=1;i<5;i++)
    {
        frames[i].setPosition(frames[i-1].getPosition().x+frames[i].getGlobalBounds().width,frames[i-1].getPosition().y);
        framesprites[i].setPosition(frames[i].getPosition().x+12,frames[i].getPosition().y+12);
        window.draw(frames[i]);
    }
    /*if(slotID[1]==axeID)
    {
        framesprites[0].setTexture(axetex);
        window.draw(framesprites[0]);
    }
    if(slotID[1]==pickID)
    {
        framesprites[0].setTexture(picktex);
        window.draw(framesprites[0]);
    }
    if(slotID[2]==axeID)
    {
        framesprites[1].setTexture(axetex);
        window.draw(framesprites[1]);
    }
    if(slotID[2]==pickID)
    {
        framesprites[1].setTexture(picktex);
        window.draw(framesprites[1]);
    }*/
    for(int i = 0; i<slot.size();i++)
    {
        framesp[0].setTexture(frameits[slot[i+1]]);
        framesp[1].setTexture(frameits[slot[i+1]]);
        framesp[2].setTexture(frameits[slot[i+1]]);
        framesp[3].setTexture(frameits[slot[i+1]]);
        framesp[4].setTexture(frameits[slot[i+1]]);
        if(i<slot.size()-1)
        window.draw(framesp[i]);
    }
    window.draw(framespear);
    window.draw(framefire);
    if(slotnumber!=0)
    window.draw(framepick);
}

void SlotManager::drop(sf::RenderTarget &window, int x, int y, std::vector<int>&durability, sf::Vector2f mousepos, float& hunger, float& water, int& hp)
{
    for(int i = 1; i<slotID.size(); i++)
    {
        if(durability[i]<=0 && slotID[i] != 5 && slotID[i] != 8 && slotID[i]!= 9 && slotID[i]!=11)
            slotID[i]=0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && slotID[slotnumber]!=0)
    {
        durab.push_back(durability[slotnumber]);
        id.push_back(slotID[slotnumber]);
        item.setPosition(x,y);
        item.setTexture(frameitems[slotID[slotnumber]]);
        item.setScale(4,4);
        if(slotID[slotnumber]!=6 && slotID[slotnumber]!=7)
        {
            slotID[slotnumber] = 0;
            durability[slotnumber]= 0;
        }
        else if(durability[slotnumber]>0)
        {
            durability[slotnumber]=0;
        }
        items.push_back(item);
    }
    for(int i = 0; i<items.size(); i++)
    {
        window.draw(items[i]);
        if(mousepos.x>=items[i].getPosition().x && mousepos.x <=items[i].getPosition().x+items[i].getGlobalBounds().width && mousepos.y>=items[i].getPosition().y && mousepos.y <= items[i].getPosition().y+items[i].getGlobalBounds().height)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                for(int j = 1; j<slotID.size();j++)
                {
                    if(slotID[j]==0)
                    {
                        slotID[j] = id[i];
                        durability[j] = durab[i];
                        items.erase(items.begin()+i);
                        id.erase(id.begin()+i);
                        durab.erase(durab.begin()+i);
                        break;
                    }
                    if(j==slotID.size()-1)
                    {
                        std::cout<<"inventory full"<<std::endl;
                    }
                }
            }
        }
    }
    if(e1.getPosition().x!=e2.getPosition().x)
        {
            e1.move(1,0);
        }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right) && slotID[slotnumber]==7)
    {
        if(durability[slotnumber]>0 && e1.getPosition().x==e2.getPosition().x)
        {
            durability[slotnumber]-=1;
            hunger+=50;
            water+=20;
            hp+=20;
            if(hp>100)
                hp=100;
            e1.setPosition(0,0);
        }
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right) && slotID[slotnumber]==6)
    {
        if(e1.getPosition().x==e2.getPosition().x)
        {
            durability[slotnumber]-=1;
            hunger+=20;
            water+=10;
            hp-=20;
            e1.setPosition(0,0);
        }
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right) && slotID[slotnumber]==8)
    {
        if(e1.getPosition().x==e2.getPosition().x)
        {
            slotID[slotnumber]=5;
            water+=60;
            e1.setPosition(0,0);
        }
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right) && slotID[slotnumber]==10)
    {
        if(e1.getPosition().x==e2.getPosition().x)
        {
            durability[slotnumber]-=1;
            hunger+=10;
            water+=4;
            e1.setPosition(0,0);
        }
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right) && slotID[slotnumber]==13)
    {
        if(e1.getPosition().x==e2.getPosition().x)
        {
            durability[slotnumber]-=1;
            hunger+=27;
            e1.setPosition(0,0);
        }
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right) && slotID[slotnumber]==11 && durability[slotnumber]>0)
    {
        durability[slotnumber]-=1;
        hunger+=1;
        water+=1;
    }
    if(hunger>100)
        hunger=100;
    if(water>100)
        water=100;
}

