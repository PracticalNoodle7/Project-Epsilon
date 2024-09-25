#include "Level1BackgroundManager.h"
#include "Texture2D.h"
#include "Constants.h"

Level1BackgroundManager::Level1BackgroundManager(SDL_Renderer* renderer, Vector2D start_position) : BackgroundManager(renderer, start_position)
{
	if (m_texture != nullptr)
	{
		m_grass = m_texture->LoadFromTileMap("images/Overworld_Tile/Grass_TileMap.png");
	}

    LoadTileMapFromFile("TextFiles/Level1.txt", levelMap, rows, columns, BACKGROUND);
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
				srcRect.x = 32, srcRect.y = 32;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 1:
				srcRect.x = 32, srcRect.y = 0;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 2:
				srcRect.x = 0, srcRect.y = 0;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 3:
				srcRect.x = 0, srcRect.y = 32;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 4:
				srcRect.x = 0, srcRect.y = 64;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 5:
				srcRect.x = 32, srcRect.y = 64;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 6:
				srcRect.x = 64, srcRect.y = 64;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 7:
				srcRect.x = 64, srcRect.y = 32;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 8:
				srcRect.x = 64, srcRect.y = 0;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			}
		}
	}
}
