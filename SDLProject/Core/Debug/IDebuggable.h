#pragma once


class IDebuggable
{
public:
    virtual ~IDebuggable() = default;

    IDebuggable() = default;

    virtual void RenderDebug() const{}
};
