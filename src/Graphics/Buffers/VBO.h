#pragma once

#include<glad/glad.h>
#include <vector>

class VBO
{
public:
	GLuint ID;
	VBO(std::vector<GLfloat> vertices);

	void Bind();
	void Unbind();
	void Delete();
};
