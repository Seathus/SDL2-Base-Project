#include "DebugManager.h"

std::vector<const IDebuggable*> DebugManager::m_debuggables;

void DebugManager::Register(const IDebuggable* debuggable)
{
    m_debuggables.push_back(debuggable);
}

void DebugManager::Render()
{
    for (const auto* debuggable : m_debuggables)
    {
        debuggable->RenderDebug();
    }
}


