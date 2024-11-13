#pragma once
#include "Entity.h"

class PlantEntity : public Entity
{
public:
	PlantEntity(float radius, const sf::Color& color)
		: Entity(radius, color)
	{
	}

	void OnCollision(Entity* other) override;
	void Shoot();
};




