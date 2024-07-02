#include "Background.h"
#include "Texture2D.h"
#include "Constants.h"

Background::Background(SDL_Renderer* renderer, string imagePath, Vector2D start_Position) : GameObject(renderer, imagePath, start_Position)
{
	//initialising moving variables
	m_rotation = ZERO;
	m_is_moving = true;
}

Background::~Background()
{

}

void Background::Render()
{
	if (m_rotation == ZERO)
	{
		m_texture->Render(m_position, SDL_FLIP_NONE, 0.0);
	}
	else if (m_rotation == NINETY)
	{
		m_texture->Render(m_position, SDL_FLIP_NONE, 90.0);
	}
	else
	{
		m_texture->Render(m_position, SDL_FLIP_NONE, 180.0);
	}
}