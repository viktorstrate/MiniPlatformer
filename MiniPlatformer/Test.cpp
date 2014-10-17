#include "includes.h"
#include "Entity.h"
#include "InputHandler.h"
#include "Player.h"
#include "Enemy.h"

	vector<CEnemy> enemies;
	void createEnemy(SDL_Renderer *renderer, CPlayer *player);

int main(int argc, char* argv[]) {

	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event mainEvent;

	double lastTime = SDL_GetTicks();
	double lastTime_EnemyCreate = SDL_GetTicks();
	double ticksPerSec = 60;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	CInputHandler inputHandler = CInputHandler();

	CPlayer player = CPlayer(renderer);

	createEnemy(renderer, &player);

	bool isRunning = true;

	while (isRunning){

		while (SDL_PollEvent(&mainEvent) != 0){
			if (mainEvent.type == SDL_QUIT){
				isRunning = false;
			}
			inputHandler.inputUpdate(mainEvent);
		}


		// update
		if (lastTime + (1000 / ticksPerSec) < SDL_GetTicks()){
			lastTime = SDL_GetTicks();

			player.update(&inputHandler);
			for (int i = 0; i < enemies.size(); i++){
				
				enemies[i].update();
				
			}

		}

		SDL_RenderClear(renderer);

		/*for (int i = 0; i < 10; i++){
			if (enemies[i].isDead == false)
				enemies[i].render();
		}*/

		for (int i = 0; i < enemies.size(); i++){
			enemies[i].render();
		}

		player.render();

		SDL_RenderPresent(renderer);
		SDL_UpdateWindowSurface(window);

		// Create Enemies
		if (lastTime_EnemyCreate + 3000 < SDL_GetTicks()){
			lastTime_EnemyCreate = SDL_GetTicks();
			
			createEnemy(renderer, &player);

		}

	}

	SDL_DestroyWindow(window);


	SDL_Quit();
	return 0;
}

void createEnemy(SDL_Renderer *renderer, CPlayer *player){
	CEnemy enm = CEnemy();
	enm.setupEnemy(renderer, player, 700, 480-32);
	enemies.push_back(enm);
	
	enm = CEnemy();
	enm.setupEnemy(renderer, player, -100, 480 - 32);
	enemies.push_back(enm);
}