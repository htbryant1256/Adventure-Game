#pragma once
#include "Entity.h"
#include "OverWorldMap.h"
#include "Player.h"
class Enemy :
    public Entity
{
public:
    Enemy();
    void update(OverWorldMap& overWorldMap, Player player);
private:
};

