#pragma once
#include "Base.h"
#include <vector>

class DLL_EXPORT FileUtil
{
public:
	static OString GetApplicationPath();
	static void GetAllFiles(OString dirPath, OString filter, std::vector<OString>& fileList, bool recursive = true);
	static OString GetFileName(OString path);
	static OString GetFolder(OString path);
};

