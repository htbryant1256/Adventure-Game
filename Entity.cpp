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
