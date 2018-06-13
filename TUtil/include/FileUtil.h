#pragma once
#include "Base.h"
#include <vector>
class DLL_EXPORT FileUtil
{
public:
	static std::string GetApplicationPath();
	static void GetAllFiles(std::string dirPath, std::string filter, std::vector<std::string>& fileList);
	
};

