#include "OverWorldMap.h"
#include "iostream"
void OverWorldMap::render(sf::RenderWindow* window)
{

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 29; j++) {
			if (tileMap[i][j] == 1) {
				objectTileMap[i][j].setTexture(&grassTexture, false);
			}
			else if (tileMap[i][j] == 2) {
				objectTileMap[i][j].setTexture(&stoneTexture,false);
			}
			else if (tileMap[i][j] == 'd') {
				objectTileMap[i][j].setTexture(&grassTexture, false);
			}
			window->draw(objectTileMap[i][j]);
		}
	}
}

void OverWorldMap::initOverWorldMap()
{
	loadTextures();
	initMapArray();
	mapPosX = 0;
	mapPosY = 0;
	sf::RectangleShape tile;
	tile.setFillColor(sf::Color(200, 200, 200));
	tile.setSize(sf::Vector2f(tileSize, tileSize));
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 29; j++) {
			tile.setPosition(sf::Vector2f(10 + (j * tileSize), 40 + (i * tileSize)));
			objectTileMap[i][j] = tile;
		}
	}

	std::ifstream file("TileMap/MapTest.json");
	reader.parse(file, actualJson);
	std::cout << "layers: \n" << actualJson["layers"][0]["data"][0] << "\n";
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 29; j++) {
			tileMap[i][j] = (char)actualJson["layers"][0]["data"][j + (i* 58)].asInt();
		}
	}

	

}

void OverWorldMap::loadTextures() {
	if (!stoneTexture.loadFromFile("./Graphics/Tiles/stoneTile.png"))
	{
		printf("Error Loading stoneTile.png\n");
	}

	if (!grassTexture.loadFromFile("./Graphics/Tiles/grassTile.png"))
	{
		printf("Error Loading grassTile.png\n");
	}

	if (!doorTexture.loadFromFile("./Graphics/Tiles/doorTile.png"))
	{
		printf("Error Loading doorTile.png\n");
	}
}

void OverWorldMap::initMapArray()
{
	for (int k = 0; k < 15; k++) {
		for (int l = 0; l < 29; l++) {
			mapArray[0][0][k][l] = map1[k][l];
		}
	}
	for (int k = 0; k < 15; k++) {
		for (int l = 0; l < 29; l++) {
			mapArray[1][0][k][l] = map2[k][l];
		}
	}
	for (int k = 0; k < 15; k++) {
		for (int l = 0; l < 29; l++) {
			mapArray[0][1][k][l] = map3[k][l];
		}
	}
	for (int k = 0; k < 15; k++) {
		for (int l = 0; l < 29; l++) {
			mapArray[1][1][k][l] = map4[k][l];
		}
	}
	for (int k = 0; k < 15; k++) {
		for (int l = 0; l < 29; l++) {
			tileMap[k][l] = mapArray[0][0][k][l];
		}
	}



}

int OverWorldMap::getTileSize()
{
	return tileSize;
}

void OverWorldMap::loadMapLeft()
{
	mapX -= 1;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 29; j++) {
			tileMap[i][j] = (char)actualJson["layers"][0]["data"][(j + (mapX * 29)) + (i * 58) + (mapY * ((30 * 58) / 2))].asInt();
		}
	}

	/*
	if (mapPosX != 0) {
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 29; j++) {
				tileMap[i][j] = mapArray[mapPosX - 1][mapPosY][i][j];
			}
		}
		mapPosX -= 1;
		newMapLoaded = true;
	}*/
}

void OverWorldMap::loadMapRight()
{

	mapX += 1;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 29; j++) {
			tileMap[i][j] = (char)actualJson["layers"][0]["data"][(j + (mapX * 29)) + (i * 58) + (mapY * ((30 * 58) / 2))].asInt();
		}
	}
	/*
	if (mapPosX != 1) {
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 29; j++) {
				tileMap[i][j] = mapArray[mapPosX + 1][mapPosY][i][j];
			}
		}
		mapPosX += 1;
		newMapLoaded = true;
	}*/
}

void OverWorldMap::loadMapUp()
{
	mapY -= 1;

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 29; j++) {
			tileMap[i][j] = (char)actualJson["layers"][0]["data"][(j + (mapX * 29)) + (i * 58) + (mapY * ((30 * 58) / 2))].asInt();
		}
	}
	/*
	if (mapPosY != 0) {
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 29; j++) {
				tileMap[i][j] = mapArray[mapPosX][mapPosY - 1][i][j];
			}
		}
		mapPosY -= 1;
		newMapLoaded = true;
	}*/
}

void OverWorldMap::loadMapDown()
{
	mapY += 1;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 29; j++) {
			tileMap[i][j] = (char)actualJson["layers"][0]["data"][(j + (mapX * 29)) + (i * 58) + (mapY * ((30* 58) / 2)) ].asInt();
		}
	}

	/*
	if (mapPosY != 1) {
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 29; j++) {
				tileMap[i][j] = mapArray[mapPosX][mapPosY + 1][i][j];
			}
		}
		mapPosY += 1;
		newMapLoaded = true;
	}*/
}
