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
				std::string sql("insert into goods values(");
				sql += InsertIntoMysql();
				if ((sql.size()) == 0) {
					MessageBox(m_hWnd, _T("请填写所有信息!"), _T("新增失败!"), MB_OK);
					return;
				}
				Ksql mysql;
				mysql.ConnectMySQL("localhost", "root", "kishere", "shop");
				mysql.Insert(sql.c_str());
				_sql = "select * from goods order by id;";
				MainWnd::ShowResult();
				ShowWindow(false);
			}
			else if (flag == 2) {
				std::string sql;
				sql = ConditionSelect();
				_sql = "select * from goods order by id;";
				MainWnd::ShowResult();
				ShowWindow(false);
			}
			else if (flag == 3) {
				std::string sql;
				sql = Update();
				Ksql mysql;
				MainWnd::DeleteInMysql_goods();
				mysql.ConnectMySQL("localhost", "root", "kishere", "shop");
				mysql.Insert(sql.c_str());
				_sql = "select * from goods order by id;";
				MainWnd::ShowResult();
				ShowWindow(false);
			}
		}
	}
	else if (msg.sType == (_T("windowinit"))) {
		if (flag == 3) {
			ShowInfo();
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
	EdiorInfo edior_info;
	GetEdiorInfo(edior_info);
	std::string sql("select * from goods where id is not null ");
	if (edior_info.str_of_ID != "") {
		sql += "and id=";
		sql += edior_info.str_of_ID;
		sql += " ";
	}
	if (edior_info.str_of_name != "") {
		sql += "and good_name='";
		sql += edior_info.str_of_name;
		sql += "' ";
	}
	if (edior_info.str_of_product_date != "") {
		sql += "and product_date='";
		sql += edior_info.str_of_product_date;
		sql += "' ";
	}
	if (edior_info.str_of_dead_date != "") {
		sql += "and dead_date='";
		sql += edior_info.str_of_dead_date;
		sql += "' ";
	}
	if (edior_info.str_of_price != "") {
		sql += "and price='";
		sql += edior_info.str_of_price;
		sql += " ";
	}
	if (edior_info.str_of_type != "") {
		sql += "and good_type='";
		sql += edior_info.str_of_type;
		sql += "' ";
	}
	if (edior_info.str_of_in_git != "") {
		sql += "and in_git=";
		sql += edior_info.str_of_in_git;
		sql += " ";
	}
	if (edior_info.str_of_uint != "") {
		sql += "and uint='";
		sql += edior_info.str_of_uint;
		sql += "' ";
	}
	sql += "order by id";
	sql += ";";
	_sql = sql;
	return sql;
}

void GoodWin::ShowInfo() {
	CEditUI* ptr_of_ID= (CEditUI*)m_PaintManager.FindControl(_T("ID"));
	ptr_of_ID->SetText(MainWnd::text_in_good_list.ID.c_str());
	CEditUI* ptr_of_name= (CEditUI*)m_PaintManager.FindControl(_T("name"));
	ptr_of_name->SetText(MainWnd::text_in_good_list.name.c_str());
	CEditUI* ptr_of_type = (CEditUI*)m_PaintManager.FindControl(_T("type"));
	ptr_of_type->SetText(MainWnd::text_in_good_list.type.c_str());
	CEditUI* ptr_of_product_date = (CEditUI*)m_PaintManager.FindControl(_T("product_date"));
	ptr_of_product_date->SetText(MainWnd::text_in_good_list.Product_date.c_str());
	CEditUI* ptr_of_dead_date= (CEditUI*)m_PaintManager.FindControl(_T("dead_date"));
	ptr_of_dead_date->SetText(MainWnd::text_in_good_list.dead_date.c_str());
	CEditUI* ptr_of_price = (CEditUI*)m_PaintManager.FindControl(_T("price"));
	ptr_of_price->SetText(MainWnd::text_in_good_list.price.c_str());
	CEditUI* ptr_of_uint = (CEditUI*)m_PaintManager.FindControl(_T("uint"));
	ptr_of_uint->SetText(MainWnd::text_in_good_list.uint.c_str());
	CEditUI* ptr_of_in_git = (CEditUI*)m_PaintManager.FindControl(_T("in_git"));
	ptr_of_in_git->SetText(MainWnd::text_in_good_list.in_git.c_str());
}
std::string GoodWin::Update()
{
	CEditUI* ptr_of_ID= (CEditUI*)m_PaintManager.FindControl(_T("ID"));
	CEditUI* ptr_of_name= (CEditUI*)m_PaintManager.FindControl(_T("name"));
	CEditUI* ptr_of_type = (CEditUI*)m_PaintManager.FindControl(_T("type"));
	CEditUI* ptr_of_product_date = (CEditUI*)m_PaintManager.FindControl(_T("product_date"));
	CEditUI* ptr_of_dead_date= (CEditUI*)m_PaintManager.FindControl(_T("dead_date"));
	CEditUI* ptr_of_price = (CEditUI*)m_PaintManager.FindControl(_T("price"));
	CEditUI* ptr_of_uint = (CEditUI*)m_PaintManager.FindControl(_T("uint"));
	CEditUI* ptr_of_in_git = (CEditUI*)m_PaintManager.FindControl(_T("in_git"));

	string ID = ptr_of_ID->GetText();
	string name = ptr_of_name->GetText();
	string type = ptr_of_type->GetText();
	string product_date = ptr_of_product_date->GetText();
	string dead_date = ptr_of_dead_date->GetText();
	string price = ptr_of_price->GetText();
	string uint = ptr_of_uint->GetText();
	string in_git = ptr_of_in_git->GetText();

	std::string sql = "insert into goods values(";
	if (""!=(ID)) {
		sql += ID.c_str();
		sql += ",";
	}
	else {
		return "";
	}
	if (""!=(name)) {
		sql += "'";
		sql += name.c_str();
		sql += "',";
	}
	else {
		return "";
	}
	if (""!=(type)) {
		sql += "'";
		sql += type.c_str();
		sql += "',";
	}
	else {
		return "";
	}
	if (""!=(product_date)) {
		sql += "'";
		sql += product_date.c_str();
		sql += "',";
	}
	else {
		return "";
	}
	if (""!=(dead_date)) {
		sql += "'";
		sql += dead_date.c_str();
		sql += "',";
	}
	else {
		return "";
	}
	if (""!=(price)) {
		sql += "'";
		sql += price.c_str();
		sql += "',";
	}
	else {
		return "";
	}
	if (""!=(uint)) {
		sql += "'";
		sql += uint.c_str();
		sql += "',";
	}
	else {
		return "";
	}
	if (""!=(in_git)) {
		sql += "";
		sql += in_git.c_str();
		sql += ",1)";
	}
	else {
		return "";
	}
	sql += ";";
	return sql;
}

void GoodWin::GetEdiorInfo(EdiorInfo& edior_info)
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
		sql += "";
		sql += ef.str_of_price.GetData();
		sql += ",";
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
		sql += ",";
	}
	else {
		return "";
	}
	sql += "1);";
	return sql;
}

