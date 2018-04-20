#pragma once
#include "Shader.h"

struct GLFWwindow;
class TutorialBase
{
public:
	TutorialBase() { shader = nullptr; };
	virtual ~TutorialBase() { delete shader; };

	virtual void init() = 0;
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void onKeydown(GLFWwindow* aWindow) = 0;

protected:
	Shader* shader;
};