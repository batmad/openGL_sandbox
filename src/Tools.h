#pragma once
#include <string>

class Tools
{
public:
	static std::string getPath(const char* fileName);
	static void loadImage(const char* fileName, unsigned int &texture);
};