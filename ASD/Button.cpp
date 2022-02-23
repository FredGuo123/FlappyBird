
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
	{                                                                                //��������
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
