#pragma once

#include <Godot.hpp>
#include <Spatial.hpp>

namespace godot {

class Entity : public Spatial {
    GODOT_CLASS(Entity, Spatial)

public:
    static void _register_methods();

    Entity();
    virtual ~Entity();

    void _init();

    void _process(float delta);
};

}
