#include "BulletEntity.h"
#include "ZombieEntity.h"

#include <iostream>

void BulletEntity::OnCollision(Entity* other)
{
    if (dynamic_cast<ZombieEntity*>(other) != nullptr) {
        Destroy();
    }
	std::cout << "BulletEntity::OnCollision" << std::endl;
}

void BulletEntity::DestroyBullet(std::vector<BulletEntity*>& bEntity) {
    for (auto it = bEntity.begin(); it != bEntity.end(); ) {
        if ((*it)->GetPosition().x < 0 || (*it)->GetPosition().x > GetScene()->GetWindowWidth()) {
            std::cout << "Bullet Destroyed" << std::endl;
            delete* it;  // Supprime l'objet si nécessaire
            it = bEntity.erase(it);  // Efface du vecteur et avance l'itérateur
        }
        else {
            ++it;
        }
    }
}

