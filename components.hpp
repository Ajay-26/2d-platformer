#pragma once

#include "ecs.h"

class PositionComponent : public Component{
private:
	int x_pos;
	int y_pos;

public:
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
	
	void set_pos(int x, int y){
		x_pos = x;
		y_pos = y;
	}
};