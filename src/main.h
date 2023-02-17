#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

std::string readFile(const char* filename);

static int width = 1920;
static int height = 1000;

static const glm::vec3 X = glm::vec3(1.0f, 0.0f, 0.0f);
static const glm::vec3 Y = glm::vec3(0.0f, 1.0f, 0.0f);
static const glm::vec3 Z = glm::vec3(0.0f, 0.0f, 1.0f);

static const glm::vec3 Vec30 = glm::vec3(0, 0, 0);