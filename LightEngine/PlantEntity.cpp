#include "PlantEntity.h"
#include <iostream>

void PlantEntity::OnCollision(Entity* other)
{
	std::cout << "ZombieEntity::OnCollision" << std::endl;
}

void PlantEntity::Shoot(std::vector<BulletEntity*>& bullets) {
	if (gun.Shoot()) {
		BulletEntity* bullet = GetScene()->CreateEntity<BulletEntity>(5, sf::Color::Cyan);
		bullet->SetPosition(GetPosition().x, GetPosition().y + 25);
		bullets.push_back(bullet);
	}
}