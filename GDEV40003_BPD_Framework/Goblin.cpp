#include "Goblin.h"

Goblin::Goblin(SDL_Renderer* renderer, Vector2D start_position) : BasicEnemy(renderer, start_position)
{
	//initialising moving variables
	m_attacking = false;
	m_frame_time = 0;
	m_current_frame = 0;

	//initialising enemy health
	maxHealth = 100;
	currentHealth = 110;
	fullBarWidth = 128;
	healthBarWidth = 128;

	//load texture
	if (m_texture != nullptr)
	{
		m_goblin = m_texture->LoadFromTileMap("images/Enemy/Goblin.png");
	}
}

Goblin::~Goblin()
{

}

void Goblin::Render()
{

}

void Goblin::Update(float deltaTime, SDL_Event e)
{
	cout << "Goblin health is " << currentHealth << endl;
}

void Goblin::FrameUpdate(float deltaTime, float delay)
{

}
