#pragma once
#include "HitInfo.h"
#include "Ray.h"
#include "SDL.h"

#include "SphereColliderComponent.h"
#include "BoxColliderComponent.h"

class ColliderComponent;

class Collision
{
private:

	
	
	static HitInfo RayToSphere(Ray& ray, const SphereColliderComponent* sphereCollider);
	static HitInfo RayToBox(const Ray& ray, const BoxColliderComponent* boxCollider);
public:
	static bool AABB(ColliderComponent& colliderA, ColliderComponent& colliderB);
	static bool IsRaycast(const Ray& ray);
	static HitInfo Raycast(Ray& ray);
};