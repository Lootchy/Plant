#include "PlantEntity.h"

#include <iostream>

void PlantEntity::OnCollision(Entity* other)
{
	std::cout << "ZombieEntity::OnCollision" << std::endl;
}

void PlantEntity::Shoot() {

}