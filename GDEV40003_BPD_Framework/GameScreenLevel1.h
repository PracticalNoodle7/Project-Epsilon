#pragma once
#include "GameScreen.h"
#include "Commons.h"
#include <vector>

//foward declarations
class Character;
class Level1BackgroundManager;
class Goblin;

class GameScreenLevel1 : GameScreen
{
public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;
	void UpdateCollions();

	Character* GetCharacter() override;

private:
	bool SetUpLevel1();

	//Declaring class pointers
	Character* m_character;
	Level1BackgroundManager* m_background;
	Goblin* m_goblin;
};

