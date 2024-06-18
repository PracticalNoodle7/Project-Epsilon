#pragma once
#include "GameScreen.h"
#include "Commons.h"

//foward declarations
class Texture2D;
class Character;
class Ground;
class GameObject;

class GameScreenLevel1 : GameScreen
{
public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

	Character* GetCharacter() override;

private:

	Texture2D* m_background_texture;
	bool SetUpLevel1();
	Character* m_character;
	Ground* m_ground;
	GameObject* m_gameObject;
};

