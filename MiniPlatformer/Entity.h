#include "includes.h"

#pragma once
class CEntity
{
public:
	CEntity();
	~CEntity();

	void setEntity(SDL_Renderer *passed_renderer, int x, int y, int w, int h, const char* file);

	void draw();

	int getPosX();
	int getPosY();

	void setPosX(int x);
	void setPosY(int y);
	void setPos(int x, int y);

	int getWidth();
	int getHeight();

private:
	SDL_Rect rect;
	SDL_Rect crop;
	SDL_Texture *image;
	SDL_Renderer *renderer;
};

