#include "GameScreenLevel1.h"
#include "Texture2D.h"
#include "Collisions.h"
#include "Character.h"
#include "Level1BackgroundManager.h"
#include "InventoryManager.h"
#include "ItemManager.h"
#include "Item.h"
#include "BasicEnemy.h"
#include "TestArena.h"
#include "Constants.h"
#include <iostream>
using namespace std;


GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel1();
}


GameScreenLevel1::~GameScreenLevel1()
{
	m_character = nullptr;
	m_background = nullptr;
	m_basic_enemy = nullptr;
}

void GameScreenLevel1::Render()
{
	m_background->Render();
	m_character->Render();
	m_test_arena->Render();
	m_item->Render();

	if (InventoryManager::Instance(m_renderer)->m_is_inventory_open)
	{
		InventoryManager::Instance(m_renderer)->Render();
	}
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{

	//Update character and background
	m_character->Update(deltaTime, e);
	m_background->Update(deltaTime, e);
	m_test_arena->Update(deltaTime, e);
	m_item->Update(deltaTime, e);

	for (Goblin* enemy : m_test_arena->m_goblin)
	{
		enemy->SetCharacter(m_character);
		enemy->SetItem(m_item);
	}

	//Update inventory
	InventoryManager::Instance(m_renderer)->Update(deltaTime, e);

	UpdateCollions();
}

void GameScreenLevel1::UpdateCollions()
{
	for (Goblin* enemy : m_test_arena->m_goblin)
	{
		//Checking if an enemy is close to a player
		if (Collisions::Instance()->Circle(m_character, enemy, CHASE))
		{
			enemy->m_player_found = true;
		}
		else
		{
			enemy->m_player_found = false;
		}

		if (Collisions::Instance()->Circle(m_character, enemy, ATTACK))
		{
			enemy->m_attacking = true;
		}

		if (m_character->m_attacking)
		{
			if (Collisions::Instance()->Box(m_character->GetAttackCollision(), enemy->GetCollisionBox()))
			{
				enemy->TakeDamage(10);
			}
		}
	}

	for (DroppedItems m_drop_item : m_item->m_dropped_items)
	{
		if (Collisions::Instance()->CircleDropItems(m_character, m_drop_item, ATTACK))
		{
			InventoryManager::Instance(m_renderer)->AddToInventory(m_drop_item.imagePath, m_drop_item.quantity);
		}
	}
}

bool GameScreenLevel1::SetUpLevel1()
{
	//set up player character and background
	m_background = new Level1BackgroundManager(m_renderer, Vector2D());
	m_character = new Character(m_renderer, Vector2D(640, 360));
	m_test_arena = new TestArena(m_renderer);
	m_item = new Item(m_renderer, Vector2D());

	InventoryManager::Instance(m_renderer)->SetItemPointer(m_item);

	return true;
}

Character* GameScreenLevel1::GetCharacter()
{
	return m_character;
}