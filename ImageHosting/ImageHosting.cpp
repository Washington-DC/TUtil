// ImageHosting.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "ImageHosting.h"
#include "MainWindow.h"


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);

	CMainWindow mainWindow;
	mainWindow.Create(NULL, L"ImageHosting", UI_WNDSTYLE_FRAME/*WS_CLIPSIBLINGS*/, WS_EX_WINDOWEDGE);
	mainWindow.CenterWindow();
	mainWindow.ShowModal();

}