#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Renderer/ShaderProgram.h"
#include "Resources/ResourceManager.h"
#include "Renderer/Texture2D.h"

int g_WindowSizeX = 640;
int g_WindowSizeY = 480;

GLfloat point[] = {
     0.0f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f
};

GLfloat colors[] = {
     1.0f, 0.0f, 0.0f,
     0.0f, 1.0f, 0.0f,
     0.0f, 0.0f, 1.0f
};

GLfloat texCoord[] = {
     0.5f, 1.0f, 
     1.0f, 0.0f, 
     0.0f, 0.0f, 
};

void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height) {
    g_WindowSizeX = width;
    g_WindowSizeY = height;
    glViewport(0, 0, g_WindowSizeX, g_WindowSizeY);

}

void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}

int main(int argc, char** argv)
{
    /* Initialize the library */
    if (!glfwInit()) {
        std::cout << "glfwInit failed" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode pWindow and its OpenGL context */
    GLFWwindow* pWindow = glfwCreateWindow(g_WindowSizeX, g_WindowSizeY, "Battle City", NULL, NULL);
    if (!pWindow)
    {
        std::cout << "glfwCreateWindow failed!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);
    glfwSetKeyCallback(pWindow, glfwKeyCallback);
    /* Make the pWindow's context current */
    glfwMakeContextCurrent(pWindow);

    if (!gladLoadGL()) {
        std::cout << "Can't load GLAD!" << std::endl;
        return -1;
    }
    std::cout << "Renderer : " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version : " << glGetString(GL_VERSION) << std::endl;


    glClearColor(0, 1, 1, 1);

    
    {
        ResourceManager resourceManager(argv[0]);
        auto pDefaultShaderProgram = resourceManager.loadShaders("DefaultShader", "res/shaders/vertex.txt", "res/shaders/fragment.txt");
        if (!pDefaultShaderProgram) {
            std::cerr << "Can't create shader program: " << "DefaultShader " << std::endl;
            return -1;
        }

        auto tex = resourceManager.loadTexture("DefaultTexture", "res/textures/pngegg.png");
        
        GLuint points_vertex_buffer_object = 0;
        glGenBuffers(1, &points_vertex_buffer_object);
        glBindBuffer(GL_ARRAY_BUFFER, points_vertex_buffer_object);
        glBufferData(GL_ARRAY_BUFFER, sizeof(point), point, GL_STATIC_DRAW);

        GLuint colors_vertex_buffer_object = 0;
        glGenBuffers(1, &colors_vertex_buffer_object);
        glBindBuffer(GL_ARRAY_BUFFER, colors_vertex_buffer_object);
        glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

        GLuint texCoord_vertex_buffer_object = 0;
        glGenBuffers(1, &texCoord_vertex_buffer_object);
        glBindBuffer(GL_ARRAY_BUFFER, texCoord_vertex_buffer_object);
        glBufferData(GL_ARRAY_BUFFER, sizeof(texCoord), texCoord, GL_STATIC_DRAW);

        GLuint vertex_attribute_object = 0;
        glGenVertexArrays(1, &vertex_attribute_object);
        glBindVertexArray(vertex_attribute_object);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, points_vertex_buffer_object);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, colors_vertex_buffer_object);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

        glEnableVertexAttribArray(2);
        glBindBuffer(GL_ARRAY_BUFFER, texCoord_vertex_buffer_object);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

        pDefaultShaderProgram->use();
        pDefaultShaderProgram->setInt("tex", 0);

        /* Loop until the user closes the pWindow */
        while (!glfwWindowShouldClose(pWindow))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            pDefaultShaderProgram->use();
            glBindVertexArray(vertex_attribute_object);
            tex->bind();
            glDrawArrays(GL_TRIANGLES, 0, 3);

            /* Swap front and back buffers */
            glfwSwapBuffers(pWindow);

            /* Poll for and process events */
            glfwPollEvents();
        }
    }
    glfwTerminate();
    system("pause");
    return 0;
}

