#include "BasicEnemy.h"
#include "Texture2D.h"
#include "Constants.h"
#include "Character.h"
#include "Item.h"
#include <ctime>

string m_drop_items[3]
{
    "images/Tiles/tile_0103.png",
    "images/Tiles/tile_0102.png",
    "images/Tiles/tile_0101.png"
};

BasicEnemy::BasicEnemy(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position), m_health(100, 24)
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

	//load texture
	if (m_texture != nullptr)
	{
        m_enemy = m_texture->LoadFromTileMap("images/Enemy/Goblin.png");
		m_health_bar = m_texture->LoadFromTileMap("images/Enemy/Health_bar.png");
		m_health_bar_boarder = m_texture->LoadFromTileMap("images/Enemy/HealthBar_Boarder.png");
	}

    srand(time(NULL));
}

BasicEnemy::~BasicEnemy()
{

}

void BasicEnemy::Render()
{
    srcRect.h = srcRect.w = 48;

    if (m_player_found && !m_attacking)
    {
        if (X > 0 && Y >= -10 && Y <= 10) // Walking right
        {
            srcRect.x = m_current_frame * 48;
            srcRect.y = 148;
            m_texture->Render(m_enemy, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
        }
        else if (X < 0 && Y >= -10 && Y <= 10) // Walking left
        {
            srcRect.x = m_current_frame * 48;
            srcRect.y = 148;
            m_texture->Render(m_enemy, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_HORIZONTAL);
        }
        else if (Y > 10) // Walking down
        {
            srcRect.x = m_current_frame * 48;
            srcRect.y = 96;
            m_texture->Render(m_enemy, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
        }
        else if (Y < -10) // Walking up
        {
            srcRect.x = m_current_frame * 48;
            srcRect.y = 192;
            m_texture->Render(m_enemy, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
        }
    }
    else if (m_attacking)
    {
        if (X > 0 && Y >= -10 && Y <= 10) // Attack right
        {
            srcRect.x = m_current_frame * 48;
            srcRect.y = 288;
            m_texture->Render(m_enemy, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
        }
        else if (X < 0 && Y >= -10 && Y <= 10) // Attack left
        {
            srcRect.x = m_current_frame * 48;
            srcRect.y = 288;
            m_texture->Render(m_enemy, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_HORIZONTAL);
        }
        else if (Y > 10) // Attack down
        {
            srcRect.x = m_current_frame * 48;
            srcRect.y = 240;
            m_texture->Render(m_enemy, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
        }
        else if (Y < -10) // Attack up
        {
            srcRect.x = m_current_frame * 48;
            srcRect.y = 336;
            m_texture->Render(m_enemy, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
        }
    }
    else
    {
        //Idle animation
        srcRect.x = m_current_frame * 48;
        srcRect.y = 0;
        m_texture->Render(m_enemy, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
    }

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.h = 8;
    srcRect.w = 24;

    m_texture->Render(m_health_bar_boarder, SDL_FLIP_NONE, 0.0, srcRect, Vector2D(m_position.x + 12, m_position.y + 3));

    srcRect.w = m_health.m_health_bar_width;
    m_texture->Render(m_health_bar, SDL_FLIP_NONE, 0.0, srcRect, Vector2D(m_position.x + 12, m_position.y + 3));
}

void BasicEnemy::Update(float deltaTime, SDL_Event e)
{
    m_health.HealthBar();

    if (m_health.m_is_dead)
    {
        Dead();
    }

    // Calculate the different between the players position and the enemy position
    if (!m_attacking && m_character != nullptr)
    {   
        Y = m_character->m_position.y - m_position.y;
        X = m_character->m_position.x - m_position.x;
    }

    if (m_health.m_damaged)
    {
        if (!m_character->m_attacking)
        {
            m_health.m_damaged = false;
        }
    }

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
    else if (m_attacking)
    {
        if (m_current_animation != ATTACKING)
        {
            m_current_animation = ATTACKING;
            m_current_frame = 0;
            m_num_of_frames = 4;
        }
         
        FrameUpdate(deltaTime, 0.25);
    }
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

    if (m_can_move && !GameObject::m_rolling)
    {
        // Calculate movement vector
        if (m_character->m_move_up)
        {
            movement.y += 1;
        }
        if (m_character->m_move_left)
        {
            movement.x += 1;
        }
        if (m_character->m_move_down)
        {
            movement.y -= 1;
        }
        if (m_character->m_move_right)
        {
            movement.x -= 1;
        }
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
                m_player_found = true;
				GameObject::m_can_move = true;
			}
		}
	}
}

Rect2D BasicEnemy::GetAttackCollision()
{
    if (X > 0 && Y >= -10 && Y <= 10) // Walking right
    {
        return Rect2D(m_position.x + 1, m_position.y, m_texture->GetWidth(), m_texture->GetHeight());
    }
    else if (X < 0 && Y >= -10 && Y <= 10) // Walking left
    {
        return Rect2D(m_position.x - 1, m_position.y, m_texture->GetWidth(), m_texture->GetHeight());
    }
    else if (Y > 10) // Walking down
    {
        return Rect2D(m_position.x, m_position.y + 1, m_texture->GetWidth(), m_texture->GetHeight());
    }
    else if (Y < -10) // Walking up
    {
        return Rect2D(m_position.x, m_position.y - 1, m_texture->GetWidth(), m_texture->GetHeight());
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
        movement.x -= 1.5;
        movement.y = 0;
        break;

    case FACING::FACING_LEFT:
        movement.x += 1.5;
        movement.y = 0;
        break;

    case FACING::FACING_DOWN:
        movement.y -= 1.5;
        movement.x = 0;
        break;

    case FACING::FACING_UP:
        movement.y += 1.5;
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

void BasicEnemy::Dead()
{
    int m_quantity = (rand() % 4) + 1;
    int m_item_num = (rand() % 3);

    cout << m_item_num << endl;
    m_item->DropItem(m_drop_items[m_item_num], Vector2D(m_position.x, m_position.y), m_quantity);
}

