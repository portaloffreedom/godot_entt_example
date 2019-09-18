# Godot gdnative EnTT example

An example on how to use gdnative with entt.

### Clone and build
- clone with `git clone --recursive` (I use git submodules). If you forget you can always run later `git submodule init --recursive && git submodule update`.
- build with `cmake`, no particular options required.
- run as a normal godot project.

#### How the example game works
When running the example, just press enter ("ui_accept") to spawn another random entity.
Entities will be removed when they get outside of the plane (72 * 72 square surface).

#### Disclaimer
this may not be the best way to use entt inside godot, it's just an easy way to do it that I want to share with the world.
