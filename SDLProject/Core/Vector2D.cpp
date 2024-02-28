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

const Vector2D Vector2D::Add(const Vector2D& vector2D) 
{
	auto valX = this->x += vector2D.x;
	auto valY = this->y += vector2D.y;
	auto result = Vector2D(valX, valY);
	return result;
}
const Vector2D Vector2D::Subtract(const Vector2D& vector2D)
{
	auto valX = this->x -= vector2D.x;
	auto valY = this->y -= vector2D.y;
	auto result = Vector2D(valX, valY);
	return result;
}
const Vector2D Vector2D::Multiply(const Vector2D& vector2D)
{
	auto valX = this->x * vector2D.x;
	auto valY = this->y * vector2D.y;
	auto result = Vector2D(valX, valY);
	return result;
}

const Vector2D Vector2D::Multiply(const float& fl)
{
	auto valX = this->x *= fl;
	auto valY = this->y *= fl;
	auto result = Vector2D(valX, valY);
	return result;
}

const Vector2D Vector2D::Divide(const Vector2D& vector2D)
{
	auto valX = this->x /= vector2D.x;
	auto valY = this->y /= vector2D.y;
	auto result = Vector2D(valX, valY);
	return result;
}

Vector2D operator+(const Vector2D& v1, const Vector2D& v2)
{
	return Vector2D(v1).Add(v2);
}

Vector2D operator+(const Vector2D& v1, Vector2D& v2)
{
	return Vector2D(v1).Add(v2);
}

Vector2D operator-(const Vector2D& v1, const Vector2D& v2)
{
	return Vector2D(v1).Subtract(v2);
}

Vector2D operator*(const Vector2D& v1, const Vector2D& v2)
{
	return Vector2D(v1).Multiply(v2);
}

Vector2D operator*(const Vector2D& v1, const float& f)
{
	return Vector2D(v1).Multiply(f);
}

Vector2D operator/(const Vector2D& v1, const Vector2D& v2)
{
	return Vector2D(v1).Divide(v2);
}

Vector2D Vector2D::operator+=(const Vector2D& vector2D)
{
	return Vector2D(this->Add(vector2D));
}

Vector2D Vector2D::operator-=(const Vector2D& vector2D)
{
	return Vector2D(this->Subtract(vector2D));
}

Vector2D Vector2D::operator*=(const Vector2D& vector2D)
{
	return Vector2D(this->Multiply(vector2D));
}

Vector2D Vector2D::operator/=(const Vector2D& vector2D)
{
	return Vector2D(this->Divide(vector2D));
}

Vector2D& Vector2D::operator*(const int& i)
{
	this->x *= i;
	this->y *= i;

	return *this;
}

Vector2D Vector2D::operator*(float x) const
{
	return {this->x * x, this->y * x};
}


Vector2D Vector2D::Zero()
{
	return {0,0};
}

Vector2D Vector2D::Normalized()
{
	auto mag = Magnitude();
	return {this->x / mag, this->y / mag};
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
