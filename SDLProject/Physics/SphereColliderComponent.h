#pragma once
#include "ColliderComponent.h"
#include "Sphere.h"

class SphereColliderComponent : public ColliderComponent
{
private:
    Sphere* m_sphere = nullptr;
public:

    SphereColliderComponent() : ColliderComponent("") {}
    SphereColliderComponent(const std::string& t, float colliderRadius): ColliderComponent(t)
    {
        m_sphere = new Sphere(0, 0, colliderRadius);
    }

    void Init() override;
    void Update() override;
    float GetRadius() const { return m_sphere->Radius;}
    void DrawDebug() override;
};
