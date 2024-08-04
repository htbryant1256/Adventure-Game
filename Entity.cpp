#include "Entity.h"

void Entity::render(sf::RenderWindow* window, OverWorldMap overWorldMap)
{
	//entity.setFillColor(sf::Color(100,150,100));
	entity.setOutlineColor(sf::Color::White);
	entity.setOutlineThickness(1);
	entity.setSize(sf::Vector2f(overWorldMap.getTileSize(), overWorldMap.getTileSize()));
	entity.setPosition(sf::Vector2f(10 + (posX * overWorldMap.getTileSize()), 40 + (posY * overWorldMap.getTileSize())));
	window->draw(entity);
}


