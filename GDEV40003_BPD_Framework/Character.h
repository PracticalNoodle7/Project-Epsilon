#pragma once
#include "GameObject.h"

class Character : public GameObject
{
public:
	Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position);
	~Character();

	virtual void Render() override;

	Vector2D previousPosition;

private:
	FACING m_facing_direction;
};