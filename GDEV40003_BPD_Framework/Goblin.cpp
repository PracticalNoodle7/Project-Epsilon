#include "Goblin.h"

Goblin::Goblin(SDL_Renderer* renderer, Vector2D start_position) : BasicEnemy(renderer, start_position)
{
	//load texture
	if (m_texture != nullptr)
	{
		m_enemy = m_texture->LoadFromTileMap("images/Enemy/Goblin.png");
	}
}

Goblin::~Goblin()
{
	delete m_enemy;
	m_enemy = nullptr;
}

