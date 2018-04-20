#include "GameManager.h"
#include "Shader.h"

#include "TutorialBase.h"
#include "Tutorial1.h"


GameManager::GameManager()
{
	tutorial = new Tutorial1();
}

GameManager::~GameManager()
{
	delete tutorial;	
}

void GameManager::init()
{
	tutorial->init();
}

void GameManager::draw()
{
	tutorial->draw();
}

void GameManager::update()
{
	tutorial->draw();
}

void GameManager::onKeydown(GLFWwindow * aWindow)
{
	tutorial->onKeydown(aWindow);
}
