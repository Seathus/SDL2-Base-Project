#include "BoxColliderComponent.h"

void BoxColliderComponent::Update()
{
    this->m_box->x = static_cast<int>(transform->Position.x);
    this->m_box->y = static_cast<int>(transform->Position.y);
    this->m_box->w = transform->Width * transform->Scale;
    this->m_box->h = transform->Height * transform->Scale;
}
