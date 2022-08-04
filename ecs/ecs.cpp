#include "ecs.hpp"

void Entity::add_group(group m_group){
	group_bitset[m_group] = true;
	manager.add_to_group(this,m_group);
}