#include "Character.h"
#include "Texture2D.h"
#include "Constants.h"

Character::Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position) : GameObject(renderer, imagePath, start_position)
{
	//initialising moving variables
	m_facing_direction = FACING_RIGHT;
	previousPosition = start_position;
	m_is_moving = false;
}

Character::~Character()
{

}

void Character::Render()
{
	//draw the Character
	if (m_facing_direction == FACING_RIGHT)
	{
		m_texture->RenderCenter(m_position, SDL_FLIP_NONE, 0.0);
	}
	else
	{
		m_texture->RenderCenter(m_position, SDL_FLIP_HORIZONTAL, 0.0);
	}
}


