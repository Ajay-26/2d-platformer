#include "collision.hpp"
#include "ecs/collider_component.hpp"

bool Collision::AABB(const SDL_Rect& rect_a, const SDL_Rect& rect_b){
	if((rect_a.x + rect_a.w >= rect_b.x) && 
		(rect_b.x + rect_b.w >= rect_a.x) && 
		(rect_a.y + rect_a.h >= rect_b.y) && 
		(rect_b.y + rect_b.h >= rect_a.y)){
		return true;
	}
	return false;
}

bool Collision::AABB(const ColliderComponent& collider_a, const ColliderComponent& collider_b){
	SDL_Rect rect_a = collider_a.collider;
	SDL_Rect rect_b = collider_b.collider;
	if((rect_a.x + rect_a.w >= rect_b.x) && 
		(rect_b.x + rect_b.w >= rect_a.x) && 
		(rect_a.y + rect_a.h >= rect_b.y) && 
		(rect_b.y + rect_b.h >= rect_a.y)){
		std::cout << collider_a.tag << " hit " << collider_b.tag << std::endl;
		return true;
	}
	return false;
}