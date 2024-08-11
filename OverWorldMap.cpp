#include "OverWorldMap.h"
#include "iostream"

OverWorldMap::OverWorldMap()
{
	loadTextures();
	initObjectTileMap();
	initJsonReader();
	loadMapFromJson();
}

void OverWorldMap::render(sf::RenderWindow* window)
{
	for (int i = 0; i < tileMapHeight; i++) {
		for (int j = 0; j < tileMapWidth; j++) {
			if (tileMap[i][j] == 1) {
				objectTileMap[i][j].setTexture(&grassTexture, false);
			}
			else if (tileMap[i][j] == 2) {
				objectTileMap[i][j].setTexture(&sandTexture, false);
			}
			else if (tileMap[i][j] == 3) {
				objectTileMap[i][j].setTexture(&stoneTexture, false);
			}
			else if (tileMap[i][j] == 4) {
				objectTileMap[i][j].setTexture(&waterTexture, false);
			}
			else if (tileMap[i][j] == 5) {
				objectTileMap[i][j].setTexture(&woodTexture, false);
			}
			window->draw(objectTileMap[i][j]);
		}
	}
}

void OverWorldMap::loadTextures() 
{
	if (!stoneTexture.loadFromFile("./Graphics/lightTiles/stoneTile.png"))
	{
		printf("Error Loading stoneTile.png\n");
	}
	if (!grassTexture.loadFromFile("./Graphics/lightTiles/grassTile.png"))
	{
		printf("Error Loading grassTile.png\n");
	}
	if (!sandTexture.loadFromFile("./Graphics/lightTiles/sandTile.png"))
	{
		printf("Error Loading grassTile.png\n");
	}
	if (!waterTexture.loadFromFile("./Graphics/lightTiles/waterTile.png"))
	{
		printf("Error Loading grassTile.png\n");
	}
	if (!woodTexture.loadFromFile("./Graphics/lightTiles/woodTile.png"))
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
	for (int i = 0; i < tileMapHeight; i++) {
		for (int j = 0; j < tileMapWidth; j++) {
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
	for (int i = 0; i < tileMapHeight; i++) {
		for (int j = 0; j < tileMapWidth; j++) {
			tileMap[i][j] = (char)actualJson["layers"][0]["data"][getMapPositionIndex(i,j)].asInt();
		}
	}
	newMapLoaded = true;
}

int OverWorldMap::getMapPositionIndex(int i, int j)
{
	return (j + (mapX * (mapWidth / (mapWidth / tileMapWidth)))) + (i * mapWidth) + (mapY * ((mapHeight * mapWidth) / (mapHeight / tileMapHeight)));
}

int OverWorldMap::getTileSize()
{
	return tileSize;
}

void OverWorldMap::resetMap()
{
	mapX = 0;
	mapY = 0;
	loadMapFromJson();
}
