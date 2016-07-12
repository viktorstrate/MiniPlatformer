#include "InputHandler.h"


CInputHandler::CInputHandler()
{
	key_left = key_right = key_up = false;
}


CInputHandler::~CInputHandler()
{
}

void CInputHandler::inputUpdate(SDL_Event mainEvent){
	if (mainEvent.type == SDL_KEYDOWN){
		switch (mainEvent.key.keysym.sym)
		{
		case SDLK_a:
			key_left = true;
			break;
		case SDLK_d:
			key_right = true;
			break;
		case SDLK_SPACE:
			key_up = true;
			break;
		default:
			break;
		}
	}
	if (mainEvent.type == SDL_KEYUP){
		switch (mainEvent.key.keysym.sym)
		{
		case SDLK_a:
			key_left = false;
			break;
		case SDLK_d:
			key_right = false;
			break;
		case SDLK_SPACE:
			key_up = false;
			break;
		default:
			break;
		}
	}
}