#pragma once
#pragma once
#include "TutorialBase.h"


class Tutorial4 : public TutorialBase
{
public:
	Tutorial4();
	virtual ~Tutorial4();

	void init() override;
	void draw() override;
	void update() override;
	void onKeydown(GLFWwindow* aWindow) override;
private:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int texture;
};