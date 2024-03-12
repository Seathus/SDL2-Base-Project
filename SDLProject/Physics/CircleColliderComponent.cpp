#include "CircleColliderComponent.h"

void CircleColliderComponent::Init()
{
    ColliderComponent::Init();

    this->m_sphere->x = static_cast<int>(transform->Position.x);
    this->m_sphere->y = static_cast<int>(transform->Position.y);
}

void CircleColliderComponent::Update()
{
    
}

bool CircleColliderComponent::CheckCollision(const Ray& ray, HitInfo& outHitInfo)
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


