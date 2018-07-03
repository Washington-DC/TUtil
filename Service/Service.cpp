// Service.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;

SERVICE_STATUS_HANDLE g_serviceStatusHandle = NULL;

const TCHAR* szServiceName = _T("test_for_service");

void setServiceStatus(DWORD status)
{
	SERVICE_STATUS serviceStatus;
	serviceStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
	serviceStatus.dwWin32ExitCode = NO_ERROR;
	serviceStatus.dwServiceSpecificExitCode = 0;
	serviceStatus.dwWaitHint = 2000;
	serviceStatus.dwCheckPoint = 0;
	serviceStatus.dwControlsAccepted = SERVICE_ACCEPT_PAUSE_CONTINUE |
		SERVICE_ACCEPT_SHUTDOWN |
		SERVICE_ACCEPT_STOP;

	serviceStatus.dwCurrentState = status;
	SAFE_CALL(SetServiceStatus(g_serviceStatusHandle, &serviceStatus), 0);
}

VOID WINAPI ServiceHandler(DWORD controlCode)
{
	switch (controlCode)
	{
	case SERVICE_CONTROL_CONTINUE:
		setServiceStatus(SERVICE_START_PENDING);    break;
	//case SERVICE_CONTROL_INTERROGATE:
	//	break;
	case SERVICE_CONTROL_PAUSE:
		setServiceStatus(SERVICE_PAUSED);           break;
	case SERVICE_CONTROL_SHUTDOWN:
		setServiceStatus(SERVICE_STOPPED);          break;
	case SERVICE_CONTROL_STOP:
		setServiceStatus(SERVICE_STOPPED);          break;
	default:
		break;
	}
}

VOID WINAPI ServiceMain(DWORD argc, LPWSTR *argv)
{
	g_serviceStatusHandle = RegisterServiceCtrlHandlerW(szServiceName, &ServiceHandler);
	if (g_serviceStatusHandle == 0)
	{
		cout << "RegisterServiceCtrlHandlerW error, code:" << GetLastError()
			<< " ,line:" << __LINE__ << "\n";
		exit(-1);
	}

	setServiceStatus(SERVICE_START_PENDING);
	setServiceStatus(SERVICE_RUNNING);
}

void runService()
{
	const SERVICE_TABLE_ENTRYW serviceTable[] = {
		{ _T("test_for_service"), ServiceMain },
		{ NULL, NULL }
	};

	SAFE_CALL(StartServiceCtrlDispatcherW(serviceTable), FALSE);
}


int _tmain(int argc, _TCHAR* argv[])
{

	//
	//ServiceHelper::StartService(szServiceName);
	ServiceHelper::InstallService(szServiceName, FileUtil::GetApplicationPath().c_str());
	runService();
	
	/*if (argc == 1)                              runService();
	else if (argc == 2) {
	if (argv[1] == wstring(L"-install"))    ServiceHelper::InstallService(szServiceName, FileUtil::GetApplicationPath().c_str()), ServiceHelper::StartService(szServiceName);
	if (argv[1] == wstring(L"-uninstall"))   ServiceHelper::UninstallService(szServiceName);*/
	return 0;
}

