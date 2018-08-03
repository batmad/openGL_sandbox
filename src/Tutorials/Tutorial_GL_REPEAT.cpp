#include "Tutorial_GL_REPEAT.h"
#include "Tools.h"

Tutorial_GL_REPEAT::Tutorial_GL_REPEAT()
{
	shader = new Shader("shaders/shader_GL_REPEAT.vs", "shaders/shader_GL_REPEAT.fs");
}

Tutorial_GL_REPEAT::~Tutorial_GL_REPEAT()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Tutorial_GL_REPEAT::init()
{
	Tools::loadImage("container.jpg", texture);

	shader->use();
	shader->setInt("ourTexture", 0);

	float vertices[] =
	{	//vertices				//texture
	    -1.0f, -1.0f, 0.0f,		0.0f, 0.0f,
	    -1.0f,  1.0f, 0.0f,		0.0f, 5.0f,
		 1.0f,  1.0f, 0.0f,		2.5f, 5.0f,

		-1.0f, -1.0f, 0.0f,		0.0f, 0.0f,
		 1.0f,  1.0f, 0.0f,		2.5f, 5.0f,
		 1.0f, -1.0f, 0.0f,		2.5f, 0.0f
	};
	
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void Tutorial_GL_REPEAT::draw()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Tutorial_GL_REPEAT::update()
{
}

void Tutorial_GL_REPEAT::onKeydown(GLFWwindow * aWindow)
{
}
