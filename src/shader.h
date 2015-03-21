#ifndef EPSILON_ENGINE_SHADER_H
#define EPSILON_ENGINE_SHADER_H

#include <GL/glew.h>
#include <GL/gl.h>

class Shader {
	public:
		Shader(GLuint shader_type);
		bool loadFromFile(const char * filename);
		bool loadFromSource(const char * src);
		GLuint id();
		bool valid();
		void infoLog();
	private:
		bool is_valid_;
		GLuint type_;
		GLuint id_;
};
#endif