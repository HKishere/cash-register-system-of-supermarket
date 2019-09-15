#include "insertwin.h"
#include "Ksql.h"

CDuiString InsertWin::GetSkinFolder() {
	return _T("");
	}
CDuiString InsertWin::GetSkinFile() {
	return _T("selectstyle.xml");
}
LPCTSTR InsertWin::GetWindowClassName(void)const {
	return _T("insertwindow");
}

void InsertWin::Notify(TNotifyUI& msg) {//捕获duilib消息
	if (msg.sType == _T("click")) {
		if (msg.pSender->GetName() == _T("cancle")) {
			ShowWindow(false);
		}
		else if (msg.pSender->GetName() == _T("ok")) {
			std::string sql = InsertIntoMysql();
			if ((sql.size()) == 0){
				MessageBox(m_hWnd, _T("请填写所有信息!"), _T("新增失败!"), MB_OK);
				return;
			}
			Ksql mysql;
			mysql.ConnectMySQL("localhost", "root", "kishere", "shop");
			mysql.Insert(sql.c_str());
			MainWnd::ShowResult();
			ShowWindow(false);
		}
	}
}
std::string InsertWin::InsertIntoMysql() {
	while (1) {
		CEditUI* ptr_of_ID = (CEditUI*)m_PaintManager.FindControl(_T("ID"));
		CDuiString str_of_ID = ptr_of_ID->GetText();
		CEditUI* ptr_of_name = (CEditUI*)m_PaintManager.FindControl(_T("name"));
		CDuiString str_of_name = ptr_of_name->GetText();
		CEditUI* ptr_of_gender = (CEditUI*)m_PaintManager.FindControl(_T("sex"));
		CDuiString str_of_gender = ptr_of_gender->GetText();
		CEditUI* ptr_of_birth = (CEditUI*)m_PaintManager.FindControl(_T("birth"));
		CDuiString str_of_birth = ptr_of_birth->GetText();
		CEditUI* ptr_of_password = (CEditUI*)m_PaintManager.FindControl(_T("password"));
		CDuiString str_of_password = ptr_of_password->GetText();
		CEditUI* ptr_of_pos = (CEditUI*)m_PaintManager.FindControl(_T("pos"));
		CDuiString str_of_pos = ptr_of_pos->GetText();
		CEditUI* ptr_of_tel = (CEditUI*)m_PaintManager.FindControl(_T("tel"));
		CDuiString str_of_tel = ptr_of_tel->GetText();
		CEditUI* ptr_of_salary = (CEditUI*)m_PaintManager.FindControl(_T("salary"));
		CDuiString str_of_salary = ptr_of_salary->GetText();

		std::string sql = "insert into employee values(";
		if (!(str_of_ID.IsEmpty())) {
			sql += str_of_ID.GetData();
			sql += ",";
		}
		else{
			return "";
		}
		if (!(str_of_name.IsEmpty())) {
			sql += "'";
			sql += str_of_name.GetData();
			sql += "',";
		}
		else{
			return "";
		}
		if (!(str_of_gender.IsEmpty())) {
			sql += "'";
			sql += str_of_gender.GetData();
			sql += "',";
		}
		else{
			return "";
		}
		if (!(str_of_birth.IsEmpty())) {
			sql += "'";
			sql += str_of_birth.GetData();
			sql += "',";
		}
		else{
			return "";
		}
		if (!(str_of_password.IsEmpty())) {
			sql += "'";
			sql += str_of_password.GetData();
			sql += "',";
		}
		else{
			return "";
		}
		if (!(str_of_pos.IsEmpty())) {
			sql += "'";
			sql += str_of_pos.GetData();
			sql += "',";
		}
		else{
			return "";
		}
		if (!(str_of_tel.IsEmpty())) {
			sql += "'";
			sql += str_of_tel.GetData();
			sql += "',";
		}
		else{
			return "";
		}
		if (!(str_of_salary.IsEmpty())) {
			sql += "";
			sql += str_of_salary.GetData();
			sql += ")";
		}
		else{
			return "";
		}
		sql += ";";
		return sql;
	}
}
