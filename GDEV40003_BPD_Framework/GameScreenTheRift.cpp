#include "GameScreenTheRift.h"
#include "Texture2D.h"
#include "Collisions.h"
#include "Character.h"
#include "TheRiftBackground.h"
#include "InventoryManager.h"
#include "Constants.h"
#include <iostream>
using namespace std;


GameScreenTheRift::GameScreenTheRift(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpTheRift();
}


GameScreenTheRift::~GameScreenTheRift()
{
	m_character = nullptr;
	m_background = nullptr;
}

void GameScreenTheRift::Render()
{
	m_background->Render();
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

	//Update inventory
	InventoryManager::Instance(m_renderer)->Update(deltaTime, e);

	UpdateCollions(deltaTime);
}

void GameScreenTheRift::UpdateCollions(float deltaTime)
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
					m_background->PreventOutOfBounds(m_character, row, column, deltaTime);
				}
			}
		}
	}
}

bool GameScreenTheRift::SetUpTheRift()
{
	//set up player character and background
	m_background = new TheRiftBackground(m_renderer, Vector2D());
	m_character = new Character(m_renderer, Vector2D(640, 360));

	m_background->SetCharacter(m_character);

	return true;
}

Character* GameScreenTheRift::GetCharacter()
{
	return m_character;
}
