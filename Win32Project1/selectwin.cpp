#include "selectwin.h"
#include "Ksql.h"

CDuiString SelectWin::GetSkinFolder() {
	return _T("");
	}
CDuiString SelectWin::GetSkinFile() {
	return _T("selectstyle.xml");
}
LPCTSTR SelectWin::GetWindowClassName(void)const {
	return _T("selectwindows");
}

void SelectWin::Notify(TNotifyUI& msg) {//²¶»ñduilibÏûÏ¢

	if (msg.sType == _T("click")) {
		if (msg.pSender->GetName() == _T("cancle")) {
			ShowWindow(false);
		}
		else if (msg.pSender->GetName() == _T("ok")) {
			Condition_Select();
			int h_wnd = 0x005B1BF0;
	//		SendMessage(h_wnd, WM_USER_SELECT_FINISH);
			MainWnd::ShowResult();
			ShowWindow(false);
		}
	}
}

void SelectWin::Condition_Select() {
	CEditUI* ptr_of_ID= (CEditUI*)m_PaintManager.FindControl(_T("ID"));
	CDuiString str_of_ID= ptr_of_ID->GetText();
	CEditUI* ptr_of_name= (CEditUI*)m_PaintManager.FindControl(_T("name"));
	CDuiString str_of_name= ptr_of_name->GetText();
	CEditUI* ptr_of_gender= (CEditUI*)m_PaintManager.FindControl(_T("sex"));
	CDuiString str_of_gender= ptr_of_gender->GetText();
	CEditUI* ptr_of_birth= (CEditUI*)m_PaintManager.FindControl(_T("birth"));
	CDuiString str_of_birth= ptr_of_birth->GetText();
	CEditUI* ptr_of_password= (CEditUI*)m_PaintManager.FindControl(_T("password"));
	CDuiString str_of_password= ptr_of_password->GetText();
	CEditUI* ptr_of_pos= (CEditUI*)m_PaintManager.FindControl(_T("pos"));
	CDuiString str_of_pos= ptr_of_pos->GetText();
	CEditUI* ptr_of_tel= (CEditUI*)m_PaintManager.FindControl(_T("tel"));
	CDuiString str_of_tel= ptr_of_tel->GetText();
	CEditUI* ptr_of_salary= (CEditUI*)m_PaintManager.FindControl(_T("salary"));
	CDuiString str_of_salary= ptr_of_salary->GetText();

	string sql = "select * from employee where id is not null ";
	if (!(str_of_ID.IsEmpty())){
		sql += "id=";
		sql += str_of_ID.GetData();
		sql += " ";
	}
	if (!(str_of_name.IsEmpty())){
		sql += "and name='";
		sql += str_of_name.GetData();
		sql += "' ";
	}
	if (!(str_of_gender.IsEmpty())){
		sql += "and gender='";
		sql += str_of_gender.GetData();
		sql += "' ";
	}
	if (!(str_of_birth.IsEmpty())){
		sql += "and birthday='";
		sql += str_of_birth.GetData();
		sql += "' ";
	}
	if (!(str_of_password.IsEmpty())){
		sql += "and password='";
		sql += str_of_password.GetData();
		sql += "' ";
	}
	if (!(str_of_pos.IsEmpty())){
		sql += "and position='";
		sql += str_of_pos.GetData();
		sql += "' ";
	}
	if (!(str_of_tel.IsEmpty())){
		sql += "and telphone='";
		sql += str_of_tel.GetData();
		sql += "' ";
	}
	if (!(str_of_salary.IsEmpty())){
		sql += "and salary=";
		sql += str_of_salary.GetData();
		sql += " ";
	}
	sql += ";";
	_sql = sql;
}
