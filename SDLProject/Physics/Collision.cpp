#include "Collision.h"

HitInfo Collision::Raycast(const Vector2D& position, const Vector2D& direction)
{
	const auto ray = new Ray(position, direction);
	
	HitInfo detectedHit;

	for	(const auto& collider : GameClient::Colliders)
	{
		collider->CheckCollision(*ray);
	}

	return detectedHit;
}
