
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

#include "PipeList.h"


void PipeList::recover()
{
	int count=pipe.GetCount();
	for(int i=0;i<count;i++){
		pipe.RemoveHead();
	}
}//*


void PipeList::add()
{
	Pipe temp;
	pipe.AddTail(temp);
}//*


void PipeList::logic(int &goals,Bird &bird,int &game_state)
{                                                                                             //�߼�����
	int count=pipe.GetCount();
	for(int i=0;i<count;i++)
	{
		Pipe temp=pipe.GetHead();
		pipe.RemoveHead();
		temp.logic();
		if(temp.pos_x==64)
		{
			goals+=1;
			mciSendString(_T("close mymusic"), NULL, 0, NULL);                                //�ȹ��ٿ���ע��˳�򣡣���
			mciSendString(mcicmd, NULL,0, NULL);
			mciSendString(_T("play mymusic"),NULL,0, NULL);	
		}
		if(temp.pos_x>=-70)pipe.AddTail(temp);

		                                                                                      //��ײ��⺯����
		if(23+bird.y+48-$d>400){                                                              //1���������ײ
			bird.y=400-230-48+$d;
			bird.stop();
			game_state=2;
		}
		else if(!(65+48-$d < temp.pos_x || temp.pos_x+52<65+$d))
		{                                                                                     //2����������ײ
			if(!(230+bird.y+$d > temp.pos_y+320 && temp.pos_y+420 > 230+bird.y+48-$d))
			{
				game_state=2;                                                                 //��ʾ��ײ,��Ϸ����;
				PlaySound(MAKEINTRESOURCE(IDR_WAVE_HIT),AfxGetResourceHandle(),SND_RESOURCE|SND_ASYNC);
			}
		}
	}
	if((pipe.GetTail()).pos_x<=140)
	{
		Pipe temp;
		pipe.AddTail(temp);
	}
}//*


void PipeList::draw(Pic &All,CDC* To,CDC* From)
{                                                                                             //���ƺ���
	int count=pipe.GetCount();
	for(int i=0;i<count;i++)
	{
		Pipe temp=pipe.GetHead();
		pipe.RemoveHead();
		pipe.AddTail(temp);
		All.pipe_down.TBlt(temp.pos_x,temp.pos_y,To,From);                                     //���������
		All.pipe_up.TBlt(temp.pos_x,temp.pos_y+420,To,From);                                   //���������
	}
}//*


bool ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName)
{
	                                                                                           // �����ļ�
	HANDLE hFile = ::CreateFile(strDstFile, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return false;

	                                                                                           // ������Դ�ļ��С�������Դ���ڴ桢�õ���Դ��С
	HRSRC	hRes	= ::FindResource(NULL, strResName, strResType);
	HGLOBAL	hMem	= ::LoadResource(NULL, hRes);
	DWORD	dwSize	= ::SizeofResource(NULL, hRes);
	
	                                                                                           // д���ļ�
	DWORD dwWrite = 0;  	                                                                   // ����д���ֽ�
	::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);
	::CloseHandle(hFile);

	return true;
}//*


PipeList::PipeList(){
	                                                                                           // ������ʱ�ļ����ļ���
	TCHAR tmpwav[_MAX_PATH];
	::GetTempPath(_MAX_PATH,tmpwav);
	_tcscat_s(tmpwav, _T("testapp_background.wav"));		
	                                                                                           // ��wav ��Դ��ȡΪ��ʱ��
	                                                                                           //ExtractResource(tmpwav,_T("WAVE"), "background.mp3");
	                                                                                           // ע�����wave��Դ�� ID Ϊ�� IDR_BACKGROUND����������
	ExtractResource(tmpwav, _T("WAVE"), MAKEINTRESOURCE(IDR_WAVE_POINT));
	                                                                                           // ������
	          //TCHAR mcicmd[300];
	_stprintf_s(mcicmd, _T("open \"%s\" alias mymusic"),tmpwav);		
	//mciSendString(mcicmd, NULL,0, NULL);
	                                                                                           // ��������
	//mciSendString(_T("play mymusic"), NULL, 0, NULL);
	                                                                                           // ֹͣ���Ų��ر�����
	//mciSendString(("stop mymusic"), NULL, 0, NULL);
	//mciSendString(("close mymusic"), NULL, 0, NULL);
	                                                                                           // ɾ����ʱ�ļ�
	
}//*

   
 //�����Ҫ�ر����ӵ��������ɽ�Ӧ�·���ɾȥ����������������ע�⣬ϵͳ��ʱ�������ݣ�δ�����������     

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
