#include "Collision.h"

HitInfo Collision::Raycast(const Vector2D& position, const Vector2D& endPosition)
{
	const auto ray = new Ray(position, endPosition);
	
	HitInfo detectedHit;

	for	(const auto& collider : GameClient::Colliders)
	{
		auto hit = collider->CheckCollision(*ray);

		if (hit.Point.Magnitude() > 0.0f)
		{
			detectedHit = hit;
		}
	}

	return detectedHit;
}
