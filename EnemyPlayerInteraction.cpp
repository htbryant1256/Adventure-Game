#include "EnemyPlayerInteraction.h"

void EnemyPlayerInteraction::update(EnemyManager& enemyManager, Player player)
{
	if (attackDelay <= 0) {
		attackEnemy(enemyManager, player);
	}
	attackDelay--;
}

void EnemyPlayerInteraction::attackEnemy(EnemyManager& enemyManager, Player player)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
		for (auto& element : enemyManager.enemyVector) {
			switch (player.direction) {
			case player.NORTH:
				if ((CommonMathFunctions::distanceFormula(element.posX, player.posX, element.posY, player.posY) <= attackRange && element.posY < player.posY)) {
					element.hit = true;
				}
				break;
			case player.EAST:
				if ((CommonMathFunctions::distanceFormula(element.posX, player.posX, element.posY, player.posY) <= attackRange && element.posX > player.posX)) {
					element.hit = true;
				}
				break;
			case player.SOUTH:
				if ((CommonMathFunctions::distanceFormula(element.posX, player.posX, element.posY, player.posY) <= attackRange && element.posY > player.posY)) {
					element.hit = true;
				}
				break;
			case player.WEST:
				if ((CommonMathFunctions::distanceFormula(element.posX, player.posX, element.posY, player.posY) <= attackRange && element.posX < player.posX)) {
					element.hit = true;
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