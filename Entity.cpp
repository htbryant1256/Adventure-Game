#include "Entity.h"

void Entity::animate(sf::Texture texture[4])
{
	animationTimer--;
	if (animationTimer < (delay / 4)) {
		entitySprite.setTexture(&texture[0], false);
	}
	else if (animationTimer < 2 * (delay / 4)) {
		entitySprite.setTexture(&texture[1], false);
	}
	else if (animationTimer < 3 * (delay / 4)) {
		entitySprite.setTexture(&texture[2], false);
	}
	else if (animationTimer < 4 * (delay / 4)) {
		entitySprite.setTexture(&texture[3], false);
	}
}

void Entity::animateAttack()
{
	
	if (direction == WEST) {
		entitySprite.setTexture(&entityTexture.attackLeft, false);
	}
	else if (direction == EAST) {
		entitySprite.setTexture(&entityTexture.attackRight, false);
	}
	else if (direction == SOUTH) {
		entitySprite.setTexture(&entityTexture.attackDown, false);
	}
	else if (direction == NORTH) {
		entitySprite.setTexture(&entityTexture.attackUp, false);
	}
}

void Entity::moveEntity()
{
	if (moveRight) {
		entitySprite.move(sf::Vector2f(OverWorldMap::getTileSize() / delay, 0));
		if (animationTimer <= 0) {
			moveRight = false;
			posX += 1;
		}
	}
	if (moveLeft) {
		entitySprite.move(sf::Vector2f(-OverWorldMap::getTileSize() / delay, 0));
		if (animationTimer <= 0) {
			moveLeft = false;
			posX -= 1;
		}
	}
	if (moveUp) {
		entitySprite.move(sf::Vector2f(0, -OverWorldMap::getTileSize() / delay));
		if (animationTimer <= 0) {
			moveUp = false;
			posY -= 1;
		}
	}
	if (moveDown) {
		entitySprite.move(sf::Vector2f(0, OverWorldMap::getTileSize() / delay));
		if (animationTimer <= 0) {
			moveDown = false;
			posY += 1;
		}
	}
	if (animationTimer <= 0) {
		animationTimer = delay;
	}
}

void Entity::animateLeft()
{
	animate(entityTexture.left);
}

void Entity::animateRight()
{
	animate(entityTexture.right);
}

void Entity::animateUp()
{
	animate(entityTexture.up);
}

void Entity::animateDown()
{
	animate(entityTexture.down);
}

void Entity::render(sf::RenderWindow* window)
{
	window->draw(entitySprite);
}
