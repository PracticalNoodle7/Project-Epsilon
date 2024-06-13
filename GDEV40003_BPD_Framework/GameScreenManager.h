#pragma once
#include "SDL.h"
#include "Commons.h"

//foward declerations
class GameScreen;
class Character;

class GameScreenManager
{
public:
	GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen);
	~GameScreenManager();

	void Render();
	void Update(float deltaTime, SDL_Event e);

	void ChangeScreen(SCREENS new_screen);

	Character* GetCharacter();

private:

	SDL_Renderer* m_renderer;
	GameScreen* m_current_screen;
};

