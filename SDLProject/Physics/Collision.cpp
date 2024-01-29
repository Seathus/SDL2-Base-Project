#include "Collision.h"

#include <iostream>

#include "ColliderComponent.h"


HitInfo Collision::RayToSphere(Ray& ray, const SphereColliderComponent* sphereCollider)
{
	auto hitInfo = HitInfo();

	const Vector2D vectorBetweenRayOriginAndSphere = sphereCollider->transform->Position - ray.m_position;
	const float t = Vector2D::Dot(vectorBetweenRayOriginAndSphere, ray.m_direction);
	const Vector2D tPosition = ray.m_position + ray.m_direction * t;

	const float rSquared = sphereCollider->GetRadius() * sphereCollider->GetRadius();
	const float y = (sphereCollider->transform->Position - tPosition).Magnitude();
	const float ySquared = y * y;
	float x = sqrt(rSquared - ySquared);
	float t1 = t - x;
	float t2 = t + x;

	if (t > t1 && t < t2)
	{
		Vector2D resultEnterIntersectLocation = ray.m_position + (ray.m_direction * t1);
		Vector2D resultExitIntersectLocation = ray.m_position + (ray.m_direction * t2);
		
		hitInfo.Point = Vector2D(resultEnterIntersectLocation);
	}

	return hitInfo;
}

HitInfo Collision::RayToBox(const Ray& ray, const BoxColliderComponent* boxCollider)
{
	HitInfo hit;
	return hit;
}

bool Collision::AABB(ColliderComponent& colliderA, ColliderComponent& colliderB)
{
	const auto boxColliderA = dynamic_cast<BoxColliderComponent*>(&colliderA);
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
	}

	return false;
}

bool Collision::IsRaycast(const Ray& ray)
{
	return false;
}

HitInfo Collision::Raycast(Ray* ray)
{
	HitInfo detectedHit;

	for	(const auto& collider : GameClient::Colliders)
	{
		const auto sphereCollider = dynamic_cast<SphereColliderComponent*>(collider);

		if (sphereCollider != nullptr)
		{
			detectedHit = RayToSphere(*ray, sphereCollider);
		}
		else
		{
			const auto boxCollider = dynamic_cast<BoxColliderComponent*>(collider);

			if (boxCollider != nullptr)
			{
				detectedHit = RayToBox(*ray, boxCollider);
			}
		}
	}

	return detectedHit;
}
