#include "includes.h"
#include "Entity.h"
#include "InputHandler.h"

#pragma once
class CPlayer
{
public:
	CPlayer(SDL_Renderer *renderer);
	~CPlayer();

	void update(CInputHandler *inputHandler);
	void render();

	int getPosX();
	int getPosY();

	void setPosX(int x);
	void setPosY(int y);

	void setPos(int x, int y);

	void hit(bool *kill);

private:
	CEntity entity;
	SDL_Renderer *renderer;
	float velosityY;
	bool onGround;
};

