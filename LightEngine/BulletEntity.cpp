#include "BulletEntity.h"

#include <iostream>

void BulletEntity::OnCollision(Entity* other)
{
	std::cout << "BulletEntity::OnCollision" << std::endl;
}

