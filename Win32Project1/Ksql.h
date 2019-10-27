#pragma once
#include "mysql.h"
#include <string>
#include "mainwindow.h"


using std::string;


class Ksql :public MainWnd{
public:
	Ksql();
	bool ConnectMySQL(const char* host, const char* user, const char* password, const char* dbnamme);//连接数据库
	~Ksql();

	bool Select(const string& strSQL,DuiLib::CListUI* pList);
	bool Insert(const string& strSQL);
	bool Delete(const string& strSQL);
	bool Updata(const string& strSQL);
	bool Add_to_cart(const string& strSQL, DuiLib::CListUI* pList);
	MYSQL* Get_Mysql();
	bool CheckPasswords(CDuiString& username, CDuiString& password);
private:
	MYSQL* _mysql;//数据库连接句柄
};
