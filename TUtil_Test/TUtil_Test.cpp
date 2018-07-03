// ConsoleApplicationTest.cpp : 定义控制台应用程序的入口点。
//
#pragma once
#include "stdafx.h"

#include "CalcUtil_Test.h"
#include "FileUtil_Test.h"
#include "Other_Test.h"
#include "String_Test.h"

//#include "BaseEnvironment.h"

int _tmain(int argc, _TCHAR* argv[])
{
	testing::GTEST_FLAG(output) = "xml:";
	testing::AddGlobalTestEnvironment(new BaseEnvironment);
	testing::InitGoogleTest(&argc, argv);
	testing::InitGoogleMock(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}

