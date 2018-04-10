#include "Tools.h"
#include <Windows.h>

std::string Tools::getPath(const char * fileName)
{
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	std::string path = std::string(buffer).substr(0, pos + 1);
	return path + fileName;
}
