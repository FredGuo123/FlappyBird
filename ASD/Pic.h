
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
#include <afxwin.h>
class Pic
{                                                                                               //����ͼƬ
public:
	class PicInfo
	{
	public:
		double x,y,pos_x,pos_y;
		void set(double X,double Y,double Pos_x,double Pos_y){
			x=X;y=Y;pos_x=Pos_x;pos_y=Pos_y;
		}
		void TBlt(int p_x,int p_y,CDC* To,CDC* From){
			To->TransparentBlt(p_x,p_y,x,y,From,pos_x*1024,pos_y*1024,x,y,RGB(0,0,0));
		}
	};//*
public:
	PicInfo bg[2],bird[3][3],black,blink[3],brand_copyright,button_menu,
		button_ok,button_pause,button_play,button_rate,button_resume,
		button_score,button_share,font[10],land,medals[4],
		New,number_context[11],number_score[10],pipe2_down,
		pipe2_up,pipe_down,pipe_up,score_panel,text_game_over,
		text_ready,title,tutorial,white;//ͼƬ��Ϣ
public:
	Pic();
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
