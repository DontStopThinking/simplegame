// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

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
