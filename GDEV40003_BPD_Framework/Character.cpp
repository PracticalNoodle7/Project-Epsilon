#include "Character.h"
#include "Texture2D.h"
#include "Constants.h"

Character::Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position) : GameObject(renderer, imagePath, start_position)
{
	//initialising moving variables
	m_facing_direction = FACING_RIGHT;
	m_move_left = false;
	m_move_right = false;
	m_can_jump = false;
	m_jumping = false;
	m_acceleration = 5;
}

Character::~Character()
{

}

void Character::Render()
{
	//draw the Character
	if (m_facing_direction == FACING_RIGHT)
	{
		m_texture->Render(m_position, SDL_FLIP_NONE);
	}
	else
	{
		m_texture->Render(m_position, SDL_FLIP_HORIZONTAL);
	}
}

void Character::Update(float deltaTime, SDL_Event e)
{

	if (m_move_left)
	{
		MoveLeft(deltaTime);
	}
	else if (m_move_right)
	{
		MoveRight(deltaTime);
	}

	//handle the events
	switch (e.type)
	{
	case SDL_KEYDOWN:

		switch (e.key.keysym.sym)
		{
			//Press A to move left
		case SDLK_a:
			m_move_left = true;
			break;

			//Press D to move right
		case SDLK_d:
			m_move_right = true;
			break;	
		
			//press space to jump
		case SDLK_SPACE:
			Jump();
			break;
		}
		break;

	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
			//Check if a is up
		case SDLK_a:
			m_move_left = false;
			break;

			//Check if d is up
		case SDLK_d:
			m_move_right = false;
			break;
		}

	}

}
	void Character::MoveLeft(float deltaTime)
	{
		if (m_move_left)
		{
			m_position.x -= deltaTime * 100;
			m_facing_direction = FACING_LEFT;
		}
	}

	void Character::MoveRight(float deltaTime)
	{
		if (m_move_right)
		{
			m_position.x += deltaTime * 100;
			m_facing_direction = FACING_RIGHT;
		}
	}

	void Character::Jump()
	{

	}


