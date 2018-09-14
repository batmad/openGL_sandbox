#include "Tutorial_book_0.h"
#include "Tools.h"

#define VERTEX_POS_SIZE 3 //x,y,z
#define VERTEX_COLOR_SIZE 4 //r,g,b,a
#define VERTEX_POS_INDX 0
#define VERTEX_COLOR_INDX 1


Tutorial_book_0::Tutorial_book_0()
{
	shader = new Shader("shaders/shader_book_0.vs", "shaders/shader_book_0.fs");
}

Tutorial_book_0::~Tutorial_book_0()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(2, VBO);
}

void Tutorial_book_0::init()
{
	offsetLoc = glGetUniformLocation(shader->ID, "u_offset");
	Tools::loadImage("container.jpg", texture);
	VBO[0] = 0;
	VBO[1] = 0;
}

void Tutorial_book_0::draw()
{
	GLfloat vertices[3 * (VERTEX_POS_SIZE + VERTEX_COLOR_SIZE)] = 
 	{   //vertex			  //color
		-0.5f, 0.5f, 0.0f,    1.0f, 0.0f, 0.0f, 1.0f,
		-1.0f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, -0.5f, 0.0f,    0.0f, 0.0f, 1.0f, 1.0f
	};

	GLushort indices[3] = { 0,1,2 };

	shader->use();
	glUniform1f(offsetLoc, 0.0f);
	drawPrimitiveWithoutVBOs(vertices, sizeof(GLfloat) * (VERTEX_POS_SIZE + VERTEX_COLOR_SIZE), 3, indices);
	glUniform1f(offsetLoc, 1.0f);
	drawPrimitiveWithVBOs(3, vertices, sizeof(GLfloat) * (VERTEX_POS_SIZE + VERTEX_COLOR_SIZE), 3, indices);
}


void Tutorial_book_0::drawPrimitiveWithoutVBOs(GLfloat * vertices, GLint vtxStride, GLint numIndices, GLushort * indices)
{
	GLfloat* vtxBuf = vertices;
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glEnableVertexAttribArray(VERTEX_POS_INDX);
	glEnableVertexAttribArray(VERTEX_COLOR_INDX);

	glVertexAttribPointer(VERTEX_POS_INDX, VERTEX_POS_SIZE, GL_FLOAT, GL_FALSE, vtxStride, vtxBuf);
	vtxBuf += VERTEX_POS_SIZE;

	glVertexAttribPointer(VERTEX_COLOR_INDX, VERTEX_COLOR_SIZE, GL_FLOAT, GL_FALSE, vtxStride, vtxBuf);
	glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, indices);

	glDisableVertexAttribArray(VERTEX_POS_INDX);
	glDisableVertexAttribArray(VERTEX_COLOR_INDX);
}

void Tutorial_book_0::drawPrimitiveWithVBOs(GLint numVertices, GLfloat * vtxBuf, GLint vtxStride, GLint numIndices, GLushort * indices)
{
	GLuint offset = 0;
	if (VBO[0] == 0 && VBO[1] == 0)
	{
		glGenBuffers(2, VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
		glBufferData(GL_ARRAY_BUFFER, vtxStride * numVertices, vtxBuf, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO[1]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort) * numVertices, indices, GL_STATIC_DRAW);
	}

	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO[1]);

	glEnableVertexAttribArray(VERTEX_POS_INDX);
	glEnableVertexAttribArray(VERTEX_COLOR_INDX);

	glVertexAttribPointer(VERTEX_POS_INDX, VERTEX_POS_SIZE, GL_FLOAT, GL_FALSE, vtxStride, (const void*)offset);

	offset += VERTEX_POS_SIZE * sizeof(GLfloat);
	glVertexAttribPointer(VERTEX_COLOR_INDX, VERTEX_COLOR_SIZE, GL_FLOAT, GL_FALSE, vtxStride, (const void*)offset);

	glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, 0);

	glDisableVertexAttribArray(VERTEX_POS_INDX);
	glDisableVertexAttribArray(VERTEX_COLOR_INDX);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


void Tutorial_book_0::update()
{
}

void Tutorial_book_0::onKeydown(GLFWwindow * aWindow)
{
}