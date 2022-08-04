#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <memory>
#include <array>

class Component;
class Entity;
class Manager;

using component_id = std::size_t;
using group = std::size_t;

inline component_id get_new_component_type_id(){
	static component_id last_id = 0u;
	return last_id++;
}

template <typename T>
inline component_id get_component_type_id() noexcept{
	static_assert(std::is_base_of<Component, T>::value, "");
	static component_id type_id = get_new_component_type_id();
	return type_id;
}

constexpr std::size_t max_components = 32;
constexpr std::size_t max_groups = 32;

using ComponentBitset = std::bitset<max_components>;
using GroupBitset = std::bitset<max_groups>;
using ComponentArray = std::array<Component *, max_components>;

class Component{

public:
	Entity *entity;
	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}

	virtual ~Component() {}
};


class Entity{

private:
	Manager& manager;
	bool active = true;
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray component_array;
	ComponentBitset component_bitset;
	GroupBitset group_bitset;
public:

	Entity(Manager& mManager): manager(mManager){}

	void update(){
		for(auto& c : components){
			c->update();
		}
	}

	void draw(){
		for(auto& c : components){
			c->draw();
		}
	}

	bool is_active() const {
		return active;
	}

	void destroy(){
		active = false;
	}

	bool has_group(group m_group){
		return group_bitset[m_group];
	}

	void add_group(group m_group);

	void delete_group(group m_group){
		group_bitset[m_group] = false;
	}

	template <typename T>
	bool has_component() const{
		return component_bitset[get_component_type_id<T>()];
	}

	template <typename T,typename ...TArgs>
	T& add_component(TArgs&&... mArgs){
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uptr(c);
		components.emplace_back(std::move(uptr));
		
		component_array[get_component_type_id<T>()] = c;
		component_bitset[get_component_type_id<T>()] = true;

		c->init();
		return *c;
	}

	template <typename T>
	T& get_component() const{
		auto ptr(component_array[get_component_type_id<T>()]);
		return *static_cast<T*>(ptr);
	}

};

class Manager{
private:
	std::vector<std::unique_ptr<Entity>>  entities;
	std::array<std::vector<Entity *>, max_groups> grouped_entities;

public:
	void update(){
		for(auto& e : entities){
			e->update();
		}
	}

	void draw(){
		for(auto& e : entities){
			e->draw();
		}
	}

	void refresh(){

		for(auto i(0u); i<max_groups;i++){
			auto &v = grouped_entities[i];
			v.erase(std::remove_if(std::begin(v),std::end(v),[i](Entity *mEntity){
				return !mEntity->is_active() || !mEntity->has_group(i);
			}),
			std::end(v));
		}

		entities.erase(std::remove_if(std::begin(entities),std::end(entities), [](const std::unique_ptr<Entity> &mEntity){
			return !mEntity->is_active();
		}),
		std::end(entities));
	}

	void add_to_group(Entity *mEntity, group mGroup){
		grouped_entities[mGroup].emplace_back(mEntity);
		mEntity->add_group(mGroup);
	}

	std::vector<Entity*>& get_group(group mGroup){
		return grouped_entities[mGroup];
	}

	Entity& add_entity(){
		Entity *e = new Entity(*this);
		std::unique_ptr<Entity> uptr(e);
		entities.emplace_back(std::move(uptr));
		return *e;
	}
};


