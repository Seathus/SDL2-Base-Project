#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID GetComponentTypeID()
{
	static ComponentID lastID = 0;
	return lastID++;
}

template <typename T> inline ComponentID GetComponentTypeID() noexcept
{
	static ComponentID typeID = GetComponentTypeID();
	return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component 
{
public:
	Entity* m_entity;

	virtual void Init(){}
	virtual void Update(){}
	virtual void Draw(){}

	virtual ~Component(){}
};

class Entity
{
private:
	bool m_active = true;
	std::vector<std::unique_ptr<Component>> m_components;
	ComponentArray m_componentArray;
	ComponentBitSet m_componentBitSet;

public:
	void Update() 
	{
		for (auto& component : m_components)
		{
			component->Update();
		}
	}

	void Draw()	
	{
		for (auto& component : m_components)
		{
			component->Draw();
		}
	}

	bool IsActive() const { return m_active; }
	void Destroy() { m_active = false; }

	template <typename T> bool HasComponent() const 
	{
		return m_componentBitSet[GetComponentTypeID<T>()];
	}

	template <typename T, typename... TArgs>
	T& AddComponent(TArgs&&... mArgs)
	{
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->m_entity = this;
		std::unique_ptr<Component> uPtr{ c };
		m_components.emplace_back(std::move(uPtr));

		m_componentArray[GetComponentTypeID<T>()] = c;
		m_componentBitSet[GetComponentTypeID<T>()] = true;

		c->Init();
		return *c;
	}

	template <typename T> T& GetComponent() const
	{
		auto ptr(m_componentArray[GetComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
	
};

class Manager
{
private:
	std::vector<std::unique_ptr<Entity>> m_entities;

public:
	void Update()
	{
		for (auto& entity : m_entities)
		{
			entity->Update();
		}
	}

	void Draw()
	{
		for (auto& entity : m_entities)
		{
			entity->Draw();
		}
	}

	void Refresh()
	{
		m_entities.erase(std::remove_if(std::begin(m_entities), std::end(m_entities),
			[](const std::unique_ptr<Entity>& mEntity)
			{
				return !mEntity->IsActive();
			}),
			std::end(m_entities));
	}

	Entity& AddEntity()
	{
		Entity* e = new Entity();
		std::unique_ptr<Entity> uPtr{ e };
		m_entities.emplace_back(std::move(uPtr));
		return *e;
	}
};