#pragma once
#include "Box.h"
#include "ColliderComponent.h"

class BoxColliderComponent : public ColliderComponent
{
private:
    Box* m_box = nullptr;
    
public:

    BoxColliderComponent() : ColliderComponent(""), m_box(nullptr) {}
    BoxColliderComponent(const std::string& t, Box* box) : ColliderComponent(t), m_box(box)
    {

    }
    
    void Update() override;
    HitInfo CheckCollision(const Ray& ray) override;
    ICollider GetCollider();
};
