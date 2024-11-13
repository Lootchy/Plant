#pragma once
#include "Entity.h"
#include <vector>

class BulletEntity : public Entity
{
public:
	BulletEntity(float radius, const sf::Color& color)
		: Entity(radius, color)
	{
	}

	void OnCollision(Entity* other) override;
	void DestroyBullet(std::vector<BulletEntity*>& bEntity);
};




