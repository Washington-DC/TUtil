// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include <string>

#include "../TUtil/include/TUtil.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"


#ifdef _DEBUG
#pragma comment(lib,"../bin/TUtil_ud.lib")
#pragma comment(lib,"googletest/lib/gtestd.lib")
#pragma comment(lib,"googletest/lib/gmockd.lib")
#else
#pragma comment(lib,"../bin/TUtil_u.lib")
#pragma comment(lib,"googletest/lib/gtest.lib")
#pragma comment(lib,"googletest/lib/gmock.lib")
#endif // _DEBUG