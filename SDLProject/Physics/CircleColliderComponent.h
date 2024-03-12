#pragma once
#include "ColliderComponent.h"
#include "Circle.h"
#include "../Core/Debug/Debug.h"

class CircleColliderComponent : public ColliderComponent
{
private:
    Circle* m_sphere = nullptr;
public:

    CircleColliderComponent() : ColliderComponent("") {}
    CircleColliderComponent(const std::string& t, float colliderRadius): ColliderComponent(t)
    {
        m_sphere = new Circle(0, 0, colliderRadius);
    }

    void Init() override;
    void Update() override;
    float GetRadius() const { return m_sphere->Radius;}
    bool CheckCollision(const Ray& ray, HitInfo& outHitInfo) override;
};
