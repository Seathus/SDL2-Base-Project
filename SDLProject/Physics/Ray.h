#pragma once
#include <SDL_render.h>

#include "../Core/Vector2D.h"
#include "../Core/GameClient.h"
#include "../Core/Debugg/Debug.h"

class Ray
{
public:

    Vector2D m_position;
    Vector2D m_direction;
    
    Ray(Vector2D position, Vector2D endPosition)
    {
        m_position = position;
        m_direction = (endPosition - position).Normalized();
    }
};
