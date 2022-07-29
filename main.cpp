#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <cstdint>
#include "game.hpp"

//#include "renderwindow.hpp"
//#include "entity.hpp"
//#include "utils.hpp"
//Used this guide: https://www.youtube.com/watch?v=qEzyb1EAVoY&list=PL2RPjWnJduNmXHRYwdtublIPdlqocBoLS&index=5
//Now using this guide : https://www.youtube.com/watch?v=44tO977slsU&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&index=3

int main(int argc, char **argv){
	const int fps = 60;
	const int frame_delay = 1000/fps; //Max Time in ms between frames
	
	uint32_t frame_start;
	int frame_time;

	Game *game = new Game();
	game->init("NewGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,800,600,false);
	while(game->running()){
		frame_start = SDL_GetTicks();

		game->handle_events();
		game->update();
		game->render();

		frame_time  = SDL_GetTicks() - frame_start;

		if(frame_delay > frame_time){
			SDL_Delay(frame_delay - frame_time);
		}
	}

	game->clean();
	std::cout << "Done" << std::endl;

	return 0;
}