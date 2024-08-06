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
		switch (player.direction) {
		case player.NORTH:
			for (auto& element : enemyManager.enemyVector) {
				if (((element.posX == player.posX) || (element.posX == player.posX - 1) || (element.posX == player.posX + 1)) && (element.posY == player.posY - 1)) {
					element.hit = true;
				}
			}
			break;
		case player.EAST:
			for (auto& element : enemyManager.enemyVector) {
				if (((element.posY == player.posY) || (element.posY == player.posY - 1) || (element.posY == player.posY + 1)) && (element.posX == player.posX + 1)) {
					element.hit = true;
				}
			}
			break;
		case player.SOUTH:
			for (auto& element : enemyManager.enemyVector) {
				if (((element.posX == player.posX) || (element.posX == player.posX - 1) || (element.posX == player.posX + 1)) && (element.posY == player.posY + 1)) {
					element.hit = true;
				}
			}
			break;
		case player.WEST:
			for (auto& element : enemyManager.enemyVector) {
				if (((element.posY == player.posY) || (element.posY == player.posY - 1) || (element.posY == player.posY + 1)) && (element.posX == player.posX - 1)) {
					element.hit = true;
				}
			}
			break;
		}
		attackDelay = delay;
	}
}