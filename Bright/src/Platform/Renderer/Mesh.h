#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.h"
#include <string>
#include <vector>

#define MAX_BONE_INFLUENCE 4

namespace Core
{

    struct Vertex
    {
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec2 TexCoords;
        glm::vec3 Tangent;
        glm::vec3 Bitangent;
        int m_BoneIDs[MAX_BONE_INFLUENCE];
        float m_Weights[MAX_BONE_INFLUENCE];
    };
    struct Texture
    {
        unsigned int id;
        std::string type;
        std::string path;
    };



    class Mesh
    {
    private:
        std::vector<Vertex>       vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture>      textures;
        unsigned int VAO, VBO, EBO;

    public:
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);

        void Draw(Core::Shader& shader);

    private:
        void setupMesh();
    };



}


































//#pragma once
//
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <glm/glm.hpp>
//#include <vector>
//#include <string>
//#include <sstream>
//#include "Shader/Shader.h"
//
//
//struct Vertex {
//    glm::vec3 Position;
//    glm::vec3 Normal;
//    glm::vec2 TexCoords;
//};
//
//struct  Texture
//{
//    unsigned int id;
//    std::string type;
//    std::string path;
//};
//
//
//
//
//namespace Core
//{
//
//
//    class Mesh
//    {
//    private:
//        unsigned int VAO, VBO, EBO;
//    public:
//        std::vector<Vertex> vertices;
//        std::vector<unsigned int > indices;
//        std::vector<Texture> textures;
//    public:
//        Mesh(std::vector<Vertex>vertices, std::vector<unsigned int>indices, std::vector<Texture>textures);
//        void Draw(Core::Shader& shader);
//    private:
//        void setupMesh();
//
//
//    };
//
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
