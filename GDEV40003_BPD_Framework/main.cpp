#include "SDL.h"
#include "SDL_image.h"
#include "Constants.h"
#include "Commons.h"
#include "Texture2D.h"
#include "GameScreenManager.h"
#include <iostream>
#include "Character.h"
using namespace std;

//Globals
SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
GameScreenManager* game_screen_manager;
Camera camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
Uint32 g_old_time;

//Function prototypes
bool InitSDL();
bool Update();
void CloseSDL();
void Render();
void UpdateCamera(Character* character);


int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	if (InitSDL())
	{
		game_screen_manager = new GameScreenManager(g_renderer, SCREEN_LEVEL1);
		//set the time
		g_old_time = SDL_GetTicks();

		//flag to check if we wish to quit
		bool quit = false;

		//Game loop
		while (!quit)
		{
			Render();
			quit = Update();
		}
	}

	CloseSDL();

	return 0;
}


bool InitSDL()
{
	// Setup SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL did not initialise. Error: " << SDL_GetError();
		return false;
	}

	// Set the texture scaling mode to nearest neighbor (disable interpolation)
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

	// Create window
	g_window = SDL_CreateWindow("Project A", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (g_window == nullptr)
	{
		// Window failed
		cout << "Window was not created. Error: " << SDL_GetError();
		return false;
	}

	// Create renderer
	g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
	if (g_renderer == nullptr)
	{
		// Renderer creation failed
		cout << "Renderer could not initialise. Error: " << SDL_GetError();
		return false;
	}

	// Initialize PNG loading
	int imageFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imageFlags) & imageFlags))
	{
		cout << "SDL_Image could not initialise. Error: " << IMG_GetError();
		return false;
	}

	return true;
}


void CloseSDL()
{
	SDL_DestroyWindow(g_window);
	g_window = nullptr;
	SDL_Quit();

	//release the renderer
	SDL_DestroyRenderer(g_renderer);
	g_renderer = nullptr;

	//destroy the game screen manager
	delete game_screen_manager;
	game_screen_manager = nullptr;
}


bool Update()
{
	Uint32 new_time = SDL_GetTicks();

	//Event handler
	SDL_Event e;
	
	//Get events
	SDL_PollEvent(&e);

	//handle the events
	switch (e.type)
	{
		//click the 'X' to quit
	case SDL_QUIT:
		return true;
		break;
	}

	game_screen_manager->Update((float)(new_time - g_old_time) / 1000.0f, e);
	g_old_time = new_time;

	Character* character = game_screen_manager->GetCharacter();
	if (character != nullptr)
	{
		UpdateCamera(character);
	}

	return false;
}

void Render()
{
	//Clear the screen
	SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(g_renderer);

	game_screen_manager->Render();

	//Update the screen
	SDL_RenderPresent(g_renderer);
}

void UpdateCamera(Character* character)
{
	camera.x = character->m_position.x - (camera.width / 2);
	camera.y = character->m_position.y - (camera.height / 2);
}








