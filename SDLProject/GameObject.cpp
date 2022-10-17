#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y)
{
	m_objectTexture = TextureManager::LoadTexture(textureSheet);
	m_xPosition = x;
	m_yPosition = y;
}

GameObject::~GameObject()
{

}

void GameObject::Update()
{
	m_xPosition++;
	m_yPosition++;

	m_sourceRectangle.h = 32;
	m_sourceRectangle.w = 32;
	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;

	m_destinationRectangle.x = m_xPosition;
	m_destinationRectangle.y = m_yPosition;
	m_destinationRectangle.h = m_sourceRectangle.h * 2;
	m_destinationRectangle.w = m_sourceRectangle.w * 2;	
}

void GameObject::Render()
{
	SDL_RenderCopy(GameClient::Renderer, m_objectTexture, NULL, &m_destinationRectangle);
}
