#include "Texture2D.h"
#include "SDL_image.h"
#include <iostream>
using namespace std;


Texture2D::Texture2D(SDL_Renderer* renderer)
{	
	m_width = 0;
	m_height = 0;
	m_texture = nullptr;
	m_renderer = renderer;
}

Texture2D::~Texture2D()
{
	//Free up memory
	Free();
	m_renderer = nullptr;
}

bool Texture2D::LoadFromFile(string path)
{
	//remove memory used for a previouse texture
	Free();

	//Load the image
	SDL_Surface* p_surface = IMG_Load(path.c_str());
	if (p_surface != nullptr)
	{
		//colour key the image to be transparent
		SDL_SetColorKey(p_surface, SDL_TRUE, SDL_MapRGB(p_surface->format, 0, 0XFF, 0XFF));

		//create the texture from the pixels on the surface
		m_texture = SDL_CreateTextureFromSurface(m_renderer, p_surface);
		if (m_texture == nullptr)
		{
			cout << "Unable to create texture from surface. Error: " << SDL_GetError();
		}
		else
		{
			m_width = p_surface->w;
			m_height = p_surface->h;
		}
		//remove the loaded surface now that we have a texture
		SDL_FreeSurface(p_surface);
	}
	else
	{
		cout << "Unable to create texture from surface. Error: " << IMG_GetError();
	}
	//Return wheather the process was successful
	return m_texture != nullptr;
}

void Texture2D::Free()
{
	//Check if texture exists before removing it
	if (m_texture != nullptr)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
		m_width = 0;
		m_height = 0;
	}
}

void Texture2D::Render(Vector2D new_position, SDL_RendererFlip flip, double angle)
{
	//Set where to render the texture
	SDL_Rect renderLocation = { new_position.x, new_position.y, m_width, m_height };

	//Render to screen
	SDL_RenderCopyEx(m_renderer, m_texture, nullptr, &renderLocation, angle, nullptr, flip);
}

void Texture2D::RenderCenter(Vector2D new_position, SDL_RendererFlip flip, double angle)
{
	//Set to the center of the texture
	SDL_Point center = { m_width / 2, m_height / 2 };

	//Set where to render the texture
	SDL_Rect renderLocation = { (new_position.x - center.x), (new_position.y - center.y), m_width, m_height };

	//Render to screen
	SDL_RenderCopyEx(m_renderer, m_texture, nullptr, &renderLocation, angle, &center, flip);
}



















