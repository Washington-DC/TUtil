#include "Base.h"
#include <windows.h>

#define SAFE_CALL(FuncCall, ErrorCode)		                        \
	if (FuncCall == ErrorCode) {			                        \
		std::cout << #FuncCall " error, code:" << GetLastError()	\
            <</* " ,file: << __FILE__ << */" ,line:" << __LINE__ << "\n";\
			exit(-1);							                     \
		}


class DLL_EXPORT ServiceHelper
{
public:
	static void InstallService(LPCTSTR lpServiceName, LPCTSTR lpBinaryPathName)
	{
		SC_HANDLE scmHandle = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
		SAFE_CALL(scmHandle, NULL);

		SC_HANDLE serviceHandle = CreateService(scmHandle,
			lpServiceName,
			lpServiceName,
			SERVICE_ALL_ACCESS,
			SERVICE_WIN32_OWN_PROCESS,
			SERVICE_AUTO_START,
			SERVICE_ERROR_NORMAL,
			lpBinaryPathName,
			NULL,
			NULL,
			_T(""),
			NULL,
			_T("")
			);

		SAFE_CALL(serviceHandle, NULL);

		CloseServiceHandle(scmHandle);
		CloseServiceHandle(serviceHandle);
	}


	static void StartService(LPCTSTR lpServiceName)
	{
		SC_HANDLE scmHandle = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
		SAFE_CALL(scmHandle, NULL);

		SC_HANDLE serviceHandle = OpenService(scmHandle, lpServiceName, SERVICE_ALL_ACCESS);
		SAFE_CALL(serviceHandle, NULL);

		SERVICE_STATUS serviceStatus;
		SAFE_CALL(QueryServiceStatus(serviceHandle, &serviceStatus), 0);
		if (serviceStatus.dwCurrentState == SERVICE_START &&
			serviceStatus.dwCurrentState != SERVICE_START_PENDING)
		{
			return;
		}

		SAFE_CALL(::StartService(serviceHandle, 0, NULL), FALSE);

		CloseServiceHandle(scmHandle);
		CloseServiceHandle(serviceHandle);
	}


	static void StopService(LPCTSTR lpServiceName)
	{
		SC_HANDLE scmHandle = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
		SAFE_CALL(scmHandle, NULL);

		SC_HANDLE serviceHandle = OpenService(scmHandle, lpServiceName, SERVICE_ALL_ACCESS);
		SAFE_CALL(serviceHandle, NULL);

		SERVICE_STATUS serviceStatus;
		SAFE_CALL(QueryServiceStatus(serviceHandle, &serviceStatus), 0);

		if (serviceStatus.dwCurrentState == SERVICE_RUNNING)
		{
			SAFE_CALL(ControlService(serviceHandle, SERVICE_CONTROL_STOP, &serviceStatus), 0);
			SAFE_CALL(serviceStatus.dwCurrentState, NO_ERROR);
		}

		do
		{
			SAFE_CALL(QueryServiceStatus(serviceHandle, &serviceStatus), 0);
			Sleep(100);
		} while (serviceStatus.dwCurrentState != SERVICE_STOPPED);
	}


	static void UninstallService(LPCTSTR lpServiceName)
	{
		SC_HANDLE scmHandle = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
		SAFE_CALL(scmHandle, NULL);

		SC_HANDLE serviceHandle = OpenService(scmHandle, lpServiceName, SERVICE_ALL_ACCESS);
		SAFE_CALL(serviceHandle, NULL);

		SERVICE_STATUS serviceStatus;
		SAFE_CALL(QueryServiceStatus(serviceHandle, &serviceStatus), 0);

		if (serviceStatus.dwCurrentState == SERVICE_RUNNING)
		{
			SAFE_CALL(ControlService(serviceHandle, SERVICE_CONTROL_STOP, &serviceStatus), 0);
			SAFE_CALL(serviceStatus.dwCurrentState, NO_ERROR);
		}

		do
		{
			SAFE_CALL(QueryServiceStatus(serviceHandle, &serviceStatus), 0);
			Sleep(100);
		} while (serviceStatus.dwCurrentState != SERVICE_STOPPED);

		SAFE_CALL(DeleteService(serviceHandle), FALSE);

		CloseServiceHandle(scmHandle);
		CloseServiceHandle(serviceHandle);
	}

};
