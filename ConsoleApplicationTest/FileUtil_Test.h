#include "stdafx.h"

TEST(FileUtil_Test, test_GetApplicationPath_01)
{
	OString strPath = FileUtil::GetApplicationPath();
	OString strParent = strPath.substr(strPath.length() - 3, 3);

	EXPECT_STRNE(strPath.c_str(), _T(""));
	EXPECT_STREQ(strParent.c_str(), _T("bin"));
}