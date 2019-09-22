#include "Goodwin.h"
#include "Ksql.h"
CDuiString GoodWin::GetSkinFolder() {
	return _T("");
	}
CDuiString GoodWin::GetSkinFile() {
	return _T("goodsstyle.xml");
}
LPCTSTR GoodWin::GetWindowClassName(void)const {
	return _T("goodswindows");
}
void GoodWin::Notify(TNotifyUI& msg) {//捕获duilib消息

	if (msg.sType == _T("click")) {
		if (msg.pSender->GetName() == _T("cancle")) {
			ShowWindow(false);
		}
		else if (msg.pSender->GetName() == _T("ok")) {
			if (flag == 1) {
				std::string sql;
				sql = InsertIntoMysql();
				if ((sql.size()) == 0) {
					MessageBox(m_hWnd, _T("请填写所有信息!"), _T("新增失败!"), MB_OK);
					return;
				}
				Ksql mysql;
				mysql.ConnectMySQL("localhost", "root", "kishere", "shop");
				mysql.Insert(sql.c_str());
				MainWnd::ShowResult();
				ShowWindow(false);
			}
			MainWnd::ShowResult();
			ShowWindow(false);
		}
	}
}

std::string GoodWin::InsertIntoMysql()
{
	EdiorInfo edior_info;
	GetEdiorInfo(edior_info);
	std::string sql;
	sql = BuildSQL(sql, edior_info);
	return sql;
}

std::string GoodWin::ConditionSelect()
{
	return std::string();
}

std::string GoodWin::Update()
{
	return std::string();
}

void GoodWin::GetEdiorInfo(EdiorInfo edior_info)
{
	CEditUI* ptr_of_ID= (CEditUI*)m_PaintManager.FindControl(_T("ID"));
	CEditUI* ptr_of_name= (CEditUI*)m_PaintManager.FindControl(_T("name"));
	CEditUI* ptr_of_type= (CEditUI*)m_PaintManager.FindControl(_T("type"));
	CEditUI* ptr_of_product_date= (CEditUI*)m_PaintManager.FindControl(_T("product_date"));
	CEditUI* ptr_of_dead_date= (CEditUI*)m_PaintManager.FindControl(_T("dead_date"));
	CEditUI* ptr_of_price= (CEditUI*)m_PaintManager.FindControl(_T("price"));
	CEditUI* ptr_of_uint= (CEditUI*)m_PaintManager.FindControl(_T("uint"));
	CEditUI* ptr_of_in_git= (CEditUI*)m_PaintManager.FindControl(_T("in_git"));

	edior_info.str_of_ID = ptr_of_ID->GetText();
	edior_info.str_of_name = ptr_of_name->GetText();
	edior_info.str_of_type = ptr_of_type->GetText();
	edior_info.str_of_product_date = ptr_of_product_date->GetText();
	edior_info.str_of_dead_date = ptr_of_dead_date->GetText();
	edior_info.str_of_price = ptr_of_price->GetText();
	edior_info.str_of_uint = ptr_of_uint->GetText();
	edior_info.str_of_in_git = ptr_of_in_git->GetText();
}
std::string GoodWin::BuildSQL(std::string& sql, EdiorInfo& ef) {
	if (!(ef.str_of_ID.IsEmpty())) {
		sql += ef.str_of_ID.GetData();
		sql += ",";
	}
	else {
		return "";
	}
	if (!(ef.str_of_name.IsEmpty())) {
		sql += "'";
		sql += ef.str_of_name.GetData();
		sql += "',";
	}
	else {
		return "";
	}
	if (!(ef.str_of_type.IsEmpty())) {
		sql += "'";
		sql += ef.str_of_type.GetData();
		sql += "',";
	}
	else {
		return "";
	}
	if (!(ef.str_of_product_date.IsEmpty())) {
		sql += "'";
		sql += ef.str_of_product_date.GetData();
		sql += "',";
	}
	else {
		return "";
	}
	if (!(ef.str_of_dead_date.IsEmpty())) {
		sql += "'";
		sql += ef.str_of_dead_date.GetData();
		sql += "',";
	}
	else {
		return "";
	}
	if (!(ef.str_of_price.IsEmpty())) {
		sql += "'";
		sql += ef.str_of_price.GetData();
		sql += "',";
	}
	else {
		return "";
	}
	if (!(ef.str_of_uint.IsEmpty())) {
		sql += "'";
		sql += ef.str_of_uint.GetData();
		sql += "',";
	}
	else {
		return "";
	}
	if (!(ef.str_of_in_git.IsEmpty())) {
		sql += "";
		sql += ef.str_of_in_git.GetData();
		sql += ")";
	}
	else {
		return "";
	}
	sql += ";";
	return sql;
}


