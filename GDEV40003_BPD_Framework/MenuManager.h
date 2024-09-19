#pragma once
#include "GameObject.h"

class MenuManager : public GameObject
{
public:
	MenuManager(SDL_Renderer* renderer, Vector2D start_position);
	~MenuManager();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

	std::string m_images[3];

private:
	void SetUpMenu();

	//static bool to control the menu
	static bool s_main_menu_open;
	Menu m_menu[3];
	SDL_Rect srcRect;
};

