#include <Godot.hpp>
#include "Entity.h"
#include "EntityManager.h"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o)
{
	std::cout << "godot_gdnative_init()" << std::endl;
	godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o)
{
	std::cout << "godot_gdnative_terminate()" << std::endl;
        godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle)
{
	std::cout << "godot_nativescript_init()" << std::endl;
	godot::Godot::nativescript_init(handle);
	godot::register_class<godot::Entity>();
	godot::register_class<godot::EntityManager>();
}
