#pragma once
#include "TutorialBase.h"

class Tutorial2 : public TutorialBase
{
public:
	Tutorial2();
	~Tutorial2();
	void init() override;
	void draw() override;
	void update() override;
	void onKeydown(GLFWwindow* aWindow) override;

private:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	unsigned int texture;
};