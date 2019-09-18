#include <sstream>
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>
#include <Input.hpp>
#include "EntityManager.h"

using namespace godot;

typedef Vector3 position;

struct velocity
{
    float dx;
    float dy;
    float dz;
};

void EntityManager::_register_methods()
{
    register_method("_process", &EntityManager::_process);
}

EntityManager::EntityManager()
    : rd()
    , gen(rd())
    , dis(-5.0, 5.0)
{}

EntityManager::~EntityManager()
{}

void EntityManager::_init()
{
    this->entity_scene = ResourceLoader::get_singleton()->load("res://models/Entity.tscn");
    this->create_entity();
}

void EntityManager::_process(float delta)
{
    registry.view<position, velocity, Spatial*>().each([delta](position &pos, velocity &vel, Spatial* s_entity) {
        pos.x += vel.dx * delta;
        pos.y += vel.dy * delta;
        pos.z += vel.dz * delta;
        s_entity->set_translation(Vector3(pos.x, pos.y, pos.z));
    });

    for(auto &entity: registry.view<position, Spatial*>())
    {
        const float arena_size = 36.0f;
        auto &pos = registry.get<position>(entity);
        if (fabs(pos.x) > arena_size or fabs(pos.y) > arena_size)
        {
            registry.get<Spatial*>(entity)->queue_free();
            registry.destroy(entity);
        }
    }

    Input *input = Input::get_singleton();
    if (input->is_action_just_pressed("ui_accept"))
    {
        this->create_entity();
    }
}

void EntityManager::create_entity()
{
    Godot::print("Adding node");
    entt::entity entity = registry.create();
    float dx = dis(gen);
    float dz = dis(gen);
    std::stringstream message;
    message << "Generating entity with velocity dx(" << dx << ") dz(" << dz << ")";
    Godot::print(message.str().c_str());
    registry.assign<position>(entity, 0.0f, 0.0f, 0.0f);
    registry.assign<velocity>(entity, dx, 0.0f, dz);
    Spatial* entity_node = reinterpret_cast<Spatial*>(entity_scene->instance());
    this->add_child(entity_node);
    registry.assign<Spatial*>(entity, entity_node);
    Godot::print("Node Added");
}
