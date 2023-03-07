#pragma once
#include <vector>
#include "../Chunk/Chunk.h"

class World {
	public:
		std::vector<Chunk> chunks;
		void Generate();
		int Get(int x, int y, int z);
};