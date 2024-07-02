#pragma once
#include "GameScreen.h"
#include "Commons.h"

//foward declarations
class Character;
class Background;

class GameScreenLevel1 : GameScreen
{
public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

	Character* GetCharacter() override;

private:
	bool SetUpLevel1();
	Character* m_character;
	Background* m_background;
};

