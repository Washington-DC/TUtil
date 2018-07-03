#include "stdafx.h"
#include "FileUtil.h"

#include <Shlwapi.h> 
#pragma comment(lib,"Shlwapi.lib")

TString FileUtil::GetApplicationPath()
{
	TCHAR szPath[MAX_PATH] = { 0 };
	GetModuleFileName(nullptr, szPath, MAX_PATH);
	PathRemoveFileSpec(szPath);
	return TString(szPath);
}

//********************************************************************     
// ����˵����	�����ļ����µ������ļ�     
// ���ߣ�	yszs     
// ʱ�䣺	2018/07/02 11:21     
// ����ֵ:  	void     
// ����: 	OString dirPath    �ļ������� 
// ����: 	OString filter     ������
// ����: 	std::vector<OString> & fileList     
// ����: 	bool recursive     �Ƿ�������ļ���
//******************************************************************** 
void FileUtil::GetAllFiles(TString dirPath, TString filter, std::vector<TString>& fileList, bool recursive)
{
	WIN32_FIND_DATA findFileData = { 0 };
	int nLength = dirPath.length();
	if (dirPath[nLength - 1] != _T('\\'))
	{
		dirPath += _T('\\');
	}
	TString iFile = dirPath + filter;
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

TString FileUtil::GetFileName(TString path)
{
	if (!path.empty())
	{
		int iPos = path.find_last_of(_T('\\'));
		if (iPos != TString::npos)
			return path.substr(iPos + 1, path.length() - iPos - 1);
	}
	return path;
}

TString FileUtil::GetFolder(TString path)
{
	if (!path.empty())
	{
		int iPos = path.find_last_of(_T('\\'));
		if (iPos != TString::npos)
			return path.substr(0, iPos);
	}
	return _T("");
}



