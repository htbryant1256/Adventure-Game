#pragma once
#include "Entity.h"
class Player :
    public Entity
{
public:
    void update(OverWorldMap& overWorldMap);
    void resetPlayer();
    Player();
private:
    void updateCollisions(OverWorldMap& overWorldMap);
    void updateScreenChange(OverWorldMap& overWorldMap);

    void initTextures();


    int totalHealth = 100;
    int playerStartingPosX = 15;
    int playerStartingPosY = 8;
};

