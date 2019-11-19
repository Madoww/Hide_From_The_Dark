#include "ItemCrafting.h"

hiveClass::hiveClass()
{
    hivetex.loadFromFile("Sources/Textures/beehive.png");
    hive.setTexture(hivetex);
    hive.setOrigin(8,8);
    hive.setScale(6,6);
    hiveArea.setSize(sf::Vector2f(3000,3000));
    hiveArea.setOrigin(hiveArea.getSize().x/2,hiveArea.getSize().y/2);
    hiveArea.setPosition(hive.getPosition());
    h1.setSize(sf::Vector2f(1,1));
    h2.setSize(sf::Vector2f(2,2));
    h2.setPosition(10,0);
}

hiveClass::~hiveClass()
{
    //dtor
}


void hiveClass::draw(sf::RenderWindow &window)
{
    hrect.setFillColor(sf::Color::Yellow);
    hrect.setSize(sf::Vector2f(10,honey/2));
    hrect.setPosition(hive.getPosition().x-50,hive.getPosition().y+16-honey/2);
    window.draw(hrect);
    h1.move(1,0);
    hiveArea.setPosition(hive.getPosition());
    if(h1.getPosition().x == h2.getPosition().x && honey < 100)
    {
        honey += 0.1 * beesam;
        h1.setPosition(0,0);
    }
    if(honey < 0)
        honey = 0;
    window.draw(hive);
}


