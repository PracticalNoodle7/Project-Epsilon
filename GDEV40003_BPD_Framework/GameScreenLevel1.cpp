#include "GameScreenLevel1.h"
#include "Texture2D.h"
#include "Collisions.h"
#include "Character.h"
#include "Level1BackgroundManager.h"
#include "InventoryManager.h"
#include "Goblin.h"
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
	m_goblin = nullptr;
}

void GameScreenLevel1::Render()
{
	m_background->Render();
	m_character->Render();
	m_goblin->Render();

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
	m_goblin->Update(deltaTime, e);

	//Update inventory
	InventoryManager::Instance(m_renderer)->Update(deltaTime, e);

	UpdateCollions();
}

void GameScreenLevel1::UpdateCollions()
{
	//Checking if an enemy is close to a player
	if (Collisions::Instance()->Circle(m_character, m_goblin, CHASE))
	{
		m_goblin->m_player_found = true;
	}
	else
	{
		m_goblin->m_player_found = false;
	}

	if (Collisions::Instance()->Circle(m_character, m_goblin, ATTACK))
	{
		m_goblin->m_attacking = true;
	}
	else
	{
		m_goblin->m_attacking = false;
	}
}

bool GameScreenLevel1::SetUpLevel1()
{
	//set up player character and background
	m_background = new Level1BackgroundManager(m_renderer, Vector2D());
	m_character = new Character(m_renderer, Vector2D(640, 360));
	m_goblin = new Goblin(m_renderer, Vector2D(300, 360));


	//set pointers
	m_goblin->SetCharacter(m_character);

	return true;
}

Character* GameScreenLevel1::GetCharacter()
{
	return m_character;
}