#include "stdafx.h"

TEST(StringTest, test_01)
{
	std::wstring text_W = _T("补偿绳与其它零部件互磨（未断股）");
	std::wstring key_W = _T("桑");
	
	std::string text_A = ("补偿绳与其它零部件互磨（未断股）");
	std::string key_A = "桑";

	EXPECT_TRUE(text_W.find(key_W) == std::wstring::npos);
	EXPECT_TRUE(text_A.find(key_A) != std::string::npos);

	EXPECT_TRUE(wcsstr(text_W.c_str(), key_W.c_str()) == nullptr);
	EXPECT_TRUE(strstr(text_A.c_str(), key_A.c_str()) != nullptr);


}