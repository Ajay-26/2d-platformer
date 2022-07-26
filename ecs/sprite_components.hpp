#pragma once

#include "components.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class SpriteComponent : public Component{

private:
	PositionComponent *position;
	SDL_Texture *texture;
	SDL_Rect src_rect, dest_rect;

public:
	void set_tex(const char *path){
		texture = TextureManager::load_texture(path);
	}

	SpriteComponent() = default;
	SpriteComponent(const char * path) {
		set_tex(path);
	}
	void init() override {
		position = &entity->get_component<PositionComponent>();

		src_rect.x = src_rect.y = 0;
		src_rect.w = src_rect.h = 32;
		dest_rect.w = dest_rect.h = 64;

	}

	void update() override {
		dest_rect.x = position->get_x();
		dest_rect.y = position->get_y();
	}
	
	void draw() override {
		TextureManager::draw(texture,src_rect,dest_rect);
	}

};

