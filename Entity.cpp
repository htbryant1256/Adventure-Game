#include "Entity.h"

void Entity::render(sf::RenderWindow* window, OverWorldMap* overWorldMap)
{
	
	entity.setOutlineColor(sf::Color::White);
	entity.setOutlineThickness(1);
	entity.setSize(sf::Vector2f(overWorldMap->getTileSize(), overWorldMap->getTileSize()));
	entity.setPosition(sf::Vector2f(10 + (posX * overWorldMap->getTileSize()), 40 + (posY * overWorldMap->getTileSize())));

	entityDirection.setFillColor(sf::Color(200,0,0));
	entityDirection.setOutlineColor(sf::Color::White);
	entityDirection.setOutlineThickness(1);
	entityDirection.setSize(sf::Vector2f(10, 25));
	entityDirection.setPosition(sf::Vector2f(entity.getPosition().x + overWorldMap->getTileSize() / 2, entity.getPosition().y + overWorldMap->getTileSize() / 2));
	
	window->draw(entity);
	window->draw(entityDirection);
}


