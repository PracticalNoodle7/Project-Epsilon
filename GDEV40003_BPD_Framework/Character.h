#pragma once
#include "GameObject.h"

class Character : public GameObject
{
public:
	Character(SDL_Renderer* renderer, Vector2D start_position);
	~Character();

	virtual void Render() override;

	Vector2D previousPosition;

	SDL_Texture* m_character_left;
	SDL_Texture* m_character_right;
	SDL_Texture* m_character_down;
	SDL_Texture* m_character_up;
};