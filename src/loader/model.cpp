#include "model.hpp"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>            
#include <assimp/postprocess.h>      
#include <iostream>

static Mesh load(const std::string& name)
{
    Assimp::Importer importer;
    unsigned int flags = aiProcess_Triangulate | aiProcess_GenNormals | aiProcess_FlipUVs | aiProcess_JoinIdenticalVertices;
    const aiScene* scene = importer.ReadFile(name.c_str(), flags);
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cerr << "Error while loading: " << importer.GetErrorString() << std::endl;
        return Mesh(nullptr, 0, {}); 
    }

    aiMesh* mesh = scene->mMeshes[0];  
    unsigned int numVertices = mesh->mNumVertices;

   
    std::vector<float> vertexData;
    vertexData.reserve(numVertices * 6); 

    for (unsigned int i = 0; i < numVertices; i++) {
        
        vertexData.push_back(mesh->mVertices[i].x);
        vertexData.push_back(mesh->mVertices[i].y);
        vertexData.push_back(mesh->mVertices[i].z);

        
        if (mesh->HasNormals()) {
            vertexData.push_back(mesh->mNormals[i].x);
            vertexData.push_back(mesh->mNormals[i].y);
            vertexData.push_back(mesh->mNormals[i].z);
        } else {
            vertexData.push_back(0.0f);
            vertexData.push_back(1.0f);
            vertexData.push_back(0.0f);
        }
    }

   
    std::vector<int> attributes = {3, 3};

   
    return Mesh(vertexData.data(), vertexData.size() * sizeof(float), attributes);
}
