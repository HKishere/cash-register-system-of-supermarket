//#pragma once
//class CDuiFrameWnd : public WindowImplBase {
//public:
//    virtual LPCTSTR GetWindowClassName() const {return _T("DUIMainFrame"); }
//	virtual CDuiString GetSkinFile()                {   return _T("duilib.xml");  }
//    virtual CDuiString GetSkinFolder()              {   return _T("");  }//��ȡxml�ļ�����·��
//    virtual void    Notify(TNotifyUI& msg) {//����duilib��Ϣ
//		if (msg.sType == _T("click")){
//			if (msg.pSender == m_PaintManager.FindControl(_T("closebtn"))) {//�жϰ������ʱ����İ�ť�����Ƿ�Ϊ�رհ�ť������
//				PostQuitMessage(0);//�رմ���
//			}
//			if (msg.pSender->GetName() == _T("logoin_btn")) {//�жϰ������ʱ����İ�ť�����Ƿ�Ϊ�رհ�ť������
//			ShowWindow(false,false);//�رմ���
//			}
//		}
//		void CenterWindow();	// ���У�֧����չ��Ļ
//	}
//	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
//		LRESULT lRes = 0;
//
//		if (uMsg == WM_CREATE)
//		{
//			m_PaintManager.Init(m_hWnd);
//
//			CDialogBuilder builder;
//			CControlUI* pRoot = builder.Create(_T("duilib.xml"), (UINT)0, NULL, &m_PaintManager);   // duilib.xml��Ҫ�ŵ�exeĿ¼��
//			ASSERT(pRoot && "Failed to parse XML");
//
//			m_PaintManager.AttachDialog(pRoot);
//			m_PaintManager.AddNotifier(this);   // ��ӿؼ�����Ϣ��Ӧ��������Ϣ�ͻᴫ�ﵽduilib����Ϣѭ�������ǿ�����Notify����������Ϣ����
//			return lRes;
//		}
//
//		 ����3����ϢWM_NCACTIVATE��WM_NCCALCSIZE��WM_NCPAINT��������ϵͳ������
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