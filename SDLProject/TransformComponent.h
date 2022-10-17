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
		Position.x = 0.0f;
		Position.y = 0.0f;
	}

	TransformComponent(float x, float y)
	{
		Position.x = x;
		Position.y = y;
	}

	TransformComponent(float x, float y, int h, int w, int scale)
	{
		Position.x = x;
		Position.y = y;
		Width = w;
		Height = h;
		Scale = scale;
	}

	void Init() override
	{
		Velocity.x = 0;
		Velocity.y = 0;
	}

	void Update() override
	{
		Position.x += Velocity.x * Speed;
		Position.y += Velocity.y * Speed;
	}
};
