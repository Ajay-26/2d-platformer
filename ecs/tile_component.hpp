#pragma once

#include "ecs.hpp"
#include "transform_components.hpp"
#include "sprite_components.hpp"
#include <SDL2/SDL.h>

class TileComponent : public Component{

public:
	TransformComponent *transform;
	SpriteComponent *sprite;

	char *path;
	SDL_Rect tile_rect;
	int tile_id;

	TileComponent() =default;

	TileComponent(int p_x, int p_y, int p_w, int p_h, int id){
		tile_rect.x = p_x;
		tile_rect.y = p_y;
		tile_rect.w = p_w;
		tile_rect.h = p_h;
		tile_id = id;

		switch(tile_id){
			case 0:
				path = "assets/dirt.png";
				break;
			case 1:
				path = "assets/grass.png";
				break;
			case 2:
				path = "assets/water.png";
				break;
			default:
				break;
		}
	}
	void init() override{
		entity->add_component<TransformComponent>(static_cast<float>(tile_rect.x),static_cast<float>(tile_rect.y),tile_rect.h,tile_rect.w,1);
		transform = &entity->get_component<TransformComponent>();

		entity->add_component<SpriteComponent>(path);
		sprite = &entity->get_component<SpriteComponent>();
	}
};