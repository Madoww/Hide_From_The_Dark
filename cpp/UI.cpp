#include "UI.h"

UI::UI(sf::RenderWindow &window)
{
    woodtext.setFont(rat);
    stonetext.setFont(rat);
    irontext.setFont(rat);


    timetext.setFont(rat);
    timetext.setCharacterSize(40);

    woodtex.loadFromFile("Sources/Textures/woodlog.png");
    rocktex.loadFromFile("Sources/Textures/rock.png");
    irontex.loadFromFile("Sources/Textures/iron.png");

    wood.setTexture(woodtex);
    rock.setTexture(rocktex);
    iron.setTexture(irontex);
    wood.setScale(4,4);
    rock.setScale(4,4);
    //iron.setScale(4,4);

    wood.setOrigin(8,8);
    rock.setOrigin(8,8);
    iron.setOrigin(iron.getGlobalBounds().width/2,iron.getGlobalBounds().height/2);

    lamptex.loadFromFile("Sources/Textures/lantern.png");

    mat.setFont(rat);
    oil.setFont(rat);
    oil.setCharacterSize(40);
    oil.setPosition(window.getSize().x/2,7);
    oil.setColor(sf::Color::White);
    woodtext.setPosition(window.getSize().x/1.39,window.getSize().y-100);
    oildroptex.loadFromFile("Sources/Textures/oildrop.png");
    oildrop.setTexture(oildroptex);
    oildrop.setScale(4,4);
    oildrop.setPosition(oil.getPosition().x-oil.getGlobalBounds().width-65,0);
}

UI::~UI()
{
    //dtor
}

