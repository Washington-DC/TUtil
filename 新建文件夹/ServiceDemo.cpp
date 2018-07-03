// ServiceDemo.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "ServiceDemo.h"

#include "ServiceManage.h"

//const TCHAR* szServiceName = _T("test_for_service");


int _tmain(int argc, TCHAR * argv[])
{
	if (argc == 1)                              runService();
	else if (argc == 2) {
		if (argv[1] == wstring(L"-install"))    ServiceHelper::InstallService(szServiceName, FileUtil::GetApplicationPath().c_str()), ServiceHelper::StartService(szServiceName);
		if (argv[1] == wstring(L"-uninstall"))   ServiceHelper::UninstallService(szServiceName);
	}
}

//int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
//	_In_opt_ HINSTANCE hPrevInstance,
//	_In_ LPTSTR    lpCmdLine,
//	_In_ int       nCmdShow)
//{
//	//ServiceHelper::UninstallService(_T("testforservice"));
//	//
//	////RunService();
//	///*if (argc == 1)                              runService();
//	//else if (argc == 2) {
//	//if (argv[1] == wstring(L"-install"))    installService(), startService();
//	//if (argv[1] == wstring(L"-uninstall"))  uninstallService();
//	//}
//	//else                                        std::cout << "usage: a.exe [-install/-uninstall]";
//	//*/
//	//ServiceHelper::UninstallService(_T("test_for_service"));
//	//TCHAR szPathName[MAX_PATH] = { 0 };
//	//GetModuleFileName(hInstance, szPathName, MAX_PATH);
//	//ServiceHelper::InstallService(szServiceName, szPathName);
//	//ServiceHelper::StartService(szServiceName);
//
//	runService();
//
//	
//}
