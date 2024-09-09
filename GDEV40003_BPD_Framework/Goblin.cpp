#include "Goblin.h"

Goblin::Goblin(SDL_Renderer* renderer, Vector2D start_position) : BasicEnemy(renderer, start_position)
{
	//load texture
	if (m_texture != nullptr)
	{
		m_enemy = m_texture->LoadFromTileMap("images/Enemy/Goblin.png");
	}

	// Initialize m_drop_items with the paths
	m_drop_items[0] = "images/Tiles/tile_0103.png";
	m_drop_items[1] = "images/Tiles/tile_0102.png";
	m_drop_items[2] = "images/Tiles/tile_0101.png";
}

Goblin::~Goblin()
{

}

