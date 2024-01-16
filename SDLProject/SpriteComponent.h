#pragma once
#include "Components.h"
#include "SDL.h"
#include "TextureManager.h"
#include "Animation.h"
#include <map>

class SpriteComponent : public Component
{
private:
	TransformComponent* m_transform;
	SDL_Texture* m_texture;
	SDL_Rect m_sourceRect;
	SDL_Rect m_destinationRect;

	bool m_animated = false;
	int m_frames = 0;
	int m_speed = 100; //delay between frames in milliseconds

public:

	int AnimIndex = 0;

	std::map<const char*, Animation> Animations;

	SpriteComponent() = default;
	SpriteComponent(const char* filePath)
	{
		SetTexture(filePath);
	}

	SpriteComponent(const char* filePath, bool isAnimated)
	{
		m_animated = isAnimated;

		Animation idle = Animation(0, 3, 100);
		Animation walk = Animation(1, 8, 100);

		Animations.emplace("Idle", idle);
		Animations.emplace("Walk", walk);

		Play("Idle");

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
		if (m_animated)
		{
			m_sourceRect.x = m_sourceRect.w * static_cast<int>((SDL_GetTicks() / m_speed) % m_frames);
		}

		m_sourceRect.y = AnimIndex * m_transform->Height;

		m_destinationRect.x = static_cast<int>(m_transform->Position.x);
		m_destinationRect.y = static_cast<int>(m_transform->Position.y);		
	}

	void Draw() override
	{
		TextureManager::Draw(m_texture, m_sourceRect, m_destinationRect);
	}

	void Play(const char* animationName)
	{
		m_frames = Animations[animationName].frames;
		AnimIndex = Animations[animationName].index;
		m_speed = Animations[animationName].speed;
	}
};