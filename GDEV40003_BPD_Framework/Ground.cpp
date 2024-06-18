#include "Ground.h"
#include "Texture2D.h"
#include "Constants.h"

Ground::Ground(SDL_Renderer* renderer, string imagePath, Vector2D start_position) : GameObject(renderer, imagePath, start_position)
{

}

Ground::~Ground()
{

}

void Ground::Render()
{
	//draw the Ground
	m_texture->Render(m_position, SDL_FLIP_NONE);
}

