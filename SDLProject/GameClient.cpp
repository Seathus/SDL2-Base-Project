#include "GameClient.h"
#include "TextureManager.h"
#include "Map.h"
#include "Components.h"
#include "Vector2D.h"
#include "Collision.h"

Map* map;

SDL_Renderer* GameClient::Renderer = nullptr;
SDL_Event GameClient::Event;
Manager manager;
auto& player(manager.AddEntity());
auto& wall(manager.AddEntity());

GameClient::GameClient()
{

}

GameClient::~GameClient()
{

}

void GameClient::Init(const char* title, int windowXPos, int windowYPos, int windowWidth, int windowHeight, bool fullScreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialized." << std::endl;

		int flags = 0;
		if (fullScreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}

		m_window = SDL_CreateWindow(title, windowXPos, windowYPos, windowWidth, windowHeight, flags);

		if (m_window)
		{
			std::cout << "Window created." << std::endl;
		}

		Renderer = SDL_CreateRenderer(m_window, -1, 0);
		
		if (Renderer)
		{
			SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
			std::cout << "Renderer created." << std::endl;
		}

		m_isRunning = true;
	}
	else 
	{
		m_isRunning = false;
	}
	
	
	map = new Map();

	player.AddComponent<TransformComponent>();
	player.AddComponent<SpriteComponent>("Assets/player.png");
	player.AddComponent<KeyboardController>();
	player.AddComponent<ColliderComponent>("player");

	wall.AddComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	wall.AddComponent<SpriteComponent>("Assets/dirt.png");
	wall.AddComponent<ColliderComponent>("wall");
}

void GameClient::HandleEvents()
{
	SDL_PollEvent(&Event);

	switch (Event.type)
	{
		case SDL_QUIT:
			m_isRunning = false;
			break;
	}
}

void GameClient::Update()
{
	manager.Refresh();
	manager.Update();

	if (Collision::AABB(player.GetComponent<ColliderComponent>().Collider,
		wall.GetComponent<ColliderComponent>().Collider))
	{
		std::cout << "Wall hit!" << std::endl;
	}
}

void GameClient::Render()
{
	SDL_RenderClear(Renderer);

	map->DrawMap();

	manager.Draw();

	SDL_RenderPresent(Renderer);
}

void GameClient::Clean()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
	std::cout << "Game cleaned." << std::endl;
}
