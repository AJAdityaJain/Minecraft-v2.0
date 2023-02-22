#pragma once
#include "../Block/Block.h"


class Chunk {
public:
	char blocks[chunkSize][chunkSize][chunkSize];
	void SetBlock(int id, int x, int y, int z);
};