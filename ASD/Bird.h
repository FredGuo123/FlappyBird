

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
#include "Pic.h"
#include "resource.h"
#include <afxwin.h>
#include <cmath>
#include <mmsystem.h>
#pragma comment( lib, "Winmm.lib" )

#define bird_v0 -14
#define bird_a0 2
#define $d 12                                            //边缘内缩
#define PI 3.1415926

#define state_up		 0
#define state_turn		 2
#define state_down		 3
#define state_delay      4

class Bird
{
public:
	int bird_state,fly_state,dis_state;                  //种类，飞行状态,方向状态
	int y,v,a;                                           //鸟的位置,y方向的速度，y方向上的加速度
	double Time;                                         //开始鸟上下sin函数的时间轴
	int state;                                           //鸟运动过程各种状态
	int delay;                                           //音乐播放延迟时间
	CBitmap bird[3][3];
public:
	Bird();
	void recover();
	void stop();
	void jump();
	void logic(int ID,int &game_state);
	void paint(CDC* To,CDC* From);
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





