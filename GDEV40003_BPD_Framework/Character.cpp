#include "Character.h"
#include "Texture2D.h"
#include "Constants.h"

Character::Character(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position)
{
	//initialising moving variables
	m_attacking = false;
	m_frame_time = 0;
	m_current_frame = 0;

	//initialising character health
	maxHealth = 100;
	currentHealth = 100;
	fullBarWidth = 128;
	healthBarWidth = 128;

	//load texture
	if (m_texture != nullptr)
	{
		m_character_walk = m_texture->LoadFromTileMap("images/Character/Character_Walk.png");
		m_character_slash = m_texture->LoadFromTileMap("images/Character/Character_Slash.png");
		m_character_rolling = m_texture->LoadFromTileMap("images/Character/Character_Rolling.png");

		m_health_bar = m_texture->LoadFromTileMap("images/Character/HealthBar.png");
		m_health_bar_boarder = m_texture->LoadFromTileMap("images/Character/HealthBar_Boarder.png");
	}
}

Character::~Character()
{
	delete m_character_walk;
	m_character_walk = nullptr;

	delete m_character_slash;
	m_character_slash = nullptr;

	delete m_character_rolling;
	m_character_rolling = nullptr;

	delete m_health_bar;
	m_health_bar = nullptr;

	delete m_health_bar_boarder;
	m_health_bar_boarder = nullptr;

}

void Character::Render()
{
	srcRect.h = 32;
	srcRect.w = 32;

	if (!m_attacking && !GameObject::m_rolling)
	{
		switch (m_facing_direction)
		{

		case FACING::FACING_RIGHT:
			srcRect.x = (m_current_frame * 32) + 128;
			srcRect.y = 0;
			m_texture->Render(m_character_walk, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;

		case FACING::FACING_LEFT:
			srcRect.x = m_current_frame * 32;
			srcRect.y = 0;
			m_texture->Render(m_character_walk, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;

		case FACING::FACING_DOWN:
			srcRect.x = m_current_frame * 32;
			srcRect.y = 32;
			m_texture->Render(m_character_walk, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;

		case FACING::FACING_UP:
			srcRect.x = (m_current_frame * 32) + 128;
			srcRect.y = 32;
			m_texture->Render(m_character_walk, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;
		}
	}
	else if (m_attacking)
	{
		switch (m_facing_direction)
		{
		case FACING::FACING_RIGHT:
			srcRect.x = (m_current_frame * 32) + 128;
			srcRect.y = 0;
			m_texture->Render(m_character_slash, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;

		case FACING::FACING_LEFT:
			srcRect.x = m_current_frame * 32;
			srcRect.y = 0;
			m_texture->Render(m_character_slash, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;

		case FACING::FACING_DOWN:
			srcRect.x = m_current_frame * 32;
			srcRect.y = 32;
			m_texture->Render(m_character_slash, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;

		case FACING::FACING_UP:
			srcRect.x = (m_current_frame * 32) + 128;
			srcRect.y = 32;
			m_texture->Render(m_character_slash, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;
		}
	}
	else
	{
		switch (m_facing_direction)
		{
		case FACING::FACING_RIGHT:
			srcRect.x = (m_current_frame * 32) + 128;
			srcRect.y = 0;
			m_texture->Render(m_character_rolling, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;

		case FACING::FACING_LEFT:
			srcRect.x = m_current_frame * 32;
			srcRect.y = 0;
			m_texture->Render(m_character_rolling, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;

		case FACING::FACING_DOWN:
			srcRect.x = m_current_frame * 32;
			srcRect.y = 32;
			m_texture->Render(m_character_rolling, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;

		case FACING::FACING_UP:
			srcRect.x = (m_current_frame * 32) + 128;
			srcRect.y = 32;
			m_texture->Render(m_character_rolling, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;
		}
	}

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = 16;
	srcRect.w = 128;

	m_texture->Render(m_health_bar_boarder, SDL_FLIP_NONE, 0.0, srcRect, Vector2D(10, 10));

	srcRect.w = healthBarWidth;
	m_texture->Render(m_health_bar, SDL_FLIP_NONE, 0.0, srcRect, Vector2D(10, 10));

}

void Character::Update(float deltaTime, SDL_Event e)
{
	// Calculate the width of the health bar portion to display
	healthBarWidth = (currentHealth * fullBarWidth) / maxHealth;

	if (GameObject::m_is_moving && !m_attacking && !GameObject::m_rolling)
	{
		if (m_current_animation != WALKING)
		{
			m_current_animation = WALKING;
			m_current_frame = 0;
		}

		FrameUpdate(deltaTime, 0.1);
	}
	else if(m_attacking)
	{
		if (m_current_animation != ATTACKING)
		{
			m_current_animation = ATTACKING;
			m_current_frame = 0;
		}

		FrameUpdate(deltaTime, 0.15);
	}
	else if (m_rolling && !m_attacking)
	{
		if (m_current_animation != ROLLING)
		{
			m_current_animation = ROLLING;
			m_current_frame = 0;
		}

		FrameUpdate(deltaTime, 0.15);
	}
	else
	{
		m_current_frame = 0;
	}

	switch (e.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		switch (e.button.state)
		{
		case SDL_BUTTON_LEFT:
			m_attacking = true; 
			GameObject::m_can_move = false;
			break;
		}

	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_SPACE:
			Character::m_rolling = true;
			break;
		}
	}
}

void Character::FrameUpdate(float deltaTime, float delay)
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
			if (m_rolling)
			{
				Character::m_rolling = false;
			}
		}
	}
}

