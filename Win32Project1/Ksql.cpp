#include "Ksql.h"
#include <string.h>
#include <iostream>
using namespace std;


Ksql::Ksql() {
	_mysql = mysql_init(nullptr);
	mysql_options(_mysql, MYSQL_SET_CHARSET_NAME, "gbk");
}
bool Ksql::ConnectMySQL(const char* host, const char* user, const char* password, const char* dbnamme) {
	if (!mysql_real_connect(_mysql, host, user, password, dbnamme, 3306, nullptr, 0)) {
		return false;
	}
	return true;
	
}
bool Ksql::Select(const string& strSQL,DuiLib::CListUI* pList) {
	if (mysql_query(_mysql, strSQL.c_str())) {//通过mysql_query函数执行SQL语句
		cout << mysql_error(_mysql) << endl;
		return false;
	}
	MYSQL_RES* MysqlRes = mysql_store_result(_mysql);//获取查询的结果集
	if (MysqlRes == nullptr) {
		cout << mysql_error((_mysql)) << endl;
		return false;
	}
	int itemcount = mysql_num_fields(MysqlRes);//获取结果集中有多少列
	MYSQL_ROW MysqlRow;
	//while (MysqlRow = mysql_fetch_row(MysqlRes)){//获取其中一行结果集
	//	for (size_t i = 0; i < itemcount; ++i) {
	//		cout << MysqlRow[i] << '\t';
	//	}
	//	cout << endl;
	//}
	//mysql_free_result(MysqlRes);//使用完结果集后需要及时释放结果集

	DuiLib::CDuiString str;
	int row = MysqlRes->row_count;
	// 添加List列表内容，必须先Add(pListElement)，再SetText	
	pList->RemoveAll();
	while (row) {//获取其中一行结果集	
		MysqlRow = mysql_fetch_row(MysqlRes);
		DuiLib::CListTextElementUI* pListElement = new  DuiLib::CListTextElementUI;
		pListElement->SetTag(row);
		pList->Add(pListElement);
		for (int i = 0; i < itemcount; i++) {
			str.Format(_T("%s"), MysqlRow[i]);
			pListElement->SetText(i, str);
		}
		row--;
	}
	return true;
	mysql_free_result(MysqlRes);//使用完结果集后需要及时释放结果集
}
bool Ksql::Insert(const string& strSQL) {
	if (mysql_query(_mysql,strSQL.c_str())){//通过mysql_query函数执行SQL语句
		cout << mysql_error(_mysql) << endl;
		return false;
	}
	else
		return true;
}
bool Ksql::Delete(const string& strSQL) {
	if (mysql_query(_mysql,strSQL.c_str())){//通过mysql_query函数执行SQL语句
		cout << mysql_error(_mysql) << endl;
		return false;
	}
	else
		return true;
}
bool Ksql::Updata(const string& strSQL) {
	if (mysql_query(_mysql,strSQL.c_str())){//通过mysql_query函数执行SQL语句
		cout << mysql_error(_mysql) << endl;
		return false;
	}
	else
		return true;
}
bool Ksql::CheckPasswords(CDuiString& username,CDuiString& password) {
	string strSQL("select password from employee where name='");
	strSQL += (const char*)username.GetData();
	strSQL += "';";
	if (mysql_query(_mysql, strSQL.c_str())){//通过mysql_query函数执行SQL语句
		MessageBox(m_hWnd, _T("数据库查询失败!"), _T("登录失败!"), MB_OK);
		return false;
	}
	MYSQL_RES* MysqlRes = mysql_store_result(_mysql);//获取查询的结果集
	MYSQL_ROW MysqlRow;
	MysqlRow = mysql_fetch_row(MysqlRes);
	if (!(MysqlRow)){
		MessageBox(m_hWnd, _T("找不到用户名!"), _T("登录失败!"), MB_OK);
		return false;
	}
	if (strcmp(*MysqlRow , password.GetData())){
		password = "";
		return false;
	}
	return true;
}


Ksql::~Ksql() {
	mysql_close(_mysql);
 }															