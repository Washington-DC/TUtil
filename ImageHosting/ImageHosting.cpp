// ImageHosting.cpp : ����Ӧ�ó������ڵ㡣
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

	CMainWindow duiFrame;
	duiFrame.Create(NULL, L"DuiMainWnd", UI_WNDSTYLE_FRAME/*WS_CLIPSIBLINGS*/, WS_EX_WINDOWEDGE);

	duiFrame.CenterWindow();
	duiFrame.ShowModal();

}