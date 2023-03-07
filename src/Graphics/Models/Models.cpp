#include "Models.h"

void LoadModels() {
    struct dirent* diren = NULL;
    DIR* dir = opendir((ResDir + "Models").c_str());
    while ((diren = readdir(dir)) != NULL) {
        const char* v = diren->d_name;
        if (v[0] != '.') {
            LoadModel(readFile((ResDir + "Models\\" + v).c_str()));
        }
    }
    closedir(dir);
}

void LoadModel(std::string json) {
    if (json.length() > 0){
        Model face = Model();
        Document doc;doc.Parse(json.c_str());
    
        const Value& verts = doc["Vertex"]; assert(verts.IsArray());
        for (SizeType i = 0; i < verts.Size(); i++) {
            face.Vertex.push_back(verts[i].GetFloat());
        }        

        const Value& uv = doc["UV"]; assert(uv.IsArray());
        for (SizeType i = 0; i < uv.Size(); i++) {
            face.UV.push_back(uv[i].GetFloat()* (float)slotSize/ getTexSize());//tez
        }

        const Value& inds = doc["Index"]; assert(inds.IsArray());
        for (SizeType i = 0; i < inds.Size(); i++) {
            face.Index.push_back(inds[i].GetInt());
        }
        const Value& name = doc["Name"]; assert(name.IsString());
        face.Name = name.GetString();

        modelDict.push_back(face);
    }
}

Model* GetModel(int id) {
    return &modelDict[id];
}

int GetModel(std::string s) {
    for (int i = 0; i < modelDict.size(); i++) {
        if (modelDict[i].Name._Equal(s)) {
            return i;
        }
    }

    return -1;
}