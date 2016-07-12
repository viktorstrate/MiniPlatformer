#include "Player.h"


CPlayer::CPlayer(SDL_Renderer *passed_renderer){
	entity = CEntity();
	renderer = NULL;
	
	renderer = passed_renderer;
	entity.setEntity(renderer, 10, 10, 32, 32, "assets/player.bmp");

	velosityY = 0;
	onGround = false;
}


CPlayer::~CPlayer()
{
}

void CPlayer::hit(bool *kill){
	if (velosityY > 0){
		// Kill
		*kill = true;
		velosityY = -10;
	}
	else {
		// Die
		
	}
}

void CPlayer::update(CInputHandler *inputHandler){
	
	// Gravity
	if (getPosY() < 480-entity.getHeight()){
		velosityY += 0.5f;
		onGround = false;
	}
	else {
		onGround = true;
		velosityY = 0;
	}
	
	if (inputHandler->key_right && getPosX() < 640-entity.getWidth()){
		setPosX(getPosX() + 5);
	}
	else if (inputHandler->key_left && getPosX() > 0){
		setPosX(getPosX() - 5);
	}

	if (inputHandler->key_up && onGround){
		velosityY = -10;
	}

	setPosY(getPosY() + velosityY);
}

void CPlayer::render(){
	entity.draw();
}

int CPlayer::getPosX(){
	return entity.getPosX();
}

int CPlayer::getPosY(){
	return entity.getPosY();
}

void CPlayer::setPosX(int x){
	entity.setPosX(x);
}

void CPlayer::setPosY(int y){
	entity.setPosY(y);
}
void CPlayer::setPos(int x, int y){
	entity.setPosX(x);
	entity.setPosY(y);
}