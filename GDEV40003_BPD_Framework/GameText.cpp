#include "GameText.h"

bool GameText::ttfHasInit = false;

GameText::GameText(SDL_Renderer* renderer, const string& fontPath, unsigned int fontSize)
{
	//Initialise TTF if needed
	if (!InitTTF())
	{
		cerr << "Cound't initialise TTF; error is " << TTF_GetError() << endl;
		errorEncountered = true;
		return;
	}

	//Set renderer
	this->renderer = renderer;
	LoadFont(fontPath, fontSize);
}

GameText::~GameText()
{
	Destroy();
}


bool GameText::LoadFont(const string& fontPath, unsigned int fontSize)
{
	//TTF has been initalised at this point
	this->font = TTF_OpenFont(fontPath.c_str(), fontSize);

	if (!this->font)
	{
		//No font has been loaed, show error
		cerr << "Couldn't load font from path " << fontPath << "; error is " << TTF_GetError() << endl;
		errorEncountered = true;
		return false;
	}

	return true;
}

void GameText::Destroy()
{

}

bool GameText::InitTTF()
{
	//Aready inited? Don't bother doing anything else
	if (ttfHasInit)
		return true;

	//Init TTF, return error if not inited correctly
	return (TTF_Init() >= 0);
}

void GameText::RenderTextAt(const string& text, int x, int y)
{
	//Erors? Die
	if (errorEncountered)
		return;

	//Destroy tex if needed
	if (texture != nullptr)
		SDL_DestroyTexture(texture);

	//Size the text
	int w, h;
	TTF_SizeText(font, text.c_str(), &w, &h);

	//Load surf and tex
	SDL_Surface* surf = TTF_RenderText_Blended(font, text.c_str(), color);
	texture = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);

	//Get render rect and render with it
	SDL_Rect renderRect{ x, y, w, h };
	SDL_RenderCopy(renderer, texture, NULL, &renderRect);
}

void GameText::RenderNumberAt(unsigned int number, int x, int y)
{
	//Erors? Die
	if (errorEncountered)
		return;

	//Destroy tex if needed
	if (texture != nullptr)
		SDL_DestroyTexture(texture);

	string numberText = to_string(number);

	//Size the text
	int w, h;
	TTF_SizeText(font, numberText.c_str(), &w, &h);

	//Load surf and tex
	SDL_Surface* surf = TTF_RenderText_Blended(font, numberText.c_str(), color);
	texture = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);

	//Get render rect and render with it
	SDL_Rect renderRect{ x, y, w, h };
	SDL_RenderCopy(renderer, texture, NULL, &renderRect);
}

void GameText::SetColor(SDL_Color color)
{
	this->color = color;
}