#include"Block.h"

using namespace std;
void LoadBlocks() {
	std::string json = readFile((ResDir + "blocks.json").c_str());
	Document doc; doc.Parse(json.c_str());
	const Value& blocks = doc["blocks"]; assert(blocks.IsArray());

	for (SizeType i = 0; i < blocks.Size(); i++) {
		const Value& block = blocks[i]; assert(blocks.IsObject());
		const Value& model = block["model"]; assert(name.IsString());
		const Value& textures = block["uv"]; assert(name.IsArray());
		Block b = Block();
		b.model = GetModel(model.GetString());
		b.x = textures[0].GetInt();
		b.y = textures[1].GetInt();
		blockDict.push_back(b);
	}
}

Block* GetBlock(int id) {
	return &blockDict[id];
}