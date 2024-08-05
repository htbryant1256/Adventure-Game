#pragma once
#include "Entity.h"
#include "EnemyManager.h"
class Player :
    public Entity
{
public:
    void update(OverWorldMap& overWorldMap, EnemyManager& enemyManager);

    Player();
private:
    void updateCollisions(OverWorldMap& overWorldMap);
    void updateScreenChange(OverWorldMap& overWorldMap);
    void attackEnemy(EnemyManager& enemyManager);

};

