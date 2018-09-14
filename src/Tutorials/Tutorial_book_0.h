#pragma once
#include "TutorialBase.h"


class Tutorial_book_0 : public TutorialBase
{
public:
	Tutorial_book_0();
	virtual ~Tutorial_book_0();

	void init() override;
	void draw() override;
	void update() override;
	void onKeydown(GLFWwindow* aWindow) override;
private:
	void drawPrimitiveWithoutVBOs(GLfloat* vertices, GLint vtxStride, GLint numIndices, GLushort* indices);
	void drawPrimitiveWithVBOs(GLint numVertices, GLfloat* vtxBuf, GLint vtxStride, GLint numIndices, GLushort* indices);
	unsigned int VAO;
	unsigned int VBO[2];	
	unsigned int texture;
	GLuint offsetLoc;
};