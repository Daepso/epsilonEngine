#include "shaderprogram.h"

#include <assert.h>
#include <iostream>

ShaderProgram::ShaderProgram() 
:is_valid_(false), id_(-1)
{
	id_ = glCreateProgram();
}

bool ShaderProgram::attachShader(Shader & s) {
	glAttachShader(id_,s.id());
}

bool ShaderProgram::link() {
	glLinkProgram(id_);

	GLint is_linked;
	glGetProgramiv(id_, GL_LINK_STATUS, &is_linked);
	infoLog();
	is_valid_ = is_linked == GL_TRUE;
	return is_valid_;
}

bool ShaderProgram::activate() const{
	assert(is_valid_);
	glUseProgram(id_);
}

template<typename U>
void ShaderProgram::sendUniform(const char * name, const U & uni) {

}

GLuint ShaderProgram::id() const {
	return id_;
}

bool ShaderProgram::valid() const {
	return is_valid_;
}


void ShaderProgram::infoLog() {
	int logLength = 0, written = 0;
	glGetShaderiv(id_,GL_INFO_LOG_LENGTH, &logLength);
	if(logLength > 0) {
		GLchar * log = new GLchar[logLength];
		glGetShaderInfoLog(id_, logLength, &written, log);
		if (written>0)
			std::cerr << "Program info : \n" << log << std::endl;
		delete[] log;
	}
}