#pragma once
#include "header.h"

class LogoinWindow : public WindowImplBase {
public:
	virtual void    Notify(TNotifyUI& msg);//≤∂ªÒduilibœ˚œ¢
	void login();
protected:
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
	virtual LPCTSTR GetWindowClassName(void)const;
};
