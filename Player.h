#pragma once
#include "Entity.h"
class Player :
    public Entity
{
public:
    void update(OverWorldMap& overWorldMap);

    Player();
private:
    void updateCollisions(OverWorldMap& overWorldMap);
    void updateScreenChange(OverWorldMap& overWorldMap);
    

};

