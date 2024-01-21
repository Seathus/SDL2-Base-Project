#pragma once
#include "GameClient.h"

class GameObject
{

public:
	GameObject(const char* textureSheet, int x, int y);
	~GameObject();

	void Update();
	void Render();

private:
	int m_xPosition;
	int m_yPosition;

	SDL_Texture* m_objectTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;
};

