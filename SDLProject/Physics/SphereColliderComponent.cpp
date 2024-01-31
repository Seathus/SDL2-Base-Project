#include "SphereColliderComponent.h"

void SphereColliderComponent::Init()
{
    ColliderComponent::Init();

    this->m_sphere->x = static_cast<int>(transform->Position.x);
    this->m_sphere->y = static_cast<int>(transform->Position.y);
}

void SphereColliderComponent::Update()
{
    
}

void SphereColliderComponent::RenderDebug() const
{
    SDL_SetRenderDrawColor(GameClient::Renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    
    int32_t x = (this->m_sphere->Radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - this->m_sphere->Diameter);

    while (x >= y)
    {
        // Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(GameClient::Renderer, this->m_sphere->x + x, this->m_sphere->y - y);
        SDL_RenderDrawPoint(GameClient::Renderer, this->m_sphere->x + x, this->m_sphere->y + y);
        SDL_RenderDrawPoint(GameClient::Renderer, this->m_sphere->x - x, this->m_sphere->y - y);
        SDL_RenderDrawPoint(GameClient::Renderer, this->m_sphere->x - x, this->m_sphere->y + y);
        SDL_RenderDrawPoint(GameClient::Renderer, this->m_sphere->x + y, this->m_sphere->y - x);
        SDL_RenderDrawPoint(GameClient::Renderer, this->m_sphere->x + y, this->m_sphere->y + x);
        SDL_RenderDrawPoint(GameClient::Renderer, this->m_sphere->x - y, this->m_sphere->y - x);
        SDL_RenderDrawPoint(GameClient::Renderer, this->m_sphere->x - y, this->m_sphere->y + x);

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
            error += (tx - this->m_sphere->Diameter);
        }

    }
}
