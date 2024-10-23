#include "Slime.h"

Slime::Slime(SDL_Renderer* renderer, Vector2D start_position) : BasicEnemy(renderer, start_position)
{
	//load texture
	if (m_texture != nullptr)
	{
		m_enemy = m_texture->LoadFromTileMap("images/Enemy/Slime.png");
	}

	// Initialize m_drop_items with the paths
	m_drop_items[0] = "images/Items/tile_0104.png";
	m_drop_items[1] = "images/Items/tile_0102.png";
	m_drop_items[2] = "images/Items/tile_0123.png";
}

Slime::~Slime()
{
	delete m_enemy;
	m_enemy = nullptr;
}

