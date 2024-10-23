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
#include "GameText.h"
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

	m_item->Update(deltaTime, e);
	m_item->MoveGameObject(deltaTime, e);

	m_test_arena->Update(deltaTime, e);
	m_test_arena->MoveGameObject(deltaTime, e);

	for (BasicEnemy* enemy : m_test_arena->m_enemies)
	{
		enemy->SetCharacter(m_character);
		enemy->SetItem(m_item);
		enemy->Update(deltaTime, e);
	}

	//Update inventory
	InventoryManager::Instance(m_renderer)->Update(deltaTime, e);

	UpdateCollions(deltaTime, e);
}

void GameScreenLevel1::UpdateCollions(float deltaTime, SDL_Event e)
{
	// Loop over each row
	for (size_t row = 0; row < m_background->m_wall_map.size(); ++row)
	{
		for (size_t column = 0; column < m_background->m_wall_map[row].size(); ++column)
		{
			if (m_background->m_wall_map[row][column].type != 0)
			{
				if (Collisions::Instance()->Box(m_character->GetCollisionBox(), m_background, row, column))
				{
					// Move the background to prevent the player from going out of bounds
					m_background->PreventOutOfBounds(m_character, row, column, deltaTime);
				}
			}
		}
	}

	for (BasicEnemy* enemy : m_test_arena->m_enemies)
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
				if (m_character->m_current_frame == 3)
				{
					enemy->m_health.TakeDamage(m_character->m_stats.m_attack_damage);
				}
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

	if (Collisions::Instance()->Box(m_character->GetCollisionBox(), m_test_arena->GetCollisionBox(16,0)))
	{
		m_test_arena->MoveBack(m_character, m_test_arena, m_background, deltaTime);
		m_item->m_can_move = false;
	}
	else
	{
		m_item->m_can_move = true;
	}

	if (Collisions::Instance()->Circle(m_character, m_test_arena, BASIC))
	{
		m_character->m_interact_text = true;

		// Handle the events
		switch (e.type)
		{
		case SDL_KEYDOWN:

			switch (e.key.keysym.sym)
			{
				// Press F to start arena
			case SDLK_f:
				if (m_test_arena->m_currentWave % 5 == 0)
				{

				}

				m_test_arena->IncreaseWave();
			}
		}
	}
	else
	{
		m_character->m_interact_text = false;
	}
}

bool GameScreenLevel1::SetUpLevel1()
{
	//set up player character and background
	m_background = new Level1BackgroundManager(m_renderer, Vector2D());
	m_character = new Character(m_renderer, Vector2D(640, 360));
	m_test_arena = new TestArena(m_renderer, Vector2D(896,896));
	m_item = new Item(m_renderer, Vector2D());
	m_text = new GameText(m_renderer, "fonts/arial.ttf", 16);

	InventoryManager::Instance(m_renderer)->SetItemPointer(m_item);
	InventoryManager::Instance(m_renderer)->SetCharacterPointer(m_character);

	ItemManager::Instance(m_renderer, Vector2D())->SetUpItems();

	m_test_arena->SetLevel1BackgroundPointer(m_background);
	m_background->SetCharacter(m_character);

	m_item->DropItem("images/Items/tile_0104.png", Vector2D(600, 480), 1);

	return true;
}

Character* GameScreenLevel1::GetCharacter()
{
	return m_character;
}