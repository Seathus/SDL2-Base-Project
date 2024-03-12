#pragma once
#include "ICollider.h"

class Circle : public ICollider
{
public:
    int x, y;
    float Radius;
    float Diameter;

    Circle(int x, int y, float radius) : x(x), y(y), Radius(radius)
    {
        Diameter = radius * 2;
    }
};
