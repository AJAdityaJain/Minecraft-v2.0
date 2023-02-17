#pragma once

#include "../../main.h"

class Shader {
public:
	GLuint ID;
	Shader(const char* vert, const  char* frag);
	void Bind();
	void Delete();
};
