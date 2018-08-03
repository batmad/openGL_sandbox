#pragma once
#include "TutorialBase.h"


class Tutorial_GL_REPEAT : public TutorialBase
{
public:
	Tutorial_GL_REPEAT();
	virtual ~Tutorial_GL_REPEAT();

	void init() override;
	void draw() override;
	void update() override;
	void onKeydown(GLFWwindow* aWindow) override;
private:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int texture;
};