ItemCrafting::ItemCrafting(sf::RenderWindow &window)
{
    r1.setPosition(0,0);
    r2.setPosition(10,0);
    menuBack.setSize(sf::Vector2f(500,750));
    menuBack.setOrigin(menuBack.getSize().x/2,menuBack.getSize().y/2);
    menuBack.setFillColor(sf::Color::White);
    menuBack.setPosition(window.getSize().x/2,window.getSize().y/2.13);
    axetex.loadFromFile("Sources/Textures/axe.png");
    picktex.loadFromFile("Sources/Textures/pickaxe.png");
    swordtex.loadFromFile("Sources/Textures/sword.png");
    lanterntex.loadFromFile("Sources/Textures/lantern.png");
    buckettex.loadFromFile("Sources/Textures/bucket.png");
    furnancetex.loadFromFile("Sources/Textures/furnance.png");
    benchtex.loadFromFile("Sources/Textures/bench.png");
    menubacktex.loadFromFile("Sources/Textures/craftingback.png");
    furnanceback.loadFromFile("Sources/Textures/furnanceback.png");
    waterbucket.loadFromFile("Sources/Textures/bucketwater.png");
    oilbucket.loadFromFile("Sources/Textures/oilbucket.png");
    shroom.loadFromFile("Sources/Textures/mushroom.png");
    jar.loadFromFile("Sources/Textures/jar.png");
    torch.loadFromFile("Sources/Textures/torch.png");
    fire.loadFromFile("Sources/Textures/fire.png");
    upfiretex.loadFromFile("Sources/Textures/topfire.png");
    upfire.setTexture(upfiretex);
    upfire.setScale(4,4);
    menuBack.setTexture(menubackptr);
    emptytext.setCharacterSize(17);
    emptytext.setColor(sf::Color::White);
    emptytext.setFont(rat);
    mouse.setSize(sf::Vector2f(1,1));
    for(int i = 0; i<craftingitemsamount;i++)
    {
        craftingitems.push_back(emptysprite);
        craftstrings.push_back(emptytext);
    }
    craftingitems[0].setTexture(axetex);
    //craftingitems[0].setScale(4,4);
    craftingitems[1].setTexture(picktex);
    //craftingitems[1].setScale(4,4);
    craftingitems[2].setTexture(swordtex);
    craftingitems[3].setTexture(lanterntex);
    craftingitems[3].setScale(4,4);
    craftingitems[4].setTexture(buckettex);
    craftingitems[5].setTexture(furnancetex);
    craftingitems[5].setScale(4,4);
    craftingitems[6].setTexture(benchtex);
    craftingitems[6].setScale(4,4);
    craftingitems[7].setTexture(bhive.hivetex);
    craftingitems[7].setScale(4,4);
    craftingitems[8].setTexture(waterbucket);
    craftingitems[8].setScale(4,4);
    craftingitems[9].setTexture(oilbucket);
    craftingitems[9].setScale(4,4);
    craftingitems[10].setTexture(shroom);
    craftingitems[10].setScale(4,4);
    craftingitems[11].setTexture(jar);
    craftingitems[11].setScale(4,4);
    craftingitems[12].setTexture(torch);
    craftingitems[12].setScale(4,4);
    craftingitems[13].setTexture(fire);
    craftingitems[13].setScale(4,4);
    for(int i = 0; i<5; i++)
    if(i !=3)
    {
        craftingitems[i].setScale(4,4);
    }

    craftingitems[0].setPosition(menuBack.getPosition().x-menuBack.getSize().x/2+50,menuBack.getPosition().y-menuBack.getSize().y/2+25);
    craftingitems[1].setPosition(menuBack.getPosition().x-menuBack.getSize().x/2+50,menuBack.getPosition().y-menuBack.getSize().y/2+125);
    craftingitems[2].setPosition(menuBack.getPosition().x-menuBack.getSize().x/2+50,menuBack.getPosition().y-menuBack.getSize().y/2+225);
    craftingitems[3].setPosition(menuBack.getPosition().x-menuBack.getSize().x/2+50,menuBack.getPosition().y-menuBack.getSize().y/2+325);
    craftingitems[4].setPosition(menuBack.getPosition().x-menuBack.getSize().x/2+50,menuBack.getPosition().y-menuBack.getSize().y/2+425);
    craftingitems[5].setPosition(menuBack.getPosition().x-menuBack.getSize().x/2+50,menuBack.getPosition().y-menuBack.getSize().y/2+525);
    craftingitems[6].setPosition(menuBack.getPosition().x-menuBack.getSize().x/2+50,menuBack.getPosition().y-menuBack.getSize().y/2+610);

    craftingitems[7].setPosition(craftingitems[0].getPosition());
    craftingitems[11].setPosition(menuBack.getPosition().x-menuBack.getSize().x/2+50,menuBack.getPosition().y-menuBack.getSize().y/2+125);
    craftingitems[12].setPosition(menuBack.getPosition().x-menuBack.getSize().x/2+50,menuBack.getPosition().y-menuBack.getSize().y/2+225);
    craftingitems[13].setPosition(menuBack.getPosition().x-menuBack.getSize().x/2+50,menuBack.getPosition().y-menuBack.getSize().y/2+325);
    craftingitems[14].setPosition(menuBack.getPosition().x-menuBack.getSize().x/2+50,menuBack.getPosition().y-menuBack.getSize().y/2+425);


    for(int i = 0; i<craftstrings.size();i++)
    {
        craftstrings[i].setPosition(craftingitems[i].getPosition().x+100,craftingitems[i].getPosition().y);
        craftstrings[i].setOutlineColor(sf::Color::Black);
        craftstrings[i].setOutlineThickness(2);
    }
    craftstrings[6].setPosition(craftstrings[6].getPosition().x,craftstrings[6].getPosition().y+15);
    c1.setSize(sf::Vector2f(1,1));
    c2.setSize(sf::Vector2f(1,1));
    c1.setPosition(0,0);
    c2.setPosition(10,0);
    furnanceplacing.setTexture(furnancetex);
    furnanceplacing.setColor(sf::Color(255,255,255,190));
    furnanceplacing.setScale(6,6);
    furnanceplacing.setOrigin(furnanceplacing.getGlobalBounds().width/2,furnanceplacing.getGlobalBounds().height/2);
    cooking.setFillColor(sf::Color::White);
    cooking.setTexture(furnancebackptr);
    cooking.setSize(sf::Vector2f(600,400));
    cooking.setOrigin(300,200);
    cooking.setPosition(window.getSize().x/2,window.getSize().y/2);
    uncookedIronText.setPosition(cooking.getPosition().x-280,cooking.getPosition().y-200);
    woodNeededText.setPosition(cooking.getPosition().x-280,cooking.getPosition().y-100);
    uncookedIronText.setFont(rat);
    uncookedIronText.setFillColor(sf::Color::Black);
    uncookedIronText.setCharacterSize(50);
    woodNeededText.setFont(rat);
    woodNeededText.setFillColor(sf::Color::Black);
    woodNeededText.setCharacterSize(50);

    dist.setSize(sf::Vector2f(300,300));
    dist.setOrigin(dist.getSize().x/2,dist.getSize().y/2);

    convert[0]<<mats_for_axe[0];
    convert[1]<<mats_for_pick[0];
    convert[2]<<mats_for_pick[1];
    convert[3]<<mats_for_sword[0];
    convert[4]<<mats_for_sword[1];
    convert[5]<<mats_for_lamp[0];
    convert[6]<<mats_for_bucket[0];
    convert[7]<<mats_for_furnance[0];
    convert[8]<<mats_for_bench[0];

    for(int i = 0; i<6; i++)
    {
        durtext[i].setFont(rat);
        durtext[i].setCharacterSize(20);
        durtext[i].setFillColor(sf::Color::White);
    }

    mats_unchanged[0] = mats_for_axe[0];
    mats_unchanged[1] = mats_for_pick[0];
    mats_unchanged[2] = mats_for_pick[1];
    mats_unchanged[3] = mats_for_sword[0];
    mats_unchanged[4] = mats_for_sword[1];
    mats_unchanged[5] = mats_for_lamp[0];
    mats_unchanged[6] = mats_for_bucket[0];
    mats_unchanged[7] = mats_for_furnance[0];
    mats_unchanged[8] = mats_for_bench[0];

    mats_changed[0] = mats_for_axe[0]*discount;
    mats_changed[1] = mats_for_pick[0]*discount;
    mats_changed[2] = mats_for_pick[1]*discount;
    mats_changed[3] = mats_for_sword[0]*discount;
    mats_changed[4] = mats_for_sword[1]*discount;
    mats_changed[5] = mats_for_lamp[0]*discount;
    mats_changed[6] = mats_for_bucket[0]*discount;
    mats_changed[7] = mats_for_furnance[0]*discount;
    mats_changed[8] = mats_for_bench[0]*discount;


    direction.setSize(sf::Vector2f(20,20));
    direction.setOrigin(10,-270);
    direction.setFillColor(sf::Color::Transparent);

    penter.setCharacterSize(60);
    penter.setFillColor(sf::Color::Black);
    penter.setString("ENTER");
    penter.setFont(rat);

    lamp.setTexture(lanterntex);
    lamp.setScale(4,4);
    file.open("Sources/Saves/durab.txt",std::ios::in);
    if(file.good()==true)
    {
        while(std::getline(file,line))
        {
            switch(nrline)
            {
                case 1: durability[1] = atoi(line.c_str());
                break;
                case 2: durability[2] = atoi(line.c_str());
                break;
                case 3: durability[3] = atoi(line.c_str());
                break;
                case 4: durability[4] = atoi(line.c_str());
                break;
                case 5: durability[5] = atoi(line.c_str());
                break;
            }
            nrline++;
        }
    }
    file2.open("Sources/Saves/builds.txt",std::ios::in);
    if(file2.good()==true)
    {
        while(std::getline(file2,line2))
        {
            std::cout<<"line"<<std::endl;
            if(line2==">>>1<<<" || line2==">>>2<<<")
            {
                loadlevel++;
            }
            if(loadlevel==0)
                fsize++;
            if(loadlevel==1)
                hsize++;
            if(loadlevel==2)
                bsize++;
        }
        int* fpositions = new int[fsize];
        int* hpositions = new int[hsize];
        int* bpositions = new int[bsize];
        int loadline = 0;
        loadlevel = 0;
        file2.clear();
        file2.seekg(0);
        while(std::getline(file2,line2))
        {
            if(loadline>=fsize && loadlevel == 0)
            {
                loadline = 0;
                loadlevel = 1;
                goto skip;
            }
            if(line2 == ">>>2<<<")
            {
                loadline = 0;
                loadlevel = 2;
                goto skip;
            }
            if(loadline<fsize && loadlevel == 0)
            {
                if(line2 != ">>>0<<<" && line2 != ">>>1<<<" && line2!=">>>2<<<")
                {
                    fpositions[loadline] = atoi(line2.c_str());
                    loadline++;
                }

            }
            if(loadline < hsize && loadlevel == 1)
            {
                if(line2 != ">>>0<<<" && line2 != ">>>1<<<" && line2!=">>>2<<<")
                {
                    hpositions[loadline] = atoi(line2.c_str());
                    loadline++;
                }

            }
            if(loadline < bsize && loadlevel == 2)
            {
                if(line2 != ">>>0<<<" && line2 != ">>>1<<<" && line2!=">>>2<<<")
                {
                    bpositions[loadline] = atoi(line2.c_str());
                    loadline++;
                }

            }
            skip:
                char throwaway;
        }
        int linetouse = 0;
        for(int i = 0; i<hsize/2; i++)
        {
                //bhive.hive.setOrigin(bhive.hive.getGlobalBounds().width/2,bhive.hive.getGlobalBounds().height/2);
                bhive.hive.setPosition(hpositions[linetouse],hpositions[linetouse+1]);
                direction.setTexture(bhive.hivetexptr);
                hives.push_back(bhive);
                hiveDirections.push_back(direction);
                hrotation.push_back(0);
                linetouse+=2;
        }
        linetouse = 0;
        furnanceplacing.setOrigin(8,8);
        furnanceplacing.setColor(sf::Color(255,255,255,255));
        for(int i = 0; i<fsize/2; i++)
        {
                //furnanceplacing.setPosition(fpositions[linetouse],fpositions[linetouse+1]);
                furnanceplacing.setPosition(fpositions[linetouse],fpositions[linetouse+1]);
                dist.setPosition(500,500);
                direction.setTexture(furDirecPtr);
                direction.setRotation(180);
                furnances.push_back(furnanceplacing);
                furDirections.push_back(direction);
                frotation.push_back(0);
                linetouse+=2;
        }
        linetouse=0;
        for(int i = 0; i<bsize/2; i++)
        {
                furnanceplacing.setTexture(benchtex);
                furnanceplacing.setOrigin(8,8);
                furnanceplacing.setPosition(bpositions[linetouse], bpositions[linetouse+1]);
                direction.setTexture(benDirecPtr);
                dist.setPosition(furnanceplacing.getPosition());
                benchrect.push_back(dist);
                benches.push_back(furnanceplacing);
                benDirections.push_back(direction);
                brotation.push_back(0);
                linetouse+=2;
        }

    }


    arrow.setPointCount(3);
    arrow.setRadius(40);
    arrow.setScale(0.75,1);
    arrow.setRotation(90);
    arrow.setPosition(menuBack.getPosition().x+menuBack.getGlobalBounds().width/2+70, menuBack.getPosition().y);
    arrow.setFillColor(sf::Color(255,255,255,180));

    arrowleft = arrow;
    arrowleft.setRotation(-90);
    arrowleft.setPosition(menuBack.getPosition().x-menuBack.getGlobalBounds().width/2-70, menuBack.getPosition().y+50);
    std::cout<<"pos"<<bhive.hive.getPosition().x<<std::endl;
}

