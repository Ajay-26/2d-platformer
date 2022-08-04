#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>


class Game{
public:
	Game();
	~Game();
	void init(const char *title, int x_pos,int y_pos, int width, int height, int fullscreen);
	void handle_events();
	void update();
	void render();
	void clean();
	bool running();

	static SDL_Renderer *renderer;
	static SDL_Event event;

private:
	int count = 0;
	SDL_Texture *player_tex;
	SDL_Rect src_rect,dest_rect;
	bool is_running;
	SDL_Window *window;
	
};