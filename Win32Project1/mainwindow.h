#pragma once

#include "header.h"

class MainWnd :public WindowImplBase {
	virtual void    Notify(TNotifyUI& msg);//≤∂ªÒduilibœ˚œ¢
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
	virtual LPCTSTR GetWindowClassName(void)const;
};
