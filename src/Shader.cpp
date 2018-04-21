#include "Shader.h"
#include "Tools.h"
#include <glm\gtc\type_ptr.hpp>

Shader::Shader(const GLchar * vertexPath, const GLchar * fragmentPath)
{
	GLint vertex = compile(load(Tools::getPath(vertexPath)), GL_VERTEX_SHADER);
	GLint fragment = compile(load(Tools::getPath(fragmentPath)), GL_FRAGMENT_SHADER);

	// shader Program
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);

	int success;
	char infoLog[512];
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

std::string Shader::load(std::string path)
{
	std::string code;
	std::ifstream file;
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);	
	try
	{
		file.open(path);		
		std::stringstream stream;
		stream << file.rdbuf();		
		file.close();		
		code = stream.str();		
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	return code;
}

int Shader::compile(std::string code, GLint type)
{
	const char* codeStr = code.c_str();
	unsigned int shaderId;
	shaderId = glCreateShader(type);
	glShaderSource(shaderId, 1, &codeStr, NULL);
	glCompileShader(shaderId);

	int success;	
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT2::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	return shaderId;
}


void Shader::use()
{
	glUseProgram(ID);
}

void Shader::setBool(const std::string & name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string & name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string & name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setMat4(const std::string &name, glm::mat4 value) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}
