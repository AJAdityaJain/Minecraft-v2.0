#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<fstream>
#include<sstream>
#include<iostream>



std::string readFile(const char* filename);
int getTexSize();

static int texSize;


static const int width = 1920;
static const int height = 1000;

static const int slotSize = 16;

static const int chunkSize = 16;

static const std::string ShaderDir = "src\\Graphics\\Shaders\\";
static const std::string ResDir = "C:\\Minecraft2\\Resources\\";

static const glm::vec3 X = glm::vec3(1.0f, 0.0f, 0.0f);
static const glm::vec3 Y = glm::vec3(0.0f, 1.0f, 0.0f);
static const glm::vec3 Z = glm::vec3(0.0f, 0.0f, 1.0f);

//static const glm::vec3 Vec30 = glm::vec3(0, 0, 0);

int createWindow(GLFWwindow*& window);