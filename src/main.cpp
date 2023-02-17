#include"main.h"
#include "Graphics/Shaders/Shader.h"
#include "Graphics/Buffers/VAO.h"
#include "Graphics/Buffers/EBO.h"
#include "Graphics/Textures/Texture.h"
#include "Entity/Camera/Camera.h"
#include "Graphics/Models.h"


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
    va.LinkAttrib(vb, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
    va.LinkAttrib(vb, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));

    va.Unbind();
    vb.Unbind();
    eb.Unbind();

    GLuint Uniform1 = glGetUniformLocation(shader.ID, "scale");
    glUniform1f(Uniform1, 1.0f);

    Texture tex = Texture("C:\\Minecraft2\\Resources\\Textures\\Textures.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    tex.texUnit(shader, "tex0", 0); 
        
    tex.Bind();
    va.Bind();

    Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        camera.Inputs(window);
        camera.Matrix(45.0f, 0.1f, 100.0f, shader, "camMatrix");
        glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(GLuint), GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();

    }
    va.Delete();
    vb.Delete();
    eb.Delete();
    shader.Delete();
    tex.Delete();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

std::string readFile(const char* filename) {
    std::ifstream in(filename, std::ios::binary);
    if (in)
    {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();

        return(contents);
    }
    throw(errno);
}
