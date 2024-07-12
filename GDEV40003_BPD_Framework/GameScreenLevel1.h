#pragma once
#include "GameScreen.h"
#include "Commons.h"
#include <vector>

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

	//Declaring class pointers
	Character* m_character;

	//Declaring class vectors
	vector<Background*> m_Backgrounds;
};

