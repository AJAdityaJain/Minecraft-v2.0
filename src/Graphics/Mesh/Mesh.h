#pragma once
#include <vector>
#include "../../main.h"
#include "../Models/Models.h"
#include "../../Blocks/Block/Block.h"

class Mesh {
public:
	std::vector<GLfloat> vertex;
	std::vector<GLuint> index;
	
	void AddModel(int m);
	void Clear();
};