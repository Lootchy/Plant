#include <iostream>

#include "SampleScene.h"

#include "DummyEntity.h"

#include "ZombieEntity.h"

#include "BulletEntity.h"

#include "PlantEntity.h"

#include "Debug.h"


void SampleScene::Initialize()
{
	srand(time(NULL));
	for (int i = 0; i < 3; i++) {
		PlantEntity* plant = CreateEntity<PlantEntity>(25, sf::Color::Green);
		plant->SetPosition(200, 200 + i * 100);
		plants.push_back(plant);
	}

	for (int i = 0; i < 3; i++) {
		ZombieEntity* zombie = CreateEntity<ZombieEntity>(25, sf::Color::Cyan);
		zombie->SetPosition(1000, 200 + i * 100);
		ZombieVector.push_back(zombie);
	}
	
	pEntitySelected = nullptr;
}

void SampleScene::HandleInput(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		TrySetSelectedEntity(pEntity1, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(pEntity2, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(pEntity3, event.mouseButton.x, event.mouseButton.y);
	}

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (pEntitySelected != nullptr) 
		{
			pEntitySelected->GoToPosition(event.mouseButton.x, event.mouseButton.y, 100.f);
		}
	}
	if (sf::Event::KeyPressed)
	{
		for (PlantEntity* plant : plants) {
			plant->Shoot(bullets);
		}
	}
}

void SampleScene::TrySetSelectedEntity(Entity* pEntity, int x, int y)
{
	if (pEntity->IsInside(x, y) == false)
		return;

	pEntitySelected = pEntity;
}

void SampleScene::Update()
{
	if (pEntitySelected != nullptr)
	{
		sf::Vector2f position = pEntitySelected->GetPosition();
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
	}

	// Mise à jour des bullets
	for (auto* bullet : bullets)
	{
		bullet->GoToDirection(2000, 0, 100);
	}

	for (auto* plant : plants)
	{
		std::cout << plant->GetGun().GetLabel();
		plant->GetGun().Update(0.016);
		
	}

	// Mise à jour des zombies et marquage pour suppression si nécessaire
	for (auto* zombie : ZombieVector)
	{
		zombie->ZombieUpdate();
	}

	// Suppression des zombies marqués pour destruction
	ZombieVector.erase(
		std::remove_if(ZombieVector.begin(), ZombieVector.end(),
			[](ZombieEntity* zombie) { return zombie->ToDestroy(); }),
		ZombieVector.end()
	);

	// Respawn d'un zombie si le vecteur est vide
	if (ZombieVector.size() != 3) {
		std::cout << "Spawning Zombie" << std::endl;
		ZombieEntity* zombie = CreateEntity<ZombieEntity>(25, sf::Color::Cyan);
		zombie->SetPosition(1000, LanePosition[rand() % 3]);
		ZombieVector.push_back(zombie);
	}
}



