#include "Character.h"
#include "Texture2D.h"
#include "Constants.h"

Character::Character(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position)
{
	//initialising moving variables
	m_can_move = false;

	m_frame_time = 0;
	m_frame_delay = 0.1;
	m_current_frame = 0;

	//load texture
	if (m_texture != nullptr)
	{
		m_character_left = m_texture->LoadFromFileBackground("images/Character/Character_Left.png");
		m_character_right = m_texture->LoadFromFileBackground("images/Character/Character_Right.png");
		m_character_down = m_texture->LoadFromFileBackground("images/Character/Character_Down.png");
		m_character_up = m_texture->LoadFromFileBackground("images/Character/Character_Up.png");
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
	srcRect.x = m_current_frame * 32;
	srcRect.y = 0;

	//draw the Character
	if (m_facing_direction == FACING_RIGHT)
	{
		m_texture->RenderBackground(m_character_right, srcRect, Vector2D(m_position.x, m_position.y));
	}
	else if (m_facing_direction == FACING_LEFT)
	{
		m_texture->RenderBackground(m_character_left, srcRect, Vector2D(m_position.x, m_position.y));
	}
	else if (m_facing_direction == FACING_DOWN)
	{
		m_texture->RenderBackground(m_character_down, srcRect, Vector2D(m_position.x, m_position.y));
	}
	else if (m_facing_direction == FACING_UP)
	{
		m_texture->RenderBackground(m_character_up, srcRect, Vector2D(m_position.x, m_position.y));
	}

}

void Character::Update(float deltaTime, SDL_Event e)
{
	if (GameObject::m_is_moving)
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
}


