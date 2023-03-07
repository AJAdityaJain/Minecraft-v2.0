#include "Mesh.h"
void Mesh::AddWorld(World* wo) {
	for (auto chunk: wo->chunks)
	{
		AddChunk(&chunk);
	}
}
void Mesh::AddChunk(Chunk* c) {
	const float k = (float)slotSize / getTexSize();
	for (size_t x = c->x*chunkSize; x < (c->x+1) *chunkSize; x++)
	{
		for (size_t y = c->y * chunkSize; y < (c->y + 1) * chunkSize; y++)
		{
			for (size_t z = c->z * chunkSize; z < (c->z + 1) * chunkSize; z++)
			{
				int b = GetBlockAbs(x, y, z);
				if (b > 0) {
					AddBlock(b, x, y, z,k);
				}
			}
		}
	}
}

void Mesh::AddBlock(int bid, int x, int y, int z, float k) {
	Block* b = GetBlock(bid);
	AddModel(b->m_global, x, y, z, k);
	if (GetBlockAbs(x + 1, y, z) == 0) {
		AddModel(b->m_right, x, y, z, k);
	}
	if (GetBlockAbs(x - 1, y, z) == 0) {
		AddModel(b->m_left, x, y, z, k);
	}
	if (GetBlockAbs(x, y + 1, z) == 0) {
		AddModel(b->m_top, x, y, z, k);
	}
	if (GetBlockAbs(x, y - 1, z) == 0) {
		AddModel(b->m_bottom, x, y, z, k);
	}
	if (GetBlockAbs(x, y, z+1) == 0) {
		AddModel(b->m_far, x, y, z, k);
	}
	if (GetBlockAbs(x, y, z-1) == 0) {
		AddModel(b->m_near, x, y, z, k);
	}
}

void Mesh::AddModel(TexModel m, int x, int y, int z, float k) {
	int uv = 0;
	int si = vertex.size() / 5;
	Model* model = GetModel(m.ID);
	std::vector<GLfloat> UVW = model->UV;
	for (size_t i = 0; i < model->Vertex.size(); i += 3)
	{
		vertex.push_back(model->Vertex[i] + x);
		vertex.push_back(model->Vertex[i + 1] + y);
		vertex.push_back(model->Vertex[i + 2] + z);
		if (UVW.size() > uv) {
			vertex.push_back(UVW[uv] + (m.x * k));
			uv++;
			vertex.push_back(UVW[uv] + (m.y * k));
			uv++;
		}
		else {
			vertex.push_back(0);
			uv++;
			vertex.push_back(0);
			uv++;
		}

	}

	for (GLuint m : model->Index) {
		index.push_back(m + si);
	}

}



void Mesh::Clear() {
	vertex.clear();
	index.clear();
	std::cout << "...Empty Mesh..." << std::endl;
}