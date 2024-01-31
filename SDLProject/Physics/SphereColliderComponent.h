#pragma once
#include "ColliderComponent.h"
#include "Sphere.h"
#include "../Core/Debug/DebugManager.h"

class SphereColliderComponent : public ColliderComponent, public IDebuggable
{
private:
    Sphere* m_sphere = nullptr;
public:

    SphereColliderComponent() : ColliderComponent("") {}
    SphereColliderComponent(const std::string& t, float colliderRadius): ColliderComponent(t)
    {
        m_sphere = new Sphere(0, 0, colliderRadius);
        DebugManager::Register(this);
    }

    void Init() override;
    void Update() override;
    float GetRadius() const { return m_sphere->Radius;}
    void RenderDebug() const override;
};
