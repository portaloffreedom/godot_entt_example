#pragma once

#include <random>
#include <Godot.hpp>
#include <Spatial.hpp>
#include <PackedScene.hpp>
#include <entt/entt.hpp>

namespace godot {

class EntityManager : public Spatial {
    GODOT_CLASS(EntityManager, Spatial)

public:
    static void _register_methods();

    EntityManager();
    virtual ~EntityManager();

    void _init();
    void _process(float delta);

    void create_entity();
private:
    // registry
    entt::registry registry;

    // preload of the resources to create a single entity
    Ref<PackedScene> entity_scene;
    Ref<Resource> entity_script;

    // stuff for the random generator
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<float> dis;
};

}
