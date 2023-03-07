#include "World.h"

void World::Generate() {
	Chunk ch = Chunk(0, 0, 0); ch.Generate();
	chunks.push_back(ch);
}

int World::Get(int x, int y, int z){
	if (x < 0 || y < 0 || z < 0) 
		return 1;
	
	for (Chunk ch : chunks) {
		if (ch.x == floorf(x / chunkSize) && ch.y == floorf(y / chunkSize) && ch.z == floorf(z / chunkSize)) {
			return ch.blocks[x % chunkSize][y % chunkSize][z % chunkSize];
		}
	}
	return 1;
}