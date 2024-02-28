#pragma once

#include <string>

#include "HitInfo.h"
#include "ICollider.h"
#include "Ray.h"
#include "SDL.h"
#include "../Core/Components.h"


class ColliderComponent : public Component
{
public:

	ICollider Collider;
	
	std::string m_tag;	
	TransformComponent* transform = nullptr;
	
	ColliderComponent(const std::string& t)
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

	virtual bool CheckCollision(const Ray& ray, HitInfo& outHitInfo) = 0;
};
