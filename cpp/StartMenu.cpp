#include "StartMenu.h"

StartMenu::StartMenu(sf::RenderWindow &window)
{
    start.setFont(rat);
    start.setCharacterSize(70);
    start.setString("START");
    start.setOrigin(start.getGlobalBounds().width/2,start.getGlobalBounds().height/2);
    start.setPosition(window.getSize().x/3.2,window.getSize().y/3);

    quit.setFont(rat);
    quit.setCharacterSize(60);
    quit.setString("QUIT");
    quit.setOrigin(quit.getGlobalBounds().width/2,quit.getGlobalBounds().height/2);
    quit.setPosition(start.getPosition().x,start.getPosition().y+300);

    how2play.setFont(rat);
    how2play.setCharacterSize(60);
    how2play.setString("How To Play");
    how2play.setOrigin(how2play.getGlobalBounds().width/2,how2play.getGlobalBounds().height/2);
    how2play.setPosition(start.getPosition().x,start.getPosition().y+100);
    instr.setFont(rat);
    instr.setCharacterSize(50);
    instr.setString("Survive as long as you can.\nLook at item descriptions for some intel.\nI'll give you some tips tho:\n-Hold 'M' for directions to your structures.\n-Bees only hide at night.\n-You will go crazy while staying in the dark.\n\nThat's about it.(I don't want to make it too easy for you)\nIf you have any suggestions or you've found a bug, make\nsure to let me know at fourpiecegames@gmail.com.\nI really appreciate any feedback.");

    settings.setFont(rat);
    settings.setCharacterSize(60);
    settings.setString("Settings");
    settings.setOrigin(settings.getGlobalBounds().width/2,settings.getGlobalBounds().height/2);
    settings.setPosition(how2play.getPosition().x, how2play.getPosition().y+100);

    menubackrect.setSize(sf::Vector2f(window.getSize().x,window.getSize().y));
    menubackrect.setFillColor(sf::Color::Black);

    menubacktex.loadFromFile("Sources/Textures/menuback.png");
    firetex.loadFromFile("Sources/Textures/fireplace.png");
    menuback.setTexture(firetex);
    menuback.setScale(1.2,1.125);
    //menuback.setPosition(window.getSize().x/1.77,0);
    menuback.setPosition(window.getSize().x/1.57,400);

    volumeback.setSize(sf::Vector2f(400,50));
    volumeback.setPosition(window.getSize().x/2.66,window.getSize().y/5);
    volumeback.setFillColor(sf::Color(100,0,0,180));
    volumeback.setOutlineColor(sf::Color(100,100,0,255));
    volumeback.setOutlineThickness(10);

    volumetext.setCharacterSize(60);
    volumetext.setFont(rat);
    volumetext.setString("volume");
    volumetext.setOrigin(volumetext.getGlobalBounds().width/2,volumetext.getGlobalBounds().height/2);
    volumetext.setPosition(volumeback.getPosition().x+200,volumeback.getPosition().y-60);
    volume.setFillColor(sf::Color::Green);
    volume.setSize(sf::Vector2f(200,50));

    vsync.setCharacterSize(60);
    vsync.setFont(rat);
    vsync.setString("vSync");
    vsync.setOrigin(vsync.getGlobalBounds().width/2,vsync.getGlobalBounds().height/2);
    vsync.setPosition(volumeback.getPosition().x+volumeback.getGlobalBounds().width/2,volumeback.getPosition().y+100);

    vsyncon.setCharacterSize(40);
    vsyncon.setFont(rat);
    vsyncon.setString("ON");
    vsyncon.setOrigin(vsyncon.getGlobalBounds().width/2,vsyncon.getGlobalBounds().height/2);

    vsyncoff.setCharacterSize(40);
    vsyncoff.setFont(rat);
    vsyncoff.setString("OFF");
    vsyncoff.setOrigin(vsyncoff.getGlobalBounds().width/2,vsyncoff.getGlobalBounds().height/2);

    vsyncon.setPosition(vsync.getPosition().x-54,vsync.getPosition().y+50);
    vsyncoff.setPosition(vsync.getPosition().x+50,vsync.getPosition().y+50);
    vsyncon.setFillColor(sf::Color::Green);

    resText.setCharacterSize(60);
    resText.setFont(rat);
    resText.setString("Resolution");
    resText.setOrigin(resText.getGlobalBounds().width/2,resText.getGlobalBounds().height/2);
    resText.setPosition(vsync.getPosition().x,vsync.getPosition().y+150);

    click.setSize(sf::Vector2f(1,1));

    resolutiontext.setCharacterSize(40);
    resolutiontext.setFont(rat);

    resolutiontext.setString("1600x900");
    resolution.push_back(resolutiontext);
    resolutiontext.setString("1920x1080");
    resolution.push_back(resolutiontext);
    std::cout<<window_style_menu<<std::endl;
    if(window.getSize().x==1600)
    {
        resolution[0].setFillColor(sf::Color::Green);
    }
    if(window.getSize().x==1920)
    {
        resolution[1].setFillColor(sf::Color::Green);
    }
    resolution[0].setOrigin(resolution[0].getGlobalBounds().width/2,resolution[0].getGlobalBounds().height/2);
    resolution[0].setPosition(resText.getPosition().x-resolution[0].getGlobalBounds().width/1.5,resText.getPosition().y+70);

    file.open("Sources/Saves/config.cfg");

    for(int i = 1; i<resolution.size(); i++)
    {
        resolution[i].setPosition(resolution[i-1].getPosition().x,resolution[i-1].getPosition().y+70);
        resolution[i].setOrigin(resolution[i].getGlobalBounds().width/2,resolution[i].getGlobalBounds().height/2);
    }

    apply.setCharacterSize(60);
    apply.setFillColor(sf::Color::Red);
    apply.setFont(rat);
    apply.setString("Apply");
    apply.setOrigin(apply.getGlobalBounds().width/2,apply.getGlobalBounds().height/2);
    apply.setPosition(resText.getPosition().x+500,resText.getPosition().y+50);

    restartText.setFont(rat);
    restartText.setCharacterSize(30);
    restartText.setString("Requires a Restart");
    restartText.setOrigin(restartText.getGlobalBounds().width/2,restartText.getGlobalBounds().height/2);
    restartText.setPosition(apply.getPosition().x,apply.getPosition().y+60);

    wscreen.setString("Windowed");
    wscreen.setCharacterSize(40);
    wscreen.setFont(rat);
    wscreen.setOrigin(wscreen.getGlobalBounds().width/2,wscreen.getGlobalBounds().height/2);
    wscreen.setPosition(resolution[0].getPosition().x+300,resolution[0].getPosition().y);

    fscreen.setString("Fullscreen");
    fscreen.setFont(rat);
    fscreen.setCharacterSize(40);
    fscreen.setOrigin(fscreen.getGlobalBounds().width/2,fscreen.getGlobalBounds().height/2);
    fscreen.setPosition(resolution[1].getPosition().x+300,resolution[1].getPosition().y);
    sizex = window.getSize().x;
    sizey = window.getSize().y;
    status = window_style_menu;

    grass.setCharacterSize(60);
    grass.setString("Dynamic Grass");
    grass.setFont(rat);
    grass.setOrigin(grass.getGlobalBounds().width/2,grass.getGlobalBounds().height/2);
    grass.setPosition(resText.getPosition().x,resText.getPosition().y+200);

    grasson.setCharacterSize(40);
    grasson.setString("ON");
    grasson.setFont(rat);
    grasson.setOrigin(grasson.getGlobalBounds().width/2,grasson.getGlobalBounds().height/2);
    grasson.setPosition(grass.getPosition().x-120,grass.getPosition().y+90);

    grassoff.setCharacterSize(40);
    grassoff.setString("OFF");
    grassoff.setFont(rat);
    grassoff.setOrigin(grassoff.getGlobalBounds().width/2,grassoff.getGlobalBounds().height/2);
    grassoff.setPosition(grass.getPosition().x+120,grass.getPosition().y+90);

    p1.setSize(sf::Vector2f(1,1));
    p2.setSize(sf::Vector2f(1,1));
    p2.setPosition(2,0);

    part.setSize(sf::Vector2f(3,3));
    part.setFillColor(sf::Color::Red);

    ftex.loadFromFile("Sources/Textures/firepart.png");
    firepart = &ftex;

    for(int i = 0; i<6; i++)
    {
        triangles.push_back(sf::RectangleShape(sf::Vector2f(80,100)));
        goup.push_back(true);
        colup.push_back(false);
    }
    for(int i = 0; i<6; i++)
    {
        triangles[i].setFillColor(sf::Color(196, 118, 15));
        triangles[i].setOrigin(40,100);
        triangles[i].setTexture(firepart);
        triangles[i].setPosition(menuback.getPosition().x+75+(i*15), menuback.getPosition().y+120);
    }
}

