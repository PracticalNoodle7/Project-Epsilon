#include "GameScreenMenu.h"
#include "Texture2D.h"
#include "Collisions.h"
#include "MenuManager.h"
#include "Constants.h"
#include <iostream>
using namespace std;

GameScreenMenu::GameScreenMenu(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpMenu();
}

GameScreenMenu::~GameScreenMenu()
{

}

void GameScreenMenu::Render()
{
	m_menu->Render();
}

void GameScreenMenu::Update(float deltaTime, SDL_Event e)
{
	m_menu->Update(deltaTime, e);
}

Character* GameScreenMenu::GetCharacter()
{
	return nullptr;
}

bool GameScreenMenu::SetUpMenu()
{
	m_menu = new MenuManager(m_renderer, Vector2D());

	return true;
}
