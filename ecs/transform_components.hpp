#pragma once
#include "../vector2d.hpp"
#include "ecs.hpp"

class TransformComponent : public Component{

public:

	Vector2D position;
	Vector2D velocity;

	int height = 32;
	int width = 32;
	int scale = 1;

	int speed = 3;

	TransformComponent(){
		position.x = 0;
		position.y = 0;
	}

	TransformComponent(float x, float y){
		position.x = x;
		position.y = y;
	}

	TransformComponent(float x, float y, int h, int w, int sc){
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = sc;
	}

	void init() override{
		velocity.x = 0;
		velocity.y = 0;
	}

	void update() override{
		position.x += velocity.x*speed;
		position.y += velocity.y*speed;
	}

};