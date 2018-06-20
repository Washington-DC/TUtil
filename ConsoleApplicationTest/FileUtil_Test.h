#include "stdafx.h"
#include <vector>

TEST(FileUtil_Test, test_GetApplicationPath_01)
{
	OString strPath = FileUtil::GetApplicationPath();
	OString strParent = strPath.substr(strPath.length() - 3, 3);

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
	OString strFolder = FileUtil::GetFolder(FileUtil::GetApplicationPath());
	std::vector<OString> fileList;
	FileUtil::GetAllFiles(strFolder, _T("*"), fileList,false);
	EXPECT_EQ(fileList.size(), 4) << "size: " << fileList.size();
	EXPECT_STREQ(FileUtil::GetFileName(strFolder).c_str(),_T("TUtil"));
}

