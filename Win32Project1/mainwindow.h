#pragma once

#include "header.h"

class MainWnd :public WindowImplBase {
public:
	MainWnd::MainWnd();
	void DeleteInMysql();
	virtual void    Notify(TNotifyUI& msg);//≤∂ªÒduilibœ˚œ¢
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
	virtual LPCTSTR GetWindowClassName(void)const;
	void MainWnd::ShowResult();
protected:
	std::string _sql;	
};
