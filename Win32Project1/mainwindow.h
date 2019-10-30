#pragma once

#include "header.h"

class MainWnd :public WindowImplBase {
protected:
	std::string _sql;	
	typedef struct ContentOfEmployeeList {
		std::string ID;
		std::string name;
		std::string gender;
		std::string birthday;
		std::string password;
		std::string pos;
		std::string tel;
		std::string salary;
	}ContentOfEmployeeList;
	typedef struct ContentOfGoodList {
		std::string ID;
		std::string name;
		std::string type;
		std::string Product_date;
		std::string dead_date;
		std::string price;
		std::string uint;
		std::string in_git;
	}ContentOfGoodList;
	DuiLib::CListUI* _pList;
public:
	MainWnd::MainWnd();
	void DeleteInMysql();
	virtual void    Notify(TNotifyUI& msg);//≤∂ªÒduilibœ˚œ¢
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
	virtual LPCTSTR GetWindowClassName(void)const;
	void MainWnd::ShowResult();
	void MainWnd::GetListInfoOfemployee(ContentOfEmployeeList& p);
	void MainWnd::GetListInfoOfGood(ContentOfGoodList& text_in_good_list);
	void DeleteInMysql_goods();
	ContentOfEmployeeList text_in_list;
	ContentOfGoodList text_in_good_list;
};
