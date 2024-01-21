#pragma once
#include "ICollider.h"

class Sphere : public ICollider
{
public:
    int x, y;
    float Radius;
    float Diameter;

    Sphere(int x, int y, float radius) : x(x), y(y), Radius(radius)
    {
        Diameter = radius * 2;
    }
};
