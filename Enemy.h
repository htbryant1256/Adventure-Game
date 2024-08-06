#pragma once
#include "Entity.h"
#include "OverWorldMap.h"
#include <stdlib.h>     
#include <time.h>
#include "CommonMathFunctions.h"
class Enemy :
    public Entity
{
public:
    Enemy(int x,int y);
    void update(OverWorldMap& overWorldMap, int playerPosX, int playerPosY);
    void render(sf::RenderWindow* window, OverWorldMap* overWorldMap);
private:
    void seekPlayer(OverWorldMap& overWorldMap, int playerPosX, int playerPosY);
    void randomlyWalk(OverWorldMap& overWorldMap);
    int seekingDistance;

    sf::RectangleShape enemySprite;
    sf::Texture enemyTexture;
    sf::RectangleShape enemyDirectionRect;
};

