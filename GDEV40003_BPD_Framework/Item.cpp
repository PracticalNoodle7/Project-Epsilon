#include "Item.h"
#include "Character.h"
#include "BackgroundManager.h"


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
