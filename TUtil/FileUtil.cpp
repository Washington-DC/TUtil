#include "stdafx.h"
#include "FileUtil.h"

#include <Shlwapi.h> 
#pragma comment(lib,"Shlwapi.lib")

std::string FileUtil::GetApplicationPath()
{
	char szPath[MAX_PATH] = { 0 };
	GetModuleFileNameA(nullptr, szPath, MAX_PATH);
	PathRemoveFileSpecA(szPath);
	return std::string(szPath);
}

void FileUtil::GetAllFiles(std::string dirPath,std::string filter, std::vector<std::string>& fileList)
{
	WIN32_FIND_DATA fd = { 0 };
}
