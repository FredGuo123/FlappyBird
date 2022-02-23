

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
#include "Pic.h"
#include "resource.h"
#include <afxwin.h>
#include <cmath>
#include <mmsystem.h>
#pragma comment( lib, "Winmm.lib" )

#define bird_v0 -14
#define bird_a0 2
#define $d 12                                            //��Ե����
#define PI 3.1415926

#define state_up		 0
#define state_turn		 2
#define state_down		 3
#define state_delay      4

class Bird
{
public:
	int bird_state,fly_state,dis_state;                  //���࣬����״̬,����״̬
	int y,v,a;                                           //���λ��,y������ٶȣ�y�����ϵļ��ٶ�
	double Time;                                         //��ʼ������sin������ʱ����
	int state;                                           //���˶����̸���״̬
	int delay;                                           //���ֲ����ӳ�ʱ��
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





