#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

#include "Mesh.h"
#include "Shader.h"

namespace Core
{



    class Model
    {
    public:
        // model data 
        std::vector<Core::Texture> textures_loaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
        std::vector<Core::Mesh>    meshes;
        std::string directory;
        bool gammaCorrection;

        //Model(std::string const& path, bool gamma = false);
        Model() {};

        void Draw(Core::Shader& shader);

    public:
        void loadModel(std::string const& path);


    private:
        // processes a node in a recursive fashion. Processes each individual mesh located at the node and repeats this process on its children nodes (if any).
        void processNode(aiNode* node, const aiScene* scene);

        Core::Mesh processMesh(aiMesh* mesh, const aiScene* scene);
        unsigned int TextureFromFile(const char* path, const std::string& directory, bool gamma = false);
        // checks all material textures of a given type and loads the textures if they're not loaded yet.
        // the required info is returned as a Texture struct.
        std::vector<Core::Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
    };



}


