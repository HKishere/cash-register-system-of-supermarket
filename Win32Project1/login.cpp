#include "login.h"
#include "mainwindow.h"
CDuiString LogoinWindow::GetSkinFolder() {
	return _T("");
}
CDuiString LogoinWindow::GetSkinFile() {
	return _T("loginstyle.xml");
}
LPCTSTR LogoinWindow::GetWindowClassName(void)const {
	return _T("loginwindows");
}
void LogoinWindow::Notify(TNotifyUI& msg) {//捕获duilib消息

	if (msg.sType == _T("click")){
		if (msg.pSender->GetName() == _T("closebtn")){
			PostQuitMessage(0);
		}
		else if (msg.pSender->GetName() == _T("minbtn")){
			SendMessage(WM_SYSCOMMAND, SW_MINIMIZE);
		}
		else if (msg.pSender->GetName() == _T("loginbtn")){
			login();
		}
	}

}

void LogoinWindow::login(){
	CEditUI* p_edit_user_name = (CEditUI*)m_PaintManager.FindControl(_T("username_Edit"));
	CDuiString str_user_name = p_edit_user_name->GetText();

	CEditUI* p_edit_password = (CEditUI*)m_PaintManager.FindControl(_T("password_Edit"));
	CDuiString str_password = p_edit_password->GetText();

	if (str_user_name.IsEmpty()){
		MessageBox(m_hWnd, _T("请输入用户名"), _T("登录失败!"), MB_OK);
		return;
	}
	else {
		if (str_password.IsEmpty()){
			MessageBox(m_hWnd, _T("请输入密码"), _T("登录失败!"), MB_OK);
			return;
		}
		else {
			ShowWindow(false);
		}
	}

    MainWnd mainwindows;
    mainwindows.Create(NULL, _T("mainwindow"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	mainwindows.CenterWindow();
    mainwindows.ShowModal();
}