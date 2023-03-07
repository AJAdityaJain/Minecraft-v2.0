#include "Chunk.h"

void Chunk::SetBlock(int id, int x, int y, int z) {
	blocks[x][y][z] = (char)(id);
}
int Chunk::GetBlock(int x, int y, int z) {

	return (int)blocks[x % 16][y % 16][z % 16];
}
Chunk::Chunk(int X, int Y, int Z) {
	x = X; y = Y; z = Z;
	for (size_t x1 = 0; x1 < chunkSize; x1++)
	{
		for (size_t y1 = 0; y1 < chunkSize; y1++)
		{
			for (size_t z1 = 0; z1 < chunkSize; z1++)
			{
				SetBlock(0, x1, y1, z1);
			}
		}
	}
}

void Chunk::Generate() {
	for (size_t i = 0; i < chunkSize; i++)
	{
		for (size_t j = 0; j < chunkSize; j++)
		{
			SetBlock(4, i, 0, j);
	//		SetBlock(3, i, 1, j);
	//		SetBlock(3, i, 2, j);
	//		if (rand() % 2 == 0){
	//			SetBlock(3, i, 3, j);
	//			SetBlock(2, i, 4, j);
	//			SetBlock(1, i, 5, j);
	//		}
	//		else {
	//			SetBlock(2, i, 3, j);
	//			SetBlock(1, i, 4, j);

	//		}
		}
	}

	SetBlock(2, 8, 6, 9);
	SetBlock(2, 7, 7, 9);
	SetBlock(2, 8, 7, 9);
	SetBlock(2, 7, 6, 9);

	SetBlock(2, 8, 5, 8);
	SetBlock(2, 7, 5, 8);
	SetBlock(2, 8, 5, 7);
	SetBlock(2, 7, 5, 7);

	SetBlock(2, 6, 6, 8);
	SetBlock(2, 6, 7, 8);
	SetBlock(2, 6, 6, 7);
	SetBlock(2, 6, 7, 7);

}
