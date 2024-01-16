#pragma once
#include "GameClient.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component
{
public:
	TransformComponent* transform;
	SpriteComponent* sprite;

	void Init() override
	{
		transform = &m_entity->GetComponent<TransformComponent>();
		sprite = &m_entity->GetComponent<SpriteComponent>();
	}

	void Update() override
	{
		if (GameClient::Event.type == SDL_KEYDOWN)
		{
			switch (GameClient::Event.key.keysym.sym)
			{
				case SDLK_w:
					transform->Velocity.y = -1;
					sprite->Play("Walk");
					break;
				case SDLK_s:
					transform->Velocity.y = +1;
					sprite->Play("Walk");
					break;
				case SDLK_a:
					transform->Velocity.x = -1;
					sprite->Play("Walk");
					break;
				case SDLK_d:
					transform->Velocity.x = +1;
					sprite->Play("Walk");
					break;
			}
		}

		if (GameClient::Event.type == SDL_KEYUP)
		{
			switch (GameClient::Event.key.keysym.sym)
			{
			case SDLK_w:
				transform->Velocity.y = 0;
				sprite->Play("Idle");
				break;
			case SDLK_s:
				transform->Velocity.y = 0;
				sprite->Play("Idle");
				break;
			case SDLK_a:
				transform->Velocity.x = 0;
				sprite->Play("Idle");
				break;
			case SDLK_d:
				transform->Velocity.x = 0;
				sprite->Play("Idle");
				break;
			}
		}
	}
};