#pragma once
#ifndef _TEXTURE2D_H
#define _TEXTURE2D_H
#include <SDL.h>
#include <string>
#include "Commons.h"

class Texture2D
{
public:
	Texture2D(SDL_Renderer* renderer);
	~Texture2D();

	bool LoadFromFile(std::string path);
	SDL_Texture* LoadFromFileBackground(std::string path);
	void Free();
	void Render(Vector2D new_position, SDL_RendererFlip flip, double angle);
	void RenderCenter(SDL_Texture* texture, SDL_Rect srcRect, Vector2D new_position);

	void RenderBackground(SDL_Texture* texture, SDL_Rect srcRect, Vector2D new_position);

	int GetWidth() { return m_width; }
	int GetHeight() { return m_height; }

private:
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	SDL_Texture* m_tile_map_texture;

	int m_width;
	int m_height;

};

#endif //_TEXTURE2D_H

#include <SDL.h>