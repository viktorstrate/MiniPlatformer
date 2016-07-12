#include "Entity.h"

CEntity::CEntity()
{
	renderer = NULL;
	image = NULL;

	image = NULL;

	rect.x = NULL;
	rect.y = NULL;
	rect.w = NULL;
	rect.h = NULL;

	crop.x = NULL;
	crop.y = NULL;
	crop.w = NULL;
	crop.h = NULL;
}

CEntity::~CEntity()
{
}

void CEntity::setEntity(SDL_Renderer *passed_renderer, int x, int y, int w, int h, const char* passed_file){
	renderer = passed_renderer;
	image = IMG_LoadTexture(renderer, passed_file);

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	crop.x = 0;
	crop.y = 0;
	crop.w = w;
	crop.h = h;
}

void CEntity::draw(){
	SDL_RenderCopy(renderer, image, &crop, &rect);
}

int CEntity::getPosX(){
	return rect.x;
}

int CEntity::getPosY(){
	return rect.y;
}

void CEntity::setPosX(int x){
	rect.x = x;
}

void CEntity::setPosY(int y){
	rect.y = y;
}
void CEntity::setPos(int x, int y){
	setPosX(x);
	setPosY(y);
}

int CEntity::getWidth(){
	return rect.w;
}

int CEntity::getHeight(){
	return rect.h;
}