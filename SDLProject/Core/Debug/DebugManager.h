#pragma once
#include <vector>
#include "IDebuggable.h"

class DebugManager
{
    
    
public:
    static std::vector<const IDebuggable*> m_debuggables;

    DebugManager() = default;
    
    static void Register(const IDebuggable* debuggable);

    static void Render();
 
};
