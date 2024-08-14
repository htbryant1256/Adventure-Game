#include "EnemyPlayerInteraction.h"

void EnemyPlayerInteraction::update(EnemyManager& enemyManager, Player& player, OverWorldMap& overWorldMap)
{
	
	playerAttackEnemy(enemyManager, player, overWorldMap);
	enemyAttackPlayer(enemyManager, player, overWorldMap);
}

void EnemyPlayerInteraction::playerAttackEnemy(EnemyManager& enemyManager, Player& player, OverWorldMap& overWorldMap)
{
	if (player.attackDelay <= 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
			for (auto& element : enemyManager.enemyVector) {
				switch (player.direction) {
				case player.NORTH:
					if ((CommonMathFunctions::distanceFormula(element.posX, player.posX, element.posY, player.posY) <= attackRange && element.posY < player.posY)) {
						element.hit = true;
						if (overWorldMap.tileMap[element.posY - knockBackDistance][element.posX] < 3) {
							element.posY -= knockBackDistance;
						}
					}
					break;
				case player.EAST:
					if ((CommonMathFunctions::distanceFormula(element.posX, player.posX, element.posY, player.posY) <= attackRange && element.posX > player.posX)) {
						element.hit = true;
						if (overWorldMap.tileMap[element.posY][element.posX + 1] < 3) {
							element.posX += knockBackDistance;
						}
					}
					break;
				case player.SOUTH:
					if ((CommonMathFunctions::distanceFormula(element.posX, player.posX, element.posY, player.posY) <= attackRange && element.posY > player.posY)) {
						element.hit = true;
						if (overWorldMap.tileMap[element.posY + knockBackDistance][element.posX] < 3) {
							element.posY += knockBackDistance;
						}
					}
					break;
				case player.WEST:
					if ((CommonMathFunctions::distanceFormula(element.posX, player.posX, element.posY, player.posY) <= attackRange && element.posX < player.posX)) {
						element.hit = true;
						if (overWorldMap.tileMap[element.posY][element.posX - knockBackDistance] < 3) {
							element.posX -= knockBackDistance;
						}
					}
					break;
				}
				if (CommonMathFunctions::distanceFormula(element.posX, player.posX, element.posY, player.posY) == 0) {
					element.hit = true;
				}
			}
			player.attackDelay = playerAttackDelay;
		}
	}
	player.attackDelay--;
}

void EnemyPlayerInteraction::enemyAttackPlayer(EnemyManager& enemyManager, Player& player, OverWorldMap& overWorldMap)
{
	for (auto& element : enemyManager.enemyVector) {
		if (element.attackDelay <= 0) {
			if (CommonMathFunctions::distanceFormula(element.posX, player.posX, element.posY, player.posY) <= 1.5) {
				player.hit = true;
				element.animateAttack();
			}
			element.attackDelay = enemyAttackDelay;
		}
		element.attackDelay--;
		
	}

}
