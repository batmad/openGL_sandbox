#pragma once

struct GLFWwindow;
class Shader;
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
	float mix;
	Shader* shader;
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	unsigned int texture1;
	unsigned int texture2;
};
