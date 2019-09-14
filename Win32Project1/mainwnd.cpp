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
			 _sql = "select * from employee;";
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
		else if (msg.pSender->GetName() == _T("delete")) {
			CListTextElementUI * pListElement = new CListTextElementUI;
			int nIndex = _pList->GetCurSel();
			pListElement = (CListTextElementUI*)_pList->GetItemAt(nIndex);
			DeleteInMysql();
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
void MainWnd::DeleteInMysql() {
	CListTextElementUI * pListElement = new CListTextElementUI;
	int nIndex = _pList->GetCurSel();
	pListElement = (CListTextElementUI*)_pList->GetItemAt(nIndex);

	std::string ID = pListElement->GetText(0);
	std::string name = pListElement->GetText(1);
	std::string gender = pListElement->GetText(2);
	std::string birthday = pListElement->GetText(3);
	std::string password = pListElement->GetText(4);
	std::string pos = pListElement->GetText(5);
	std::string tel = pListElement->GetText(6);
	std::string salary = pListElement->GetText(7);

	std::string sql = "delete from employee where ";
	sql += "id=";
	sql += ID;
	sql += " ";
	sql += "and name='";
	sql += name;
	sql += "' ";
	sql += "and gender='";
	sql += gender;
	sql += "' ";
	sql += "and birthday='";
	sql += birthday;
	sql += "' ";
	sql += "and password='";
	sql += password;
	sql += "' ";
	sql += "and position='";
	sql += pos;
	sql += "' ";
	sql += "and telphone='";
	sql += tel;
	sql += "' ";
	sql += "and salary=";
	sql += salary;
	sql += "";
	sql += ";";
	Ksql mysql;
	mysql.ConnectMySQL("localhost", "root", "kishere", "shop");
	mysql.Delete(sql);
	_sql = "select * from employee;";
	ShowResult();
}