void UI::displayResAmount(int woodAm, int stoneAm, int ironAm, std::vector<sf::Sprite>&frames, sf::RenderWindow &window, float &darkness, int unIron, bool &matsused, int &imatsused, int& matstype
                          , bool &matsgath, int &matsgtype, float &oilAm, int &iflamp, std::vector<int>&slotID, std::vector<hiveClass> &hives, float& timeneeded)
{
    time = clock.getElapsedTime();

    woodtext.setOrigin(woodtext.getGlobalBounds().width/2,woodtext.getGlobalBounds().height/2);
    stonetext.setOrigin(stonetext.getGlobalBounds().width/2,stonetext.getGlobalBounds().height/2);
    irontext.setOrigin(irontext.getGlobalBounds().width/2,irontext.getGlobalBounds().height/2);
    if(matsused == true)
    {
            mats<<imatsused;
            mat.setString(mats.str());
            mat.setOrigin(mat.getGlobalBounds().width/2,mat.getGlobalBounds().height/2);
            if(matstype == 1)
                mat.setPosition(woodtext.getPosition());
            else if(matstype == 2)
                mat.setPosition(stonetext.getPosition());
            else if(matstype == 3)
                mat.setPosition(irontext.getPosition());
            matstext.push_back(mat);
            mats.clear();
            mats.str("");
            std::cout<<"Mats"<<std::endl;
            matsused = false;
    }
    if(matsgath == true)
    {
        if(matsgtype == 1)
        {
            growwood = true;
        }
        if(matsgtype == 2)
        {
            growstone = true;
        }
        if(matsgtype == 3)
        {
            growiron = true;
        }
    }
    if(growwood == true)
    {
        woodtext.setScale(woodtext.getScale().x+0.1,woodtext.getScale().y+0.1);
        woodtext.setColor(sf::Color(woodtext.getColor().r-40, woodtext.getColor().g, woodtext.getColor().b-40));
        if(woodtext.getScale().x>=1.6)
        {
            matsgtype = 0;
            growwood = false;
            matsgath = false;
        }
    }

    if(growwood == false && woodtext.getScale().x>1)
    {
        woodtext.setScale(woodtext.getScale().x-0.1,woodtext.getScale().y-0.1);
        woodtext.setColor(sf::Color(woodtext.getColor().r+40, woodtext.getColor().g, woodtext.getColor().b+40));
    }

    if(growstone == true)
    {
        stonetext.setScale(stonetext.getScale().x+0.1,stonetext.getScale().y+0.1);
        stonetext.setColor(sf::Color(stonetext.getColor().r-40, stonetext.getColor().g, stonetext.getColor().b-40));
        if(stonetext.getScale().x>=1.6)
        {
            matsgtype = 0;
            growstone = false;
            matsgath = false;
        }
    }
    if(growstone == false && stonetext.getScale().x>1)
    {
        stonetext.setScale(stonetext.getScale().x-0.1,stonetext.getScale().y-0.1);
        stonetext.setColor(sf::Color(stonetext.getColor().r+40, stonetext.getColor().g, stonetext.getColor().b+40));
    }

    if(growiron == true)
    {
        irontext.setScale(irontext.getScale().x+0.1,irontext.getScale().y+0.1);
        irontext.setColor(sf::Color(irontext.getColor().r-40, irontext.getColor().g, irontext.getColor().b-40));
        if(irontext.getScale().x>=1.5)
        {
            matsgtype = 0;
            growiron = false;
            matsgath = false;
        }
    }

    if(growiron == false && irontext.getScale().x>1)
    {
        irontext.setScale(irontext.getScale().x-0.1,irontext.getScale().y-0.1);
        irontext.setColor(sf::Color(irontext.getColor().r+40, irontext.getColor().g, irontext.getColor().b+40));
    }



    ws.clear();
    ws.str("");
    ws<<woodAm;
    woodtext.setString(ws.str().c_str());


    ss.clear();
    ss.str("");
    ss<<stoneAm;
    stonetext.setString(ss.str().c_str());

    is.clear();
    is.str("");
    is<<ironAm<<"("<<unIron<<")";
    irontext.setString(is.str().c_str());


    oilstream.clear();
    oilstream.str("");
    if(oilAm > 0)
    oilstream<<std::setprecision(4)<<oilAm;
    else
        oilstream<<0;
    oil.setString(oilstream.str().c_str());
    oil.setOrigin(oil.getGlobalBounds().width/2,0);
    //oil.setPosition(window.getSize().x/2,0);


    tl.clear();
    tl.str("");
    tl<<minutes;
    tl<<":";
    if(seconds < 10)
    {
        tl<<"0";
    }
    tl<<seconds;
    timetext.setString(tl.str().c_str());

    wood.setPosition(woodtext.getPosition().x,woodtext.getPosition().y+60);
    rock.setPosition(stonetext.getPosition().x,stonetext.getPosition().y+60);
    iron.setPosition(irontext.getPosition().x,irontext.getPosition().y+50);

    //woodtext.setPosition(frames[0].getPosition().x+frames[0].getGlobalBounds().width/2,frames[0].getPosition().y+frames[0].getGlobalBounds().height/2-10);
    //stonetext.setPosition(frames[1].getPosition().x+frames[1].getGlobalBounds().width/2,frames[1].getPosition().y+frames[1].getGlobalBounds().height/2-10);
    //irontext.setPosition(frames[2].getPosition().x+frames[2].getGlobalBounds().width/2,frames[2].getPosition().y+frames[2].getGlobalBounds().height/2-10);

    //woodtext.setPosition(window.getSize().x/1.39,window.getSize().y-100);
    stonetext.setPosition(woodtext.getPosition().x+150,woodtext.getPosition().y);
    irontext.setPosition(stonetext.getPosition().x+150,stonetext.getPosition().y);

    if(time.asSeconds() >= timeneeded )
    {
        //seconds -= 1;
        //if(darkness < 254)
        //darkness += 0.15;
        clock.restart();
    }
    if(seconds < 0)
    {
        seconds = 59;
        minutes -= 1;
    }

    for(int i = 0; i<matstext.size(); i++)
    {
        matstext[i].setColor(sf::Color(255,255,255,matstext[i].getColor().a-5));
        matstext[i].move(0,-1);
        if(matstext[i].getColor().a<=0)
        {
            matstext.erase(matstext.begin()+i);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        nighttime = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        nighttime = true;
    }
    /*if(minutes == 0)
    {
        mins = 1;
        if(seconds == 0 && nighttime == false)
        {

            nighttime = true;
            tonight = true;
            today = false;
            minutes = 0;
            seconds = 10;
        }
        else
            tonight = false;
    }

        if(minutes == 0 && seconds == 0 && nighttime == true)
        {
            nighttime = false;
            today = true;
            tonight = false;
            for(int i = 0; i<hives.size(); i++)
                hives[i].beesam = 0;
            minutes = 0;
            seconds = 10;
        }
        else
            today = false;*/
    if(darkness > 220)
    {
        nighttime = true;
        today = false;
    }
    if(darkness > 219 && darkness < 221)
        tonight = true;
    else
        tonight = false;
    if(darkness < 220)
    {
        nighttime = false;
        today = true;
        tonight = false;
        for(int i = 0; i<hives.size(); i++)
        {
            hives[i].beesam = 0;
        }
    }
    else
        today = false;
    window.draw(woodtext);
    window.draw(stonetext);
    window.draw(irontext);
    //window.draw(timetext);

    window.draw(oil);

    it = std::find(slotID.begin(),slotID.end(),4);

    for(int i = 0; i<slotID.size(); i++)
    {
    if((iflamp == 4 && oil.getColor().a < 255) || (*it == 0 && oil.getColor().a < 255))
    {
        oil.setColor(sf::Color(255,255,255,oil.getColor().a+5));
    }
    else if(oil.getColor().a > 0 && slotID[i]==4)
        oil.setColor(sf::Color(255,255,255,oil.getColor().a-5));
    }
    oildrop.setPosition(oil.getPosition().x-oil.getGlobalBounds().width-65,0);
    window.draw(wood);
    window.draw(rock);
    window.draw(iron);
    window.draw(oildrop);
}


