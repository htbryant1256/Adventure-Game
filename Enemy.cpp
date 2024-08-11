#include "Enemy.h"
 
Enemy::Enemy(int x, int y)
{
	posX = x;
	posY = y;
	delay = 25;
	seekingDistance = 10;
	srand(time(NULL));
	health = 5;

	loadTextures();
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
	enemySprite.setSize(sf::Vector2f(overWorldMap.getTileSize(), overWorldMap.getTileSize()));
	enemySprite.setPosition(sf::Vector2f(10 + (posX * overWorldMap.getTileSize()), 40 + (posY * overWorldMap.getTileSize())));

	updateDelay--;
	if (hit) {
		enemySprite.setFillColor(sf::Color(100,100,100));
	}
	else {
		enemySprite.setFillColor(sf::Color::White);
	}
}

void Enemy::seekPlayer(OverWorldMap& overWorldMap, int playerPosX, int playerPosY)
{
	if (playerPosX > posX && overWorldMap.tileMap[posY][posX + 1] < 3 && posX + 1 != playerPosX) {
		posX += 1;
		enemyDirectionRect.setRotation(-90);
		enemySprite.setTexture(&enemyTextureRight, false);
	}
	else if (playerPosX < posX && overWorldMap.tileMap[posY][posX - 1] < 3 && posX +- 1 != playerPosX) {
		posX -= 1;
		enemyDirectionRect.setRotation(90);
		enemySprite.setTexture(&enemyTextureLeft, false);
	}
	if (playerPosY > posY && overWorldMap.tileMap[posY + 1][posX] < 3 && posY + 1 != playerPosY) {
		posY += 1;
		enemyDirectionRect.setRotation(0);
		enemySprite.setTexture(&enemyTextureLeft, false);
	}
	else if (playerPosY < posY && overWorldMap.tileMap[posY - 1][posX] < 3 && posY - 1 != playerPosY) {
		posY -= 1;
		enemyDirectionRect.setRotation(180);
		enemySprite.setTexture(&enemyTextureRight, false);
	}
	updateDelay = delay;
}

void Enemy::randomlyWalk(OverWorldMap& overWorldMap)
{
	int movement = rand() % 4 + 1;
	if (movement == 1 && overWorldMap.tileMap[posY][posX + 1] < 3) {
		posX += 1;
		enemyDirectionRect.setRotation(-90);
		enemySprite.setTexture(&enemyTextureRight, false);
	}
	if (movement == 2 && overWorldMap.tileMap[posY][posX - 1] < 3) {
		posX -= 1;
		enemyDirectionRect.setRotation(90);
		enemySprite.setTexture(&enemyTextureLeft, false);
	}
	if (movement == 3 && overWorldMap.tileMap[posY + 1][posX] < 3) {
		posY += 1;
		enemyDirectionRect.setRotation(0);
		enemySprite.setTexture(&enemyTextureLeft, false);
	}
	if (movement == 4 && overWorldMap.tileMap[posY - 1][posX] < 3) {
		posY -= 1;
		enemyDirectionRect.setRotation(180);
		enemySprite.setTexture(&enemyTextureRight, false);
	}
	updateDelay = delay;
}

void Enemy::loadTextures()
{
	if (!enemyTextureLeft.loadFromFile("./Graphics/Tiles/enemyTile.png"))
	{
		printf("Error Loading enemyTile.png\n");
	}
	if (!enemyTextureRight.loadFromFile("./Graphics/Tiles/enemyTileRight.png"))
	{
		printf("Error Loading enemyTileRight.png\n");
	}
    enemySprite.setTexture(&enemyTextureRight, false);
}

void Enemy::render(sf::RenderWindow* window, OverWorldMap* overWorldMap)
{
	window->draw(enemySprite);
}