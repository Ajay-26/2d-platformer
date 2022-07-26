#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <memory>
#include <array>

class Component;
class Entity;

using component_id = std::size_t;

inline component_id get_component_id(){
	static component_id last_id = 0;
	return last_id++;
}

template <typename T>
