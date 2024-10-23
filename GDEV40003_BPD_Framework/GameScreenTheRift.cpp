#include "GameScreenTheRift.h"
#include "Texture2D.h"
#include "Collisions.h"
#include "Character.h"
#include "TheRiftBackground.h"
#include "InventoryManager.h"
#include "Teleporter.h"
#include "Constants.h"
#include <iostream>
#include "GameScreenManager.h"
using namespace std;


GameScreenTheRift::GameScreenTheRift(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpTheRift();
}


GameScreenTheRift::~GameScreenTheRift()
{
	m_character = nullptr;
	m_background = nullptr;
	m_teleporter = nullptr;
}

void GameScreenTheRift::Render()
{
	m_background->Render();
	m_teleporter->Render();
	m_character->Render();

	if (InventoryManager::Instance(m_renderer)->m_is_inventory_open)
	{
		InventoryManager::Instance(m_renderer)->Render();
	}
}

void GameScreenTheRift::Update(float deltaTime, SDL_Event e)
{

	//Update character and background
	m_character->Update(deltaTime, e);
	m_background->Update(deltaTime, e);

	//Update GameObject to move
	m_teleporter->MoveGameObject(deltaTime, e);

	//Update inventory
	InventoryManager::Instance(m_renderer)->Update(deltaTime, e);

	UpdateCollions(deltaTime, e);
}

void GameScreenTheRift::UpdateCollions(float deltaTime, SDL_Event e)
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

					//Move specified objects back to prevent them from out of place
					m_teleporter->MoveBack(m_character, m_background->m_wall_map[row][column].x, m_background->m_wall_map[row][column].y, m_background->m_wall_map[row][column].tile, deltaTime);
				}
			}
		}
	}

	if (Collisions::Instance()->Circle(m_character, m_teleporter, BASIC))
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
				GameScreenManager::s_start_level_1 = true;
			}
		}
	}
	else
	{
		m_character->m_interact_text = false;
	}
}

bool GameScreenTheRift::SetUpTheRift()
{
	//set up player character and background
	m_background = new TheRiftBackground(m_renderer, Vector2D());
	m_character = new Character(m_renderer, Vector2D(640, 360));
	m_teleporter = new Teleporter(m_renderer, Vector2D(1392, 288));

	m_background->SetCharacter(m_character);

	return true;
}

Character* GameScreenTheRift::GetCharacter()
{
	return m_character;
}