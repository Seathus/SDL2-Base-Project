#pragma once
#include <iostream>

class Vector2D
{
public:

	float x;
	float y;

	Vector2D();
	Vector2D(float x, float y);
	~Vector2D();

	const Vector2D Add(const Vector2D& vector2D);
	const Vector2D Subtract(const Vector2D& vector2D);
	const Vector2D Multiply(const Vector2D& vector2D);
	const Vector2D Multiply(const float& f);
	const Vector2D Divide(const Vector2D& vector2D);
	

	friend Vector2D operator+(const Vector2D& v1, const Vector2D& v2);
	friend Vector2D operator-(const Vector2D& v1, const Vector2D& v2);
	friend Vector2D operator*(const Vector2D& v1, const Vector2D& v2);
	friend Vector2D operator/(const Vector2D& v1, const Vector2D& v2);

	const Vector2D& operator+=(const Vector2D& vector2D);
	const Vector2D& operator-=(const Vector2D& vector2D);
	const Vector2D& operator*=(const Vector2D& vector2D);
	const Vector2D& operator/=(const Vector2D& vector2D);	

	Vector2D& operator*(const int& i);
	Vector2D& Zero();
	Vector2D& Normalized();
	const float& Magnitude();
	
	static float Dot(const Vector2D& v1, const Vector2D& v2);

	friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vector2D);
};
