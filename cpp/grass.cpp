#include "grass.h"

grassClass::grassClass()
{
    grasstex.loadFromFile("Sources/Textures/grass.png");
    grassSp.setTexture(grasstex);
    grassSp.setOrigin(8,16);
    grassSp.setScale(4,4);
}

grassClass::~grassClass()
{
    //dtor
}

pileClass::pileClass()
{
    piletex.loadFromFile("Sources/Textures/pile.png");
    pile.setTexture(piletex);
    pile.setScale(4,4);
    pile.setOrigin(8,16);
}
pileClass::~pileClass()
{
    //dtor
}

lilyClass::lilyClass()
{
    lilytex.loadFromFile("Sources/Textures/wlily.png");
    lily.setTexture(lilytex);
    lily.setScale(4,4);
    lily.setOrigin(8,8);
}

lilyClass::~lilyClass()
{
    //dtor
}
