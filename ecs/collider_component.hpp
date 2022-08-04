#pragma once

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ecs.hpp"
#include "components.hpp"

class ColliderComponent : public Component{

public:
	SDL_Rect collider;
	std::string tag;
	TransformComponent *transform;

	ColliderComponent(std::string p_tag){
		tag = p_tag;
	}

	void init() override{
		if(entity->has_component<TransformComponent>()){
			entity->add_component<TransformComponent>();
		}
		transform = &entity->get_component<TransformComponent>();

		Game::colliders.push_back(this);
	}

	void update() override{
		collider.x = transform->position.x;
		collider.y = transform->position.y;
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}

};