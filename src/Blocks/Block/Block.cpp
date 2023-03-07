#include"Block.h"


void LoadBlocks() {
	std::string json = readFile((ResDir + "blocks.json").c_str());
	Document doc; doc.Parse(json.c_str());
	const Value& blocks = doc["blocks"]; assert(blocks.IsArray());

	for (SizeType i = 0; i < blocks.Size(); i++) {
		const Value& block = blocks[i]; assert(block.IsObject());
		const Value& model = block["model"]; assert(model.IsObject());
		
		Block b = Block();
		b.m_global = GetModel("global", model);
		b.m_bottom= GetModel("bottom", model);
		b.m_top = GetModel("top", model);
		b.m_far = GetModel("far", model);
		b.m_near = GetModel("near", model);
		b.m_left = GetModel("left", model);
		b.m_right = GetModel("right", model);

		blockDict.push_back(b);
	}
}

Block* GetBlock(int id) {
	return &blockDict[id];
}

TexModel GetModel(const char* name, const Value& obj){
	TexModel tm;
	if (obj.HasMember(name)) {
		const Value& uv = obj[name]["uv"]; assert(uv.IsArray());
		tm.x = uv[0].GetInt();
		tm.y = uv[1].GetInt();
		tm.ID = GetModel(obj[name]["name"].GetString());
		return tm;
	}
	tm.ID = 0;
	tm.x = 0;
	tm.y = 0;
	return tm;
}
//const Value& global = model["global"]; assert(global.IsObject);
//const Value& gname = ; assert(gname.IsString);