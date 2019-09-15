#pragma once
#include "header.h"
#include "mainwindow.h"
class SelectWin :public MainWnd{
public:
	virtual void    Notify(TNotifyUI& msg);//≤∂ªÒduilibœ˚œ¢
	void Condition_Select();
private:	

	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
	virtual LPCTSTR GetWindowClassName(void)const;
};
