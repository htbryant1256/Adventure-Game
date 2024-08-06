#pragma once
#include "OverWorldMap.h"
#include "EnemyManager.h"
#include "Player.h"

class EnemyPlayerInteraction
{

public:
	
	void update(EnemyManager& enemyManager, Player player);
private:
	int attackDelay = delay;
	int delay = 10;
	void attackEnemy(EnemyManager& enemyManager, Player player);
};

