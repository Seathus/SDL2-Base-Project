#include "GameClient.h"
#include "../Graphics/TextureManager.h"
#include "../Graphics/GameMap.h"
#include "Components.h"
#include "RGBColor.h"
#include "Vector2D.h"
#include "../Physics/Collision.h"
#include "Debug/Debug.h"

GameMap* Map;

SDL_Renderer* GameClient::Renderer = nullptr;
SDL_Event GameClient::Event;

std::vector<ColliderComponent*> GameClient::Colliders;

Manager manager;
auto& player(manager.AddEntity());
auto& wall(manager.AddEntity());
auto& ball(manager.AddEntity());

Vector2D lineEndLocation;
Vector2D lineStartLocation;

enum GroupLabels : std::size_t 
{
	Group_Map,
	Group_Player,
	Group_Enemies
};

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
			SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
			std::cout << "Renderer created." << std::endl;
		}

		m_isRunning = true;
	}
	else 
	{
		m_isRunning = false;
	}
	
	
	Map = new GameMap();

	GameMap::LoadMap("Assets/Map16x16.map", 16, 16);

	/*player.AddComponent<TransformComponent>();
	player.AddComponent<SpriteComponent>("Assets/player_anims.png", true);
	player.AddComponent<KeyboardController>();
	player.AddComponent<BoxColliderComponent>("player");
	player.AddGroup(Group_Player);

	wall.AddComponent<TransformComponent>(300.0f, 300.0f, 20, 300, 1);
	wall.AddComponent<SpriteComponent>("Assets/dirt.png");
	wall.AddComponent<BoxColliderComponent>("wall");
	wall.AddGroup(Group_Map);*/

	ball.AddComponent<TransformComponent>(80.0f,80.0f);
	ball.AddComponent<CircleColliderComponent>("Sphere-collider", 35.0f);
	ball.AddGroup(Group_Enemies);

	
	
}

void GameClient::HandleEvents()
{
	SDL_PollEvent(&Event);

	switch (Event.type)
	{
		case SDL_QUIT:
			m_isRunning = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			lineEndLocation = Vector2D(Event.button.x, Event.button.y);
			break;
	}
}

bool hitCircle = false;

void GameClient::Update()
{
	manager.Refresh();
	manager.Update();

	HitInfo hitInfo;
	lineStartLocation = Vector2D(0,0);
	
	hitCircle = Collision::Raycast(lineStartLocation, lineEndLocation, hitInfo);
}

auto& tiles(manager.GetGroup(Group_Map));
auto& players(manager.GetGroup(Group_Player));
auto& enemies(manager.GetGroup(Group_Enemies));

void GameClient::Render()
{
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(Renderer);

	for (auto& t : tiles)
	{
		t->Draw();
	}

	for (auto& p : players)
	{
		p->Draw();
	}

	for (auto& e : enemies)
	{
		e->Draw();
	}

	auto debugColor = RGBColor(255, 0, 0);
	
	if (hitCircle)
	{
		debugColor = RGBColor(0, 255, 0);
	}
	
	Debug::RenderRay(Vector2D(0,0), lineEndLocation, debugColor);
	Debug::RenderCircle(Vector2D(350, 350), 35, RGBColor(255, 0, 0));
	
	SDL_SetRenderDrawColor(Renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderPresent(Renderer);
}

void GameClient::Clean()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
	std::cout << "Game cleaned." << std::endl;
}

void GameClient::AddTile(int id, int x, int y)
{
	auto& tile(manager.AddEntity());
	tile.AddComponent<TileComponent>(x, y, 32, 32, id);
	tile.AddGroup(Group_Map);
}
