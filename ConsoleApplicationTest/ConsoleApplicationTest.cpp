// ConsoleApplicationTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <string>

#include "..\TUtil\include\TUtil.h"
#pragma comment(lib,"..\\bin\\TUtil_d.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << CalcUtil::Add(1, 2) << std::endl;

	std::cout << FileUtil::GetApplicationPath() << std::endl;

	return 0;
}

