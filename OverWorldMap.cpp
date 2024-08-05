#include "OverWorldMap.h"

void OverWorldMap::render(sf::RenderWindow* window)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 19; j++) {
			if (tileMap[i][j] == 'g') {
				objectTileMap[i][j].setFillColor(sf::Color(100,200,100));
			}
			else if (tileMap[i][j] == 's') {
				objectTileMap[i][j].setFillColor(sf::Color(100, 100, 100));
			}
			else if (tileMap[i][j] == 'd') {
				objectTileMap[i][j].setFillColor(sf::Color(200, 100, 100));
			}
			window->draw(objectTileMap[i][j]);
		}
	}
}

void OverWorldMap::initOverWorldMap()
{
	initMapArray();
	mapPosX = 0;
	mapPosY = 0;
	sf::RectangleShape tile;
	tile.setFillColor(sf::Color::Black);
	tile.setOutlineColor(sf::Color::White);
	tile.setOutlineThickness(1);
	tile.setSize(sf::Vector2f(tileSize, tileSize));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 19; j++) {
			tile.setPosition(sf::Vector2f(10 + (j * tileSize), 40 + (i * tileSize)));
			objectTileMap[i][j] = tile;
		}
	}
}

void OverWorldMap::initMapArray()
{
	for (int k = 0; k < 10; k++) {
		for (int l = 0; l < 19; l++) {
			mapArray[0][0][k][l] = map1[k][l];
		}
	}
	for (int k = 0; k < 10; k++) {
		for (int l = 0; l < 19; l++) {
			mapArray[1][0][k][l] = map2[k][l];
		}
	}
	for (int k = 0; k < 10; k++) {
		for (int l = 0; l < 19; l++) {
			mapArray[0][1][k][l] = map3[k][l];
		}
	}
	for (int k = 0; k < 10; k++) {
		for (int l = 0; l < 19; l++) {
			mapArray[1][1][k][l] = map4[k][l];
		}
	}
}

int OverWorldMap::getTileSize()
{
	return tileSize;
}

void OverWorldMap::loadMapLeft()
{
	if (mapPosX != 0) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 19; j++) {
				tileMap[i][j] = mapArray[mapPosX - 1][mapPosY][i][j];
			}
		}
		mapPosX -= 1;
		newMapLoaded = true;
	}
}

void OverWorldMap::loadMapRight()
{
	if (mapPosX != 1) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 19; j++) {
				tileMap[i][j] = mapArray[mapPosX + 1][mapPosY][i][j];
			}
		}
		mapPosX += 1;
		newMapLoaded = true;
	}
}

void OverWorldMap::loadMapUp()
{
	if (mapPosY != 0) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 19; j++) {
				tileMap[i][j] = mapArray[mapPosX][mapPosY - 1][i][j];
			}
		}
		mapPosY -= 1;
		newMapLoaded = true;
	}
}

void OverWorldMap::loadMapDown()
{
	if (mapPosY != 1) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 19; j++) {
				tileMap[i][j] = mapArray[mapPosX][mapPosY + 1][i][j];
			}
		}
		mapPosY += 1;
		newMapLoaded = true;
	}
}
