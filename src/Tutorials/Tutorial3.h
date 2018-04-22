#pragma once
#include "TutorialBase.h"
class Tutorial3 : public TutorialBase
{
public:
	Tutorial3();
	~Tutorial3();

	void init() override;
	void draw() override;
	void update() override;
	void onKeydown(GLFWwindow* aWindow) override;

private:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int texture;
	float angle;
};