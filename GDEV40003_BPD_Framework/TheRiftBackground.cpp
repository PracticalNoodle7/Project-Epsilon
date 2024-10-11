#include "TheRiftBackground.h"
#include "Texture2D.h"
#include "Constants.h"

TheRiftBackground::TheRiftBackground(SDL_Renderer* renderer, Vector2D start_position) : BackgroundManager(renderer, start_position)
{
	if (m_texture != nullptr)
	{
		m_grass = m_texture->LoadFromTileMap("images/Overworld_Tile/TX Tileset Grass 2.png");
		m_stone = m_texture->LoadFromTileMap("images/Overworld_Tile/TX Tileset Stone Ground.png");
		m_walls = m_texture->LoadFromTileMap("images/Overworld_Tile/TX Tileset Wall.png");
		m_staire = m_texture->LoadFromTileMap("images/Overworld_Tile/TX Struct.png");
	}

	LoadTileMapFromFile("TextFiles/TheRift/TheRiftBackground.txt", levelMap, rows, columns, BACKGROUND);
	LoadTileMapFromFile("TextFiles/TheRift/TheRiftWalls.txt", levelMap, rows, columns, WALLS);
	LoadTileMapFromFile("TextFiles/TheRift/TheRiftStairs.txt", levelMap, rows, columns, STAIRS);
	LoadTileMapFromFile("TextFiles/TheRift/TheRiftProps.txt", levelMap, rows, columns, PROPS);
}

TheRiftBackground::~TheRiftBackground()
{
	delete m_grass;
	m_grass = nullptr;
}

void TheRiftBackground::Render()
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
				srcRect.x = 0, srcRect.y = 0;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 2:
				srcRect.x = 32, srcRect.y = 32;
				m_texture->Render(m_stone, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
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

			m_position.x = m_staire_map[row][column].x;
			m_position.y = m_staire_map[row][column].y;

			switch (m_staire_map[row][column].type)
			{
			case 0:
				break;
			case 1:
				srcRect.x = 32, srcRect.y = 32;
				m_texture->Render(m_staire, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 2:
				srcRect.x = 64, srcRect.y = 32;
				m_texture->Render(m_staire, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 3:
				srcRect.x = 32, srcRect.y = 64;
				m_texture->Render(m_staire, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 4:
				srcRect.x = 64, srcRect.y = 64;
				m_texture->Render(m_staire, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 5:
				srcRect.x = 32, srcRect.y = 96;
				m_texture->Render(m_staire, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			case 6:
				srcRect.x = 64, srcRect.y = 96;
				m_texture->Render(m_staire, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			}
		}
	}
}
