#pragma once
#include "HitInfo.h"
#include "Ray.h"
#include "SDL.h"

#include "SphereColliderComponent.h"
#include "BoxColliderComponent.h"

class ColliderComponent;

class Collision
{
public:
	static HitInfo Raycast(const Vector2D& position, const Vector2D& direction);
};