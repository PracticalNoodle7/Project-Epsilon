#pragma once
#include "GameScreen.h"
#include "Commons.h"
#include <vector>

//foward declarations

class MenuManager;

class GameScreenMenu : GameScreen
{
public:
	GameScreenMenu(SDL_Renderer* renderer);
	~GameScreenMenu();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;
	Character* GetCharacter() override;

private:
	bool SetUpMenu();

	MenuManager* m_menu;
};

