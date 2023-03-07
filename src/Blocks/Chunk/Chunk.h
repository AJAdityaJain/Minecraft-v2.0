#pragma once
#include "../Block/Block.h"


class Chunk {
public:
	int x = 0;
	int y = 0;
	int z = 0;

	Chunk(int X, int Y,int Z);
	char blocks[chunkSize][chunkSize][chunkSize];


	void Generate();
	void SetBlock(int id, int x, int y, int z);
	int GetBlock(int x, int y, int z);
};