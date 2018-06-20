#include "stdafx.h"
#include "FileUtil.h"

#include <Shlwapi.h> 
#pragma comment(lib,"Shlwapi.lib")

OString DLL_EXPORT FileUtil::GetApplicationPath()
{
	OChar szPath[MAX_PATH] = {0};
	GetModuleFileName(nullptr, szPath, MAX_PATH);
	PathRemoveFileSpec(szPath);
	return OString(szPath);
}
//
//void FileUtil::GetAllFiles(OChar* dirPath, OChar* filter, std::vector<OChar*>& fileList, bool recursive)
//{
//	/*WIN32_FIND_DATA findFileData = { 0 };
//	int nLength = dirPath.length();
//	if (dirPath[nLength-1] != TEXT('\\'))
//	{
//		dirPath += TEXT('\\');
//	}
//	OString iFile = dirPath + filter;
//	HANDLE hHandle = FindFirstFile(iFile.c_str(), &findFileData);
//
//	if (hHandle!=INVALID_HANDLE_VALUE)
//	{
//		do
//		{
//			if (findFileData.cFileName == TEXT(".") || findFileData.cFileName == TEXT(".."))
//			{
//				continue;
//			}
//			else if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
//			{
//				GetAllFiles(dirPath, filter, fileList, recursive);
//			}
//			else
//			{
//				fileList.push_back(dirPath + findFileData.cFileName);
//			}
//		} while (FindNextFile(hHandle, &findFileData));
//	}*/
//}
//
//OChar* FileUtil::GetFileName(OChar* path)
//{
//	/*int iPos = path.find_last_of(TEXT('\\'));
//	return path.substr(iPos + 1, path.length() - iPos - 1);*/
//	return TEXT("");
//}
