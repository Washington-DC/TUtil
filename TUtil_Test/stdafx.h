// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


// TODO:  在此处引用程序需要的其他头文件
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