void ItemCrafting::save()
{
    file.close();
    file.open("Sources/Saves/durab.txt", std::ios::out);
    file<<durability[1]<<std::endl;
    file<<durability[2]<<std::endl;
    file<<durability[3]<<std::endl;
    file<<durability[4]<<std::endl;
    file<<durability[5]<<std::endl;
    file2.close();
    file2.open("Sources/Saves/builds.txt",std::ios::out);
    {
        for(int i = 0; i<furnances.size(); i++)
        {
            file2<<furnances[i].getPosition().x<<std::endl;
            file2<<furnances[i].getPosition().y<<std::endl;
        }
        file2<<">>>1<<<"<<std::endl;
        for(int i = 0; i<hives.size(); i++)
        {
            file2<<hives[i].hive.getPosition().x<<std::endl;
            file2<<hives[i].hive.getPosition().y<<std::endl;
        }
        file2<<">>>2<<<"<<std::endl;
        for(int i = 0; i<benches.size(); i++)
        {
            file2<<benches[i].getPosition().x<<std::endl;
            file2<<benches[i].getPosition().y<<std::endl;
        }
    }
}

ItemCrafting::~ItemCrafting()
{
    //dtor
}

void ItemCrafting::menuOpenCheck(sf::RenderWindow &window, bool &lockstatus, std::vector<int>&slotID, int &woodAm, int &stoneAm, int &ironAm, bool &craftstatus, int slotnumber, bool nighttime, float& oilAm)
{
    craftstrings[0].setString("A typical wooden axe.\nChop down trees like a boss.\n");
    craftstrings[1].setString("Not much more than a pickaxe.\nShow them stones who's the\nbest.\n");
    craftstrings[2].setString("Hunting tool.\nDeers won't see it coming.\n");
    craftstrings[3].setString("You are gonna need it.\nTrust me, it gets really dark.\n");
    craftstrings[4].setString("A bucket used to carry water\nand collect oil.\nMake sure not to spill any.\n");
    craftstrings[5].setString("Melts iron and cooks meat.\nAmazing, huh?\n");
    craftstrings[6].setString("-20% off material usage while near it.\nOnly for the cheap ones.\n");
    craftstrings[7].setString("Shelter for bees. Collects honey.\n(200 wood)");
    craftstrings[11].setString("Just a jar.\nUsed to store honey.\n(100 wood)");
    craftstrings[12].setString("Portable source of light.\n(40 wood, 20 oil)");
    craftstrings[13].setString("Placable campfire.\nYou can even cook using it.\n(70 wood)");

    for(int i = 0; i< 9; i++)
    {
        convert[i].clear();
        convert[i].str("");
    }

    convert[0]<<mats_for_axe[0];
    convert[1]<<mats_for_pick[0];
    convert[2]<<mats_for_pick[1];
    convert[3]<<mats_for_sword[0];
    convert[4]<<mats_for_sword[1];
    convert[5]<<mats_for_lamp[0];
    convert[6]<<mats_for_bucket[0];
    convert[7]<<mats_for_furnance[0];
    convert[8]<<mats_for_bench[0];

    craftstrings[0].setString(craftstrings[0].getString() + "(" + convert[0].str() + " wood)");
    craftstrings[1].setString(craftstrings[1].getString() + "(" + convert[1].str() + " wood, " + convert[2].str() + " stone)");
    craftstrings[2].setString(craftstrings[2].getString() + "(" + convert[3].str() + " wood, " + convert[4].str() + " stone)");
    craftstrings[3].setString(craftstrings[3].getString() + "(" + convert[5].str() + " iron)");
    craftstrings[4].setString(craftstrings[4].getString() + "(" + convert[6].str() + " iron)");
    craftstrings[5].setString(craftstrings[5].getString() + "(" + convert[7].str() + " stone)");
    craftstrings[6].setString(craftstrings[6].getString() + "(" + convert[8].str() + " wood)");

    if(c1.getPosition().x!=c2.getPosition().x)
    {
        c1.move(1,0);
    }

    if(craftingMenuStatus == false)
    {
        if(r1.getPosition().x!=r2.getPosition().x)
        {
            r1.move(1,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)&&r1.getPosition().x==r2.getPosition().x)
        {
            r1.setPosition(0,0);
            craftstatus = false;
            craftingMenuStatus = true;
        }
    }
    mouse.setPosition(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y);

    if(craftingMenuStatus == true)
    {
        window.draw(menuBack);
        window.draw(arrow);
        window.draw(arrowleft);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::U))
        {
            pnumber = 2;
        }
