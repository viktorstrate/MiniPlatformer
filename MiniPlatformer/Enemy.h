#include "includes.h"
#include "Entity.h"
#include "Player.h"

#pragma once
class CEnemy
{
public:
	CEnemy();
	~CEnemy();

	void update();
	void render();

	int getPosX();
	int getPosY();

	void setPosX(int x);
	void setPosY(int y);

	void setPos(int x, int y);

	void setupEnemy(SDL_Renderer *passed_renderer, CPlayer *player, int x, int y);

	bool isDead();

private:
	CEntity entity;
	SDL_Renderer *renderer;
	float velosityY;
	bool onGround;
	CPlayer *player;
	bool isDieing;
};

