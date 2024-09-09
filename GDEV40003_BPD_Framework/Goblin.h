#pragma once
#include "BasicEnemy.h"

class Goblin : public BasicEnemy
{
public:
	Goblin(SDL_Renderer* renderer, Vector2D start_position);
	~Goblin();

};

