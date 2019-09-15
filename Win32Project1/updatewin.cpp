#include "updatewin.h"
#include "Ksql.h"
CDuiString UpdateWin::GetSkinFolder() {
	return _T("");
	}
CDuiString UpdateWin::GetSkinFile() {
	return _T("selectstyle.xml");
}
LPCTSTR UpdateWin::GetWindowClassName(void)const {
	return _T("UpdateWin");
}
void UpdateWin::Notify(TNotifyUI& msg) {//捕获duilib消息
	if (msg.sType == _T("click")) {
		if (msg.pSender->GetName() == _T("cancle")) {
			ShowWindow(false);
		}
		else if (msg.pSender->GetName() == _T("ok")) {
			std::string sql = Update();
			if ((sql.size()) == 0){
				MessageBox(m_hWnd, _T("请填写所有信息!"), _T("修改失败!"), MB_OK);
				return;
			}
			Ksql mysql;
			MainWnd::DeleteInMysql();
			mysql.ConnectMySQL("localhost", "root", "kishere", "shop");
			mysql.Insert(sql.c_str());
			MainWnd::ShowResult();
			ShowWindow(false);

		}

	}
	else if(msg.sType == (_T("windowinit"))) {
		ShowInfo();
	}
}
void UpdateWin::ShowInfo() {
	CEditUI* ptr_of_ID= (CEditUI*)m_PaintManager.FindControl(_T("ID"));
	ptr_of_ID->SetText(MainWnd::text_in_list.ID.c_str());
	CEditUI* ptr_of_name= (CEditUI*)m_PaintManager.FindControl(_T("name"));
	ptr_of_name->SetText(MainWnd::text_in_list.name.c_str());
	CEditUI* ptr_of_gender= (CEditUI*)m_PaintManager.FindControl(_T("sex"));
	ptr_of_gender->SetText(MainWnd::text_in_list.gender.c_str());
	CEditUI* ptr_of_birth= (CEditUI*)m_PaintManager.FindControl(_T("birth"));
	ptr_of_birth->SetText(MainWnd::text_in_list.birthday.c_str());
	CEditUI* ptr_of_password= (CEditUI*)m_PaintManager.FindControl(_T("password"));
	ptr_of_password->SetText(MainWnd::text_in_list.password.c_str());
	CEditUI* ptr_of_pos= (CEditUI*)m_PaintManager.FindControl(_T("pos"));
	ptr_of_pos->SetText(MainWnd::text_in_list.pos.c_str());
	CEditUI* ptr_of_tel= (CEditUI*)m_PaintManager.FindControl(_T("tel"));
	ptr_of_tel->SetText(MainWnd::text_in_list.tel.c_str());
	CEditUI* ptr_of_salary= (CEditUI*)m_PaintManager.FindControl(_T("salary"));
	ptr_of_salary ->SetText(MainWnd::text_in_list.salary.c_str());
}
std::string UpdateWin::Update() {
	CEditUI* ptr_of_ID= (CEditUI*)m_PaintManager.FindControl(_T("ID"));
	CEditUI* ptr_of_name= (CEditUI*)m_PaintManager.FindControl(_T("name"));
	CEditUI* ptr_of_gender= (CEditUI*)m_PaintManager.FindControl(_T("sex"));
	CEditUI* ptr_of_birth= (CEditUI*)m_PaintManager.FindControl(_T("birth"));
	CEditUI* ptr_of_password= (CEditUI*)m_PaintManager.FindControl(_T("password"));
	CEditUI* ptr_of_pos= (CEditUI*)m_PaintManager.FindControl(_T("pos"));
	CEditUI* ptr_of_tel= (CEditUI*)m_PaintManager.FindControl(_T("tel"));
	CEditUI* ptr_of_salary= (CEditUI*)m_PaintManager.FindControl(_T("salary"));

	UpdateWin::text_in_list.ID= ptr_of_ID->GetText();
	UpdateWin::text_in_list.name= ptr_of_name->GetText();
	UpdateWin::text_in_list.gender= ptr_of_gender->GetText();
	UpdateWin::text_in_list.birthday= ptr_of_birth->GetText();
	UpdateWin::text_in_list.password= ptr_of_password->GetText();
	UpdateWin::text_in_list.pos= ptr_of_pos->GetText();
	UpdateWin::text_in_list.tel= ptr_of_tel->GetText();
	UpdateWin::text_in_list.salary= ptr_of_salary->GetText();

	std::string sql = "insert into employee values(";
	if (""!=(text_in_list.ID)) {
		sql += text_in_list.ID.c_str();
		sql += ",";
	}
	else {
		return "";
	}
	if (""!=(text_in_list.name)) {
		sql += "'";
		sql += text_in_list.name.c_str();
		sql += "',";
	}
	else {
		return "";
	}
	if (""!=(text_in_list.gender)) {
		sql += "'";
		sql += text_in_list.gender.c_str();
		sql += "',";
	}
	else {
		return "";
	}
	if (""!=(text_in_list.birthday)) {
		sql += "'";
		sql += text_in_list.birthday.c_str();
		sql += "',";
	}
	else {
		return "";
	}
	if (""!=(text_in_list.password)) {
		sql += "'";
		sql += text_in_list.password.c_str();
		sql += "',";
	}
	else {
		return "";
	}
	if (""!=(text_in_list.pos)) {
		sql += "'";
		sql += text_in_list.pos.c_str();
		sql += "',";
	}
	else {
		return "";
	}
	if (""!=(text_in_list.tel)) {
		sql += "'";
		sql += text_in_list.tel.c_str();
		sql += "',";
	}
	else {
		return "";
	}
	if (""!=(text_in_list.salary)) {
		sql += "";
		sql += text_in_list.salary.c_str();
		sql += ")";
	}
	else {
		return "";
	}
	sql += ";";
	return sql;
}

