#include "Bat.h"

Bat::Bat(SDL_Renderer* renderer, Vector2D start_position) : BasicEnemy(renderer, start_position)
{
	//load texture
	if (m_texture != nullptr)
	{
		m_enemy = m_texture->LoadFromTileMap("images/Enemy/Bat.png");
	}
}

Bat::~Bat()
{
	delete m_enemy;
	m_enemy = nullptr;
}

