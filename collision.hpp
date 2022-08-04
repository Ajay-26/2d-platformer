#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Collision{

public:
	bool AABB(const SDL_Rect& rect_a, const SDL_Rect& rect_b);

};