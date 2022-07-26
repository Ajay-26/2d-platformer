#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "game.hpp"

class TextureManager{

public:
	static SDL_Texture* load_texture(const char *filename);
	static void draw(SDL_Texture *tex, SDL_Rect src_rect, SDL_Rect dest_rect);
};