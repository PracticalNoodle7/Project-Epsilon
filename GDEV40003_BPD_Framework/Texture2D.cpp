#include "Texture2D.h"
#include "SDL_image.h"
#include "Constants.h"
#include <iostream>
using namespace std;


Texture2D::Texture2D(SDL_Renderer* renderer)
{	
	m_width = 0;
	m_height = 0;
	m_texture = nullptr;
	m_tile_map_texture = nullptr;
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
		else if (path == "images/Inventory/InventoryPannel1.png")
		{
			m_width = SCREEN_WIDTH - 200;
			m_height = SCREEN_HEIGHT - 200;
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

	return m_texture != nullptr;
}

SDL_Texture* Texture2D::LoadFromTileMap(std::string path)
{
	// Remove memory used for a previous texture
	Free();

	// Load the image
	SDL_Surface* p_surface = IMG_Load(path.c_str());
	if (p_surface == nullptr)
	{
		std::cout << "Unable to load image. Error: " << IMG_GetError() << std::endl;
		return nullptr; 
	}

	// Color key the image to be transparent
	if (SDL_SetColorKey(p_surface, SDL_TRUE, SDL_MapRGB(p_surface->format, 0, 0xFF, 0xFF)) != 0)
	{
		std::cout << "Unable to set color key. Error: " << SDL_GetError() << std::endl;
		SDL_FreeSurface(p_surface);
		return nullptr;
	}

	// Create the texture from the pixels on the surface
	SDL_Texture* new_texture = SDL_CreateTextureFromSurface(m_renderer, p_surface);
	if (new_texture == nullptr)
	{
		std::cout << "Unable to create texture from surface. Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		m_width = p_surface->w;
		m_height = p_surface->h;
	}

	// Remove the loaded surface now that we have a texture
	SDL_FreeSurface(p_surface);

	// Return the texture
	return new_texture;
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

void Texture2D::Render(SDL_Texture* texture, SDL_RendererFlip flip, double angle, SDL_Rect srcRect, Vector2D new_position)
{
	//Set where to render the texture
	SDL_Rect renderLocation = { new_position.x, new_position.y, srcRect.w, srcRect.h };

	SDL_Rect renderImage = { srcRect.x, srcRect.y, srcRect.w, srcRect.h };

	//Render to screen
	SDL_RenderCopyEx(m_renderer, texture, &renderImage, &renderLocation, angle, nullptr, flip);
}

void Texture2D::Render(SDL_Texture* texture, SDL_Rect srcRect, Vector2D new_position, SDL_RendererFlip flip)
{
	//Set where to render the texture
	SDL_Rect renderLocation = { new_position.x, new_position.y, srcRect.w, srcRect.h };

	SDL_Rect renderImage = { srcRect.x, srcRect.y, srcRect.w, srcRect.h };

	double angle = 0;

	SDL_RenderCopyEx(m_renderer, texture, &renderImage, &renderLocation, angle, nullptr, flip);
}