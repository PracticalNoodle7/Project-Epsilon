#include "Level1BackgroundManager.h"

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

Level1BackgroundManager::Level1BackgroundManager(SDL_Renderer* renderer) : TileMap(renderer)
{
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
			m_tile_map[row][column].x = column * 32;
			m_tile_map[row][column].y = row * 32;
			
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

