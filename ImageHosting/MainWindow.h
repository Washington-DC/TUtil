#pragma once
class CMainWindow :public WindowImplBase
{
public:
	CMainWindow();
	~CMainWindow();

	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFile();
	virtual CDuiString GetSkinFolder();

	virtual CControlUI* CreateControl(LPCTSTR pstrClass);
	virtual void InitWindow();

	virtual void Notify(TNotifyUI& msg);

private:
	CTreeViewUI* m_pTreeView = nullptr;
	bool m_bExpend = false;

	CContainerUI* m_pUploadPage = nullptr;
	CContainerUI* m_pBrowerPage = nullptr;
	CContainerUI* m_pQiniuPage = nullptr;
	CContainerUI* m_pGithubPage = nullptr;
	CContainerUI* m_pSettingPage = nullptr;
};

