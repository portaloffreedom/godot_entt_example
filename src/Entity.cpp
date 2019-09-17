#include "Entity.h"

using namespace godot;

void Entity::_register_methods()
{
    Godot::print("Register methods()");
    register_method("_process", &Entity::_process);
}

Entity::Entity()
{
    Godot::print("Entity()");
}

Entity::~Entity()
{
    Godot::print("~Entity()");
}

void Entity::_init()
{
    Godot::print("Init entity()");
}

void Entity::_process(float delta)
{

}
