#include "GameScreenManager.h"
#include "GameScreenLevel1.h"
#include "GameScreenMenu.h"
#include "GameScreen.h"
#include "Character.h"

bool GameScreenManager::s_start_level_1 = false;

GameScreenManager::GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen)
{
	m_renderer = renderer;
	m_current_screen = nullptr;

	
	ChangeScreen(startScreen);
}

GameScreenManager::~GameScreenManager()
{
	m_renderer = nullptr;
	delete m_current_screen;
	m_current_screen = nullptr;
}

void GameScreenManager::Render()
{
	m_current_screen->Render();

	if (s_start_level_1)
	{
		ChangeScreen(SCREEN_LEVEL1);
		s_start_level_1 = false;
	}
}

void GameScreenManager::Update(float deltaTime, SDL_Event e)
{
	m_current_screen->Update(deltaTime, e);

}

void GameScreenManager::ChangeScreen(SCREENS new_screen)
{
	//clear up the old screen
	if (m_current_screen != nullptr)
	{
		delete m_current_screen;
	}

	switch (new_screen)
	{
	case SCREEN_MENU:
		GameScreenMenu* tempScreenMenu;
		tempScreenMenu = new GameScreenMenu(m_renderer);
		m_current_screen = (GameScreen*)tempScreenMenu;
		tempScreenMenu = nullptr;
		break;

	case SCREEN_LEVEL1:
		GameScreenLevel1* tempScreenLevel1;
		tempScreenLevel1 = new GameScreenLevel1(m_renderer);
		m_current_screen = (GameScreen*)tempScreenLevel1;
		tempScreenLevel1 = nullptr;
		break;
	}
}

Character* GameScreenManager::GetCharacter()
{
	if (m_current_screen != nullptr)
	{
		return m_current_screen->GetCharacter();
	}
	
	return nullptr;
}