#include "ZombieEntity.h"

#include <iostream>

void ZombieEntity::OnCollision(Entity* other)
{
	std::cout << "ZombieEntity::OnCollision" << std::endl;
}