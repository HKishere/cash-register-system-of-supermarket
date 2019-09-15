#pragma once
#include "header.h"
#include "mainwindow.h"
class InsertWin : public MainWnd{
public:
	virtual void    Notify(TNotifyUI& msg);//≤∂ªÒduilibœ˚œ¢
	std::string InsertIntoMysql();
private:
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
	virtual LPCTSTR GetWindowClassName(void)const;
};
