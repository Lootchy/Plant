#include "ZombieEntity.h"
#include "PlantEntity.h"
#include "BulletEntity.h"

#include <iostream>

void ZombieEntity::OnCollision(Entity* other)
{
	if (dynamic_cast<PlantEntity*>(other) != nullptr) {
		std::cout << "Collision avec une plante détectée !" << std::endl;
	}
	else if(dynamic_cast<BulletEntity*>(other) != nullptr){
		Destroy();
	}
	else{ std::cout << "ZombieEntity::OnCollision" << std::endl; }
}

void ZombieEntity::ZombieUpdate() {
	GoToDirection(-1000, 0, 75);
}

void ZombieEntity::DestroyZombie() {

}