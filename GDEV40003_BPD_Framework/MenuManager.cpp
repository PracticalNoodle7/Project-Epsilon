#include "MenuManager.h"
#include "Texture2D.h"
#include "Constants.h"
#include "GameScreenManager.h"
using namespace std;

static bool s_main_menu_open = false;

MenuManager::MenuManager(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position)
{
	m_images[0] = "images/Menu/StartButton.png";
	m_images[1] = "images/Menu/SettingsButton.png";
	m_images[2] = "images/Menu/ControlsButton.png";

	SetUpMenu();

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 0;
	srcRect.h = 0;
}

MenuManager::~MenuManager()
{

}

void MenuManager::Render()
{
	for (int i = 0; i < 3; i++)
	{
		m_position.x = m_menu[i].x;
		m_position.y = m_menu[i].y;

		srcRect.w = 96 * 2;
		srcRect.h = 32 * 2;

		m_texture->Render(m_menu[i].imageTexture, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);

	}
}

void MenuManager::Update(float deltaTime, SDL_Event e)
{
	// Variables to hold the mouse position
	int x, y;
	SDL_GetMouseState(&x, &y);

	switch (e.type)
	{
		// Detecting if the mouse button is down
	case SDL_MOUSEBUTTONDOWN:
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			// Check for clicks in inventory slots
			for (int i = 0; i < 3; i++)
			{
				int slotX = m_menu[i].x;
				int slotY = m_menu[i].y;
				int slotWidth = 96 * 2;
				int slotHeight = 32 * 2;

				if (x >= slotX && x <= slotX + slotWidth &&
					y >= slotY && y <= slotY + slotHeight)
				{
					// Slot at (row, column) is clicked

					if (m_menu[i].imagePath == "images/Menu/StartButton.png")
					{
						cout << "START" << endl;
						GameScreenManager::s_start_the_rift = true;
						break;
					}
					else if (m_menu[i].imagePath == "images/Menu/SettingsButton.png")
					{
						cout << "SETTINGS" << endl;
						break;
					}
					else if (m_menu[i].imagePath == "images/Menu/ControlsButton.png")
					{
						cout << "CONTROLS" << endl;
						break;
					}
				}
			}
		}
		break;
	}
}

void MenuManager::SetUpMenu()
{
	for (int i = 0; i < 3; i++)
	{
		m_menu[i].type = i;
		m_menu[i].imageTexture = m_texture->LoadFromTileMap(m_images[i]);
		m_menu[i].imagePath = m_images[i];
		m_menu[i].x = (SCREEN_WIDTH / 2) - 96;
		m_menu[i].y = 200 + ( 100 * i);
	}
}
