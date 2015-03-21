#include "shader.h"

#include <fstream>
#include <iostream>

Shader::Shader(GLuint shader_type) 
	:is_valid_(false), type_(shader_type), id_(-1)
{
}

bool Shader::loadFromFile(const char * filename) {
	std::ifstream file(filename,std::ios::in);

	if(!file) {
		std::cerr << "File not found " << filename << std::endl;
        return false;
	}

	file.seekg( 0, std::ios::end );
	std::streampos fsize = file.tellg();
	char * src = new char[fsize];
	file.read(src,fsize);
	bool res = loadFromSource(src);
	delete[] src;
	return res;
}

bool Shader::loadFromSource(const char * src) {
    id_ = glCreateShader(type_);
    const GLchar * arbSource = src;

    glShaderSource(id_, 1, (const GLchar **)&arbSource, 0);
    glCompileShader(id_);

    GLint compiled;
    glGetShaderiv(id_,GL_COMPILE_STATUS,&compiled);
   	infoLog();
    return compiled == GL_TRUE;
}


GLuint Shader::id() {
	return id_;
}

bool Shader::valid() {
	return is_valid_;
}


void Shader::infoLog() {
	int logLength = 0, written = 0;
	glGetShaderiv(id_,GL_INFO_LOG_LENGTH, &logLength);
	if(logLength > 0) {
		GLchar * log = new GLchar[logLength];
		glGetShaderInfoLog(id_, logLength, &written, log);
		if (written>0)
			std::cerr << "Shader info : \n" << log << std::endl;
		delete[] log;
	}
}