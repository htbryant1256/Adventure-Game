#pragma once
#include "Entity.h"
#include "OverWorldMap.h"
#include "Player.h"
#include <stdlib.h>     
#include <time.h>   
class Enemy :
    public Entity
{
public:
    Enemy(int x,int y);
    void update(OverWorldMap& overWorldMap, Player player);
private:
    void seekPlayer(OverWorldMap& overWorldMap, Player player);
    void randomlyWalk(OverWorldMap& overWorldMap, Player player);
    float distanceFromPlayer(Player player);

    int seekingDistance = 5;
};

