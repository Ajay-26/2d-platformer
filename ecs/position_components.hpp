#pragma once
#include "ecs.hpp"

class PositionComponent : public Component{
private:
	int x_pos;
	int y_pos;

public:
	PositionComponent(){
		x_pos = 0;
		y_pos = 0;
	}

	PositionComponent(int x, int y){
		x_pos = x;
		y_pos = y;
	}

	int get_x(){
		return x_pos;
	}
	
	int get_y(){
		return y_pos;
	}

	void init() override{
		x_pos = 0;
		y_pos = 0;
	}

	void update() override{
		x_pos++;
		y_pos++;
	}
	
	void set_pos(int x, int y){
		x_pos = x;
		y_pos = y;
	}
};