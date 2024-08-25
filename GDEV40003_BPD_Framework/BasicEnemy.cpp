#include "BasicEnemy.h"
#include "Texture2D.h"
#include "Constants.h"

BasicEnemy::BasicEnemy(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position)
{
	//initialising moving variables
	m_attacking = false;
	m_frame_time = 0;
	m_current_frame = 0;

	//initialising enemy health
	maxHealth = 100;
	currentHealth = 100;
	fullBarWidth = 128;
	healthBarWidth = 128;

	//load texture
	if (m_texture != nullptr)
	{
		m_health_bar = m_texture->LoadFromTileMap("images/Character/HealthBar.png");
		m_health_bar_boarder = m_texture->LoadFromTileMap("images/Character/HealthBar_Boarder.png");
	}
}

BasicEnemy::~BasicEnemy()
{

}

void BasicEnemy::Render()
{

}

void BasicEnemy::Update(float deltaTime, SDL_Event e)
{

}

void BasicEnemy::FrameUpdate(float deltaTime, float delay)
{
	m_frame_time += deltaTime;

	if (m_frame_time >= delay)
	{
		m_frame_time = 0;
		m_current_frame++;

		if (m_current_frame >= m_num_of_frames)
		{
			m_current_frame = 0;

			if (m_attacking)
			{
				m_attacking = false;
				GameObject::m_can_move = true;
			}
		}
	}
}
