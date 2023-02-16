#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Graphics/Shaders/Shader.h"
#include "Graphics/Buffers/VAO.h"
#include "Graphics/Buffers/EBO.h"

int width = 1600;
int height = 800;

GLfloat vertices[] = {
    -0.51, -0.81 ,0 ,
    -0.41, 0.41 ,0,
    .41, -0.41, 0,
    .41,.41,0
};

GLuint indices[] = {
     0,1,2,
     1,2,3
};


int main()
{
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
     
    GLFWwindow* window = glfwCreateWindow(width, height, "urmo", NULL, NULL);
    if (!window)
    {
        std::cout << "Welp... Window not working, glfwWindow not created" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL();
    glViewport(0,0,width,height);

    Shader shader = Shader("src\\Graphics\\Shaders\\vert.gls", "src\\Graphics\\Shaders\\frag.gls");   
    shader.Bind();

    
    VAO va;va.Bind();
    VBO vb(vertices, sizeof(vertices));
    EBO eb(indices, sizeof(indices));
    va.LinkVBO(vb, 0);
    
    va.Unbind();
    vb.Unbind();
    eb.Unbind();

    
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        va.Bind();
        glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(GLuint), GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    va.Delete();
    vb.Delete();
    eb.Delete();
    shader.Delete();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}