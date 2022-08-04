#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class ColliderComponent;

class Collision{

public:
	static bool AABB(const SDL_Rect& rect_a, const SDL_Rect& rect_b);
	static bool AABB(const ColliderComponent& collider_a, const ColliderComponent& collider_b);
};