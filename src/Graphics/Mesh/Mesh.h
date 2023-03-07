#pragma once
#include <vector>
#include "../../main.h"
#include "../../Blocks/World/World.h"

class Mesh {
public:
	std::vector<GLfloat> vertex;
	std::vector<GLuint> index;

	void AddWorld(World* c);
	void AddChunk(Chunk* c);
	void AddBlock(int m, int x, int y, int z, float k);
	void AddModel(TexModel m, int x, int y, int z, float k);
	void Clear();
};