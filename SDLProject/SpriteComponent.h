#pragma once
#include "Components.h"
#include "SDL.h"
#include "TextureManager.h"


class SpriteComponent : public Component
{
private:
	TransformComponent* m_transform;
	SDL_Texture* m_texture;
	SDL_Rect m_sourceRect;
	SDL_Rect m_destinationRect;

public:

	SpriteComponent() = default;
	SpriteComponent(const char* filePath)
	{
		SetTexture(filePath);
	}

	~SpriteComponent()
	{
		SDL_DestroyTexture(m_texture);
	}

	void SetTexture(const char* path)
	{
		m_texture = TextureManager::LoadTexture(path);
	}

	void Init() override
	{
		m_transform = &m_entity->GetComponent<TransformComponent>();

		m_sourceRect.x = 0;
		m_sourceRect.y = 0;
		m_sourceRect.w = m_transform->Width * m_transform->Scale;
		m_sourceRect.h = m_transform->Height * m_transform->Scale;

		m_destinationRect.x = 0;
		m_destinationRect.y = 0;
		m_destinationRect.w = m_transform->Width * m_transform->Scale;
		m_destinationRect.h = m_transform->Height * m_transform->Scale;
	}

	void Update() override
	{
		m_destinationRect.x = static_cast<int>(m_transform->Position.x);
		m_destinationRect.y = static_cast<int>(m_transform->Position.y);		
	}

	void Draw() override
	{
		TextureManager::Draw(m_texture, m_sourceRect, m_destinationRect);
	}
};