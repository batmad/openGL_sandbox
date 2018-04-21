#include "Tutorial1.h"
#include "Shader.h"
#include "Tools.h"
#include <GLFW\glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Tutorial1::Tutorial1()
{
	shader = new Shader("shaders/shader1.vs", "shaders/shader1.fs");
}

Tutorial1::~Tutorial1()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Tutorial1::init()
{
	Tools::loadImage("container.jpg", texture1);
	Tools::loadImage("awesomeface.png", texture2);

	shader->use();
	glUniform1i(glGetUniformLocation(shader->ID, "texture1"), 0);
	shader->setInt("texture2", 1);

	float vertices[] = {
		//vertices			  //color				//texture
		0.5f, -0.5f, 0.0f,    1.0f, 0.0f, 0.0f,   2.0f, 0.0f,
		-0.5f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,   0.0f, 0.0f,
		0.0f,  0.5f, 0.0f,    0.0f, 0.0f, 1.0f,   1.0f, 2.0f
	};

	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glm::mat4 trans;
	trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
	unsigned int transformLoc = glGetUniformLocation(shader->ID, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
}

void Tutorial1::draw()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2);

	glm::mat4 trans;
	trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
	trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
	unsigned int transformLoc = glGetUniformLocation(shader->ID, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	trans = glm::mat4();
	trans = glm::translate(trans, glm::vec3(-0.5f, 0.5f, 0.0f));
	float scaleAmount = sin(glfwGetTime());
	trans = glm::scale(trans, glm::vec3(scaleAmount, scaleAmount, scaleAmount));
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, &trans[0][0]);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Tutorial1::update()
{
	float timer = glfwGetTime();
	float x = sin(timer) / 2 + 0.5f;
	shader->setFloat("offset", x);
	shader->setFloat("ourMix", mix);
}

void Tutorial1::onKeydown(GLFWwindow * aWindow)
{
	if (glfwGetKey(aWindow, GLFW_KEY_UP) == GLFW_PRESS)
	{
		mix += 0.01f;
	}
	else if (glfwGetKey(aWindow, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		mix -= 0.01f;
	}
}
