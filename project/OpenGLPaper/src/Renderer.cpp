#include "Renderer.h"
#include <iostream>

namespace OpenGLTestProject {
    namespace Renderer
    {
        const char* vertexShaderSource = 
            "#version 460 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\0";

        const char* fragmentShaderSource = 
            "#version 460 core\n"
            "out vec4 FragColor;\n"
            "void main()\n"
            "{\n"
                "FragColor = vec4(111.0f / 255.0f, 84.0f / 255.0f, 76.0f / 255.0f, 1.0f);\n"
            "}\0";

        unsigned int shaderProgram;
        unsigned int VAO; //ID of Vertex Array Object

        void checkSuccess(unsigned int shader, int status) {
            int success;
            char infoLog[512];
            if(status == GL_COMPILE_STATUS)
                glGetShaderiv(shader, status, &success);
            else if(status == GL_LINK_STATUS)
                glGetProgramiv(shader, status, &success);

            if(!success) {
                glGetShaderInfoLog(shader, 512, NULL, infoLog);
                printf("SHADER ERROR\n");
                printf(infoLog);
                printf("\n");
            }
            else {
                printf("Shader %d successful for status %d!\n", shader, status);
            }
        }

        unsigned int setupVertex() {
            //tag::setupvertex[]
            unsigned int vertexShader; //id of vertex shader
            vertexShader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
            glCompileShader(vertexShader);
            checkSuccess(vertexShader, GL_COMPILE_STATUS);
            return vertexShader;
            //end::setupvertex[]
        }

        unsigned int setupFragment() {
            unsigned int fragmentShader; //id of fragment shader
            fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
            glCompileShader(fragmentShader);
            checkSuccess(fragmentShader, GL_COMPILE_STATUS);
            return fragmentShader;
        }

        void Renderer::setupRenderer() {

            // tag::vertices[]
            float vertices[] = {
                -0.5f, -0.5f, 0.0f, //Bottom left
                 0.5f, -0.5f, 0.0f, //Bottom Right
                 0.0f,  0.5f, 0.0f //Top
            };
            // end::vertices[]

            // tag::vbo[]
            unsigned int VBO; //id of Vertex Buffer Object
            glGenBuffers(1, &VBO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO); //Set OpenGL's array buffer to our VBO

            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
            // end::vbo[]

            // tag::vao[]
            glGenVertexArrays(1, &VAO);  

            glBindVertexArray(VAO);
            // Set vertex attributes pointers
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
            // end::vao[]

            unsigned int vertexShader, fragmentShader; //IDs of the shaders
            vertexShader = setupVertex();
            fragmentShader = setupFragment();

            // tag::shaderprogram[]
            shaderProgram = glCreateProgram();

            glAttachShader(shaderProgram, vertexShader);
            glAttachShader(shaderProgram, fragmentShader);
            glLinkProgram(shaderProgram);
            checkSuccess(shaderProgram, GL_LINK_STATUS);

            glUseProgram(shaderProgram);
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);
            // end::shaderprogram[]
        }

        void Renderer::drawTriangle() {
            glUseProgram(shaderProgram);
            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES, 0, 3);
        }

    } // namespace Renderer
}
