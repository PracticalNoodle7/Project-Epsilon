#include "GameScreenLevel1.h"
#include "Texture2D.h"
#include "Character.h"
#include "Level1BackgroundManager.h"
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
}

void GameScreenLevel1::Render()
{
	m_background->Render();
	m_character->Render();
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	//update the character
	m_character->Update(deltaTime, e);
}

bool GameScreenLevel1::SetUpLevel1()
{
	//set up player character
	m_character = new Character(m_renderer, "images/tile_0084.png", Vector2D(640, 360));
	m_background = new Level1BackgroundManager(m_renderer);

	return true;
}

Character* GameScreenLevel1::GetCharacter()
{
	return m_character;
}