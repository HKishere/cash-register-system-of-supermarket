#include "selectwin.h"
#include "insertwin.h"
#include "mainwindow.h"
#include "Ksql.h"

DuiLib::CListUI* _pList;


MainWnd::MainWnd() {
	_sql = "select * from employee;";
}
CDuiString MainWnd::GetSkinFolder() {
	return _T("");
}
CDuiString MainWnd::GetSkinFile() {
	return _T("mainstyle.xml");
}
LPCTSTR MainWnd::GetWindowClassName(void)const {
	return _T("mainwindow");
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
			 _pList = static_cast<DuiLib::CListUI*>(m_PaintManager.FindControl(_T("employeelist")));
			ShowResult();
		}
		else if(msg.pSender->GetName()==_T("conditionselect")){
			_pList = static_cast<DuiLib::CListUI*>(m_PaintManager.FindControl(_T("employeelist")));
			SelectWin sw;
			sw.Create(NULL, _T("selectwindow"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
			sw.CenterWindow();
			sw.ShowModal();
		}
		else if(msg.pSender->GetName()==_T("insert")){
			InsertWin iw;
			iw.Create(NULL, _T("insertwindow"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
			iw.CenterWindow();
			iw.ShowModal();
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
	}
}
void MainWnd::ShowResult() {
	Ksql mysql;
	mysql.ConnectMySQL("localhost", "root", "kishere", "shop");
	mysql.Select(_sql.c_str(), _pList);
}
