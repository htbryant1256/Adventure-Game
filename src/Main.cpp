#include "Game.h"
#include <iostream>
#include <fstream>
#include <string.h>

int main()
{
    Game game;

    while (true)
    {
        game.update();
        game.render();
    }
    return 0;
}

