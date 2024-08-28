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
	delete m_goblin;
	m_goblin = nullptr;
}

void Goblin::Render()
{
	srcRect.h = srcRect.w = 48;

	if (m_player_found && !m_attacking)
	{
		if (X > 0 && Y >= -10 && Y <= 10) // Walking right
		{
			srcRect.x = m_current_frame * 48;
			srcRect.y = 148;
			m_texture->Render(m_goblin, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
		}
		else if (X < 0 && Y >= -10 && Y <= 10) // Walking left
		{
			srcRect.x = m_current_frame * 48;
			srcRect.y = 148;
			m_texture->Render(m_goblin, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_HORIZONTAL);
		}
		else if (Y > 10) // Walking down
		{
			srcRect.x = m_current_frame * 48;
			srcRect.y = 96;
			m_texture->Render(m_goblin, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
		}
		else if (Y < -10) // Walking up
		{
			srcRect.x = m_current_frame * 48;
			srcRect.y = 192;
			m_texture->Render(m_goblin, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
		}
	}
	else if (m_attacking)
	{
		if (X > 0 && Y >= -10 && Y <= 10) // Attack right
		{
			srcRect.x = m_current_frame * 48;
			srcRect.y = 288;
			m_texture->Render(m_goblin, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
		}
		else if (X < 0 && Y >= -10 && Y <= 10) // Attack left
		{
			srcRect.x = m_current_frame * 48;
			srcRect.y = 288;
			m_texture->Render(m_goblin, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_HORIZONTAL);
		}
		else if (Y > 10) // Attack down
		{
			srcRect.x = m_current_frame * 48;
			srcRect.y = 240;
			m_texture->Render(m_goblin, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
		}
		else if (Y < -10) // Attack up
		{
			srcRect.x = m_current_frame * 48;
			srcRect.y = 336;
			m_texture->Render(m_goblin, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
		}
	}
	else
	{
		//Idle animation
		srcRect.x = m_current_frame * 48;
		srcRect.y = 0;
		m_texture->Render(m_goblin, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
	}


}

