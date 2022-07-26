#include "texture_manager.hpp"

SDL_Texture *TextureManager::load_texture(const char *filename){
	SDL_Surface *temp_surface = IMG_Load(filename);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer,temp_surface);
	SDL_FreeSurface(temp_surface);

	return tex;
}

void TextureManager::draw(SDL_Texture *tex, SDL_Rect src_rect, SDL_Rect dest_rect){
	SDL_RenderCopy(Game::renderer, tex, &src_rect, &dest_rect);
}