StartMenu::~StartMenu()
{
    //dtor
}


void StartMenu::displayMenu(sf::RenderWindow &window)
{
    if(options == false){
    if(window_style_menu == 7)
    {
        wscreen.setFillColor(sf::Color::Green);
        fscreen.setFillColor(sf::Color::White);
    }
    if(window_style_menu == 8)
    {
        fscreen.setFillColor(sf::Color::Green);
        wscreen.setFillColor(sf::Color::White);
    }
    if(window.getSize().x==1600)
    {
        resolution[0].setFillColor(sf::Color::Green);
        resolution[1].setFillColor(sf::Color::White);
    }
    if(window.getSize().x==1920)
    {
        resolution[0].setFillColor(sf::Color::White);
        resolution[1].setFillColor(sf::Color::Green);
    }
    if(drawgrass)
        grasson.setFillColor(sf::Color::Green);
    else
        grassoff.setFillColor(sf::Color::Green);
    }
    click.setPosition(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y);
    if(start.getString()=="Loading")
        loading = true;
    if(todraw == true && startgame == false || ingameMenu == true)
    {
        window.draw(menubackrect);
        if(instruction == false && options == false)
        {
            window.draw(start);
            window.draw(how2play);
            window.draw(settings);
            window.draw(quit);
            if(loading == false)
            {
                window.draw(menuback);
            }

        }
        if(instruction == true)
        {
            window.draw(instr);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                instruction = false;
            }
        }
        if(options == true)
        {
            window.draw(volumeback);
            window.draw(volume);
            window.draw(volumetext);
            window.draw(vsync);
            window.draw(vsyncon);
            window.draw(vsyncoff);
            window.draw(resText);
            window.draw(wscreen);
            window.draw(fscreen);
            window.draw(grass);
            window.draw(grasson);
            window.draw(grassoff);
            if(changed == true){
            window.draw(apply);
            window.draw(restartText);
            }
            if(no_res_changed)
                window.draw(apply);
            for(int i = 0; i<resolution.size(); i++)
            {
                window.draw(resolution[i]);
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if(click.getGlobalBounds().intersects(vsyncon.getGlobalBounds()))
                {
                    window.setVerticalSyncEnabled(true);
                    vsyncon.setFillColor(sf::Color::Green);
                    vsyncoff.setFillColor(sf::Color::White);
                }
                if(click.getGlobalBounds().intersects(vsyncoff.getGlobalBounds()))
                {
                    window.setVerticalSyncEnabled(false);
                    vsyncoff.setColor(sf::Color::Green);
                    vsyncon.setFillColor(sf::Color::White);
                }
                if(click.getGlobalBounds().intersects(resolution[0].getGlobalBounds()))
                {
                    sizex = 1600;
                    sizey = 900;
                    resolution[0].setFillColor(sf::Color::Green);
                    resolution[1].setFillColor(sf::Color::White);
                    if(window.getSize().x!=1600 || status != window_style_menu && status != 0)
                        changed = true;
                    else
                        changed = false;
                }
                if(click.getGlobalBounds().intersects(resolution[1].getGlobalBounds()))
                {
                    sizex = 1920;
                    sizey = 1080;
                    resolution[1].setFillColor(sf::Color::Green);
                    resolution[0].setFillColor(sf::Color::White);
                    if(window.getSize().x!=1920 || status != window_style_menu && status != 0)
                        changed = true;
                    else
                        changed = false;
                }
                if(click.getGlobalBounds().intersects(wscreen.getGlobalBounds()))
                {
                    status = 7;
                    fscreen.setFillColor(sf::Color::White);
                    wscreen.setFillColor(sf::Color::Green);
                    if(window_style_menu != status || window.getSize().x != sizex)
                        changed = true;
                    else
                        changed = false;
                }
                if(click.getGlobalBounds().intersects(fscreen.getGlobalBounds()))
                {
                    status = 8;
                    fscreen.setFillColor(sf::Color::Green);
                    wscreen.setFillColor(sf::Color::White);
                    if(window_style_menu != status || window.getSize().x != sizex)
                    changed = true;
                    else
                        changed = false;
                }
                if(click.getGlobalBounds().intersects(apply.getGlobalBounds()) && changed == true )
                {
                    options = false;
                    changed = false;
                    window.close();
                    file<<sizex<<std::endl;
                    file<<sizey<<std::endl;
                    file<<status<<std::endl;
                    file<<drawgrass<<std::endl;
                    system("ProjectSurvival");
                }
            if(click.getGlobalBounds().intersects(apply.getGlobalBounds()) && no_res_changed == true)
            {
                no_res_changed = false;
                options = false;
                file<<sizex<<std::endl;
                file<<sizey<<std::endl;
                file<<status<<std::endl;
                file<<drawgrass<<std::endl;
            }
                if(click.getGlobalBounds().intersects(grasson.getGlobalBounds()) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    grasson.setFillColor(sf::Color::Green);
                    grassoff.setFillColor(sf::Color::White);
                    no_res_changed = true;
                    drawgrass = true;
                }
                if(click.getGlobalBounds().intersects(grassoff.getGlobalBounds()) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    grassoff.setFillColor(sf::Color::Green);
                    grasson.setFillColor(sf::Color::White);
                    no_res_changed = true;
                    drawgrass = false;
                }
            }
            if(changed == true || no_res_changed)
            {
                apply.setFillColor(sf::Color::Green);
            }
            else
                apply.setFillColor(sf::Color::Red);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                status = window_style_menu;
                sizex = window.getSize().x;
                sizey = window.getSize().y;
                changed = false;
                options = false;
            }
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&click.getGlobalBounds().intersects(start.getGlobalBounds()))
    {
        start.setString("Loading");
        start.setOrigin(start.getGlobalBounds().width/2,start.getGlobalBounds().height/2);
        start.setPosition(window.getSize().x/2,window.getSize().y/2);
        quit.setString("");
        how2play.setString("");
        settings.setString("");
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&click.getGlobalBounds().intersects(how2play.getGlobalBounds()))
    {
        instruction = true;
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&click.getGlobalBounds().intersects(settings.getGlobalBounds()))
    {
        options = true;
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&click.getGlobalBounds().intersects(quit.getGlobalBounds())&&options == false&&startgame==false)
    {
        window.close();
    }
    }
    if(togamemenu == true)
    {
        start.setString("ESC to continue");
        start.setOrigin(start.getGlobalBounds().width/2,start.getGlobalBounds().height/2);
        start.setPosition(window.getSize().x/2,window.getSize().y/3);
        menuback.setPosition(-1000,0);
        quit.setString("Quit");
        settings.setString("Settings");
        how2play.setString("");
        quit.setPosition(start.getPosition().x,start.getPosition().y+300);
        settings.setPosition(start.getPosition().x, start.getPosition().y+100);
    }
    if(startgame == true)
        menubackrect.setFillColor(sf::Color(0,0,0,40));
}

