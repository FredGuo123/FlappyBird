
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
#include "PipeList.h"
#include "resource.h"
#include "Pic.h"
#include "Bird.h"
#include "Button.h"
#include <afxwin.h>
#include <mmsystem.h>
#pragma comment( lib, "Winmm.lib" )
#define  $d 12                                                 //ͼƬ��������

class PipeList
{                                                              //�����߼�����
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
	};//*                                                      //�ڲ�������
public:
	CList<Pipe, Pipe&> pipe;                                    //����
	TCHAR mcicmd[300];                                          //������ʱ�ļ�
public:
	PipeList();
	void recover();
	void add();                                                 //����
	void logic(int &goals,Bird &bird,int &game_state);          //�߼�
	void draw(Pic &All,CDC* To,CDC* From);                      //����
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
