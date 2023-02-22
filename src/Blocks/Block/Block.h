#pragma once
#include<vector>
#include <rapidjson/document.h>
#include "../../main.h"
#include "../../Graphics/Models/Models.h"
using namespace rapidjson;


class Block {
public:
	int model,x, y;
};
static std::vector<Block> blockDict = std::vector<Block>();

void LoadBlocks();

Block* GetBlock(int id);