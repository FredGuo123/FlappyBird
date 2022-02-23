
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
#include "PipeList.h"
#include "resource.h"
#include "Pic.h"
#include "Bird.h"
#include "Button.h"
#include <afxwin.h>
#include <mmsystem.h>
#pragma comment( lib, "Winmm.lib" )
#define  $d 12                                                 //图片内缩函数

class PipeList
{                                                              //柱子逻辑函数
public:
	class Pipe
	{
	public:
		int pos_x,pos_y,speed;
		Pipe(int x=300,int y=rand()%200-270,int Speed=-4)
		{
			pos_x=x;pos_y=y;speed=Speed;
		}
		void logic(){pos_x+=speed;}
		void stop() {speed=0;}
		void start(){speed=-4;}
	};//*                                                      //内部类柱子
public:
	CList<Pipe, Pipe&> pipe;                                    //柱子
	TCHAR mcicmd[300];                                          //音乐临时文件
public:
	PipeList();
	void recover();
	void add();                                                 //增加
	void logic(int &goals,Bird &bird,int &game_state);          //逻辑
	void draw(Pic &All,CDC* To,CDC* From);                      //绘制
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
