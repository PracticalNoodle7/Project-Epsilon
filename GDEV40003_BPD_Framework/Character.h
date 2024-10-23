#pragma once
#include "GameObject.h"

class GameText;

class Character : public GameObject
{
public:
	Character(SDL_Renderer* renderer, Vector2D start_position);
	~Character();

	virtual void Render() override;
	virtual void Update(float deltaTime, SDL_Event e) override;

	virtual void FrameUpdate(float deltaTime, float delay);

	//Character textures
	SDL_Texture* m_character_walk;
	SDL_Texture* m_character_slash;
	SDL_Texture* m_character_rolling;

	//Health bar textures
	SDL_Texture* m_health_bar;
	SDL_Texture* m_health_bar_boarder;

	//Attacking variables
	bool m_attacking;
	int m_current_frame;

	//Character stats
	PlayerStats m_stats;
	void UpdatePlayerStats(int row, int column, string state);

	bool m_interact_text;

protected:
	//animation variables
	float m_frame_time;
	const int m_num_of_frames = 4;
	ANIMATION_STATES m_current_animation;

	void PlayerDead();

	GameText* m_text;
};