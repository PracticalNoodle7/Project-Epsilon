#include "GameScreenLevel1.h"
#include "Texture2D.h"
#include "Character.h"
#include "Ground.h"
#include "Constants.h"
#include <iostream>
using namespace std;


GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel1();
}


GameScreenLevel1::~GameScreenLevel1()
{
	m_background_texture = nullptr;
	m_character = nullptr;
}

void GameScreenLevel1::Render()
{
	//draw the background
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
	m_character->Render();
	m_ground->Render();
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	//update character
	m_character->Update(deltaTime, e);
	m_ground->Update(deltaTime, e);
}

bool GameScreenLevel1::SetUpLevel1()
{
	//load texture
	m_background_texture = new Texture2D(m_renderer);
	if (!m_background_texture->LoadFromFile("Images/Smile.png"))
	{
		cout << "Failed to load backgound texture!" << endl;
		return false;
	}

	//set up player character
	m_character = new Character(m_renderer, "images/tile_0084.png", Vector2D(640, 360));
	m_ground = new Ground(m_renderer, "images/tile_0084.png", Vector2D(400, 330));

	return true;
}

Character* GameScreenLevel1::GetCharacter()
{
	return m_character;
}