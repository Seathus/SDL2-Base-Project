#pragma once
#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component
{
public:

	Vector2D Position;
	Vector2D Velocity;

	int Height = 32;
	int Width = 32;
	int Scale = 1;
	int Speed = 3;

	TransformComponent()
	{
		Position.Zero();
	}

	TransformComponent(int scale)
	{
		Position.Zero();
		Scale = scale;
	}

	TransformComponent(float x, float y)
	{
		Position.x = x;
		Position.y = y;
	}

	TransformComponent(float x, float y, int width, int height, int scale)
	{
		Position.x = x;
		Position.y = y;
		Width = width;
		Height = height;		
		Scale = scale;
	}

	void Init() override
	{
		Velocity.Zero();
	}

	void Update() override
	{
		Position.x += Velocity.x * Speed;
		Position.y += Velocity.y * Speed;
	}
};
