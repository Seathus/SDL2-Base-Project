#pragma once
#include <SDL_render.h>

#include "../Core/Vector2D.h"
#include "../Core/GameClient.h"
#include "../Core/Debug/DebugManager.h"

class Ray : public IDebuggable
{
public:

    Vector2D m_position;
    Vector2D m_direction;
    
    Ray(const Vector2D& position, const Vector2D& direction)
    {
        m_position = position;
        m_direction = direction;

        DebugManager::Register(this);
    }

    static void DrawDebug()
    {
                
    }

    void RenderDebug() const override
    {
        SDL_SetRenderDrawColor(GameClient::Renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(GameClient::Renderer, m_position.x,m_position.y,m_direction.x,m_direction.y);
    }
};
