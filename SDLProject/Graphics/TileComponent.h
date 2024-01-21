#pragma once
#include "Components.h"
#include "TransformComponent.h"
#include "SDL.h"

class TileComponent : public Component
{
public:
	TransformComponent* Transform;
	SpriteComponent* Sprite;

	SDL_Rect TileRect;
	int TileID;
	const char* path;

	TileComponent() = default;

	TileComponent(int x, int y, int w, int h, int id)
	{
		TileRect.x = x;
		TileRect.y = y;
		TileRect.w = w;
		TileRect.h = h;
		TileID = id;

		switch (TileID)
		{
			case 0:
				path = "Assets/water.png";
				break;
			case 1:
				path = "Assets/grass.png";
				break;
			case 2:
				path = "Assets/dirt.png";
				break;
		}
	}

	void Init() override
	{
		m_entity->AddComponent<TransformComponent>((float)TileRect.x, (float)TileRect.y, TileRect.w, TileRect.h, 1);
		Transform = &m_entity->GetComponent<TransformComponent>();

		m_entity->AddComponent<SpriteComponent>(path);
		Sprite = &m_entity->GetComponent<SpriteComponent>();
	}
};
