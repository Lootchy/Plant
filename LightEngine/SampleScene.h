#pragma once

#include "Scene.h"
#include <vector>

class DummyEntity;
class ZombieEntity;
class BulletEntity;
class PlantEntity;

class SampleScene : public Scene
{
	DummyEntity* pEntity1;
	DummyEntity* pEntity2;
	ZombieEntity* pEntity3;
	Entity* pEntity;

	Entity* pEntitySelected;
	std::vector<BulletEntity*> bullets;
	std::vector<PlantEntity*> plants;
	std::vector<ZombieEntity*> ZombieVector;

private:
	void TrySetSelectedEntity(Entity* pEntity, int x, int y);

public:
	void Initialize() override;
	void HandleInput(const sf::Event& event) override;
	void Update() override;
};


