#pragma once
#include "includes.h"

class CInputHandler
{
public:
	CInputHandler();
	~CInputHandler();

	void inputUpdate(SDL_Event mainEvent);

	bool key_up =false,
		key_left = false,
		key_right = false;
};

