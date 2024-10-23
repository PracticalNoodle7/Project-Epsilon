#pragma once
#include "GameScreen.h"
#include "Commons.h"
#include <vector>

class TheRiftBackground;
class Character;
class Teleporter;

class GameScreenTheRift : GameScreen
{
public:
	GameScreenTheRift(SDL_Renderer* renderer);
	~GameScreenTheRift();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;
	void UpdateCollions(float deltaTime, SDL_Event e);

	Character* GetCharacter() override;

private:
	bool SetUpTheRift();

	//Declaring class pointers
	Character* m_character;
	TheRiftBackground* m_background;
	Teleporter* m_teleporter;
};

