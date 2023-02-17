#include "Shader.h"

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