if(pnumber == 1)
    {
        window.draw(craftstrings[1]);
        for(int i = 0; i<craftingitems.size() && i<7;i++)
        {
            if(woodAm<mats_for_axe[0])
            {
                craftingitems[0].setColor(sf::Color(255,255,255,160));
            }
            else
            {
                craftingitems[0].setColor(sf::Color(255,255,255,255));
            }
            if(woodAm < mats_for_pick[0] || stoneAm < mats_for_pick[1])
            {
                craftingitems[1].setColor(sf::Color(255,255,255,160));
            }
            else
            {
                craftingitems[1].setColor(sf::Color(255,255,255,255));
            }
            if(woodAm < mats_for_sword[0] || stoneAm < mats_for_sword[1])
            {
                craftingitems[2].setColor(sf::Color(255,255,255,160));
            }
            else
            {
                craftingitems[2].setColor(sf::Color(255,255,255,255));
            }
            if(ironAm < mats_for_lamp[0])
            {
                craftingitems[3].setColor(sf::Color(255,255,255,160));
            }
            else
            {
                craftingitems[3].setColor(sf::Color(255,255,255,255));
            }
            if(ironAm < mats_for_bucket[0])
            {
                craftingitems[4].setColor(sf::Color(255,255,255,160));
            }
            else
            {
                craftingitems[4].setColor(sf::Color(255,255,255,255));
            }
            if(stoneAm < mats_for_furnance[0])
            {
                craftingitems[5].setColor(sf::Color(255,255,255,160));
            }
            else
            {
                craftingitems[5].setColor(sf::Color(255,255,255,255));
            }
            if(woodAm < mats_for_bench[0])
            {
                craftingitems[6].setColor(sf::Color(255,255,255,160));
            }
            else
                craftingitems[6].setColor(sf::Color(255,255,255,255));
            window.draw(craftingitems[i]);
            window.draw(craftstrings[i]);
            if(mouse.getGlobalBounds().intersects(craftingitems[i].getGlobalBounds()))
            {
                if(craftingitems[i].getScale().x<=1.3*4)
                {
                        craftingitems[i].setScale(craftingitems[i].getScale().x+0.1,craftingitems[i].getScale().y+0.1);
                }
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && c1.getPosition().x==c2.getPosition().x)
                {
                    c1.setPosition(0,0);
                    for(int j = 1; j<slotID.size(); j++)
                    {
                        if(slotID[j]==0 && i !=5)
                        {
                            if(i == 0 && woodAm >= mats_for_axe[0])//axe
                            {
                                woodAm -= mats_for_axe[0];
                                slotID[j]=i+1;
                                durability[j]=100;
                            }
                            if(i == 1 && woodAm >= mats_for_pick[0] && stoneAm >= mats_for_pick[1])//pickaxe
                            {
                                stoneAm -= mats_for_pick[0];
                                woodAm -= mats_for_pick[1];
                                slotID[j]=i+1;
                                durability[j]=100;
                            }
                            if(i == 2 && woodAm >= mats_for_sword[0] && stoneAm >= mats_for_sword[1])//sword
                            {
                                woodAm -= mats_for_sword[0];
                                stoneAm -= mats_for_sword[1];
                                slotID[j]=i+1;
                                durability[j]=100;
                            }
                            if(i == 3 && ironAm >= mats_for_lamp[0])//lamp
                            {
                               /* if(slotID[1]!=4 && slotID[2]!=4 && slotID[3]!=4 && slotID[4]!=4 && slotID[5]!=4 && slotID[0]!=4)
                                {
                                    ironAm -= mats_for_lamp[0];
                                    slotID[j]=i+1;
                                    durability[j]= 0;
                                }*/
                                if(havelamp == false)
                                {
                                    ironAm -= mats_for_lamp[0];
                                    havelamp = true;
                                }

                            }
                            if(i == 4 && ironAm >= mats_for_bucket[0])//bucket
                            {
                                ironAm -= mats_for_bucket[0];
                                slotID[j]=i+1;
                                durability[j]=0;
                            }
                            if(i == 6 && woodAm >= mats_for_bench[0])
                            {
                            benchstat = true;
                            craftingMenuStatus = false;
                            }
                            break;
                        }
                    /*else if(slotID[5]!= 0 && i!= 5 && i !=6 )
                        {

                            if(i == 0 && woodAm >= mats_for_axe[0])//axe
                            {
                                woodAm -= mats_for_axe[0];
                                slotID[slotnumber]=i+1;
                                durability[slotnumber]=100;
                            }
                            if(i == 1 && woodAm >= mats_for_pick[0] && stoneAm >= mats_for_pick[1])//pickaxe
                            {
                                stoneAm -= mats_for_pick[0];
                                woodAm -= mats_for_pick[1];
                                slotID[slotnumber]=i+1;
                                durability[slotnumber]=100;
                            }
                            if(i == 2 && woodAm >= mats_for_sword[0] && stoneAm >= mats_for_sword[1])//sword
                            {
                                woodAm -= mats_for_sword[0];
                                stoneAm -= mats_for_sword[1];
                                slotID[slotnumber]=i+1;
                                durability[slotnumber]=100;
                            }*/
                            if(i == 3 && ironAm >= mats_for_lamp[0])//lamp
                            {
                               // if(slotID[1]!=4 && slotID[2]!=4 && slotID[3]!=4 && slotID[4]!=4 && slotID[5]!=4 && slotID[0]!=4)
                               // {
                               //     ironAm -= mats_for_lamp[0];
                               //     slotID[slotnumber]=i+1;
                               //     durability[slotnumber]=0;
                              //  }

                                if(havelamp == false)
                                {
                                    ironAm -= mats_for_lamp[0];
                                    havelamp = true;
                                }

                            }
                            /*if(i == 4 && ironAm >= mats_for_bucket[0])//bucket
                            {
                                ironAm -= mats_for_bucket[0];
                                slotID[slotnumber]=i+1;
                                durability[slotnumber]=0;
                            }
                            break;
                        }
                        */
                        if(i == 5 && stoneAm >= mats_for_furnance[0])
                        {
                            furstat = true;
                            craftingMenuStatus = false;
                            break;
                        }
                        if(i == 6 && woodAm >= mats_for_bench[0])
                        {
                            benchstat = true;
                            craftingMenuStatus = false;
                            break;
                        }

                    }
                }

            }
            else if(craftingitems[i].getScale().x>1*4)
            {
                craftingitems[i].setScale(craftingitems[i].getScale().x-0.1,craftingitems[i].getScale().y-0.1);
            }
        }
    }
