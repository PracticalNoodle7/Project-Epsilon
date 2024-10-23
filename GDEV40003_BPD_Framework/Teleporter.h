#pragma once
#include "GameObject.h"

class Teleporter : public GameObject
{
public:
	Teleporter(SDL_Renderer* renderer, Vector2D start_position);
	~Teleporter();

	void Render() override;

private:

	SDL_Texture* m_teleporter;
};

