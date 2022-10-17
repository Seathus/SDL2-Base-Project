#pragma once

#include "GameClient.h"

class Map
{
public:

	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();

private:

	SDL_Rect m_sourceRect;
	SDL_Rect m_destinationRect;

	SDL_Texture* m_dirt;
	SDL_Texture* m_grass;
	SDL_Texture* m_water;

	int map[20][25];
};

