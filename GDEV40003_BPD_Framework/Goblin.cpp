#include "Goblin.h"

Goblin::Goblin(SDL_Renderer* renderer, Vector2D start_position) : BasicEnemy(renderer, start_position)
{
	//initialising moving variables
	m_attacking = false;
	m_frame_time = 0;
	m_current_frame = 0;

	//initialising enemy health
	maxHealth = 100;
	currentHealth = 110;
	fullBarWidth = 128;
	healthBarWidth = 128;

	//load texture
	if (m_texture != nullptr)
	{
		m_goblin = m_texture->LoadFromTileMap("images/Enemy/Goblin.png");
	}
}

Goblin::~Goblin()
{

}

void Goblin::Render()
{
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = 32;
	m_texture->Render(m_goblin, srcRect, Vector2D(m_position.x, m_position.y));
}

void Goblin::FrameUpdate(float deltaTime, float delay)
{

}
