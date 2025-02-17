#include "Level1BackgroundManager.h"
#include "Texture2D.h"
#include "Constants.h"

Level1BackgroundManager::Level1BackgroundManager(SDL_Renderer* renderer, Vector2D start_position) : BackgroundManager(renderer, start_position)
{
	if (m_texture != nullptr)
	{
		m_grass = m_texture->LoadFromTileMap("images/Overworld_Tile/Grass_TileMap.png");
		m_walls = m_texture->LoadFromTileMap("images/Overworld_Tile/TX Tileset Wall.png");
	}

    LoadTileMapFromFile("TextFiles/Level1Background.txt", levelMap, rows, columns, BACKGROUND);
	LoadTileMapFromFile("TextFiles/Level1Walls.txt", levelMap, rows, columns, WALLS);
}

Level1BackgroundManager::~Level1BackgroundManager()
{
	delete m_grass;
	m_grass = nullptr;
}

void Level1BackgroundManager::Render()
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			m_position.x = m_background_map[row][column].x;
			m_position.y = m_background_map[row][column].y;

			switch (m_background_map[row][column].type)
			{
			case 0:
				break;
			case 1:
				srcRect.x = 32, srcRect.y = 32;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			}

			m_position.x = m_wall_map[row][column].x;
			m_position.y = m_wall_map[row][column].y;

			switch (m_wall_map[row][column].type)
			{
			case 0:
				break;
			case 1:
				srcRect.x = 64, srcRect.y = 96;
				m_texture->Render(m_walls, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 2:
				srcRect.x = 64, srcRect.y = 128;
				m_texture->Render(m_walls, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 3:
				srcRect.x = 32, srcRect.y = 96;
				m_texture->Render(m_walls, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 4:
				srcRect.x = 32, srcRect.y = 128;
				m_texture->Render(m_walls, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 5:
				srcRect.x = 96, srcRect.y = 96;
				m_texture->Render(m_walls, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 6:
				srcRect.x = 96, srcRect.y = 128;
				m_texture->Render(m_walls, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 7:
				srcRect.x = 32, srcRect.y = 64;
				m_texture->Render(m_walls, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 8:
				srcRect.x = 32, srcRect.y = 32;
				m_texture->Render(m_walls, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 9:
				srcRect.x = 64, srcRect.y = 32;
				m_texture->Render(m_walls, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 10:
				srcRect.x = 96, srcRect.y = 32;
				m_texture->Render(m_walls, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 11:
				srcRect.x = 96, srcRect.y = 64;
				m_texture->Render(m_walls, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 12:
				srcRect.x = 256, srcRect.y = 32;
				m_texture->Render(m_walls, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 13:
				srcRect.x = 128, srcRect.y = 32;
				m_texture->Render(m_walls, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 14:
				srcRect.x = 256, srcRect.y = 128;
				m_texture->Render(m_walls, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 15:
				srcRect.x = 128, srcRect.y = 128;
				m_texture->Render(m_walls, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			}
		}
	}
}
