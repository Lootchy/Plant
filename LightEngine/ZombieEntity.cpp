#include "ZombieEntity.h"
#include "PlantEntity.h"
#include "BulletEntity.h"

#include <iostream>

void ZombieEntity::OnCollision(Entity* other)
{
	if (dynamic_cast<PlantEntity*>(other) != nullptr) {
		//rien
	}
	else if(dynamic_cast<BulletEntity*>(other) != nullptr){
		Destroy();
	}
	else{ //rien 
	}
}

void ZombieEntity::ZombieUpdate() {
	GoToDirection(-1000, 0, 75);
}

void ZombieEntity::DestroyZombie() {

}