#include "Enemy.h"
 
Enemy::Enemy(int x, int y)
{
	posX = x;
	posY = y;
	delay = 10;
	seekingDistance = 10;
	srand(time(NULL));
	health = 5;

	if (!enemyTexture.loadFromFile("./Graphics/Tiles/playerTile.png"))
	{
		printf("Error Loading playerTile.png\n");
	}

	enemySprite.setTexture(&enemyTexture, false);

	enemyDirectionRect.setFillColor(sf::Color(200, 0, 0));
	enemyDirectionRect.setSize(sf::Vector2f(10, 25));
}

void Enemy::update(OverWorldMap& overWorldMap, int playerPosX, int playerPosY)
{
	if (updateDelay <= 0) {
		if (CommonMathFunctions::distanceFormula(playerPosX, posX, playerPosY, posY) <= seekingDistance) {
			seekPlayer(overWorldMap, playerPosX, playerPosY);
		}
		else {
			randomlyWalk(overWorldMap);
		}
	}
	updateDelay--;
	if (hit) {
		enemySprite.setFillColor(sf::Color(250, 250, 250));
	}
	else {
		enemySprite.setFillColor(sf::Color(150, 100, 100));
	}
}

void Enemy::seekPlayer(OverWorldMap& overWorldMap, int playerPosX, int playerPosY)
{
	if (playerPosX > posX && overWorldMap.tileMap[posY][posX + 1] == 'g' && posX + 1 != playerPosX) {
		posX += 1;
		enemyDirectionRect.setRotation(-90);
	}
	else if (playerPosX < posX && overWorldMap.tileMap[posY][posX - 1] == 'g' && posX +- 1 != playerPosX) {
		posX -= 1;
		enemyDirectionRect.setRotation(90);
	}
	if (playerPosY > posY && overWorldMap.tileMap[posY + 1][posX] == 'g' && posY + 1 != playerPosY) {
		posY += 1;
		enemyDirectionRect.setRotation(0);
	}
	else if (playerPosY < posY && overWorldMap.tileMap[posY - 1][posX] == 'g' && posY - 1 != playerPosY) {
		posY -= 1;
		enemyDirectionRect.setRotation(180);
	}
	updateDelay = delay;
}

void Enemy::randomlyWalk(OverWorldMap& overWorldMap)
{
	int movement = rand() % 4 + 1;

	if (movement == 1 && overWorldMap.tileMap[posY][posX + 1] == 'g') {
		posX += 1;
		enemyDirectionRect.setRotation(-90);
	}
	if (movement == 2 && overWorldMap.tileMap[posY][posX - 1] == 'g') {
		posX -= 1;
		enemyDirectionRect.setRotation(90);
	}
	if (movement == 3 && overWorldMap.tileMap[posY + 1][posX] == 'g') {
		posY += 1;
		enemyDirectionRect.setRotation(0);
	}
	if (movement == 4 && overWorldMap.tileMap[posY - 1][posX] == 'g') {
		posY -= 1;
		enemyDirectionRect.setRotation(180);
	}
	updateDelay = delay;
}

void Enemy::render(sf::RenderWindow* window, OverWorldMap* overWorldMap)
{
	enemySprite.setSize(sf::Vector2f(overWorldMap->getTileSize(), overWorldMap->getTileSize()));
	enemySprite.setPosition(sf::Vector2f(10 + (posX * overWorldMap->getTileSize()), 40 + (posY * overWorldMap->getTileSize())));
	enemyDirectionRect.setPosition(sf::Vector2f(enemySprite.getPosition().x + overWorldMap->getTileSize() / 2, enemySprite.getPosition().y + overWorldMap->getTileSize() / 2));
	window->draw(enemySprite);
	window->draw(enemyDirectionRect);
}