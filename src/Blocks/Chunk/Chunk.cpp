#include "Chunk.h"

void Chunk::SetBlock(int id, int x, int y, int z) {
	blocks[x % 16][y % 16][z % 16] = (char)(id);
}