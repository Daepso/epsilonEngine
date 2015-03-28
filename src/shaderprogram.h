#ifndef EPSILON_ENGINE_PROGRAMSHADER_H
#define EPSILON_ENGINE_PROGRAMSHADER_H

#include "shader.h"

class ShaderProgram {
public:
	ShaderProgram();
	void init();
	bool attachShader(Shader & s);
	bool link();
	bool activate() const;
	template<typename U> void sendUniform(const char * name, const U & uni); //Not implemented
	GLuint id() const;
	bool valid() const;
	void infoLog();
private:
	bool is_init_;
	bool is_valid_;
	GLuint id_;
};
#endif
