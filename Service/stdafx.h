// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO:  在此处引用程序需要的其他头文件

// Windows 头文件: 
#include <windows.h>

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

// TODO:  在此处引用程序需要的其他头文件
#include <string>
#include <iostream>

#include "../TUtil/include/TUtil.h"

#ifdef _DEBUG
#pragma comment(lib,"../bin/TUtil_ud.lib")
#else
#pragma comment(lib,"../bin/TUtil_u.lib")
#endif // _DEBUG