#include "Character.h"
#include "Texture2D.h"
#include "Constants.h"

Character::Character(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position)
{
	//initialising moving variables
	m_attacking = false;

	m_frame_time = 0;
	m_frame_delay = 0.1;
	m_current_frame = 0;

	m_attack_frame_time = 0;
	m_attack_frame_delay = 0.15;
	m_attack_current_frame = 0;

	m_roll_frame_time = 0;
	m_roll_frame_delay = 0.15;
	m_roll_current_frame = 0;

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
		m_health_bar = m_texture->LoadFromTileMap("images/Character/HealthBar.png");
		m_health_bar_boarder = m_texture->LoadFromTileMap("images/Character/HealthBar_Boarder.png");
	}
}

Character::~Character()
{

}

void Character::Render()
{

	srcRect.h = 32;
	srcRect.w = 32;

	if (!m_attacking)
	{
		switch (m_facing_direction)
		{

		case FACING::FACING_RIGHT:
			srcRect.x = (m_current_frame * 32) + 128;
			srcRect.y = 0;
			m_texture->Render(m_character_walk, srcRect, Vector2D(m_position.x, m_position.y));
			break;

		case FACING::FACING_LEFT:
			srcRect.x = m_current_frame * 32;
			srcRect.y = 0;
			m_texture->Render(m_character_walk, srcRect, Vector2D(m_position.x, m_position.y));
			break;

		case FACING::FACING_DOWN:
			srcRect.x = m_current_frame * 32;
			srcRect.y = 32;
			m_texture->Render(m_character_walk, srcRect, Vector2D(m_position.x, m_position.y));
			break;

		case FACING::FACING_UP:
			srcRect.x = (m_current_frame * 32) + 128;
			srcRect.y = 32;
			m_texture->Render(m_character_walk, srcRect, Vector2D(m_position.x, m_position.y));
			break;
		}
	}
	else
	{
		switch (m_facing_direction)
		{
		case FACING::FACING_RIGHT:
			srcRect.x = (m_attack_current_frame * 32) + 128;
			srcRect.y = 0;
			m_texture->Render(m_character_slash, srcRect, Vector2D(m_position.x, m_position.y));
			break;

		case FACING::FACING_LEFT:
			srcRect.x = m_attack_current_frame * 32;
			srcRect.y = 0;
			m_texture->Render(m_character_slash, srcRect, Vector2D(m_position.x, m_position.y));
			break;

		case FACING::FACING_DOWN:
			srcRect.x = m_attack_current_frame * 32;
			srcRect.y = 32;
			m_texture->Render(m_character_slash, srcRect, Vector2D(m_position.x, m_position.y));
			break;

		case FACING::FACING_UP:
			srcRect.x = (m_attack_current_frame * 32) + 128;
			srcRect.y = 32;
			m_texture->Render(m_character_slash, srcRect, Vector2D(m_position.x, m_position.y));
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

	if (GameObject::m_is_moving && !m_attacking)
	{
		m_frame_time += deltaTime;

		if (m_frame_time >= m_frame_delay)
		{
			m_frame_time = 0;
			m_current_frame++;

			if (m_current_frame >= m_num_of_frames)
			{
				m_current_frame = 0;
			}
		}
	}
	else
	{
		m_current_frame = 0;
	}

	if (m_attacking)
	{
		m_attack_frame_time += deltaTime;

		if (m_attack_frame_time >= m_attack_frame_delay)
		{
			m_attack_frame_time = 0;
			m_attack_current_frame++;

			if (m_attack_current_frame >= m_num_of_frames)
			{
				m_attack_current_frame = 0;
				m_attacking = false;
				GameObject::m_can_move = true;
			}
		}
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
	}
}

