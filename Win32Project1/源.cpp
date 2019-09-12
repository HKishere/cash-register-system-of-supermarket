//#pragma once
//class CDuiFrameWnd : public WindowImplBase {
//public:
//    virtual LPCTSTR GetWindowClassName() const {return _T("DUIMainFrame"); }
//	virtual CDuiString GetSkinFile()                {   return _T("duilib.xml");  }
//    virtual CDuiString GetSkinFolder()              {   return _T("");  }//获取xml文件所在路径
//    virtual void    Notify(TNotifyUI& msg) {//捕获duilib消息
//		if (msg.sType == _T("click")){
//			if (msg.pSender == m_PaintManager.FindControl(_T("closebtn"))) {//判断按下鼠标时点击的按钮名字是否为关闭按钮的名字
//				PostQuitMessage(0);//关闭窗口
//			}
//			if (msg.pSender->GetName() == _T("logoin_btn")) {//判断按下鼠标时点击的按钮名字是否为关闭按钮的名字
//			ShowWindow(false,false);//关闭窗口
//			}
//		}
//		void CenterWindow();	// 居中，支持扩展屏幕
//	}
//	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
//		LRESULT lRes = 0;
//
//		if (uMsg == WM_CREATE)
//		{
//			m_PaintManager.Init(m_hWnd);
//
//			CDialogBuilder builder;
//			CControlUI* pRoot = builder.Create(_T("duilib.xml"), (UINT)0, NULL, &m_PaintManager);   // duilib.xml需要放到exe目录下
//			ASSERT(pRoot && "Failed to parse XML");
//
//			m_PaintManager.AttachDialog(pRoot);
//			m_PaintManager.AddNotifier(this);   // 添加控件等消息响应，这样消息就会传达到duilib的消息循环，我们可以在Notify函数里做消息处理
//			return lRes;
//		}
//
//		 以下3个消息WM_NCACTIVATE、WM_NCCALCSIZE、WM_NCPAINT用于屏蔽系统标题栏
//		if (uMsg == WM_NCACTIVATE)
//		{
//			if (!::IsIconic(m_hWnd))
//			{
//				return (wParam == 0) ? TRUE : FALSE;
//			}
//		}
//		else if (uMsg == WM_NCCALCSIZE)
//		{
//			return 0;
//		}
//		else if (uMsg == WM_NCPAINT)
//		{
//			return 0;
//		}
//
//		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
//		{
//			return lRes;
//		}
//
//		return __super::HandleMessage(uMsg, wParam, lParam);
//	}*/
//
//protected:
//    CPaintManagerUI m_PaintManager;
//};
//
#include "login.h"
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    CPaintManagerUI::SetInstance(hInstance);
    LogoinWindow duiFrame;
    duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.CenterWindow();
    duiFrame.ShowModal();
    return 0;
}