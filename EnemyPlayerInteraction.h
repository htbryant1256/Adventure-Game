#pragma once
#include "OverWorldMap.h"
#include "EnemyManager.h"
#include "Player.h"
#include "CommonMathFunctions.h"

class EnemyPlayerInteraction
{
public:
	void update(EnemyManager& enemyManager, Player& player, OverWorldMap& overWorldMap);
private:
	int attackDelay = delay;
	int delay = 15;
	int attackRange = 2;
	int knockBackDistance = 1;
	void attackEnemy(EnemyManager& enemyManager, Player& player, OverWorldMap& overWorldMap);
};

