#include "OverWorldMap.h"
#include "iostream"

void OverWorldMap::initOverWorldMap()
{
	loadTextures();
	initObjectTileMap();
	initJsonReader();
	loadMapFromJson();
}

void OverWorldMap::render(sf::RenderWindow* window)
{
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 29; j++) {
			if (tileMap[i][j] == 1) {
				objectTileMap[i][j].setTexture(&grassTexture, false);
			}
			else if (tileMap[i][j] == 2) {
				objectTileMap[i][j].setTexture(&stoneTexture, false);
			}
			window->draw(objectTileMap[i][j]);
		}
	}
}

void OverWorldMap::loadTextures() 
{
	if (!stoneTexture.loadFromFile("./Graphics/Tiles/stoneTile.png"))
	{
		printf("Error Loading stoneTile.png\n");
	}

	if (!grassTexture.loadFromFile("./Graphics/Tiles/grassTile.png"))
	{
		printf("Error Loading grassTile.png\n");
	}
}

void OverWorldMap::initJsonReader()
{
	std::ifstream file("TileMap/MapTest.json");
	reader.parse(file, actualJson);
	mapWidth = actualJson["layers"][0]["width"].asInt();
	mapHeight = actualJson["layers"][0]["height"].asInt();
}


void OverWorldMap::initObjectTileMap()
{
	sf::RectangleShape tile;
	tile.setFillColor(sf::Color(200, 200, 200));
	tile.setSize(sf::Vector2f(tileSize, tileSize));
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 29; j++) {
			tile.setPosition(sf::Vector2f(10 + (j * tileSize), 40 + (i * tileSize)));
			objectTileMap[i][j] = tile;
		}
	}
}

void OverWorldMap::loadMapLeft()
{
	mapX -= 1;
	loadMapFromJson();
}

void OverWorldMap::loadMapRight()
{
	mapX += 1;
	loadMapFromJson();
}

void OverWorldMap::loadMapUp()
{
	mapY -= 1;
	loadMapFromJson();
}

void OverWorldMap::loadMapDown()
{
	mapY += 1;
	loadMapFromJson();
}

void OverWorldMap::loadMapFromJson()
{
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 29; j++) {
			tileMap[i][j] = (char)actualJson["layers"][0]["data"][(j + (mapX * (mapWidth / 2))) + (i * mapWidth) + (mapY * ((mapHeight * mapWidth) / 2))].asInt();
		}
	}
}

int OverWorldMap::getTileSize()
{
	return tileSize;
}
