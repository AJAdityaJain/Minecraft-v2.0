#include "Mesh.h"

void Mesh::AddModel(int m) {
	int si = vertex.size()/5;
	std::cout << si << "el\n";
	int uv = 0;
	int w = 0;
	float k = (float)slotSize / getTexSize();
	Block* b = GetBlock(m);
	Model* model = GetModel(b->model);
	std::vector<GLfloat> UVW = model->UV;
	for (auto m : model->Vertex) {
		vertex.push_back(m);
		w++;
		if (w == 3) {
			if (UVW.size() > uv) {
				vertex.push_back(UVW[uv] + (b->x * k));
				uv++;
				vertex.push_back(UVW[uv] + (b->y * k));
				uv++;
			}
			else {
				vertex.push_back(0);
				uv++;
				vertex.push_back(0);
				uv++;
			}
			w = 0;
		}
	}

	for (auto m : model->Index) {
		index.push_back(m + si);
	}
}

void Mesh::Clear() {
	vertex.clear();
	index.clear();
	std::cout << "...Empty Mesh..." << std::endl;
}