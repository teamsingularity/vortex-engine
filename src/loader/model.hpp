#ifndef MODEL_HPP
#define MODEL_HPP
#include <assimp/Importer.hpp>
#include <string>
#include <engine/render/mesh.hpp>

class Model {
    public:
        static Mesh load(const std::string& name);
};





#endif