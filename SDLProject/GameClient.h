#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>

class ColliderComponent;

using namespace std;

class GameClient
{
public:
	GameClient();
	~GameClient();
	void Init(const char* title, int windowXPos, int windowYPos, int windowWidth, int windowHeight, bool fullScreen);
	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	bool IsRunning() { return m_isRunning; }

	static void AddTile(int id, int x, int y);
	static SDL_Renderer* Renderer;
	static SDL_Event Event;
	static std::vector<ColliderComponent*> Colliders;

private:
	bool m_isRunning;
	int m_updateCounter;
	SDL_Window* m_window;
};

