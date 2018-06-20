// ConsoleApplicationTest.cpp : �������̨Ӧ�ó������ڵ㡣
//
#pragma once
#include "stdafx.h"

#include "CalcUtil_Test.h"
#include "FileUtil_Test.h"
#include "Other_Test.h"

//#include "BaseEnvironment.h"

int _tmain(int argc, _TCHAR* argv[])
{
	testing::GTEST_FLAG(output) = "xml:";
	testing::AddGlobalTestEnvironment(new BaseEnvironment);
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}

