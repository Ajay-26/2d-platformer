#pragma once

#include "components.hpp"
#include "../texture_manager.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class SpriteComponent : public Component{

private:
	TransformComponent *transform;
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

	~SpriteComponent(){
		SDL_DestroyTexture(texture);
	}

	void init() override {
		transform = &entity->get_component<TransformComponent>();

		src_rect.x = src_rect.y = 0;
		src_rect.w = transform->width;
		src_rect.h = transform->height;

	}

	void update() override {

		dest_rect.x = (int)transform->position.x;
		dest_rect.y = (int)transform->position.y;
		dest_rect.w = transform->width*transform->scale;
		dest_rect.h = transform->height*transform->scale;
	}
	
	void draw() override {
		TextureManager::draw(texture,src_rect,dest_rect);
	}

};

