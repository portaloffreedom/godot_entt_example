#include "EntityManager.h"

using namespace godot;

void EntityManager::_register_methods()
{
    register_method("_process", &EntityManager::_process);
}

EntityManager::EntityManager()
{}

EntityManager::~EntityManager()
{}

void EntityManager::_init()
{}

void EntityManager::_process(float delta)
{}
