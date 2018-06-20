#include "stdafx.h"
#include "FileUtil.h"

#include <Shlwapi.h> 
#pragma comment(lib,"Shlwapi.lib")

OString FileUtil::GetApplicationPath()
{
	OChar szPath[MAX_PATH] = { 0 };
	GetModuleFileName(nullptr, szPath, MAX_PATH);
	PathRemoveFileSpec(szPath);
	return OString(szPath);
}

void FileUtil::GetAllFiles(OString dirPath, OString filter, std::vector<OString>& fileList, bool recursive)
{
	WIN32_FIND_DATA findFileData = { 0 };
	int nLength = dirPath.length();
	if (dirPath[nLength - 1] != _T('\\'))
	{
		dirPath += _T('\\');
	}
	OString iFile = dirPath + filter;
	HANDLE hHandle = FindFirstFile(iFile.c_str(), &findFileData);

	if (hHandle != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (_tcscmp(findFileData.cFileName, _T(".")) != 0 && _tcscmp(findFileData.cFileName, _T("..")) != 0)
			{
				if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					if (recursive)
						GetAllFiles(dirPath, filter, fileList, recursive);
				}
				else
				{
					fileList.push_back(dirPath + findFileData.cFileName);
				}
			}
		} while (FindNextFile(hHandle, &findFileData));
	}
}

OString FileUtil::GetFileName(OString path)
{
	if (!path.empty())
	{
		int iPos = path.find_last_of(_T('\\'));
		if (iPos != OString::npos)
			return path.substr(iPos + 1, path.length() - iPos - 1);
	}
	return path;
}

OString FileUtil::GetFolder(OString path)
{
	if (!path.empty())
	{
		int iPos = path.find_last_of(_T('\\'));
		if (iPos != OString::npos)
			return path.substr(0, iPos);
	}
	return _T("");
}

