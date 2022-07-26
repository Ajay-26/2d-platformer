#pragma once 
#include "texture_manager.hpp"

class GameObject{

public:
	GameObject(const char *texture_sheet, int x, int y);
	~GameObject();
	void update();
	void render();

private:
	int x_pos;
	int y_pos;

	SDL_Texture *object_texture;
	SDL_Rect src_rect, dest_rect;


};