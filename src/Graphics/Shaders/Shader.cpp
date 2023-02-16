#include "Shader.h"

std::string readFile(const char* filename){
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		
		return(contents);
	}
	throw(errno);
}

Shader::Shader(const char* verts, const  char* frags) {
	std::string tv = readFile(verts);
	const char* v = tv.c_str();
	
	std::string tf = readFile(frags);
	const char* f = tf.c_str();

	GLuint vert = glCreateShader(GL_VERTEX_SHADER); glShaderSource(vert, 1, &v, NULL); 
	GLuint frag = glCreateShader(GL_FRAGMENT_SHADER); glShaderSource(frag, 1, &f, NULL); 
	glCompileShader(vert);
	glCompileShader(frag);
	ID = glCreateProgram();
	glAttachShader(ID, vert);
	glAttachShader(ID, frag);
	
	glLinkProgram(ID);

	glDeleteShader(vert);
	glDeleteShader(frag);
}

void Shader::Bind() {
	glUseProgram(ID);
}

void Shader::Delete() {
	glDeleteShader(ID);
}
