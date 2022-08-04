#include "map.hpp"
#include "texture_manager.hpp"

int lvl1[20][25] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

Map::Map(){
	dirt = TextureManager::load_texture("assets/dirt.png");
	grass = TextureManager::load_texture("assets/grass.png");
	water = TextureManager::load_texture("assets/water.png");

	load_map(lvl1);

	src_rect.x = src_rect.y = 0;
	src_rect.h = dest_rect.h = 32;
	src_rect.w = dest_rect.w = 32; 
	dest_rect.x = dest_rect.y = 0;
}

void Map::load_map(int arr[20][25]){
	int row,col;
	for(row=0;row<20;row++){
		for(col=0;col<25;col++){
			map[row][col] = arr[row][col];
		}
	}
}

Map::~Map(){
	SDL_DestroyTexture(dirt);
	SDL_DestroyTexture(grass);
	SDL_DestroyTexture(water);
}

void Map::draw_map(){
	int row,col;
	int type = 0;
	for(row=0;row<20;row++){
		for(col=0;col<25;col++){
			type = map[row][col];
			dest_rect.x = col*32;
			dest_rect.y = row*32;
			switch(type){
				case 0:
					TextureManager::draw(water,src_rect,dest_rect);
					break;
				case 1:
					TextureManager::draw(grass,src_rect,dest_rect);
					break;
				case 2:
					TextureManager::draw(dirt,src_rect,dest_rect);
				default:
					break;
			}
		}
	}
}