#include "Debug.h"
#include <SDL_render.h>
#include "../Vector2D.h"
#include "../GameClient.h"


void Debug::RenderRay(const Vector2D start, const Vector2D end, const RGBColor color)
{
    SDL_SetRenderDrawColor(GameClient::Renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(GameClient::Renderer,
        start.x,
        start.y,
        end.x,
        end.y);
}

void Debug::RenderCircle(const Vector2D position, const int radius, const RGBColor color)
{
    SDL_SetRenderDrawColor(GameClient::Renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
    
    const int diameter = radius * 2;
    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    while (x >= y)
    {
        // Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(GameClient::Renderer, position.x + x, position.y - y);
        SDL_RenderDrawPoint(GameClient::Renderer, position.x + x, position.y + y);
        SDL_RenderDrawPoint(GameClient::Renderer, position.x - x, position.y - y);
        SDL_RenderDrawPoint(GameClient::Renderer, position.x - x, position.y + y);
        SDL_RenderDrawPoint(GameClient::Renderer, position.x + y, position.y - x);
        SDL_RenderDrawPoint(GameClient::Renderer, position.x + y, position.y + x);
        SDL_RenderDrawPoint(GameClient::Renderer, position.x - y, position.y - x);
        SDL_RenderDrawPoint(GameClient::Renderer, position.x - y, position.y + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}


