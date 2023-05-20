// simplegame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

#include "game.h"

int main()
{
    std::cout << "Hello World!\n";

    Game game{};

    while (game.Running())
    {
        game.Update();

        game.Render();
    }

    return 0;
}
