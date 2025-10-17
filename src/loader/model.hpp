#ifndef MODEL_HPP
#define MODEL_HPP

#include <assimp/Importer.hpp>
#include <string>
#include <engine/render/mesh.hpp>

/**
 * @file model.hpp
 * @brief Provides functionality to load 3D models into Mesh objects.
 */

/**
 * @class Model
 * @brief Utility class for loading 3D models.
 *
 * This class uses Assimp to load models from files and converts them into
 * Mesh objects usable by the engine.
 */
class Model {
public:
    /**
     * @brief Loads a 3D model by file name.
     * @param name The file path or name of the model to load.
     * @return Pointer to a Mesh object containing the model's geometry.
     *
     * This function parses the model file, processes its meshes, and returns
     * a Mesh that can be rendered in the engine.
     */
    static Mesh* load(const std::string& name);
};

#endif // MODEL_HPP
