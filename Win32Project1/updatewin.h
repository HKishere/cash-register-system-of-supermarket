#pragma once
#include "header.h"
#include "mainwindow.h"
class UpdateWin:public MainWnd{
public:
	virtual void    Notify(TNotifyUI& msg);//≤∂ªÒduilibœ˚œ¢
	void ShowInfo();
	std::string Update();
private:	

	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
	virtual LPCTSTR GetWindowClassName(void)const;
};
