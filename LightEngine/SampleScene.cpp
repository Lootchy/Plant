#include "SampleScene.h"

#include "DummyEntity.h"

#include "ZombieEntity.h"

#include "BulletEntity.h"

#include "PlantEntity.h"

#include "Debug.h"

void SampleScene::Initialize()
{
	for (int i = 0; i < 3; i++) {
		PlantEntity* plant = CreateEntity<PlantEntity>(50, sf::Color::Green);
		plant->SetPosition(200, 200 + i * 100);
		plants.push_back(plant);
	}

	pEntity3 = CreateEntity<ZombieEntity>(50, sf::Color::Cyan);
	pEntity3->SetPosition(100, 500);

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
		BulletEntity* bullet = CreateEntity<BulletEntity>(5, sf::Color::Cyan);
		bullet->SetPosition(200, 200);
		bullets.push_back(bullet);
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
		sf::Vector2f position = pEntitySelected->GetPosition(0.5f, 0.5f);
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
	}

	
	for (auto* bullet : bullets)
	{
		bullet->GoToDirection(1000, 100, 100);
		
	}
}