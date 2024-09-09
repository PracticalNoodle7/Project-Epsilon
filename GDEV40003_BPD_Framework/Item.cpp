#include "Item.h"


Item::Item(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position)
{
	//load texture
	m_texture = new Texture2D(m_renderer);
}

Item::~Item()
{


}

void Item::Render()
{
	for (DroppedItems m_drop_item : m_dropped_items)
	{
		m_position.x = m_drop_item.m_position.x;
		m_position.y = m_drop_item.m_position.y;

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 16;

		m_texture->Render(m_drop_item.imageTexture, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
	}
}

void Item::Update(float deltaTime, SDL_Event e)
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
}

void Item::Move(Vector2D movement, float deltaTime)
{
    // Apply movement to the tile map
    for (DroppedItems& m_drop_item : m_dropped_items) // Use reference here
    {
        m_drop_item.m_position.x += movement.x * deltaTime * 200;
        m_drop_item.m_position.y += movement.y * deltaTime * 200;
    }
}


void Item::Rolling(Vector2D movement, float deltaTime)
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
    for (DroppedItems& m_drop_item : m_dropped_items) // Use reference here
    {
        m_drop_item.m_position.x += movement.x * deltaTime * 200;
        m_drop_item.m_position.y += movement.y * deltaTime * 200;
    }
}

void Item::DropItem(string imagePath, Vector2D m_position, int m_quantity)
{
	//Applied the data to a new DroppedItems struct and then pushes the data back into the vector of dropped items
	DroppedItems new_item;

	if (m_texture != nullptr)
	{
        new_item.imagePath = imagePath;
		new_item.imageTexture = m_texture->LoadFromTileMap(imagePath);
	}

	new_item.m_position.x = m_position.x + 16;
    new_item.m_position.y = m_position.y + 16;
	new_item.quantity = m_quantity;


	m_dropped_items.push_back(new_item);
}

void Item::RemoveItem(const std::string& imagePath)
{
    for (auto it = m_dropped_items.begin(); it != m_dropped_items.end(); )
    {
        if (it->imagePath == imagePath)
        {
            // Erase the item and update the iterator to the next element
            it = m_dropped_items.erase(it);
        }
        else
        {
            ++it; // Move to the next element
        }
    }
}
