#include "ECS.h"

void Entity::AddGroup(Group group)
{
	m_groupBitSet[group] = true;
	m_manager.AddToGroup(this, group);
}