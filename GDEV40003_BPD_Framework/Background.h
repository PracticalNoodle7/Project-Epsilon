#pragma once
#include "GameObject.h"

class Background : public GameObject
{
public:
	Background(SDL_Renderer* renderer, string imagePath, Vector2D start_Position);
	~Background();

	virtual void Render() override;

private:
	ROTATION m_rotation;
};

