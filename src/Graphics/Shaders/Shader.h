#pragma once

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

std::string readFile(const char* filename);

class Shader {
public:
	GLuint ID;
	Shader(const char* vert, const  char* frag);
	void Bind();
	void Delete();
};
