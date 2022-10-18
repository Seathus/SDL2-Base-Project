#pragma once

#include <string>
#include "SDL.h"
#include "Components.h"

class ColliderComponent : public Component
{
public:
	SDL_Rect Collider;
	std::string m_tag;

	TransformComponent* transform;

	ColliderComponent(std::string t)
	{
		this->m_tag = t;
	}

	void Init() override
	{
		if (!m_entity->HasComponent<TransformComponent>())
		{
			m_entity->AddComponent<TransformComponent>();
		}

		transform = &m_entity->GetComponent<TransformComponent>();

		GameClient::Colliders.push_back(this);
	}

	void Update() override
	{
		Collider.x = static_cast<int>(transform->Position.x);
		Collider.y = static_cast<int>(transform->Position.y);

		Collider.w = transform->Width * transform->Scale;
		Collider.h = transform->Height * transform->Scale;
	}
};
