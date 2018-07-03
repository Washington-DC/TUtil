#include "stdafx.h"
#include <vector>

TEST(FileUtil_Test, test_GetApplicationPath_01)
{
	TString strPath = FileUtil::GetApplicationPath();
	TString strParent = strPath.substr(strPath.length() - 3, 3);

	EXPECT_STRNE(strPath.c_str(), _T(""));
	EXPECT_STREQ(strParent.c_str(), _T("bin"));
}

TEST(FileUtil_Test, test_GetFileName_01)
{
	EXPECT_STREQ(FileUtil::GetFileName(_T("1\\2\\3\\4")).c_str(),	_T("4"));
	EXPECT_STREQ(FileUtil::GetFileName(_T("1\\2\\3\\")).c_str(),	_T(""));
	EXPECT_STREQ(FileUtil::GetFileName(_T("1\\")).c_str(),			_T(""));
	EXPECT_STREQ(FileUtil::GetFileName(_T("1")).c_str(),			_T("1"));
}

TEST(FileUtil_Test, test_GetFolder_01)
{
	EXPECT_STREQ(FileUtil::GetFolder(_T("1\\2\\3\\4")).c_str(),		_T("1\\2\\3"));
	EXPECT_STREQ(FileUtil::GetFolder(_T("1\\2\\3\\")).c_str(),		_T("1\\2\\3"));
	EXPECT_STREQ(FileUtil::GetFolder(_T("1\\")).c_str(),			_T("1"));
	EXPECT_STREQ(FileUtil::GetFolder(_T("1")).c_str(),				_T(""));
}

TEST(FileUtil_Test, test_GetAllFiles_01)
{
	TString strFolder = FileUtil::GetFolder(FileUtil::GetApplicationPath());
	std::vector<TString> fileList;
	FileUtil::GetAllFiles(strFolder, _T("*"), fileList,false);
	EXPECT_EQ(fileList.size(), 4) << _T("____ actual size ____: ") << fileList.size();
	EXPECT_STREQ(FileUtil::GetFileName(strFolder).c_str(),_T("TUtil"));
}


TEST(FileUtil_Test, test_OpenFileDialog_01)
{
	TString strFile = FileUtil::OpenFileDialog(TRUE,_T("���ļ�"), _T("�ı��ļ�(*.txt)\0*.txt\0\0"));
	EXPECT_NE(_tcscmp(strFile.c_str(),_T("")),0) << _T("___file___:") << strFile ;
}



