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
	if (m_texture != nullptr)
	{
		m_grass = m_texture->LoadFromTileMap("images/Overworld_Tile/Grass_TileMap.png");
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
			m_position.x = m_tile_map[row][column].x;
			m_position.y = m_tile_map[row][column].y;


			switch (m_tile_map[row][column].type)
			{
			case 0:
				srcRect.x = 32, srcRect.y = 32;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 1:
				srcRect.x = 32, srcRect.y = 0;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 2:
				srcRect.x = 0, srcRect.y = 0;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 3:
				srcRect.x = 0, srcRect.y = 32;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 4:
				srcRect.x = 0, srcRect.y = 64;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 5:
				srcRect.x = 32, srcRect.y = 64;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 6:
				srcRect.x = 64, srcRect.y = 64;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 7:
				srcRect.x = 64, srcRect.y = 32;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 8:
				srcRect.x = 64, srcRect.y = 0;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			}
		}
	}
}

void Level1BackgroundManager::Update(float deltaTime, SDL_Event e)
{
	if (m_can_move)
	{
		if (m_move_up)
		{
			m_is_moving = true;
			MoveUp(deltaTime);
		}
		else if (m_move_left)
		{
			m_is_moving = true;
			MoveLeft(deltaTime);
		}
		else if (m_move_down)
		{
			m_is_moving = true;
			MoveDown(deltaTime);
		}
		else if (m_move_right)
		{
			m_is_moving = true;
			MoveRight(deltaTime);
		}
		else
		{
			m_is_moving = false;
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
		ChangeFacingDirection(FACING::FACING_UP);
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
		ChangeFacingDirection(FACING::FACING_LEFT);
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
		ChangeFacingDirection(FACING::FACING_DOWN);
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
		ChangeFacingDirection(FACING::FACING_RIGHT);
		for (int row = 0; row < 30; row++)
		{
			for (int column = 0; column < 35; column++)
			{
				m_tile_map[row][column].x -= deltaTime * 200;
			}
		}
	}
}