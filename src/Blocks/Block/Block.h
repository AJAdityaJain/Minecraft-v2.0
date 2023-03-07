#pragma once
#include<vector>
#include <rapidjson/document.h>
#include "../../main.h"
#include "../../Graphics/Models/Models.h"
using namespace rapidjson;

struct TexModel {
	int ID;
	int x;
	int y;
};

class Block {
public:
	TexModel m_global, m_top, m_bottom, m_left, m_right, m_far, m_near;
};
static std::vector<Block> blockDict = std::vector<Block>();

TexModel GetModel(const char* name, const Value& obj);

void LoadBlocks();

Block* GetBlock(int id);