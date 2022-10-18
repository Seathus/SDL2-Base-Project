#pragma once
#include <string>

class Map
{
public:

	Map();
	~Map();

	static void LoadMap(std::string path, int sizeX, int sizeY);

private:

	int map[20][25];
};

