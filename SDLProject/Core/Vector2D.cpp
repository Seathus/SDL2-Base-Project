#include "Vector2D.h"

Vector2D::Vector2D()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2D::Vector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2D::~Vector2D()
{

}

Vector2D& Vector2D::Add(const Vector2D& vector2D) 
{
	this->x += vector2D.x;
	this->y += vector2D.y;

	return *this;
}
Vector2D& Vector2D::Subtract(const Vector2D& vector2D)
{
	this->x -= vector2D.x;
	this->y -= vector2D.y;

	return *this;
}
Vector2D& Vector2D::Multiply(const Vector2D& vector2D)
{
	this->x *= vector2D.x;
	this->y *= vector2D.y;

	return *this;
}

Vector2D& Vector2D::Multiply(const float& fl)
{
	this->x *= fl;
	this->y *= fl;

	return *this;
}

Vector2D& Vector2D::Divide(const Vector2D& vector2D)
{
	this->x /= vector2D.x;
	this->y /= vector2D.y;

	return *this;
}

Vector2D& operator+(Vector2D& v1, const Vector2D& v2)
{
	return v1.Add(v2);
}

Vector2D& operator+(Vector2D& v1, Vector2D& v2)
{
	return v1.Add(v2);
}

Vector2D& operator-(Vector2D& v1, const Vector2D& v2)
{
	return v1.Subtract(v2);
}

Vector2D& operator*(Vector2D& v1, const Vector2D& v2)
{
	return v1.Multiply(v2);
}

Vector2D& operator*(Vector2D& v1, const float& f)
{
	return v1.Multiply(f);
}

Vector2D& operator/(Vector2D& v1, const Vector2D& v2)
{
	return v1.Divide(v2);
}

Vector2D& Vector2D::operator+=(const Vector2D& vector2D)
{
	return this->Add(vector2D);
}

Vector2D& Vector2D::operator-=(const Vector2D& vector2D)
{
	return this->Subtract(vector2D);
}

Vector2D& Vector2D::operator*=(const Vector2D& vector2D)
{
	return this->Multiply(vector2D);
}

Vector2D& Vector2D::operator/=(const Vector2D& vector2D)
{
	return this->Divide(vector2D);
}

Vector2D& Vector2D::operator*(const int& i)
{
	this->x *= i;
	this->y *= i;

	return *this;
}
Vector2D& Vector2D::Zero()
{
	this->x = 0;
	this->y = 0;

	return *this;
}

const float& Vector2D::Magnitude()
{
	return sqrt(this->x * this->x + this->y * this->y);
}

float Vector2D::Dot(const Vector2D& v1, const Vector2D& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& vector2D)
{
	stream << "Vector2D (" << vector2D.x << "," << vector2D.y << ")";
	return stream;
}
