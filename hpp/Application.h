#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

class Application
{
    public:
        Application();
        Application(int X, int Y)
        {
            sf::RenderWindow window(sf::RenderTarget &window, sf::VideoMode(X,Y));
        }
        virtual ~Application();

    protected:

    private:
};

#endif // APPLICATION_H
