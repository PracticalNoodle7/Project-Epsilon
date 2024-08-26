#pragma once
#include "BasicEnemy.h"

class Goblin : public BasicEnemy
{
public:
	Goblin(SDL_Renderer* renderer, Vector2D start_position);
	~Goblin();

	virtual void Render() override;

	virtual void FrameUpdate(float deltaTime, float delay) override;

	SDL_Texture* m_goblin;

protected:

};