void StartMenu::settingsControl(sf::Sound &wood, sf::Sound &stone, sf::Music &theme, sf::Sound &step, bool& ifwater, sf::RenderWindow &window)
{
    volumeAm = volume.getSize().x/40;
    volume.setPosition(volumeback.getPosition().x,volumeback.getPosition().y);
    wood.setVolume(volumeAm);
    stone.setVolume(volumeAm*1.2);
    theme.setVolume(volumeAm);
    if(ifwater == false)
    step.setVolume(volumeAm*30);
    else
        step.setVolume(volumeAm*5);
    if(options == true)
    {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&volume.getSize().x<=volumeback.getSize().x && volume.getSize().x>=0 && click.getGlobalBounds().intersects(volumeback.getGlobalBounds()))
    {
        volume.setSize(sf::Vector2f(sf::Mouse::getPosition(window).x - volumeback.getPosition().x,50));
    }
    if(volume.getSize().x>=volumeback.getSize().x)
    {
        volume.setSize(sf::Vector2f(volumeback.getSize().x,50));
    }
    if(volume.getSize().x <= 0)
    {
        volume.setSize(sf::Vector2f(0,50));
    }
    }
}

void StartMenu::fire(sf::RenderTarget &window)
{
    if(options == false && instruction == false &&loading == false && todraw == true && startgame == false)
    {
    if(p1.getPosition().x!=p2.getPosition().x)
    {
        p1.move(1,0);
    }
    if(p1.getPosition().x==p2.getPosition().x)
    {
        part.setPosition(menuback.getPosition().x+70+rand()%100,menuback.getPosition().y+60);
        if(rand()%2+1==1)
        {
            part.setFillColor(sf::Color::Red);
        }
        else
            part.setFillColor(sf::Color(196, 118, 15));
        particles.push_back(part);
        p1.setPosition(0,0);
    }
    for(int i = 0; i<particles.size(); i++)
    {
        window.draw(particles[i]);
        particles[i].move(rand()%10-5,-10);
        particles[i].setFillColor(sf::Color(particles[i].getFillColor().r,particles[i].getFillColor().g,particles[i].getFillColor().b,particles[i].getFillColor().a-5));
        if(particles[i].getFillColor().a < 5)
        {
            particles.erase(particles.begin()+i);
        }
    }
    for(int i = 0; i<triangles.size(); i++)
    {
        ///triangles[i].setScale(triangles[i].getScale().x,triangles[i].getScale().y+0.01);
        ///triangles[i].setScale(triangles[i].getScale().x,(float)(rand()%20)/10);
        if(goup[i] == true)
        {
            triangles[i].setScale(triangles[i].getScale().x,triangles[i].getScale().y+(float)(rand()%10)/100);
        }
        if(triangles[i].getScale().y>1.5 && goup[i] == true)
            goup[i]=false;
        if(goup[i]==false)
        {
            triangles[i].setScale(triangles[i].getScale().x,triangles[i].getScale().y-(float)(rand()%10)/100);
        }
        if(triangles[i].getScale().y<0.5 && goup[i] == false)
            goup[i]=true;
        //triangles[i].setOrigin(triangles[i].getGlobalBounds().width/2,triangles[i].getGlobalBounds().height/2);
        //triangles[i].setPosition(menuback.getPosition().x+menuback.getGlobalBounds().width/2,menuback.getPosition().y+menuback.getGlobalBounds().height/2);
        if(triangles[i].getFillColor().r <160)
        {
            colup[i] = true;
        }
        if(triangles[i].getFillColor().r >252 || triangles[i].getFillColor().g >252 || triangles[i].getFillColor().b >252)
        {
            colup[i] = false;
        }
        if(colup[i]==true)
        {
            triangles[i].setFillColor(sf::Color(triangles[i].getFillColor().r+1,triangles[i].getFillColor().g+1,triangles[i].getFillColor().b+1));
            if(menuback.getColor().r<252)
            menuback.setColor(sf::Color(menuback.getColor().r+1,menuback.getColor().g+1,menuback.getColor().b+1));
        }
        else
        {
            triangles[i].setFillColor(sf::Color(triangles[i].getFillColor().r-1,triangles[i].getFillColor().g-1,triangles[i].getFillColor().b-1));
            if(menuback.getColor().r>240)
            menuback.setColor(sf::Color(menuback.getColor().r-1,menuback.getColor().g-1,menuback.getColor().b-1));
        }

        window.draw(triangles[i]);
    }
    }
}
