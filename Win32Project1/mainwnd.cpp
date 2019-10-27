#include "Goodwin.h"
#include "selectwin.h"
#include "updatewin.h"
#include "insertwin.h"
#include "mainwindow.h"
#include "Ksql.h"



MainWnd::MainWnd() {
	_sql = "select * from employee order by id;";
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
			 _sql = "select * from employee order by id;";
			ShowResult();
		}
		else if(msg.pSender->GetName()==_T("conditionselect")){
			_pList = static_cast<DuiLib::CListUI*>(m_PaintManager.FindControl(_T("employeelist")));
			SelectWin sw;
			sw._pList = MainWnd::_pList;
			sw.Create(NULL, _T("selectwindow"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
			sw.CenterWindow();
			sw.ShowModal();
		}
		else if(msg.pSender->GetName()==_T("insert")){
			_pList = static_cast<DuiLib::CListUI*>(m_PaintManager.FindControl(_T("employeelist")));
			InsertWin iw;
			iw._pList = MainWnd::_pList;
			iw.Create(NULL, _T("insertwindow"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
			iw.CenterWindow();
			iw.ShowModal();
		}
		else if (msg.pSender->GetName() == _T("delete")) {
			if (!_pList){
				MessageBox(m_hWnd, _T("请选择一行数据"), _T("删除失败!"), MB_OK);
				return;
			}
			DeleteInMysql();
		}
		else if (msg.pSender->GetName() == _T("update")) {
			if (!_pList){
				MessageBox(m_hWnd, _T("请选择一行数据"), _T("更改失败!"), MB_OK);
				return;
			}
			_pList = static_cast<DuiLib::CListUI*>(m_PaintManager.FindControl(_T("employeelist")));
			GetListInfoOfemployee(text_in_list);
			UpdateWin uw;
			uw._pList = MainWnd::_pList;
			uw.text_in_list = MainWnd::text_in_list;
			uw.Create(NULL, _T("updatewin"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
			uw.CenterWindow();
			uw.ShowModal();
		}
		else if (msg.pSender->GetName() == _T("select_good")) {
			_pList = static_cast<DuiLib::CListUI*>(m_PaintManager.FindControl(_T("goodslist")));
			_sql = "select * from goods order by id;";
			ShowResult();
		}
		else if(msg.pSender->GetName()==_T("insert_good")){
			_pList = static_cast<DuiLib::CListUI*>(m_PaintManager.FindControl(_T("goodslist")));
			GoodWin iw;
			iw.flag = 1;
			iw._pList = MainWnd::_pList;
			iw.Create(NULL, _T("insertwindow"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
			iw.CenterWindow();
			iw.ShowModal();
		}
		else if (msg.pSender->GetName() == _T("add_good")) {
			CEditUI* goods_id = (CEditUI*)m_PaintManager.FindControl(_T("good_ID_enter"));
			string vlue = goods_id->GetText();//need test
			_pList = static_cast<DuiLib::CListUI*>(m_PaintManager.FindControl(_T("selllist")));
			Ksql mysql;
			mysql.ConnectMySQL("localhost", "root", "kishere", "shop");
			mysql.Add_to_cart(vlue, _pList);
		}
		else if (msg.pSender->GetName() == _T("delete_in_cart")) {
			if (!_pList){
				MessageBox(m_hWnd, _T("请选择一行数据"), _T("删除失败!"), MB_OK);
				return;
			}
			CListTextElementUI * pListElement = new CListTextElementUI;
			int nIndex = _pList->GetCurSel();
			pListElement = (CListTextElementUI*)_pList->GetItemAt(nIndex);
			string ID = pListElement->GetText(0);
			_pList->Remove(_pList->GetItemAt(_pList->GetCurSel()));
			Ksql mysql;
			mysql.ConnectMySQL("localhost", "root", "kishere", "shop");
			string strSQL = "update goods set in_git=in_git+1 where id=";
			strSQL += ID;
			strSQL += ";";
			if (mysql_query(mysql.Get_Mysql(), strSQL.c_str())) {//通过mysql_query函数执行SQL语句
				return;
			}
		}
	}
	else if (msg.sType == _T("selectchanged")) {
		CTabLayoutUI* ptab = (CTabLayoutUI*)m_PaintManager.FindControl(_T("table_layout1"));
		if (msg.pSender->GetName() == _T("employee")) {
			ptab->SelectItem(0);
			_sql = "select * from employee order by id;";
		}
		else if (msg.pSender->GetName() == _T("goods")) {
			ptab->SelectItem(1);
			_sql = "select * from goods order by id;";
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
void MainWnd::GetListInfoOfemployee(ContentOfEmployeeList& p) {
	CListTextElementUI * pListElement = new CListTextElementUI;
	int nIndex = _pList->GetCurSel();
	pListElement = (CListTextElementUI*)_pList->GetItemAt(nIndex);

	p.ID = pListElement->GetText(0);
	p.name = pListElement->GetText(1);
	p.gender = pListElement->GetText(2);
	p.birthday = pListElement->GetText(3);
	p.password = pListElement->GetText(4);
	p.pos = pListElement->GetText(5);
	p.tel = pListElement->GetText(6);
	p.salary = pListElement->GetText(7);

}
void MainWnd::DeleteInMysql() {

	GetListInfoOfemployee(text_in_list);
	std::string sql = "delete from employee where ";
	sql += "id=";
	sql += text_in_list.ID;
	sql += " ";
	sql += "and name='";
	sql += text_in_list.name;
	sql += "' ";
	sql += "and gender='";
	sql += text_in_list.gender;
	sql += "' ";
	sql += "and birthday='";
	sql += text_in_list.birthday;
	sql += "' ";
	sql += "and password='";
	sql += text_in_list.password;
	sql += "' ";
	sql += "and position='";
	sql += text_in_list.pos;
	sql += "' ";
	sql += "and telphone='";
	sql += text_in_list.tel;
	sql += "' ";
	sql += "and salary=";
	sql += text_in_list.salary;
	sql += "";
	sql += ";";
	Ksql mysql;
	mysql.ConnectMySQL("localhost", "root", "kishere", "shop");
	mysql.Delete(sql);
	_sql = "select * from employee order by id;";
	ShowResult();
}