if(pnumber == 2)
{
    window.draw(craftingitems[7]);
    window.draw(craftingitems[11]);
    window.draw(craftstrings[7]);
    window.draw(craftstrings[11]);
    window.draw(craftingitems[12]);
    window.draw(craftstrings[12]);
    window.draw(craftingitems[13]);
    window.draw(craftstrings[13]);
    window.draw(upfire);
    upfire.setScale(craftingitems[13].getScale());
    upfire.setPosition(craftingitems[13].getPosition());
    if(woodAm <200)
        craftingitems[7].setColor(sf::Color(255,255,255,160));
    else
        craftingitems[7].setColor(sf::Color(255,255,255,255));
    if(woodAm <100)
        craftingitems[11].setColor(sf::Color(255,255,255,160));
    else
        craftingitems[11].setColor(sf::Color(255,255,255,255));
    if(woodAm <50 || oilAm < 20)
        craftingitems[12].setColor(sf::Color(255,255,255,160));
    else
        craftingitems[12].setColor(sf::Color(255,255,255,255));
    if(woodAm <70)
    {
        craftingitems[13].setColor(sf::Color(255,255,255,160));
        upfire.setColor(sf::Color(255,255,255,160));
    }

    else
    {
        craftingitems[13].setColor(sf::Color(255,255,255,255));
        upfire.setColor(sf::Color(255,255,255,255));
    }


    for(int i = 7; i<craftingitems.size(); i++)
    {
        //window.draw(craftingitems[i]);
        //window.draw(craftstrings[i]);
        if(mouse.getGlobalBounds().intersects(craftingitems[i].getGlobalBounds()))
        {
            if(craftingitems[i].getScale().x<=1.3*4)
            {
                craftingitems[i].setScale(craftingitems[i].getScale().x+0.1,craftingitems[i].getScale().y+0.1);
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && c1.getGlobalBounds().intersects(c2.getGlobalBounds()))
            {
                for(int j = 1; j<slotID.size(); j++)
                {
                    if(woodAm >= 0 && i == 7 && nighttime == false && woodAm >= 200)
                    {
                        c1.setPosition(0,0);
                        hivestat = true;
                        break;
                    }
                    if(slotID[j]==0 && woodAm >= 100 && i == 11)
                    {
                        c1.setPosition(0,0);
                        woodAm -= 200;
                        slotID[j]=i;
                        break;
                    }
                    if(slotID[j]==0 && woodAm >= 40 && oilAm >= 20 && i == 12)
                    {
                        c1.setPosition(0,0);
                        slotID[j]=i;
                        woodAm -= 40;
                        oilAm-=20;
                        durability[j]=100;
                        break;
                    }
                    if(woodAm >= 70 && i == 13 )
                    {
                        fstat = true;
                        craftingMenuStatus = false;
                        c1.setPosition(-10,0);
                        break;
                    }
                }

            }
        }
        else if(craftingitems[i].getScale().x>1*4)
            {
                craftingitems[i].setScale(craftingitems[i].getScale().x-0.1,craftingitems[i].getScale().y-0.1);
            }
    }
}
        if(sf::Mouse::getPosition(window).x >= arrow.getPosition().x-70 && sf::Mouse::getPosition(window).x <= arrow.getPosition().x && sf::Mouse::getPosition(window).y >= arrow.getPosition().y && sf::Mouse::getPosition(window).y <= arrow.getPosition().y+60)
        {
            if(arrow.getFillColor().a<255)
                arrow.setFillColor(sf::Color(255,255,255,arrow.getFillColor().a+5));
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                pnumber = 2;
            }
        }
        else if(arrow.getFillColor().a>180)
        {
            arrow.setFillColor(sf::Color(255,255,255,arrow.getFillColor().a-5));
        }

        if(sf::Mouse::getPosition(window).x >= arrowleft.getPosition().x&& sf::Mouse::getPosition(window).x <= arrowleft.getPosition().x +70&& sf::Mouse::getPosition(window).y >= arrowleft.getPosition().y-60 && sf::Mouse::getPosition(window).y <= arrowleft.getPosition().y)
        {
            if(arrowleft.getFillColor().a<255)
                arrowleft.setFillColor(sf::Color(255,255,255,arrowleft.getFillColor().a+5));
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                pnumber = 1;
            }
        }
        else if(arrowleft.getFillColor().a>180)
        {
            arrowleft.setFillColor(sf::Color(255,255,255,arrowleft.getFillColor().a-5));
        }
        if(r1.getPosition().x!=r2.getPosition().x)
        {
            r1.move(1,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)&&r1.getPosition().x==r2.getPosition().x)
        {
            r1.setPosition(0,0);
            craftingMenuStatus = false;
        }
    }
}

