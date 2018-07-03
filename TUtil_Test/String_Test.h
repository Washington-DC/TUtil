#include "stdafx.h"

TEST(StringTest, test_01)
{
	std::wstring text_W = _T("�������������㲿����ĥ��δ�Ϲɣ�");
	std::wstring key_W = _T("ɣ");
	
	std::string text_A = ("�������������㲿����ĥ��δ�Ϲɣ�");
	std::string key_A = "ɣ";

	EXPECT_TRUE(text_W.find(key_W) == std::wstring::npos);
	EXPECT_TRUE(text_A.find(key_A) != std::string::npos);

	EXPECT_TRUE(wcsstr(text_W.c_str(), key_W.c_str()) == nullptr);
	EXPECT_TRUE(strstr(text_A.c_str(), key_A.c_str()) != nullptr);


}