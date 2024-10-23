#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>
using namespace std;

class GameText
{
public:
	GameText(SDL_Renderer* renderer, const string& frontPath, unsigned int fontSize);
	~GameText();

	bool LoadFont(const string& fontPath, unsigned int fontSize);

	void RenderTextAt(const string& text, int x, int y);
	void RenderNumberAt(unsigned int number, int x, int y);
	void SetColor(SDL_Color color);

protected:
	SDL_Texture* texture = nullptr;
	TTF_Font* font;
	SDL_Color color { 255, 255, 255, 255 };
	SDL_Renderer* renderer;

private:
	void Destroy();

	static bool ttfHasInit;
	static bool InitTTF();

	bool errorEncountered = false;
};

