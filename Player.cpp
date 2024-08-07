#include "Player.h"

Player::Player()
{
	posX = 1;
	posY = 1;
	delay = 12;
	//entity.setFillColor(sf::Color(100,150,100));
	
	
	if (!playerTexture.loadFromFile("./Graphics/Tiles/playerTile.png"))
	{
		printf("Error Loading playerTile.png\n");
	}

	if (!playerTextureLeft.loadFromFile("./Graphics/Tiles/playerTileLeft.png"))
	{
		printf("Error Loading playerTile.png\n");
	}

	if (!playerTextureLeft2.loadFromFile("./Graphics/Tiles/playerTileLeft2.png"))
	{
		printf("Error Loading playerTile.png\n");
	}

	if (!playerTextureLeft3.loadFromFile("./Graphics/Tiles/playerTileLeft3.png"))
	{
		printf("Error Loading playerTile.png\n");
	}

	if (!playerTextureLeft4.loadFromFile("./Graphics/Tiles/playerTileLeft4.png"))
	{
		printf("Error Loading playerTile.png\n");
	}




	if (!playerTextureRight2.loadFromFile("./Graphics/Tiles/playerTileRight2.png"))
	{
		printf("Error Loading playerTile.png\n");
	}

	if (!playerTextureRight3.loadFromFile("./Graphics/Tiles/playerTileRight3.png"))
	{
		printf("Error Loading playerTile.png\n");
	}

	if (!playerTextureRight4.loadFromFile("./Graphics/Tiles/playerTileRight4.png"))
	{
		printf("Error Loading playerTile.png\n");
	}

	playerSprite.setTexture(&playerTexture, false);

	playerDirectionRect.setFillColor(sf::Color(200, 0, 0));
	playerDirectionRect.setSize(sf::Vector2f(10, 25));
	
}

void Player::updateCollisions(OverWorldMap& overWorldMap)
{
	/*
	
	//TODO Add else if tree for diagonal movement handeling with the new animations.
	
	*/


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (overWorldMap.tileMap[posY][posX + 1] != 's' && posY + 1 != 38) {
			//posX += 1;
			moveRight = true;
			updateDelay = delay;
		}
		//playerSprite.setTexture(&playerTexture, false);
		direction = EAST;
		playerDirectionRect.setRotation(-90);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (overWorldMap.tileMap[posY][posX - 1] != 's' && posY - 1 != -1) {
			//posX -= 1;
			moveLeft = true;
			updateDelay = delay;
		}
	//	playerSprite.setTexture(&playerTextureLeft, false);
		direction = WEST;
		playerDirectionRect.setRotation(90);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (overWorldMap.tileMap[posY + 1][posX] != 's' && posY + 1 != 20) {
			//posY += 1;
			moveDown = true;
			updateDelay = delay;
		}
		//playerSprite.setTexture(&playerTexture, false);
		direction = SOUTH;
		playerDirectionRect.setRotation(0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (overWorldMap.tileMap[posY - 1][posX] != 's' && posY - 1 != -1) {
			//posY -= 1;
			moveUp = true;
			updateDelay = delay;
		}
		//playerSprite.setTexture(&playerTextureLeft, false);
		direction = NORTH;
		playerDirectionRect.setRotation(180);
	}
}

void Player::updateScreenChange(OverWorldMap& overWorldMap)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && overWorldMap.tileMap[posY][posX] == 'd' && posX == 37) {
		posX = 0;
		overWorldMap.loadMapRight();
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && overWorldMap.tileMap[posY][posX] == 'd' && posX == 0) {
		posX = 37;
		overWorldMap.loadMapLeft();
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && overWorldMap.tileMap[posY][posX] == 'd' && posY == 19) {
		posY = 0;
		overWorldMap.loadMapDown();
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && overWorldMap.tileMap[posY][posX] == 'd' && posY == 0) {
		posY = 19;
		overWorldMap.loadMapUp();
		updateDelay = delay;
	}
}

