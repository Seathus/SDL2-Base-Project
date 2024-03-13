#pragma once
#include "../Vector2D.h"
#include "../RGBColor.h"

class Debug
{
    
public:

    Debug() = default;

    static void Render();
    static void RenderRay(const Vector2D start, const Vector2D end, const RGBColor color);
    static void RenderCircle(const Vector2D position, const int radius, const RGBColor color);
 
};
