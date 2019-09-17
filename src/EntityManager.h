#pragma once

#include <Godot.hpp>
#include <Spatial.hpp>

namespace godot {

class EntityManager : public Spatial {
    GODOT_CLASS(EntityManager, Spatial)

public:
    static void _register_methods();

    EntityManager();
    virtual ~EntityManager();

    void _init();
    void _process(float delta);
};

}
