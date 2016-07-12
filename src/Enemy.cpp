#include "Enemy.h"

CEnemy::CEnemy()
{
	renderer = NULL;
	player = NULL;

	isDieing = true;

	velosityY = 0;
	onGround = false;
}


CEnemy::~CEnemy()
{
}

void CEnemy::setupEnemy(SDL_Renderer *passed_renderer, CPlayer *passed_player, int x, int y){
	renderer = passed_renderer;
	entity.setEntity(renderer, x, y, 32, 32, "assets/enemy.bmp");

	player = passed_player;

	isDieing = false;
}

void CEnemy::update(){

	if (isDieing){
		return;
	}

	// Gravity
	if (getPosY() < 480 - entity.getHeight()){
		velosityY += 0.5f;
		onGround = false;
	}
	else {
		onGround = true;
		velosityY = 0;
	}

	// Follow
	if (entity.getPosX() < player->getPosX()){
		entity.setPosX(entity.getPosX() + 3);
	}

	if (entity.getPosX() > player->getPosX()){
		entity.setPosX(entity.getPosX() - 3);
	}

	// if collide with player
	if (entity.getPosX() + entity.getWidth() > player->getPosX() && // Right
		entity.getPosX() - entity.getWidth() < player->getPosX() && // Left
		entity.getPosY() - entity.getWidth() <= player->getPosY()){ // Up
		
		player->hit(&isDieing);

	}

	setPosY(getPosY() + velosityY);
}

void CEnemy::render(){
	if (!isDieing)
		entity.draw();
}

int CEnemy::getPosX(){
	return entity.getPosX();
}

int CEnemy::getPosY(){
	return entity.getPosY();
}

void CEnemy::setPosX(int x){
	entity.setPosX(x);
}

void CEnemy::setPosY(int y){
	entity.setPosY(y);
}
void CEnemy::setPos(int x, int y){
	entity.setPosX(x);
	entity.setPosY(y);
}

bool CEnemy::isDead(){
	return isDieing;
}
