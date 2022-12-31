#include "Renderer.h"
#include <iostream>

namespace OpenGLTestProject {
    namespace Renderer
    {
        const char* vertexShaderSource = 
            "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\0";

        const char* fragmentShaderSource = 
            "#version 330 core\n"
            "out vec4 FragColor;\n"
            "void main()\n"
            "{\n"
                "FragColor = vec4(111.0f / 255.0f, 84.0f / 255.0f, 76.0f / 255.0f, 1.0f);\n"
            "}\0";

        unsigned int shaderProgram;
        unsigned int VAO; //ID of Vertex Array Object

        void checkSuccess(unsigned int shader) {
            int success;
            char infoLog[512];
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

            if(!success) {
                glGetShaderInfoLog(shader, 512, NULL, infoLog);
                perror("SHADER COMPILATION ERROR\n");
                perror(infoLog);
                perror("\n");
            }
        }

        unsigned int setupVertex() {
            unsigned int vertexShader; //id of vertex shader
            vertexShader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
            glCompileShader(vertexShader);
            checkSuccess(vertexShader);
            return vertexShader;
        }

        unsigned int setupFragment() {
            unsigned int fragmentShader; //id of fragment shader
            fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
            glCompileShader(fragmentShader);
            checkSuccess(fragmentShader);
            return fragmentShader;
        }

        void Renderer::setupRenderer() {
            float vertices[] = {
                -0.5f, -0.5f, 0.0f,
                 0.5f, -0.5f, 0.0f,
                 0.0f,  0.5f, 0.0f
            };

            unsigned int VBO; //id of Vertex Buffer Object
            glGenBuffers(1, &VBO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);

            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

            unsigned int vertexShader, fragmentShader; //IDs of the shaders
            vertexShader = setupVertex();
            fragmentShader = setupFragment();

            shaderProgram = glCreateProgram();

            glAttachShader(shaderProgram, vertexShader);
            glAttachShader(shaderProgram, fragmentShader);
            glLinkProgram(shaderProgram);
            checkSuccess(shaderProgram);

            glUseProgram(shaderProgram);
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

            glGenVertexArrays(1, &VAO);  

            glBindVertexArray(VAO);
            // Copy vertices array in a buffer for OpenGL to use
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
            // Set vertex attributes pointers
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
        }

        void Renderer::drawTriangle() {
            glUseProgram(shaderProgram);
            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES, 0, 3);
        }

    } // namespace Renderer
}
