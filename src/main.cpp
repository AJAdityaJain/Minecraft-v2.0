#include "main.h"
#include "Graphics/Shaders/Shader.h"
#include "Graphics/Buffers/VAO.h"
#include "Graphics/Buffers/EBO.h"
#include "Graphics/Textures/Texture.h"
#include "Entity/Camera/Camera.h"
#include "Graphics/Mesh/Mesh.h"
#include "Blocks/Chunk/Chunk.h"

int getTexSize() {
    return texSize;
}
int main()
{
    GLFWwindow* window; if (createWindow(window) != 0) { return -1; }
    VAO va; 


    va.Bind();
        Shader shader = Shader((ShaderDir + "vert.gls").c_str(), (ShaderDir + "frag.gls").c_str()); shader.Bind();
        Texture tex = Texture((ResDir + "Textures\\Textures.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
        texSize = tex.size;
        tex.texUnit(shader, "tex0", 0); tex.Bind();    
    va.Unbind();

    std::cout << texSize << "px\n";
    LoadModels();
    std::cout << texSize << "px\n";
    LoadBlocks();

    Mesh mesh;
    mesh.AddModel(0);

    va.Bind();
        VBO vb(mesh.vertex); vb.Bind();
        EBO eb(mesh.index); eb.Bind();

        va.LinkAttrib(vb, 0, 3, GL_FLOAT, 5 * sizeof(GLfloat), (void*)0);
        va.LinkAttrib(vb, 1, 2, GL_FLOAT, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

    va.Unbind();
    vb.Unbind();eb.Unbind();
    va.Bind();

    
    Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));
    

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        camera.Inputs(window);
        camera.Matrix(45.0f, 0.1f, 100.0f, shader, "camMatrix");
        glDrawElements(GL_TRIANGLES, mesh.index.size(), GL_UNSIGNED_INT, 0);
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

    return "";
}

int createWindow(GLFWwindow*& window){
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, "urmo", NULL, NULL);
    if (!window)
    {
        std::cout << "Welp... Window not working, glfwWindow not created" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL();
    glViewport(0, 0, width, height);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    return 0;
}