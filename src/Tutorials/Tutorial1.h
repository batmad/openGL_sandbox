#pragma once
#include "TutorialBase.h"

class Tutorial1 : public TutorialBase
{
public:
	Tutorial1();
	~Tutorial1();

	void init() override;
	void draw() override;
	void update() override;
	void onKeydown(GLFWwindow* aWindow) override;

private:
	float mix;
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	unsigned int texture1;
	unsigned int texture2;
};