void ItemCrafting::placeFurnance(int x, int y, sf::RenderWindow &window, std::vector<sf::RectangleShape>&water, std::vector<sf::Sprite>&walls, float &worldx, float &worldy, int &stoneAm,
                                 int &woodAm, sf::RectangleShape &drawarea, std::vector<sf::Sprite>&light, sf::Sprite torch, std::vector<float>&firefuel, std::vector<bool>&upscale, std::vector<bool>&onfire,
                                 std::vector<sf::Sprite>&firetops)
{
    if(furstat == true || benchstat == true || hivestat == true || fstat == true)
    {
        if(furstat == true)
        {
            furnanceplacing.setTexture(furnancetex);
            furnanceplacing.setOrigin(8,8);
        }
        else if(benchstat == true)
        {
            furnanceplacing.setTexture(benchtex);
            furnanceplacing.setOrigin(8,8);
        }
        else if(hivestat == true)
        {
            furnanceplacing.setTexture(bhive.hivetex);
            furnanceplacing.setOrigin(8,8);
            craftingMenuStatus = false;
        }
        else if(fstat == true)
        {
            furnanceplacing.setTexture(fire);
            furnanceplacing.setOrigin(8,8);
            craftingMenuStatus = false;
        }
        furnanceplacing.setPosition(worldx,worldy);
        window.draw(furnanceplacing);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && c1.getPosition().x==c2.getPosition().x)
        {
            c1.setPosition(-10,0);
            furnanceplacing.setColor(sf::Color(255,255,255,255));
            furnanceplacing.setPosition(x,y);
            dist.setPosition(x,y);
            dist.setPosition(x,y);
            if(furstat == true)
            {
                direction.setTexture(furDirecPtr);
                direction.setRotation(180);
                stoneAm -= mats_for_furnance[0];
                furnances.push_back(furnanceplacing);
                furDirections.push_back(direction);
                frotation.push_back(0);
            }

            else if(benchstat == true)
            {
                direction.setTexture(benDirecPtr);
                woodAm -= mats_for_bench[0];
                benchrect.push_back(dist);
                benches.push_back(furnanceplacing);
                benDirections.push_back(direction);
                brotation.push_back(0);
                std::cout<<"bench placed"<<std::endl;
            }

            else if(hivestat == true)
            {
                direction.setTexture(bhive.hivetexptr);
                woodAm -= 200;
                bhive.hive.setPosition(furnanceplacing.getPosition());
                bhive.hiveArea.setPosition(x,y);
                //bhive.hive.setOrigin(bhive.hive.getGlobalBounds().width/2,bhive.hive.getGlobalBounds().height/2);
                hives.push_back(bhive);
                hiveDirections.push_back(direction);
                hrotation.push_back(0);
            }
            if(fstat == true)
            {
                //furnanceplacing.setPosition(x,y);
                woodAm-=70;
                direction.setRotation(180);
                torch.setScale(6,6);
                firefuel.push_back(0);
                light.push_back(torch);
                fires.push_back(furnanceplacing);
                upscale.push_back(true);
                firerotation.push_back(0);
                onfire.push_back(true);
            }

            furnanceplacing.setColor(sf::Color(255,255,255,190));
            furstat = false;
            benchstat = false;
            hivestat = false;
            fstat = false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            benchstat = false;
            furstat = false;
            hivestat = false;
            fstat = false;
        }
    }
    for(int i = 0; i<furnances.size();i++)
    {
        window.draw(furnances[i]);
        if(!furnances[i].getGlobalBounds().intersects(drawarea.getGlobalBounds()))
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
            {
                if(furDirections[i].getFillColor().a < 255)
                    furDirections[i].setFillColor(sf::Color(190,0,0,furDirections[i].getFillColor().a+5));
            }
            else if(furDirections[i].getFillColor().a > 0)
            {
                furDirections[i].setFillColor(sf::Color(230,0,0,furDirections[i].getFillColor().a-5));
            }
        }
        else if(furDirections[i].getFillColor().a > 0)
            {
                furDirections[i].setFillColor(sf::Color(230,0,0,furDirections[i].getFillColor().a-5));
            }
        window.draw(furDirections[i]);
    }
    for(int i = 0; i<benches.size(); i++)
    {
        window.draw(benches[i]);
        if(!benches[i].getGlobalBounds().intersects(drawarea.getGlobalBounds()))
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
            {
                if(benDirections[i].getFillColor().a < 255)
                    benDirections[i].setFillColor(sf::Color(150,150,0,benDirections[i].getFillColor().a+5));
            }
            else if(benDirections[i].getFillColor().a > 0)
            {
                benDirections[i].setFillColor(sf::Color(150,190,0,benDirections[i].getFillColor().a-5));
            }
        }
        else if(benDirections[i].getFillColor().a > 0)
            {
                benDirections[i].setFillColor(sf::Color(150,190,0,benDirections[i].getFillColor().a-5));
            }
        window.draw(benDirections[i]);
    }
    for(int i = 0; i<hives.size(); i++)
    {
        hives[i].draw(window);
        if(!hives[i].hive.getGlobalBounds().intersects(drawarea.getGlobalBounds()))
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
            {
                if(hiveDirections[i].getFillColor().a < 255)
                    hiveDirections[i].setFillColor(sf::Color(150,150,0,hiveDirections[i].getFillColor().a+5));
            }
            else if(hiveDirections[i].getFillColor().a > 0)
            {
                hiveDirections[i].setFillColor(sf::Color(150,190,0,hiveDirections[i].getFillColor().a-5));
            }
        }
        else if(hiveDirections[i].getFillColor().a > 0)
            {
                hiveDirections[i].setFillColor(sf::Color(150,190,0,hiveDirections[i].getFillColor().a-5));
            }
        window.draw(hiveDirections[i]);
    }

    for(int i = 0; i<fires.size(); i++)
    {
        window.draw(fires[i]);
    }
    for(int i = 0; i<firetops.size(); i++)
    {
        window.draw(firetops[i]);
    }
}

