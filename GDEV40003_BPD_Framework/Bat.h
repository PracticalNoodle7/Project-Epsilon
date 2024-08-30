#pragma once
#include "BasicEnemy.h"

class Bat : public BasicEnemy
{
public:
	Bat(SDL_Renderer* renderer, Vector2D start_position);
	~Bat();
};

