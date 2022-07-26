#include "game.hpp"
#include "texture_manager.hpp"
#include "map.hpp"
#include "ecs/ecs.hpp"
#include "ecs/components.hpp"

SDL_Renderer *Game::renderer = nullptr;
Map *map;

Manager manager;
auto& player(manager.add_entity());

Game::Game(){

}

Game::~Game(){

}

void Game::init(const char *title, int x_pos,int y_pos, int width, int height, int fullscreen){
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
		std::cout << "Subsystems Initialised" << std::endl;
	}
	int flags = 0;
	if(fullscreen){
		flags = SDL_WINDOW_FULLSCREEN;
		window = SDL_CreateWindow(title,x_pos,y_pos,width,height,flags);
		//If window is created
		if(window){
			std::cout << "Window Created" << std::endl;
		}
		renderer = SDL_CreateRenderer(window,-1,0);	
		if(renderer){
			SDL_SetRenderDrawColor(renderer,255,255,255,255);
			std::cout << "Renderer Created" << std::endl;
		}
		is_running = true;

		map = new Map();

		player.add_component<PositionComponent>(0,0);
		player.add_component<SpriteComponent>("assets/player.png");
	}else{
		is_running=false;
	}


}

void Game::handle_events(){
	SDL_Event event;
	SDL_PollEvent(&event);
	if(event.type == SDL_QUIT){
		is_running = false;
	}
}

void Game::update(){
	count++;
	manager.refresh();
	manager.update();
}

void Game::render(){
	SDL_RenderClear(renderer);
	
	//this is where we would add stuff to render
	map->draw_map();

	SDL_RenderPresent(renderer);
}

void Game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
	return;
}

bool Game::running(){
	return this->is_running;
}
