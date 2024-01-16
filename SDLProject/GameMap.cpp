#include "GameMap.h"
#include "GameClient.h"
#include <fstream>

GameMap::GameMap()
{
	
}

GameMap::~GameMap()
{
	
}

void GameMap::LoadMap(std::string path, int sizeX, int sizeY)
{
	char tile;
	std::fstream mapFile;
	mapFile.open(path);

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapFile.get(tile);
			GameClient::AddTile(atoi(&tile), x * 32, y * 32);
			mapFile.ignore(); //ignores next character which is a comma in the file
		}
	}

	mapFile.close();
}