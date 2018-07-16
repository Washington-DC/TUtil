#include "stdafx.h"
#include "MainWindow.h"


CMainWindow::CMainWindow()
{
}


CMainWindow::~CMainWindow()
{
}

LPCTSTR CMainWindow::GetWindowClassName() const
{
	return _T("DuiMainWnd");
}

DuiLib::CDuiString CMainWindow::GetSkinFile()
{
	return _T("MainFrame.xml");
}

DuiLib::CDuiString CMainWindow::GetSkinFolder()
{
	return _T("skin");
}

CControlUI * CMainWindow::CreateControl(LPCTSTR pstrClass)
{
	return NULL;
}

void CMainWindow::Notify(TNotifyUI& msg)
{
	if (lstrcmp(msg.sType,DUI_MSGTYPE_WINDOWINIT)==0)
	{
		m_pTreeView = static_cast<CTreeViewUI*>(m_PaintManager.FindControl(_T("tree_view")));

		m_pUploadPage	= (CContainerUI*)m_PaintManager.FindControl(_T("tab_image_upload_page"));
		m_pBrowerPage	= (CContainerUI*)m_PaintManager.FindControl(_T("tab_image_browser_page"));
		m_pQiniuPage	= (CContainerUI*)m_PaintManager.FindControl(_T("tab_qiniur_page"));
		m_pGithubPage	= (CContainerUI*)m_PaintManager.FindControl(_T("tab_github_page"));
		m_pSettingPage	= (CContainerUI*)m_PaintManager.FindControl(_T("tab_setting_page"));

		CTreeNodeUI* pTreeNode = static_cast<CTreeNodeUI*>(m_PaintManager.FindControl(_T("btn_hosting_setting_page")));
		CCheckBoxUI* pCheckBox = pTreeNode->GetFolderButton();
		m_pTreeView->SetItemExpand(false, pTreeNode);
	}
	if (lstrcmp(msg.sType,DUI_MSGTYPE_ITEMCLICK) == 0)
	{
		if (lstrcmp(msg.pSender->GetName(),_T("btn_image_upload_page")) == 0)//图片上传
		{
			//MessageBox(m_hWnd, _T("btn_image_upload_page"), DUI_MSGTYPE_ITEMCLICK, MB_OK);
		}
		else if (lstrcmp(msg.pSender->GetName(), _T("btn_image_browser_page")) == 0)//图片管理
		{
			//MessageBox(m_hWnd, _T("btn_image_browser_page"), DUI_MSGTYPE_ITEMCLICK, MB_OK);
		}
		else if (lstrcmp(msg.pSender->GetName(), _T("btn_hosting_setting_page")) == 0)//图床设置
		{
			//MessageBox(m_hWnd, _T("btn_image_browser_page"), DUI_MSGTYPE_ITEMCLICK, MB_OK);
			CTreeNodeUI* pTreeNode = static_cast<CTreeNodeUI*>(msg.pSender);
			CCheckBoxUI* pCheckBox = pTreeNode->GetFolderButton();
			//pTreeNode->SetExpandable(false);
			m_bExpend = !m_bExpend;
			m_pTreeView->SetItemExpand(m_bExpend, pTreeNode);
			int iIndex = m_pTreeView->GetItemIndex(m_PaintManager.FindControl(_T("btn_hosting_qiniuyun_page")));
			m_pTreeView->SelectItem(iIndex,true);
			//m_PaintManager.SendNotify(m_PaintManager.FindControl(_T("btn_hosting_qiniuyun_page")), DUI_MSGTYPE_ITEMCLICK);
		}
		else if (lstrcmp(msg.pSender->GetName(), _T("btn_system_setting_page")) == 0)//系统管理
		{
			//MessageBox(m_hWnd, _T("btn_image_browser_page"), DUI_MSGTYPE_ITEMCLICK, MB_OK);
		}
		else if (lstrcmp(msg.pSender->GetName(), _T("btn_hosting_qiniuyun_page")) == 0)//七牛云
		{
			//MessageBox(m_hWnd, _T("btn_hosting_qiniuyun_page"), DUI_MSGTYPE_ITEMCLICK, MB_OK);
		}
		else if (lstrcmp(msg.pSender->GetName(), _T("btn_hosting_github_page")) == 0)//Github
		{
			//MessageBox(m_hWnd, _T("btn_hosting_github_page"), DUI_MSGTYPE_ITEMCLICK, MB_OK);
		}
	}

	__super::Notify(msg);
}

void CMainWindow::InitWindow()
{

}