void ItemCrafting::useFurnance(int x, int y, int &uncookedIron, int &cookedIron, int &woodAmount, bool &buildstatus, sf::RectangleShape &prect, int &slotID, std::vector<bool>&onfire)
{
    for(int i = 0; i<fires.size();i++)
    {
        if(x >= fires[i].getPosition().x -32 && x <= fires[i].getPosition().x+32 && y >= fires[i].getPosition().y -32 && y <= fires[i].getPosition().y+32 && onfire[i]==true)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && c1.getPosition().x == c2.getPosition().x && slotID == 6 && woodAmount >= 10)
            {
                slotID = 7;
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && c1.getPosition().x==c2.getPosition().x && slotID==10)
            {
                slotID=13;
            }
        }
    }
    for(int i = 0; i<furnances.size();i++)
    {
        if(x >= furnances[i].getPosition().x -32 && x <= furnances[i].getPosition().x+32 && y >= furnances[i].getPosition().y -32 && y <= furnances[i].getPosition().y+32)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && c1.getPosition().x==c2.getPosition().x && buildstatus == false && slotID != 6 && slotID != 7)
            {
                cookingstat = true;
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && c1.getPosition().x == c2.getPosition().x && slotID == 6 && woodAmount >= 10)
            {
                woodAmount -= 10;
                slotID = 7;
            }
        }
    }

    if(cookingstat == true)
    {
        buildstatus = false;
        unIronString = uncookedIronString;
        ironToCook = atoi(unIronString.c_str());
        ui.clear();
        ui.str("");
        ui<<"Iron to cook: ";
        ui<<ironToCook;
        ui<<"/";
        ui<<uncookedIron;
        uncookedIronText.setCharacterSize(50);
        uncookedIronText.setString(ui.str().c_str());
        uncookedIronText.setOrigin(uncookedIronText.getGlobalBounds().width/2,uncookedIronText.getGlobalBounds().height/2);
        uncookedIronText.setPosition(cooking.getPosition().x,cooking.getPosition().y-150);


        woodneeded = ironToCook*2;
        wn.clear();
        wn.str("");
        wn<<"Wood needed: ";
        wn<<woodneeded;
        wn<<"/";
        wn<<woodAmount;
        woodNeededText.setString(wn.str().c_str());
        woodNeededText.setCharacterSize(35);
        woodNeededText.setOrigin(woodNeededText.getGlobalBounds().width/2,woodNeededText.getGlobalBounds().height/2);
        woodNeededText.setPosition(uncookedIronText.getPosition().x,uncookedIronText.getPosition().y+110);

        cooking.setOrigin(cooking.getGlobalBounds().width/2,cooking.getGlobalBounds().height/2);

        penter.setOrigin(penter.getGlobalBounds().width/2,penter.getGlobalBounds().height/2);
        penter.setPosition(cooking.getPosition().x,cooking.getPosition().y+100);

        if(ironToCook <= uncookedIron && woodneeded <= woodAmount && ironToCook != 0 && woodneeded != 0)
            {
                penter.setFillColor(sf::Color::Green);
            }
        else
            penter.setFillColor(sf::Color::Red);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && c1.getPosition().x == c2.getPosition().x)
        {
            c1.setPosition(0,0);
            if(ironToCook <= uncookedIron && woodneeded <= woodAmount)
            {
                cookedIron += ironToCook;
                uncookedIron -= ironToCook;
                woodAmount -= woodneeded;
                ironToCook = 0;
                uncookedIronString = "0";
            }
        }
    }
    for(int i = 0; i<benchrect.size(); i++)
    {
        if(prect.getGlobalBounds().intersects(benchrect[i].getGlobalBounds()))
        {
           mats_for_axe[0] = mats_changed[0];
           mats_for_pick[0] = mats_changed[1];
           mats_for_pick[1] = mats_changed[2];
           mats_for_sword[0] = mats_changed[3];
           mats_for_sword[1] = mats_changed[4];
           mats_for_lamp[0] = mats_changed[5];
           mats_for_bucket[0] = mats_changed[6];
           mats_for_furnance[0] = mats_changed[7];
           mats_for_bench[0] = mats_changed[8];
        }
        else
        {
            mats_for_axe[0] = mats_unchanged[0];
            mats_for_pick[0] = mats_unchanged[1];
            mats_for_pick[1] = mats_unchanged[2];
            mats_for_sword[0] = mats_unchanged[3];
            mats_for_sword[1] = mats_unchanged[4];
            mats_for_lamp[0] = mats_unchanged[5];
            mats_for_bucket[0] = mats_unchanged[6];
            mats_for_furnance[0] = mats_unchanged[7];
            mats_for_bench[0] = mats_unchanged[8];
        }
    }


    for(int i = 0; i<furDirections.size();i++)
    {
        curPos = furnances[i].getPosition();
        position = prect.getPosition();
        dx = curPos.x - position.x;
        dy = curPos.y - position.y;
        frotation[i] = (atan2(dy,dx))*180/pi;

        furDirections[i].setRotation(frotation[i]-90);
        furDirections[i].setPosition(prect.getPosition());
    }
    for(int i = 0; i<benDirections.size(); i++)
    {
        curPos = benches[i].getPosition();
        position = prect.getPosition();
        dx = curPos.x - position.x;
        dy = curPos.y - position.y;
        brotation[i] = (atan2(dy,dx))*180/pi;

        benDirections[i].setRotation(brotation[i]-90);
        benDirections[i].setPosition(prect.getPosition());
    }
    for(int i = 0; i<hiveDirections.size(); i++)
    {
        curPos = hives[i].hive.getPosition();
        position = prect.getPosition();
        dx = curPos.x - position.x;
        dy = curPos.y - position.y;
        hrotation[i] = (atan2(dy,dx))*180/pi;

        hiveDirections[i].setRotation(hrotation[i]-90);
        hiveDirections[i].setPosition(prect.getPosition());
    }
}

