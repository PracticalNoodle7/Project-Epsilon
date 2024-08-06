#pragma once
#include "GameObject.h"

class Character : public GameObject
{
public:
	Character(SDL_Renderer* renderer, Vector2D start_position);
	~Character();

	virtual void Render() override;
	virtual void Update(float deltaTime, SDL_Event e) override;

	SDL_Texture* m_character_left;
	SDL_Texture* m_character_right;
	SDL_Texture* m_character_down;
	SDL_Texture* m_character_up;

protected:
	float m_frame_time;
	float m_frame_delay;
	int m_current_frame;
	const int m_num_of_frames = 4;

};