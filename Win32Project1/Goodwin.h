#pragma once
#include "header.h"
#include "mainwindow.h"
class GoodWin: public MainWnd{
private:
	typedef struct EdiorInfo{
	CDuiString str_of_ID;
	CDuiString str_of_name;
	CDuiString str_of_type;
	CDuiString str_of_product_date;
	CDuiString str_of_dead_date;
	CDuiString str_of_price;
	CDuiString str_of_uint;
	CDuiString str_of_in_git;
	}EdiorInfo;
public:
	virtual void    Notify(TNotifyUI& msg);//≤∂ªÒduilibœ˚œ¢
	std::string InsertIntoMysql();
	std::string ConditionSelect();
	void ShowInfo();
	std::string Update();
	void GetEdiorInfo(EdiorInfo& edior_info);
	std::string BuildSQL(std::string& sql, EdiorInfo& ef);
	int flag;
private:
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
	virtual LPCTSTR GetWindowClassName(void)const;

};
