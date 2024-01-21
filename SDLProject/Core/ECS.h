#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;
class Manager;

using ComponentID = std::size_t;
using Group = std::size_t;

inline ComponentID GetNewComponentTypeID()
{
	static ComponentID lastID = 0u;
	return lastID++;
}

template <typename T> inline ComponentID GetComponentTypeID() noexcept
{
	static_assert (std::is_base_of<Component, T>::value, "");
	static ComponentID typeID = GetNewComponentTypeID();
	return typeID;
}

constexpr std::size_t MaxComponents = 32;
constexpr std::size_t MaxGroups = 32;

using ComponentBitSet = std::bitset<MaxComponents>;
using GroupBitSet = std::bitset<MaxGroups>;


using ComponentArray = std::array<Component*, MaxComponents>;

class Component 
{
public:
	Entity* m_entity;

	virtual void Init(){}
	virtual void Update(){}
	virtual void Draw(){}
	virtual void DrawDebug(){}

	virtual ~Component(){}
};

class Entity
{
private:
	Manager& m_manager;
	bool m_active = true;
	std::vector<std::unique_ptr<Component>> m_components;
	ComponentArray m_componentArray;
	ComponentBitSet m_componentBitSet;
	GroupBitSet m_groupBitSet;

public:
	Entity(Manager& manager) : m_manager(manager)
	{
		
	}

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

	void DrawDebug()
	{
		for (auto& component : m_components)
		{
			component->DrawDebug();
		}
	}

	bool IsActive() const { return m_active; }
	void Destroy() { m_active = false; }

	bool HasGroup(Group group)
	{
		return m_groupBitSet[group];
	}

	void AddGroup(Group group);
	
	void RemoveFromGroup(Group group)
	{
		m_groupBitSet[group] = false;
	}

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
	std::array<std::vector<Entity*>, MaxGroups> m_groupedEntities;

public:
	void Update()
	{
		for (const auto& entity : m_entities)
		{
			entity->Update();
		}
	}

	void Draw()
	{
		for (const auto& entity : m_entities)
		{
			entity->Draw();
		}
	}

	void Refresh()
	{
		for (auto i(0u); i < MaxGroups; i++)
		{
			auto& v(m_groupedEntities[i]);
			v.erase(
				std::remove_if(std::begin(v), std::end(v),
					[i](Entity* entity)
					{
						return !entity->IsActive() || !entity->HasGroup(i);
					}),
				std::end(v));
		}

		m_entities.erase(std::remove_if(std::begin(m_entities), std::end(m_entities),
			[](const std::unique_ptr<Entity>& mEntity)
			{
				return !mEntity->IsActive();
			}),
			std::end(m_entities));
	}

	void AddToGroup(Entity* entity, Group group)
	{
		m_groupedEntities[group].emplace_back(entity);
	}

	std::vector<Entity*>& GetGroup(Group group)
	{
		return m_groupedEntities[group];
	}

	Entity& AddEntity()
	{
		Entity* e = new Entity(*this);
		std::unique_ptr<Entity> uPtr{ e };
		m_entities.emplace_back(std::move(uPtr));
		return *e;
	}
};