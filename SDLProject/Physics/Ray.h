#pragma once
#include <SDL_render.h>

#include "../Core/Vector2D.h"
#include "../Core/GameClient.h"
#include "../Core/Debug/DebugManager.h"

class Ray : public IDebuggable
{
public:

    Vector2D* m_position = nullptr;
    Vector2D* m_direction = nullptr;
    
    Ray(Vector2D* position, Vector2D* direction)
    {
        m_position = position;
        m_direction = direction;

        DebugManager::Register(this);
    }

    void RenderDebug() const override
    {
        SDL_SetRenderDrawColor(GameClient::Renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(GameClient::Renderer,
            this->m_position->x + 1,
            //50,
            //m_position.y,
            50,
            //m_direction.x * 10.0f,
            30,
            //m_direction.y * 10.0f
            45);
    }
};
