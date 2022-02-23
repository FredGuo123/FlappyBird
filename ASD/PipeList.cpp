
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
{                                                                                             //逻辑函数
	int count=pipe.GetCount();
	for(int i=0;i<count;i++)
	{
		Pipe temp=pipe.GetHead();
		pipe.RemoveHead();
		temp.logic();
		if(temp.pos_x==64)
		{
			goals+=1;
			mciSendString(_T("close mymusic"), NULL, 0, NULL);                                //先关再开，注意顺序！！！
			mciSendString(mcicmd, NULL,0, NULL);
			mciSendString(_T("play mymusic"),NULL,0, NULL);	
		}
		if(temp.pos_x>=-70)pipe.AddTail(temp);

		                                                                                      //碰撞检测函数↓
		if(23+bird.y+48-$d>400){                                                              //1、与地面碰撞
			bird.y=400-230-48+$d;
			bird.stop();
			game_state=2;
		}
		else if(!(65+48-$d < temp.pos_x || temp.pos_x+52<65+$d))
		{                                                                                     //2、与柱子碰撞
			if(!(230+bird.y+$d > temp.pos_y+320 && temp.pos_y+420 > 230+bird.y+48-$d))
			{
				game_state=2;                                                                 //表示碰撞,游戏结束;
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
{                                                                                             //绘制函数
	int count=pipe.GetCount();
	for(int i=0;i<count;i++)
	{
		Pipe temp=pipe.GetHead();
		pipe.RemoveHead();
		pipe.AddTail(temp);
		All.pipe_down.TBlt(temp.pos_x,temp.pos_y,To,From);                                     //上面的柱子
		All.pipe_up.TBlt(temp.pos_x,temp.pos_y+420,To,From);                                   //下面的柱子
	}
}//*


bool ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName)
{
	                                                                                           // 创建文件
	HANDLE hFile = ::CreateFile(strDstFile, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return false;

	                                                                                           // 查找资源文件中、加载资源到内存、得到资源大小
	HRSRC	hRes	= ::FindResource(NULL, strResName, strResType);
	HGLOBAL	hMem	= ::LoadResource(NULL, hRes);
	DWORD	dwSize	= ::SizeofResource(NULL, hRes);
	
	                                                                                           // 写入文件
	DWORD dwWrite = 0;  	                                                                   // 返回写入字节
	::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);
	::CloseHandle(hFile);

	return true;
}//*


PipeList::PipeList(){
	                                                                                           // 产生临时文件的文件名
	TCHAR tmpwav[_MAX_PATH];
	::GetTempPath(_MAX_PATH,tmpwav);
	_tcscat_s(tmpwav, _T("testapp_background.wav"));		
	                                                                                           // 将wav 资源提取为临时文
	                                                                                           //ExtractResource(tmpwav,_T("WAVE"), "background.mp3");
	                                                                                           // 注：如果wave资源的 ID 为宏 IDR_BACKGROUND，这样做：
	ExtractResource(tmpwav, _T("WAVE"), MAKEINTRESOURCE(IDR_WAVE_POINT));
	                                                                                           // 打开音乐
	          //TCHAR mcicmd[300];
	_stprintf_s(mcicmd, _T("open \"%s\" alias mymusic"),tmpwav);		
	//mciSendString(mcicmd, NULL,0, NULL);
	                                                                                           // 播放音乐
	//mciSendString(_T("play mymusic"), NULL, 0, NULL);
	                                                                                           // 停止播放并关闭音乐
	//mciSendString(("stop mymusic"), NULL, 0, NULL);
	//mciSendString(("close mymusic"), NULL, 0, NULL);
	                                                                                           // 删除临时文件
	
}//*

   
 //如果需要关闭柱子的声音，可将应勇符号删去！！！！！！但是注意，系统随时保存数据，未清除多余数据     

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
