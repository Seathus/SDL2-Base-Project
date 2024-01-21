#pragma once
#include <SDL_render.h>

#include "../Core/Vector2D.h"
#include "../Core/GameClient.h"

struct Ray
{
public:

    Vector2D m_position;
    Vector2D m_direction;
    
    Ray(const Vector2D& position, const Vector2D& direction)
    {
        this->m_position = position;
        this->m_direction = direction;
    }

    static void DrawDebug()
    {
        SDL_RenderDrawLine(GameClient::Renderer, 50,50,100,10);
    }
};
