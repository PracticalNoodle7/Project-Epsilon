#pragma once
#include "BackgroundManager.h"

class Level1BackgroundManager : public BackgroundManager
{
public:
	Level1BackgroundManager(SDL_Renderer* renderer, Vector2D start_position);
	~Level1BackgroundManager();

	void Render() override;

protected:
	SDL_Texture* m_grass;
};

