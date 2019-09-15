#pragma once

#include "header.h"

class MainWnd :public WindowImplBase {
protected:
	std::string _sql;	
	typedef struct ContentOfList {
		std::string ID;
		std::string name;
		std::string gender;
		std::string birthday;
		std::string password;
		std::string pos;
		std::string tel;
		std::string salary;
	}ContentOfList;
	DuiLib::CListUI* _pList;
public:
	MainWnd::MainWnd();
	void DeleteInMysql();
	virtual void    Notify(TNotifyUI& msg);//≤∂ªÒduilibœ˚œ¢
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
	virtual LPCTSTR GetWindowClassName(void)const;
	void MainWnd::ShowResult();
	void MainWnd::GetListInfo(ContentOfList& p);
	ContentOfList text_in_list;
};
