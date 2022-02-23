
//------------------------------------------------------------------------------
// ���ߣ������أ�1498880193@qq.com��
// ���ڹ�˾���ɶ��۴���ӹ������޹�˾
// ʱ�䣺2019/8/24 
// �ļ�����FlappyBird
// �汾��V1.0.3
// SDK�汾��10.0.17134.0
// ˵������PC�����C++��MFC���ĵ�������VS2017����ƽ̨��д�ɣ�֧��windows 10������
// �޸��ߣ�������
// �޸�˵������������ļ��Լ������ڳ����еġ����ء������SQL���ݿ�洢�û����ݽ�����߷���ͳ�ơ�
//------------------------------------------------------------------------------

#pragma once
#include "resource.h"
#include "Pic.h"
#include "PipeList.h"
#include "Land.h"
#include "Bird.h"
#include "Panel.h"
#include "Button.h"
#include <afxwin.h>
#include <mmsystem.h>
#pragma comment( lib, "Winmm.lib" )





class CMyApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
};//*


class CMainWindow:public CFrameWnd
{
public:
	int bg_state,game_state,last_state;//�����л�2����Ϸ״̬,���gameover״̬

	int goals,best_goals;//����

	CRect m_client;
	CBitmap m_bgBitmap,m_tempBitmap;
	CDC m_cacheDC;   //����DC  
	CDC m_bgcDC,m_tempcDC;

	Pic pic;//����ͼƬ
	PipeList pipe;//����
	Land land;//·
	Bird bird;//��
	Panel panel;//�Ʒְ�
    Button button;//��ť
public:
	CMainWindow ();
	
	void draw();
	void restart();
	void screenShot(CRect rect,int left,int top,char *name);
protected:
	afx_msg int  OnCreate (LPCREATESTRUCT lpcs);      
    afx_msg void OnTimer (UINT nTimerID);              
    afx_msg void OnClose ();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	DECLARE_MESSAGE_MAP();
	
};//*

//------------------------------------------------------------------------------
// ���ߣ������أ�1498880193@qq.com��
// ���ڹ�˾���ɶ��۴���ӹ������޹�˾
// ʱ�䣺2019/8/24 
// �ļ�����FlappyBird
// �汾��V1.0.3
// SDK�汾��10.0.17134.0
// ˵������PC�����C++��MFC���ĵ�������VS2017����ƽ̨��д�ɣ�֧��windows 10������
// �޸��ߣ�������
// �޸�˵������������ļ��Լ������ڳ����еġ����ء������SQL���ݿ�洢�û����ݽ�����߷���ͳ�ơ�
//------------------------------------------------------------------------------
