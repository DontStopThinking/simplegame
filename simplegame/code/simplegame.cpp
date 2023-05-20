// simplegame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

int main()
{
    std::cout << "Hello World!\n";

    sf::RenderWindow window{
        sf::VideoMode{640, 480},
        "My first game",
        sf::Style::Titlebar | sf::Style::Close};

    sf::Event ev{};

    while (window.isOpen())
    {
        // Event polling
        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
                break;
            }
        }

        // Update

        // Render
        window.clear(sf::Color::Blue); // clear old frame

        // TODO: Draw game here

        window.display();   // tell app that window is done drawing
    }

    return 0;
}
