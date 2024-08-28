#include "BasicEnemy.h"
#include "Texture2D.h"
#include "Constants.h"
#include "Character.h"

BasicEnemy::BasicEnemy(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position)
{
	//initialising moving variables
	m_attacking = false;
    m_player_found = false;
	m_frame_time = 0;
	m_current_frame = 0;
    m_num_of_frames = 0;

    Vector2D Chase(0.0f, 0.0f);
    Y = 0;
    X = 0;

	//initialising enemy health
	maxHealth = 100;
	currentHealth = 100;
	fullBarWidth = 128;
	healthBarWidth = 128;

	//load texture
	if (m_texture != nullptr)
	{
		m_health_bar = m_texture->LoadFromTileMap("images/Character/HealthBar.png");
		m_health_bar_boarder = m_texture->LoadFromTileMap("images/Character/HealthBar_Boarder.png");
	}


}

BasicEnemy::~BasicEnemy()
{
    delete m_health_bar;
    m_health_bar = nullptr;

    delete m_health_bar_boarder;
    m_health_bar_boarder = nullptr;
}

void BasicEnemy::Render()
{

}

void BasicEnemy::Update(float deltaTime, SDL_Event e)
{
    Y = m_character->m_position.y - m_position.y;
    X = m_character->m_position.x - m_position.x;

    if (m_player_found && !m_attacking)
    {
        if (m_current_animation != WALKING)
        {
            m_current_animation = WALKING;
            m_current_frame = 0;
            m_num_of_frames = 4;
        }

        FrameUpdate(deltaTime, 0.1);
    }
 /*   if (m_attacking)
    {
        if (m_current_animation != ATTACKING)
        {
            m_current_animation = ATTACKING;
            m_current_frame = 0;
            m_num_of_frames = 4;
        }
         
        FrameUpdate(deltaTime, 0.25);
    }*/
    else
    {
        if (m_current_animation != IDLE)
        {
            m_current_animation = IDLE;
            m_current_frame = 0;
            m_num_of_frames = 3;
        }

        FrameUpdate(deltaTime, 0.4);
    }

    Vector2D movement(0.0f, 0.0f);  // Initialize movement vector

    if (m_can_move)
    {
        // Calculate movement vector
        if (m_move_up)
        {
            movement.y += 1;
        }
        if (m_move_left)
        {
            movement.x += 1;
        }
        if (m_move_down)
        {
            movement.y -= 1;
        }
        if (m_move_right)
        {
            movement.x -= 1;
        }

        if (GameObject::m_rolling)
        {
            Rolling(movement, deltaTime);
        }


        // Normalize the movement vector to prevent faster diagonal movement
        if (movement.x != 0 || movement.y != 0)
        {
            movement = movement.Normalize();
            m_is_moving = true;

            // Apply movement
            if (!GameObject::m_rolling)
            {
                Move(movement, deltaTime);
            }

        }

        // Handle the events
        switch (e.type)
        {
        case SDL_KEYDOWN:

            switch (e.key.keysym.sym)
            {
                // Press W to move up
            case SDLK_w:
                m_move_up = true;
                break;

                // Press A to move left
            case SDLK_a:
                m_move_left = true;
                break;

                // Press S to move down
            case SDLK_s:
                m_move_down = true;
                break;

                // Press D to move right
            case SDLK_d:
                m_move_right = true;
                break;
            }
            break;
        case SDL_KEYUP:
            switch (e.key.keysym.sym)
            {
                // Check if W is up
            case SDLK_w:
                m_move_up = false;
                break;

                // Check if A is up
            case SDLK_a:
                m_move_left = false;
                break;

                // Check if S is up
            case SDLK_s:
                m_move_down = false;
                break;

                // Check if D is up
            case SDLK_d:
                m_move_right = false;
                break;
            }
        }
    }

    if (m_player_found && !m_attacking)
    {
        ChasePlayer(GetPlayerLocation(), deltaTime);
    }
}

void BasicEnemy::FrameUpdate(float deltaTime, float delay)
{
	m_frame_time += deltaTime;

	if (m_frame_time >= delay)
	{
		m_frame_time = 0;
		m_current_frame++;

		if (m_current_frame >= m_num_of_frames)
		{
			m_current_frame = 0;

			if (m_attacking)
			{
				m_attacking = false;
				GameObject::m_can_move = true;
			}
		}
	}
}

void BasicEnemy::Move(Vector2D movement, float deltaTime)
{
	// Apply movement to the basic enemies 
	m_position.x += movement.x * deltaTime * 200;
	m_position.y += movement.y * deltaTime * 200;
}

void BasicEnemy::Rolling(Vector2D movement, float deltaTime)
{
    switch (m_facing_direction)
    {
    case FACING::FACING_RIGHT:
        movement.x -= 0.5;
        movement.y = 0;
        break;

    case FACING::FACING_LEFT:
        movement.x += 0.5;
        movement.y = 0;
        break;

    case FACING::FACING_DOWN:
        movement.y -= 0.5;
        movement.x = 0;
        break;

    case FACING::FACING_UP:
        movement.y += 0.5;
        movement.x = 0;
        break;
    }

    m_position.x += movement.x * deltaTime * 200;
    m_position.y += movement.y * deltaTime * 200;
}

void BasicEnemy::ChasePlayer(Vector2D move, float deltaTime)
{
    // Apply movement to the basic enemies 
    m_position.x += move.x * deltaTime * 125;
    m_position.y += move.y * deltaTime * 125;
}

Vector2D BasicEnemy::GetPlayerLocation()
{

    if (m_can_move)
    {
        if (Y > 1.25)
        {
            Chase.y += 0.5;
        }
        if (X > 1.25)
        {
            Chase.x += 0.5;
        }
        if (Y < -1.25)
        {
            Chase.y -= 0.5;
        }
        if (X < -1.25)
        {
            Chase.x -= 0.5;
        }

        // Normalize the movement vector to prevent faster diagonal movement
        if (Chase.x != 0 || Chase.y != 0)
        {
            Chase = Chase.Normalize();
            m_is_moving = true;
        }
    }

    return Chase;
}