void ItemCrafting::checkForInput(sf::Event keyrel)
{
if(cookingstat == true)
{
    if(keyrel.type == sf::Event::KeyPressed && uncookedIronString.getSize()<= 6)
    {
        std::cout<<"Pressed"<<std::endl;
        if(keyrel.key.code == sf::Keyboard::Num0)
        {
            uncookedIronString += "0";
        }
        if(keyrel.key.code == sf::Keyboard::Num1)
        {
            uncookedIronString += "1";
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        {
            uncookedIronString += "2";
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        {
            uncookedIronString += "3";
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
        {
            uncookedIronString += "4";
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
        {
            uncookedIronString += "5";
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
        {
            uncookedIronString += "6";
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
        {
            uncookedIronString += "7";
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
        {
            uncookedIronString += "8";
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
        {
            uncookedIronString += "9";
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && uncookedIronString.getSize()>0 && keyrel.type == sf::Event::KeyPressed)
        {
            uncookedIronString.erase(uncookedIronString.getSize()-1);
        }
}


}

void ItemCrafting::updateDur(std::vector<int>&slot, std::vector<sf::Sprite>&frames)
{
    lamp.setPosition(frames[0].getPosition().x-64,frames[0].getPosition().y+12);
    for(int i = 0; i<durability.size(); i++)
    {
        dr[i].clear();
        dr[i].str("");
        dr[i]<<durability[i]<<"/100";
        if(slot[i] == 6 || slot[i] == 10 || slot[i]==13)
        {
            dr[i].clear();
            dr[i].str("");
            dr[i]<<durability[i];
        }
        durtext[i].setString(dr[i].str().c_str());
        durtext[i].setOrigin(durtext[i].getGlobalBounds().width/2,durtext[i].getGlobalBounds().height/2);
        durtext[i].setPosition(frames[i-1].getPosition().x+48,frames[i-1].getPosition().y+60);
    }
}

void ItemCrafting::drawFurMenu(sf::RenderWindow &window)
{
    if(cookingstat == true)
    {
        craftingMenuStatus = false;
        window.draw(cooking);
        window.draw(uncookedIronText);
        window.draw(woodNeededText);
        window.draw(penter);
    }
    if(havelamp == true)
    window.draw(lamp);
    for(int i = 0; i<6; i++)
    {
        if(durability[i]>0)
        {
            window.draw(durtext[i]);
        }
    }
}

void ItemCrafting::furBenchCollision(std::vector<sf::Sprite>&trees, std::vector<sf::Sprite>&stones,std::vector<sf::Sprite>&irons, std::vector<sf::Sprite>&walls, int &stoneAm, int &woodAm)
{
    for(int i = 0; i<furnances.size(); i++)
    {
        for(int j = 0; j<trees.size(); j++)
        {
            if(furnances[i].getGlobalBounds().intersects(trees[j].getGlobalBounds()))
            {
                furnances.erase(furnances.begin()+j);
                furDirections.erase(furDirections.begin()+j);
                stoneAm += mats_for_furnance[0];

                break;
            }
        }
        for(int j = 0; j<stones.size(); j++)
        {
            if(furnances[i].getGlobalBounds().intersects(stones[j].getGlobalBounds()))
            {
                furnances.erase(furnances.begin()+j);
                furDirections.erase(furDirections.begin()+j);
                stoneAm += mats_for_furnance[0];

                break;
            }
        }
        for(int j = 0; j<irons.size(); j++)
        {
            if(furnances[i].getGlobalBounds().intersects(irons[j].getGlobalBounds()))
            {
                furnances.erase(furnances.begin()+j);
                furDirections.erase(furDirections.begin()+j);
                stoneAm += mats_for_furnance[0];

                break;
            }
        }
    }
    for(int j = 0; j<walls.size(); j++)
    {
        for(int i = 0; i<furnances.size(); i++)
        {
            if(furnances[i].getGlobalBounds().intersects(walls[j].getGlobalBounds()))
            {
                furnances.erase(furnances.begin()+i);
                furDirections.erase(furDirections.begin()+i);
                stoneAm += mats_for_furnance[0];

                break;
            }
        }
    }

    for(int i = 0; i<benches.size(); i++)
    {
        for(int j = 0; j<trees.size(); j++)
        {
            if(benches[i].getGlobalBounds().intersects(trees[j].getGlobalBounds()))
            {
                benches.erase(benches.begin()+i);
                benDirections.erase(benDirections.begin()+i);
                benchrect.erase(benchrect.begin()+i);
                woodAm += mats_for_bench[0];

                break;
            }
        }
        for(int j = 0; j<stones.size(); j++)
        {
            if(benches[i].getGlobalBounds().intersects(stones[j].getGlobalBounds()))
            {
                benches.erase(benches.begin()+j);
                benDirections.erase(benDirections.begin()+j);
                benchrect.erase(benchrect.begin()+j);
                woodAm += mats_for_bench[0];

                break;
            }
        }
        for(int j = 0; j<irons.size(); j++)
        {
            if(benches[i].getGlobalBounds().intersects(irons[j].getGlobalBounds()))
            {
                benches.erase(benches.begin()+j);
                benDirections.erase(benDirections.begin()+j);
                benchrect.erase(benchrect.begin()+j);
                woodAm += mats_for_bench[0];

                break;
            }
        }
    }
    for(int j = 0; j<walls.size(); j++)
    {
        for(int i = 0; i<benches.size(); i++)
        {
            if(benches[i].getGlobalBounds().intersects(walls[j].getGlobalBounds()))
            {
                benches.erase(benches.begin()+i);
                benDirections.erase(benDirections.begin()+i);
                benchrect.erase(benchrect.begin()+i);
                woodAm += mats_for_bench[0];
                std::cout<<"removed bench number: "<<i<<std::endl;
                break;
            }
        }
    }
}
