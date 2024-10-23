#pragma once
#include "BasicEnemy.h"

class Slime : public BasicEnemy
{
public:
	Slime(SDL_Renderer* renderer, Vector2D start_position);
	~Slime();
};

