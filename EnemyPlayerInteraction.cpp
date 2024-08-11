#include "EnemyPlayerInteraction.h"

void EnemyPlayerInteraction::update(EnemyManager& enemyManager, Player& player, OverWorldMap& overWorldMap)
{
	if (attackDelay <= 0) {
		attackEnemy(enemyManager, player, overWorldMap);
	}
	attackDelay--;
}

void EnemyPlayerInteraction::attackEnemy(EnemyManager& enemyManager, Player& player, OverWorldMap& overWorldMap)
{
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
		attackDelay = delay;
	}
}