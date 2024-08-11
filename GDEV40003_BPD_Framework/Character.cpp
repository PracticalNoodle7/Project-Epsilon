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

	//load texture
	if (m_texture != nullptr)
	{
		m_character_left = m_texture->LoadFromTileMap("images/Character/Character_Left.png");
		m_character_right = m_texture->LoadFromTileMap("images/Character/Character_Right.png");
		m_character_down = m_texture->LoadFromTileMap("images/Character/Character_Down.png");
		m_character_up = m_texture->LoadFromTileMap("images/Character/Character_Up.png");

		m_attack_left = m_texture->LoadFromTileMap("images/Character/Character_Slash_Left.png");
		m_attack_right = m_texture->LoadFromTileMap("images/Character/Character_Slash_Right.png");
		m_attack_down = m_texture->LoadFromTileMap("images/Character/Character_Slash_Down.png");
		m_attack_up = m_texture->LoadFromTileMap("images/Character/Character_Slash_Up.png");
	}
}

Character::~Character()
{
	delete m_character_left;
	m_character_left = nullptr;

	delete m_character_right;
	m_character_right = nullptr;

	delete m_character_down;
	m_character_down = nullptr;

	delete m_character_up;
	m_character_up = nullptr;
}

void Character::Render()
{

	if (!m_attacking)
	{
		srcRect.x = m_current_frame * 32;
		srcRect.y = 0;

		switch (m_facing_direction)
		{

		case FACING::FACING_RIGHT:
			m_texture->Render(m_character_right, srcRect, Vector2D(m_position.x, m_position.y));
			break;

		case FACING::FACING_LEFT:
			m_texture->Render(m_character_left, srcRect, Vector2D(m_position.x, m_position.y));
			break;

		case FACING::FACING_DOWN:
			m_texture->Render(m_character_down, srcRect, Vector2D(m_position.x, m_position.y));
			break;

		case FACING::FACING_UP:
			m_texture->Render(m_character_up, srcRect, Vector2D(m_position.x, m_position.y));
			break;
		}
	}
	else
	{
		srcRect.x = m_attack_current_frame * 32;
		srcRect.y = 0;

		switch (m_facing_direction)
		{

		case FACING::FACING_RIGHT:
			m_texture->Render(m_attack_right, srcRect, Vector2D(m_position.x, m_position.y));
			break;

		case FACING::FACING_LEFT:
			m_texture->Render(m_attack_left, srcRect, Vector2D(m_position.x, m_position.y));
			break;

		case FACING::FACING_DOWN:
			m_texture->Render(m_attack_down, srcRect, Vector2D(m_position.x, m_position.y));
			break;

		case FACING::FACING_UP:
			m_texture->Render(m_attack_up, srcRect, Vector2D(m_position.x, m_position.y));
			break;
		}
	}

}

void Character::Update(float deltaTime, SDL_Event e)
{
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


