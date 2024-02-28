#include "Collision.h"

bool Collision::Raycast(const Vector2D& position, const Vector2D& endPosition, HitInfo& outHitInfo)
{
	const Ray ray(position, endPosition);
	
	HitInfo detectedHit;

	for	(const auto& collider : GameClient::Colliders)
	{
		if(collider->CheckCollision(ray, outHitInfo))
		{
			return true;
		}
	}

	return false;
}
