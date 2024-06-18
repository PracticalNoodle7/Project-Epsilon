#pragma once
#include "GameObject.h"
#include "Character.h"

class Character;

class Ground : public GameObject
{
public:
	Ground(SDL_Renderer* renderer, string imagePath, Vector2D start_position);
	~Ground();

	virtual void Render() override;
};

