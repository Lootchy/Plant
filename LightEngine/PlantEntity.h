#pragma once
#include "Entity.h"
#include "gun.h"
#include <vector>
#include "BulletEntity.h"

class PlantEntity : public Entity
{
public:
	PlantEntity(float radius, const sf::Color& color)
		: Entity(radius, color), gun(2, 5.0f, 1.0f)
	{

	}
	void OnCollision(Entity* other) override;
	void Shoot(std::vector<BulletEntity*>& bullets);
	void PlantReload();
	Gun* GetGun() { return &gun; }

	void OnUpdate() override;

private:
	Gun gun;
};




