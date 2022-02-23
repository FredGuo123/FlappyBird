
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

#include "Button.h"
#include "PipeList.h"

Button::Button()
{
	kind=none;
	move=false;
	play_y=score_y=0;
}


void Button::click(CPoint &point)
{
	if(point.x>=25 && point.x<=25+116 && point.y>=340 && point.y<=340+70)
	{
		kind=play;
		move=true;
		PlaySound(MAKEINTRESOURCE(IDR_WAVE_PANEL),AfxGetResourceHandle(),SND_RESOURCE|SND_ASYNC);
	}
	else if(point.x>=155 && point.x<=155+116 && point.y>=340 && point.y<=340+70)
	{
		kind=score;
		move=true;
		int speed = -6;
	}
	else kind=none;
}//*


void Button::logic(int &game_state)
{
	if(kind==play)
	{                                                                                //颤动控制
		if(move==true)
		{
			play_y=2;
			move=false;
		}
		else
		{
			play_y=0;
			kind=none;
			game_state=4;
			
		}


	}else if(kind==score)
	{
		if(move==true)
		{
			play_y=2;
			move=false;
		}
		else
		{
			play_y = 2;
			kind=play;
			game_state = 4;
			int speed = -6;
		}
	}
}//*


void Button::draw(Pic &All,CDC* To,CDC* From)
{
	All.button_play.TBlt(25,340+play_y,To,From);
	All.button_score.TBlt(155,340+score_y,To,From);
}//*




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
