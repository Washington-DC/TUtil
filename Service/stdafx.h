// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�

// Windows ͷ�ļ�: 
#include <windows.h>

// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include <string>
#include <iostream>

#include "../TUtil/include/TUtil.h"

#ifdef _DEBUG
#pragma comment(lib,"../bin/TUtil_ud.lib")
#else
#pragma comment(lib,"../bin/TUtil_u.lib")
#endif // _DEBUG