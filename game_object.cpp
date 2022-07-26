#include "game_object.hpp"

GameObject::GameObject(const char *texture_sheet, int x, int y){
	object_texture = TextureManager::load_texture(texture_sheet);
	x_pos = x;
	y_pos = y;
}

void GameObject::update(){
	x_pos++;
	y_pos++;

	src_rect.h = 64;
	src_rect.w = 64;
	src_rect.x = 0;
	src_rect.y = 0;

	dest_rect.x = x_pos;
	dest_rect.y = y_pos;
	dest_rect.w = src_rect.w * 2;
	dest_rect.h = src_rect.h * 2;

}

void GameObject::render(){
	SDL_RenderCopy(Game::renderer, object_texture, &src_rect, &dest_rect);
}