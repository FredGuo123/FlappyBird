
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

#include "Panel.h"

Panel::Panel()
{
	state=panel_move;
	goals=0;
	best_goals=0;
	y=520;
	new_goals=false;
	ring=true;
}//*


void Panel::recover()
{
	state=panel_move;
	goals=0;
	best_goals=0;
	y=520;
	new_goals=false;
	ring=true;
}//*


void Panel::draw(Pic &All,CDC* To,CDC* From)
{
	All.score_panel.TBlt(30,y,To,From);

	if(state!=panel_move){
		int copy=goals,wei=1;                                                 //显示分数
		while(copy/10){wei++;copy/=10;}copy=goals;
		int this_wei,first_pos=246-wei*20;
		while(wei--){
			this_wei=copy%10;
			copy/=10;
			All.number_score[this_wei].TBlt(first_pos+wei*20,226,To,From);
		}

		copy=best_goals;wei=1;                                                //显示最好成绩分数
		while(copy/10){wei++;copy/=10;}copy=best_goals;
		first_pos=246-wei*20;
		while(wei--){
			this_wei=copy%10;
			copy/=10;
			All.number_score[this_wei].TBlt(first_pos+wei*20,265,To,From);
		}
		
		if(new_goals==true){
			All.New.TBlt(170,250,To,From);
		}
		if(state==finish && goals>9){
			switch(goals/10){
			case 1:All.medals[3].TBlt(62,235,To,From);break;
			case 2:All.medals[2].TBlt(62,235,To,From);break;
			case 3:All.medals[1].TBlt(62,235,To,From);break;
			case 4:All.medals[1].TBlt(62,235,To,From); break;
			case 5:All.medals[1].TBlt(62,235,To,From); break;
			case 6:All.medals[1].TBlt(62,235,To,From); break;
			case 7:All.medals[1].TBlt(62,235,To,From); break;
			case 8:All.medals[1].TBlt(62,235,To,From); break;
			case 9:All.medals[1].TBlt(62,235,To,From); break;
			default:All.medals[0].TBlt(62,235,To,From);break;
			}
		}
	}
}//*



void Panel::logic(int &_goals,int &_best_goals){
	if(state==panel_move){
		if(ring){
			PlaySound(MAKEINTRESOURCE(IDR_WAVE_PANEL),AfxGetResourceHandle(),SND_RESOURCE|SND_ASYNC);
			ring=false;
		}
		y-=55;
		if(y<=190){
			state=goals_add;
			if(_goals>_best_goals){
				_best_goals=_goals;
				new_goals=true;
			}
			best_goals=_best_goals;
		}
	}else if(state==goals_add){
		if(goals==_goals)state=finish;
		else goals++;
	}
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
