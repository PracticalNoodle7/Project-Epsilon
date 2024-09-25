#pragma once
#include "BackgroundManager.h"

class TheRiftBackground : public BackgroundManager
{
public:
	TheRiftBackground(SDL_Renderer* renderer, Vector2D start_position);
	~TheRiftBackground();

	void Render() override;

protected:
	SDL_Texture* m_grass;
	SDL_Texture* m_stone;
	SDL_Texture* m_walls;
};

