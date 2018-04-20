#pragma once

struct GLFWwindow;
class Shader;
class TutorialBase;
class GameManager
{
public:
	GameManager();
	~GameManager();
	void init();
	void draw();
	void update();
	void onKeydown(GLFWwindow* aWindow);

private:
	TutorialBase* tutorial;
};
