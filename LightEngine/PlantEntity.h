#pragma once
#include "Entity.h"
#include "gun.h"

class PlantEntity : public Entity
{
public:
	PlantEntity(float radius, const sf::Color& color)
		: Entity(radius, color)
	{
		Gun gun(10, 2.0f, 1.0f);
	}

	void OnCollision(Entity* other) override;
	void Shoot();
};




