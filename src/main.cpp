#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    
    GLFWwindow* window = glfwCreateWindow(1600, 800, "urmo", NULL, NULL);
    if (!window)
    {
        std::cout << "Welp... Window not working, glfwWindow not created\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        //glClear(GL_COLOR_BUFFER_BIT);

        //glBegin(GL_TRIANGLES);
        //glVertex2f(0, 0);
        //glVertex2f(0.3, 0.3);
        //glVertex2f(0.5, 1);
        //glEnd();

        //glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}