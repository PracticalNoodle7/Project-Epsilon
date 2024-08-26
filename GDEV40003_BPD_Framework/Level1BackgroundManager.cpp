#include "Level1BackgroundManager.h"
#include "Texture2D.h"
#include "Constants.h"

int Level1[30][35] = {
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6}

};

Level1BackgroundManager::Level1BackgroundManager(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position)
{
    m_movment_speed = 1;

	if (m_texture != nullptr)
	{
		m_grass = m_texture->LoadFromTileMap("images/Overworld_Tile/Grass_TileMap.png");
	}

	LoadTileMap(Level1);
}

Level1BackgroundManager::~Level1BackgroundManager()
{
	delete m_grass;
	m_grass = nullptr;
}

void Level1BackgroundManager::LoadTileMap(int arr[30][35])
{
	for (int row = 0; row < 30; row++)
	{
		for (int column = 0; column < 35; column++)
		{
			m_tile_map[row][column].type = arr[row][column];
			m_tile_map[row][column].x = (column + 5) * 31;
			m_tile_map[row][column].y = (row + 5) * 31;
		}
	}
}

void Level1BackgroundManager::Render()
{
	for (int row = 0; row < 30; row++)
	{
		for (int column = 0; column < 35; column++)
		{
			m_position.x = m_tile_map[row][column].x;
			m_position.y = m_tile_map[row][column].y;


			switch (m_tile_map[row][column].type)
			{
			case 0:
				srcRect.x = 32, srcRect.y = 32;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 1:
				srcRect.x = 32, srcRect.y = 0;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 2:
				srcRect.x = 0, srcRect.y = 0;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 3:
				srcRect.x = 0, srcRect.y = 32;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 4:
				srcRect.x = 0, srcRect.y = 64;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 5:
				srcRect.x = 32, srcRect.y = 64;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 6:
				srcRect.x = 64, srcRect.y = 64;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 7:
				srcRect.x = 64, srcRect.y = 32;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			case 8:
				srcRect.x = 64, srcRect.y = 0;
				m_texture->Render(m_grass, srcRect, Vector2D(m_position.x, m_position.y));
				break;
			}
		}
	}
}

void Level1BackgroundManager::Update(float deltaTime, SDL_Event e)
{
    m_is_moving = false;  // Assume not moving by default

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
        
        if(GameObject::m_rolling)
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
}

void Level1BackgroundManager::Move(Vector2D movement, float deltaTime)
{
    // Apply movement to the tile map
    for (int row = 0; row < 30; row++)
    {
        for (int column = 0; column < 35; column++)
        {
            m_tile_map[row][column].x += movement.x * deltaTime * 200;
            m_tile_map[row][column].y += movement.y * deltaTime * 200;
        }
    }

    if (movement.y > 0)
    {
        ChangeFacingDirection(FACING::FACING_UP);
    }
    else if (movement.y < 0)
    {
        ChangeFacingDirection(FACING::FACING_DOWN);
    }
    else if (movement.x > 0)
    {
        ChangeFacingDirection(FACING::FACING_LEFT);
    }
    else if (movement.x < 0)
    {
        ChangeFacingDirection(FACING::FACING_RIGHT);
    }
}


void Level1BackgroundManager::Rolling(Vector2D movement, float deltaTime)
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

    // Apply movement to the tile map
    for (int row = 0; row < 30; row++)
    {
        for (int column = 0; column < 35; column++)
        {
            m_tile_map[row][column].x += movement.x * deltaTime * 200;
            m_tile_map[row][column].y += movement.y * deltaTime * 200;
        }
    }
}
