#pragma once
#include "Base.h"
#include <vector>

#include <ShlObj.h>
#include <vector>
#include <windows.h>
#include <commdlg.h>

class DLL_EXPORT FileUtil
{
public:
	static TString GetApplicationPath();
	static void GetAllFiles(TString dirPath, TString filter, std::vector<TString>& fileList, bool recursive = true);
	static TString GetFileName(TString path);
	static TString GetFolder(TString path);

};

TString DLL_EXPORT OpenBrowserDialog(
	HWND hWnd = NULL,
	LPCTSTR lpszTitle = _T("浏览文件夹"),
	UINT uFlags = BIF_RETURNONLYFSDIRS | BIF_USENEWUI | BIF_UAHINT
	)
{
	TCHAR szPathName[MAX_PATH] = { 0 };
	BROWSEINFO bInfo = { 0 };
	bInfo.hwndOwner = hWnd;
	bInfo.lpszTitle = lpszTitle;
	bInfo.ulFlags = uFlags;

	LPITEMIDLIST lpDlist = NULL;
	lpDlist = SHBrowseForFolder(&bInfo);
	if (lpDlist != NULL)
	{
		SHGetPathFromIDList(lpDlist, szPathName);
	}
	return TString(szPathName);
}



TString DLL_EXPORT OpenFileDialog(
	BOOL bOpenMode = TRUE,
	LPCTSTR lpszTitle = _T("选择文件"),
	LPCTSTR lpszFilter = NULL,
	UINT uFlags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST
	)
{
	OPENFILENAME ofn;
	TCHAR szFielName[MAX_PATH] = { 0 };
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.lpstrTitle = lpszTitle;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrFilter = lpszFilter;
	ofn.nFilterIndex = 0;
	ofn.lpstrFile = szFielName;
	ofn.nMaxFile = sizeof(szFielName);
	ofn.Flags = uFlags;

	if (bOpenMode)
	{
		if (GetOpenFileName(&ofn))
		{
			return TString(szFielName);
		}
	}
	else
	{
		if (GetSaveFileName(&ofn))
		{
			return TString(szFielName);
		}
	}
	return _T("");
}


void DLL_EXPORT OpenBrowser(TString strFilePath)
{

}