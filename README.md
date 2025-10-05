# Vortex Engine

Vortex Engine is our in-house 3D game engine, built to serve as the foundation for our games.  
It provides essential systems like rendering, input handling, and shader management, allowing the team to focus on creating gameplay, story, and assets without worrying about low-level graphics or window management.

## Purpose

- To give our team a **stable and flexible base** for building games.
- To handle **core engine tasks**: window creation, rendering, input, shaders.
- To enable **rapid prototyping** of gameplay and mechanics.
- To ensure **consistent tools** for all team members, regardless of platform.

This engine is not tied to a specific game yet — it’s a framework we can build upon as the game idea develops

## Building

### Linux

Install `cmake, glfw, glew, libspng, glm` from your package manager.

Run `cmake -S . -B build` to bootstrap project  
Run `cmake --build build` to build dynamic library
