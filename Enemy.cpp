#include "Enemy.h"
 
Enemy::Enemy(int x, int y)
{
	posX = x;
	posY = y;
	delay = 15;
	seekingDistance = 10;
	srand(time(NULL));
	health = 5;

	if (!enemyTexture.loadFromFile("./Graphics/Tiles/enemyTile.png"))
	{
		printf("Error Loading enemyTile.png\n");
	}
	if (!enemyTextureRight.loadFromFile("./Graphics/Tiles/enemyTileRight.png"))
	{
		printf("Error Loading enemyTileRight.png\n");
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
		enemySprite.setFillColor(sf::Color(100,100,100));
	}
	else {
		enemySprite.setFillColor(sf::Color::White);
	}
}

void Enemy::seekPlayer(OverWorldMap& overWorldMap, int playerPosX, int playerPosY)
{
	enemySprite.setTexture(&enemyTextureRight, false);
	if (playerPosX > posX && overWorldMap.tileMap[posY][posX + 1] == 'g' && posX + 1 != playerPosX) {
		posX += 1;
		enemyDirectionRect.setRotation(-90);
		enemySprite.setTexture(&enemyTextureRight, false);
	}
	else if (playerPosX < posX && overWorldMap.tileMap[posY][posX - 1] == 'g' && posX +- 1 != playerPosX) {
		posX -= 1;
		enemyDirectionRect.setRotation(90);
		enemySprite.setTexture(&enemyTexture, false);
	}
	if (playerPosY > posY && overWorldMap.tileMap[posY + 1][posX] == 'g' && posY + 1 != playerPosY) {
		posY += 1;
		enemyDirectionRect.setRotation(0);
		enemySprite.setTexture(&enemyTexture, false);
	}
	else if (playerPosY < posY && overWorldMap.tileMap[posY - 1][posX] == 'g' && posY - 1 != playerPosY) {
		posY -= 1;
		enemyDirectionRect.setRotation(180);
		enemySprite.setTexture(&enemyTextureRight, false);
	}
	updateDelay = delay;
}

void Enemy::randomlyWalk(OverWorldMap& overWorldMap)
{
	int movement = rand() % 4 + 1;
	enemySprite.setTexture(&enemyTextureRight, false);
	if (movement == 1 && overWorldMap.tileMap[posY][posX + 1] == 'g') {
		posX += 1;
		enemyDirectionRect.setRotation(-90);
		enemySprite.setTexture(&enemyTextureRight, false);
	}
	if (movement == 2 && overWorldMap.tileMap[posY][posX - 1] == 'g') {
		posX -= 1;
		enemyDirectionRect.setRotation(90);
		enemySprite.setTexture(&enemyTexture, false);
	}
	if (movement == 3 && overWorldMap.tileMap[posY + 1][posX] == 'g') {
		posY += 1;
		enemyDirectionRect.setRotation(0);
		enemySprite.setTexture(&enemyTexture, false);
	}
	if (movement == 4 && overWorldMap.tileMap[posY - 1][posX] == 'g') {
		posY -= 1;
		enemyDirectionRect.setRotation(180);
		enemySprite.setTexture(&enemyTextureRight, false);
	}
	updateDelay = delay;
}

void Enemy::render(sf::RenderWindow* window, OverWorldMap* overWorldMap)
{
	enemySprite.setSize(sf::Vector2f(overWorldMap->getTileSize(), overWorldMap->getTileSize()));
	enemySprite.setPosition(sf::Vector2f(10 + (posX * overWorldMap->getTileSize()), 40 + (posY * overWorldMap->getTileSize())));
	enemyDirectionRect.setPosition(sf::Vector2f(enemySprite.getPosition().x + overWorldMap->getTileSize() / 2, enemySprite.getPosition().y + overWorldMap->getTileSize() / 2));
	
	window->draw(enemySprite);
	//window->draw(enemyDirectionRect);
}