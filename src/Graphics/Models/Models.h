#pragma once
#include "../../main.h"
#include <dirent/dirent.h>
#include <rapidjson/document.h>
#include <vector>

extern int texSize;

using namespace rapidjson;

class Model {
public:
	std::string Name;
	std::vector<GLfloat> Vertex;
	std::vector<GLfloat> UV;
	std::vector<GLuint> Index;
};
static std::vector<Model> modelDict = std::vector<Model>();


Model* GetModel(int id);
int GetModel(std::string s);
void LoadModels();
void LoadModel(std::string json);