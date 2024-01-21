#pragma once
#include "ICollider.h"

class Box : public ICollider
{
public:
    int x, y;
    int w, h;
};
