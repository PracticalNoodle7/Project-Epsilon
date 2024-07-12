#include "GameScreenLevel1.h"
#include "Texture2D.h"
#include "Character.h"
#include "Background.h"
#include "Constants.h"
#include <iostream>
using namespace std;


GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel1();
}


GameScreenLevel1::~GameScreenLevel1()
{
	m_character = nullptr;
}

void GameScreenLevel1::Render()
{
	//Render the level
	for (Background* background : m_Backgrounds)
	{
		background->Render();
	}

	m_character->Render();
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	//update the character
	m_character->Update(deltaTime, e);

	for (Background* background : m_Backgrounds)
	{
		background->Update(deltaTime, e);
	}
}

bool GameScreenLevel1::SetUpLevel1()
{
	//set up player character
	m_character = new Character(m_renderer, "images/tile_0084.png", Vector2D(640, 360));

	//Set up L1 Background
	for (int i = 0; i < 201; ++i)
	{

		if (i <= 68)
		{
			Background* Backgrounds = new Background(m_renderer, "images/Tiles/tile_0050.png", Vector2D(), ZERO);
			Backgrounds->SetPosition(Vector2D(50 + i * 16, 250));
			m_Backgrounds.push_back(Backgrounds);
		}
		else if (i <= 137)
		{
			Background* Backgrounds = new Background(m_renderer, "images/Tiles/tile_0050.png", Vector2D(), ONE_EIGHTY);
			Backgrounds->SetPosition(Vector2D(50 + (i - 69) * 16, 650));
			m_Backgrounds.push_back(Backgrounds);
		}
		else if (i <= 138)
		{
			Background* Backgrounds = new Background(m_renderer, "images/Tiles/tile_0052.png", Vector2D(), ZERO);
			Backgrounds->SetPosition(Vector2D(1154, 250));
			m_Backgrounds.push_back(Backgrounds);
		}
		else if (i <= 139)
		{
			Background* Backgrounds = new Background(m_renderer, "images/Tiles/tile_0052.png", Vector2D(), NINETY);
			Backgrounds->SetPosition(Vector2D(1154, 650));
			m_Backgrounds.push_back(Backgrounds);
		}
		else if (i <= 140)
		{
			Background* Backgrounds = new Background(m_renderer, "images/Tiles/tile_0052.png", Vector2D(), ONE_EIGHTY);
			Backgrounds->SetPosition(Vector2D(34, 650));
			m_Backgrounds.push_back(Backgrounds);
		}
		else if (i <= 141)
		{
			Background* Backgrounds = new Background(m_renderer, "images/Tiles/tile_0052.png", Vector2D(), TWO_SEVENTY);
			Backgrounds->SetPosition(Vector2D(34, 250));
			m_Backgrounds.push_back(Backgrounds);
		}
		else if (i <= 200)
		{
			Background* Backgrounds = new Background(m_renderer, "images/Tiles/tile_0050.png", Vector2D(), TWO_SEVENTY);
			Backgrounds->SetPosition(Vector2D(34, 250 + (i - 141)));
			m_Backgrounds.push_back(Backgrounds);
		}
	}

	return true;
}

Character* GameScreenLevel1::GetCharacter()
{
	return m_character;
}