
//------------------------------------------------------------------------------
// 作者：郭晨曦（1498880193@qq.com）
// 所在公司：成都驰达电子工程有限公司
// 时间：2019/8/24 
// 文件名：FlappyBird
// 版本：V1.0.3
// SDK版本：10.0.17134.0
// 说明：此PC版采用C++的MFC单文档技术在VS2017开发平台下写成，支持windows 10环境。
// 修改者：郭晨曦
// 修改说明：添加音乐文件以及音乐在程序中的“开关”，添加SQL数据库存储用户数据进行最高分数统计。
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
	int bg_state,game_state,last_state;//背景切换2，游戏状态,最后gameover状态

	int goals,best_goals;//分数

	CRect m_client;
	CBitmap m_bgBitmap,m_tempBitmap;
	CDC m_cacheDC;   //缓冲DC  
	CDC m_bgcDC,m_tempcDC;

	Pic pic;//所有图片
	PipeList pipe;//柱子
	Land land;//路
	Bird bird;//鸟
	Panel panel;//计分板
    Button button;//按钮
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
// 作者：郭晨曦（1498880193@qq.com）
// 所在公司：成都驰达电子工程有限公司
// 时间：2019/8/24 
// 文件名：FlappyBird
// 版本：V1.0.3
// SDK版本：10.0.17134.0
// 说明：此PC版采用C++的MFC单文档技术在VS2017开发平台下写成，支持windows 10环境。
// 修改者：郭晨曦
// 修改说明：添加音乐文件以及音乐在程序中的“开关”，添加SQL数据库存储用户数据进行最高分数统计。
//------------------------------------------------------------------------------
