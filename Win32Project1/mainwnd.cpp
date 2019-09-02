#include "mainwindow.h"
#include "Ksql.h"
CDuiString MainWnd::GetSkinFolder() {
	return _T("");
}
CDuiString MainWnd::GetSkinFile() {
	return _T("mainstyle.xml");
}
LPCTSTR MainWnd::GetWindowClassName(void)const {
	return _T("mainwindows");
}
void MainWnd::Notify(TNotifyUI& msg) {

	if (msg.sType == _T("click")){
		if (msg.pSender->GetName() == _T("closebtn_main")){
			PostQuitMessage(0);
		}
		else if (msg.pSender->GetName() == _T("minbtn_main")){
			SendMessage(WM_SYSCOMMAND, SW_MINIMIZE);
		}
		else if(msg.pSender->GetName()==_T("select")){
			DuiLib::CListUI* pList = static_cast<DuiLib::CListUI*>(m_PaintManager.FindControl(_T("employeelist")));
			Ksql mysql;
			mysql.ConnectMySQL("localhost", "root", "kishere", "shop");
			mysql.Select("select * from employee;",pList);
		}
	}
	else if (msg.sType == _T("selectchanged")){
		CTabLayoutUI* ptab = (CTabLayoutUI*)m_PaintManager.FindControl(_T("table_layout1"));
		if (msg.pSender->GetName() == _T("employee")){
			ptab->SelectItem(0);
		}
		else if (msg.pSender->GetName() == _T("goods")) {
			ptab->SelectItem(1);
		}
		else if (msg.pSender->GetName() == _T("money")) {
			ptab->SelectItem(2);
		}
		else if (msg.pSender->GetName() == _T("VIP")) {
			ptab->SelectItem(3);
		}
	}
}
