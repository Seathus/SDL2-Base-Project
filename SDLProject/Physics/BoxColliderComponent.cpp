#include "BoxColliderComponent.h"

void BoxColliderComponent::Update()
{
    this->m_box->x = static_cast<int>(transform->Position.x);
    this->m_box->y = static_cast<int>(transform->Position.y);
    this->m_box->w = transform->Width * transform->Scale;
    this->m_box->h = transform->Height * transform->Scale;
}

HitInfo BoxColliderComponent::CheckCollision(const Ray& ray)
{
    /*const auto boxColliderA = dynamic_cast<BoxColliderComponent*>(&colliderA);
    const auto boxColliderB = dynamic_cast<BoxColliderComponent*>(&colliderB);

    if (boxColliderA != nullptr && boxColliderB != nullptr)
    {
        const auto boxA = static_cast<Box*>(&boxColliderA->Collider); 
        const auto boxB = static_cast<Box*>(&boxColliderB->Collider);
		
        if (
        boxA->x + boxA->w >= boxB->x &&
        boxB->x + boxB->w >= boxA->x &&
        boxA->y + boxA->h >= boxB->y &&
        boxB->y + boxB->h >= boxA->y
        )
        {
            std::cout << boxColliderA->m_tag << " hit: " << boxColliderB->m_tag << std::endl;
            return true;
        }
    }*/
    HitInfo temp;
    return temp;
}
