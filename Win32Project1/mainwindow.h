#pragma once

#include "header.h"

class MainWnd :public WindowImplBase {
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
	virtual LPCTSTR GetWindowClassName(void)const;
};
