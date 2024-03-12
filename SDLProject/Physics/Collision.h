#pragma once
#include "HitInfo.h"
#include "Ray.h"
#include "SDL.h"

#include "CircleColliderComponent.h"
#include "BoxColliderComponent.h"

class ColliderComponent;

class Collision
{
public:
	static bool Raycast(const Vector2D& position, const Vector2D& direction, HitInfo& outHitInfo);
};