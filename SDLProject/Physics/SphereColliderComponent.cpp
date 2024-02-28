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

bool SphereColliderComponent::CheckCollision(const Ray& ray, HitInfo& outHitInfo)
{
    const Vector2D vectorBetweenRayOriginAndSphere = transform->Position - ray.m_position;    
    const float t = Vector2D::Dot(vectorBetweenRayOriginAndSphere, ray.m_direction);
    const Vector2D tPosition = ray.m_position + (ray.m_direction * t);

    const float rSquared = GetRadius() * GetRadius();
    const float y = (transform->Position - tPosition).Magnitude();
    const float ySquared = y * y;
    const float x = sqrt(rSquared - ySquared);
    const float t1 = t - x;
    const float t2 = t + x;

    if (t > t1 && t < t2)
    {
        Vector2D resultEnterIntersectLocation = ray.m_position + (ray.m_direction * t1);
        Vector2D resultExitIntersectLocation = ray.m_position + (ray.m_direction * t2);
		
        outHitInfo.Point = Vector2D(resultEnterIntersectLocation);
        return true;
    }

    return false;
    
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
