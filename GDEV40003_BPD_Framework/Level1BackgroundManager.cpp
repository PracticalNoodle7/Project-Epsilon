#include "Level1BackgroundManager.h"
#include "Texture2D.h"
#include "Constants.h"

int Level1[30][35] = {
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6}

};

Level1BackgroundManager::Level1BackgroundManager(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position)
{
	//Initialising Movment variable
	m_is_moving = true;
	m_move_up = false;
	m_move_left = false;
	m_move_down = false;
	m_move_right = false;
	m_acceleration = 5;

	if (m_texture != nullptr)
	{
		m_grass = m_texture->LoadFromFileBackground("images/Overworld_Tile/Grass_TileMap.png");
	}

	LoadTileMap(Level1);
}

Level1BackgroundManager::~Level1BackgroundManager()
{
	delete m_grass;
	m_grass = nullptr;
}

void Level1BackgroundManager::LoadTileMap(int arr[30][35])
{
	for (int row = 0; row < 30; row++)
	{
		for (int column = 0; column < 35; column++)
		{
			m_tile_map[row][column].type = arr[row][column];
			m_tile_map[row][column].x = (column + 5) * 31;
			m_tile_map[row][column].y = (row + 5) * 31;
		}
	}
}

void Level1BackgroundManager::Render()
{
	for (int row = 0; row < 30; row++)
	{
		for (int column = 0; column < 35; column++)
		{
			m_tile_map[row][column].type;
			m_position.x = m_tile_map[row][column].x;
			m_position.y = m_tile_map[row][column].y;


			switch (m_tile_map[row][column].type)
			{
			case 0:
				srcRect.x = 32, srcRect.y = 32;
				m_texture->RenderBackground(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 1:
				srcRect.x = 32, srcRect.y = 0;
				m_texture->RenderBackground(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 2:
				srcRect.x = 0, srcRect.y = 0;
				m_texture->RenderBackground(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 3:
				srcRect.x = 0, srcRect.y = 32;
				m_texture->RenderBackground(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 4:
				srcRect.x = 0, srcRect.y = 64;
				m_texture->RenderBackground(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 5:
				srcRect.x = 32, srcRect.y = 64;
				m_texture->RenderBackground(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 6:
				srcRect.x = 64, srcRect.y = 64;
				m_texture->RenderBackground(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 7:
				srcRect.x = 64, srcRect.y = 32;
				m_texture->RenderBackground(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 8:
				srcRect.x = 64, srcRect.y = 0;
				m_texture->RenderBackground(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			}
		}
	}
}

void Level1BackgroundManager::Update(float deltaTime, SDL_Event e)
{
	if (m_is_moving)
	{
		if (m_move_up)
		{
			MoveUp(deltaTime);
		}
		else if (m_move_left)
		{
			MoveLeft(deltaTime);
		}
		else if (m_move_down)
		{
			MoveDown(deltaTime);
		}
		else if (m_move_right)
		{
			MoveRight(deltaTime);
		}

		//handle the events
		switch (e.type)
		{
		case SDL_KEYDOWN:

			switch (e.key.keysym.sym)
			{
				//Press W to move up
			case SDLK_w:
				m_move_up = true;
				break;

				//Press A to move left
			case SDLK_a:
				m_move_left = true;
				break;

				//Press S to move down
			case SDLK_s:
				m_move_down = true;
				break;

				//Press D to move right
			case SDLK_d:
				m_move_right = true;
				break;
			}
			break;
		case SDL_KEYUP:
			switch (e.key.keysym.sym)
			{
				//Check if w is up
			case SDLK_w:
				m_move_up = false;
				break;

				//Check if a is up
			case SDLK_a:
				m_move_left = false;
				break;

				//Check if s is up
			case SDLK_s:
				m_move_down = false;
				break;

				//Check if d is up
			case SDLK_d:
				m_move_right = false;
				break;
			}
		}
	}
}

void Level1BackgroundManager::MoveUp(float deltaTime)
{
	if (m_move_up)
	{
		for (int row = 0; row < 30; row++)
		{
			for (int column = 0; column < 35; column++)
			{
				m_tile_map[row][column].y += deltaTime * 200;
			}
		}
	}
}

void Level1BackgroundManager::MoveLeft(float deltaTime)
{
	if (m_move_left)
	{
		for (int row = 0; row < 30; row++)
		{
			for (int column = 0; column < 35; column++)
		    {
				m_tile_map[row][column].x += deltaTime * 200;
			}
		}
	}
}

void Level1BackgroundManager::MoveDown(float deltaTime)
{
	if (m_move_down)
	{
		for (int row = 0; row < 30; row++)
		{
			for (int column = 0; column < 35; column++)
			{
				m_tile_map[row][column].y -= deltaTime * 200;
			}
		}
	}
}

void Level1BackgroundManager::MoveRight(float deltaTime)
{
	if (m_move_right)
	{
		for (int row = 0; row < 30; row++)
		{
			for (int column = 0; column < 35; column++)
			{
				m_tile_map[row][column].x -= deltaTime * 200;
			}
		}
	}
}