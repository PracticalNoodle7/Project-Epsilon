#include "Character.h"
#include "Texture2D.h"
#include "Constants.h"

Character::Character(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position)
{
	//initialising moving variables
	previousPosition = start_position;
	m_is_moving = false;

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
	//draw the Character
	if (m_facing_direction == FACING_RIGHT)
	{
		srcRect.x = 0, srcRect.y = 0;
		m_texture->RenderBackground(m_character_right, srcRect, Vector2D(m_position.x, m_position.y));
	}
	else if (m_facing_direction == FACING_LEFT)
	{
		srcRect.x = 0, srcRect.y = 0;
		m_texture->RenderBackground(m_character_left, srcRect, Vector2D(m_position.x, m_position.y));
	}
	else if (m_facing_direction == FACING_DOWN)
	{
		srcRect.x = 0, srcRect.y = 0;
		m_texture->RenderBackground(m_character_down, srcRect, Vector2D(m_position.x, m_position.y));
	}
	else if (m_facing_direction == FACING_UP)
	{
		srcRect.x = 0, srcRect.y = 0;
		m_texture->RenderBackground(m_character_up, srcRect, Vector2D(m_position.x, m_position.y));
	}

}


