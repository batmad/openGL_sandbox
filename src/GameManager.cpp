#include "GameManager.h"
#include "Shader.h"

#include "TutorialBase.h"
#include "Tutorial1.h"
#include "Tutorial2.h"
#include "Tutorial3.h"
#include "Tutorial4.h"


GameManager::GameManager()
{
	tutorial = new Tutorial4();
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
