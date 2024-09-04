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
		srcRect.w = srcRect.h = 32;

		m_texture->Render(m_drop_item.imagePath, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
	}
}

void Item::Update(float deltaTime, SDL_Event e)
{

}

void Item::DropItem(string imagePath, Vector2D m_position, int m_quantity)
{
	//Applied the data to a new DroppedItems struct and then pushes the data back into the vector of dropped items
	DroppedItems new_item;

	if (m_texture != nullptr)
	{
		new_item.imagePath = m_texture->LoadFromTileMap(imagePath);
	}

	new_item.m_position = m_position;
	new_item.quantity = m_quantity;


	m_dropped_items.push_back(new_item);
}