void Player::update(OverWorldMap& overWorldMap)
{
	if (updateDelay <= 0) {

		//Stone Collisions
		updateCollisions(overWorldMap);
	}
	if (moveRight && moveUp) {
		animationTimer--;
		playerSprite.move(sf::Vector2f(50/delay, -50 / delay));

		if (animationTimer == 0) {
			playerSprite.setTexture(&playerTexture, false);
		}
		else if (animationTimer < (delay / 4)) {
			playerSprite.setTexture(&playerTextureRight2, false);
		}
		else if (animationTimer < 2 * (delay / 4)) {
			playerSprite.setTexture(&playerTextureRight3, false);
		}
		else if (animationTimer < 3 * (delay / 4)) {
			playerSprite.setTexture(&playerTextureRight4, false);
		}

		if (animationTimer <= 0) {
			moveRight = false;
			moveUp = false;
			posY -= 1;
			posX += 1;
			animationTimer = delay;
		}
	}
	else if (moveRight && moveDown) {
		animationTimer--;
		playerSprite.move(sf::Vector2f(50 / delay, 50 / delay));

		if (animationTimer == 0) {
			playerSprite.setTexture(&playerTexture, false);
		}
		else if (animationTimer < (delay / 4)) {
			playerSprite.setTexture(&playerTextureRight2, false);
		}
		else if (animationTimer < 2 * (delay / 4)) {
			playerSprite.setTexture(&playerTextureRight3, false);
		}
		else if (animationTimer < 3 * (delay / 4)) {
			playerSprite.setTexture(&playerTextureRight4, false);
		}

		if (animationTimer <= 0) {
			moveRight = false;
			moveDown = false;
			posY += 1;
			posX += 1;
			animationTimer = delay;
		}
	}
	else if (moveLeft && moveDown) {
		animationTimer--;
		playerSprite.move(sf::Vector2f(-50 / delay, 50 / delay));
		if (animationTimer == 0) {
			playerSprite.setTexture(&playerTextureLeft, false);
		}
		else if (animationTimer < (delay / 4)) {
			playerSprite.setTexture(&playerTextureLeft2, false);
		}
		else if (animationTimer < 2 * (delay / 4)) {
			playerSprite.setTexture(&playerTextureLeft3, false);
		}
		else if (animationTimer < 3 * (delay / 4)) {
			playerSprite.setTexture(&playerTextureLeft2, false);
		}
		if (animationTimer <= 0) {
			moveLeft = false;
			moveDown = false;
			posY += 1;
			posX -= 1;
			animationTimer = delay;
		}
	}
	else if (moveLeft && moveUp) {
		animationTimer--;
		playerSprite.move(sf::Vector2f(-50 / delay, -50 / delay));
		if (animationTimer == 0) {
			playerSprite.setTexture(&playerTextureLeft, false);
		}
		else if (animationTimer < (delay / 4)) {
			playerSprite.setTexture(&playerTextureLeft2, false);
		}
		else if (animationTimer < 2 * (delay / 4)) {
			playerSprite.setTexture(&playerTextureLeft3, false);
		}
		else if (animationTimer < 3 * (delay / 4)) {
			playerSprite.setTexture(&playerTextureLeft2, false);
		}
		if (animationTimer <= 0) {
			moveLeft = false;
			moveUp = false;
			posY -= 1;
			posX -= 1;
			animationTimer = delay;
		}
	}
	else if (moveLeft) {
		animationTimer--;
		playerSprite.move(sf::Vector2f(-50 / delay, 0));
		
		if (animationTimer == 0) {
			playerSprite.setTexture(&playerTextureLeft, false);
		}else if (animationTimer < (delay / 4)) {
			playerSprite.setTexture(&playerTextureLeft2, false);
		}else if (animationTimer < 2 * (delay / 4)) {
			playerSprite.setTexture(&playerTextureLeft3, false);
		}else if (animationTimer < 3 * (delay / 4)) {
			playerSprite.setTexture(&playerTextureLeft2, false);
		}
		

		if (animationTimer <= 0) {
			moveLeft = false;
			posX -= 1;
			animationTimer = delay;
		}
	}
	else if (moveRight) {
		animationTimer--;
		playerSprite.move(sf::Vector2f(50 / delay, 0));

		if (animationTimer == 0) {
			playerSprite.setTexture(&playerTexture, false);
		}
		else if (animationTimer < (delay / 4)) {
			playerSprite.setTexture(&playerTextureRight2, false);
		}
		else if (animationTimer < 2 * (delay / 4)) {
			playerSprite.setTexture(&playerTextureRight3, false);
		}
		else if (animationTimer < 3 * (delay / 4)) {
			playerSprite.setTexture(&playerTextureRight4, false);
		}

		if (animationTimer <= 0) {
			moveRight = false;
			posX += 1;
			animationTimer = delay;
		}
	}
	else if (moveUp) {
		animationTimer--;
		playerSprite.move(sf::Vector2f(0, -50 / delay));

		if (animationTimer == 0) {
			playerSprite.setTexture(&playerTextureLeft, false);
		}
		else if (animationTimer < (delay / 4)) {
			playerSprite.setTexture(&playerTextureLeft2, false);
		}
		else if (animationTimer < 2 * (delay / 4)) {
			playerSprite.setTexture(&playerTextureLeft3, false);
		}
		else if (animationTimer < 3 * (delay / 4)) {
			playerSprite.setTexture(&playerTextureLeft2, false);
		}

		if (animationTimer <= 0) {
			moveUp = false;
			posY -= 1;
			animationTimer = delay;
		}
	}
	else if (moveDown) {
		animationTimer--;
		playerSprite.move(sf::Vector2f(0, 50 / delay));

		if (animationTimer == 0) {
			playerSprite.setTexture(&playerTexture, false);
		}
		else if (animationTimer < (delay / 4)) {
			playerSprite.setTexture(&playerTextureRight2, false);
		}
		else if (animationTimer < 2 * (delay / 4)) {
			playerSprite.setTexture(&playerTextureRight3, false);
		}
		else if (animationTimer < 3 * (delay / 4)) {
			playerSprite.setTexture(&playerTextureRight4, false);
		}

		if (animationTimer <= 0) {
			moveDown = false;
			posY += 1;
			animationTimer = delay;
		}
	}
	updateDelay--;
	//Screen Change Logic
	updateScreenChange(overWorldMap);
	
}

void Player::render(sf::RenderWindow* window, OverWorldMap* overWorldMap)
{
	playerSprite.setSize(sf::Vector2f(overWorldMap->getTileSize(), overWorldMap->getTileSize()));
	if (!moveRight && !moveLeft && !moveDown && !moveUp) {
		playerSprite.setPosition(sf::Vector2f(10 + (posX * overWorldMap->getTileSize()), 40 + (posY * overWorldMap->getTileSize())));
	}
	
	playerDirectionRect.setPosition(sf::Vector2f(playerSprite.getPosition().x + overWorldMap->getTileSize() / 2, playerSprite.getPosition().y + overWorldMap->getTileSize() / 2));
	window->draw(playerSprite);
	//window->draw(playerDirectionRect);
}
