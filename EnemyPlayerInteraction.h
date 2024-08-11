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
	int playerAttackDelay = 15;
	int enemyAttackDelay = 10;
	int attackRange = 2;
	int knockBackDistance = 1;
	void playerAttackEnemy(EnemyManager& enemyManager, Player& player, OverWorldMap& overWorldMap);
	void enemyAttackPlayer(EnemyManager& enemyManager, Player& player, OverWorldMap& overWorldMap);
};

