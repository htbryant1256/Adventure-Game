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
private:
    void seekPlayer(OverWorldMap& overWorldMap, int playerPosX, int playerPosY);
    void randomlyWalk(OverWorldMap& overWorldMap);

    int seekingDistance;
    void initTextures();
};

