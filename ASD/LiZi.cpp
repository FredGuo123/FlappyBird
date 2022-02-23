
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

#include "LiZi.h"
#define bird_time 0
#define land_time 1

#define before_game 0
#define during_game 1
#define dying_game  2
#define end_game    3
#define start_game  4
#define bird_delay  4

CMyApp myapp;


BOOL CMyApp::InitInstance()
{
	m_pMainWnd=new CMainWindow;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}//*

BEGIN_MESSAGE_MAP(CMainWindow,CFrameWnd)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_CLOSE ()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
    END_MESSAGE_MAP()


CMainWindow::CMainWindow()
{
	CString strWndClass = AfxRegisterWndClass (
        CS_HREDRAW | CS_VREDRAW,
        myapp.LoadStandardCursor (IDC_ARROW),
        (HBRUSH) (COLOR_3DFACE + 1),
        myapp.LoadIcon (IDIGNORE)
    );

    Create (strWndClass,_T("FlappyBird"),WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX);
	                                                                      //������λ�úͳߴ�
	CRect rect(0, 0, 286, 512);                                           //����ͻ������ھ�����״
    CalcWindowRect (&rect);                                               //���ݷֱ��ʡ��˵�...���㴰�ھ��δ�С�������ڴ��ڴ�������ã�

    SetWindowPos (NULL, 0, 0, rect.Width (), rect.Height (),
        SWP_NOZORDER | SWP_NOMOVE | SWP_NOREDRAW);

	HICON a = AfxGetApp()->LoadIcon(IDI_ICON1);
	SetIcon(a,true);                                                      //����ͼ��

	CDC *cDC=this->GetDC();
	GetClientRect(&m_client);                                             //ͨ��ָ���ô��ڵĳߴ�
	m_cacheDC.CreateCompatibleDC(cDC);
	m_bgcDC.CreateCompatibleDC(cDC);
	m_tempcDC.CreateCompatibleDC(cDC);
	m_tempBitmap.CreateCompatibleBitmap(cDC,m_client.Width(),m_client.Height());
	m_bgBitmap.LoadBitmap(IDB_BITMAP1);
	m_cacheDC.SelectObject(&m_tempBitmap);
	ReleaseDC(cDC); 

	srand((unsigned)time(NULL));                                          //���ü�ʱ��
	bg_state=rand()%2;game_state=0;last_state=0;
	goals=best_goals=0;
}//*
                                                                            //��Ϣ
int CMainWindow::OnCreate(LPCREATESTRUCT lpcs)
{
	if (CFrameWnd::OnCreate (lpcs) == -1)
        return -1;

    if (!SetTimer (bird_time,100, NULL)) 
	{
        MessageBox (_T ("Error: SetTimer failed"));
        return -1;
    }
    if (!SetTimer (land_time,60, NULL)) 
	{
        MessageBox (_T ("Error: SetTimer failed"));
        return -1;
    }
    return 0;
}
void CMainWindow::OnTimer(UINT nTimerID)
{                                                                               //չʾ��Ϸ��ʼ������״̬�Լ����ڷ����е�����״̬
	switch(nTimerID)
	{                                                                           //ʹ��Ƕ����������λѡ��
	case bird_time:                                                             //�ڴ˿��Ը���λ������һ�㽨�飺Ҳ����Ԥ������ָ�����ʵ��ָ��
		if(game_state==before_game)bird.logic(before_game,game_state);          //��ʼǰ
		break;
	case land_time:
		if(game_state==before_game)
		{                                                                       //��ʼǰ
			land.logic();                                                       //·
		}
		else if(game_state==during_game)
		{                                                                       //��Ϸ��
			if(bird.state!=bird_delay)land.logic();                             //����·��logic���ɺ���
			bird.logic(1,game_state);                                           //�������˶�
			if(bird.state!=bird_delay)pipe.logic(goals,bird,game_state);        //�ܵ�
		}
		else if(game_state==dying_game)
		{                                                                       //ʧ�ܣ�������������
			bird.logic(2,game_state);                                           //����״̬����ֱ����
		}
		else if(game_state==end_game)
		{                                                                       //��ʾgame-over+�Ʒְ�+2����ť
			if(panel.state==finish)button.logic(game_state);
			if(last_state>=10)panel.logic(goals,best_goals);
		}
		else if(game_state==start_game){                                        //���¿�ʼ
			restart();
			game_state=before_game;
		}
		break;
	default:break;
	}
	draw();
}//*


void CMainWindow::OnClose()
{                                                                                //չʾ����������ʱ�������״̬������������ִ�����֮����ִ��ָ��
    KillTimer(0);
	KillTimer(1);
    CFrameWnd::OnClose ();
}//*


void CMainWindow::OnLButtonDown(UINT nFlags, CPoint point)
{
	if(game_state==0)
	{
		game_state=1;
		pipe.add();
		bird.jump();
	}
	else if(game_state==1)
	{
		bird.jump();
	}
	else if(game_state==3)
	{
		button.click(point);
	}
}//*


void CMainWindow::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags){
	if(game_state==end_game && (::GetKeyState (VK_CONTROL) < 0)){
		screenShot(CRect(0,0,572,1024),0,0,"ABCDEFG.bmp");
	}
	if(game_state==during_game && (::GetKeyState (VK_SHIFT) < 0)){
		goals+=10;
	}
}//*


void CMainWindow::draw()
{

	CDC *cDC=this->GetDC();                                                           //��õ�ǰ���ڵ�IDC   

	m_bgcDC.SelectObject(&m_bgBitmap); 
	pic.bg[bg_state].TBlt(0,0,&m_cacheDC,&m_bgcDC);                                   //����
	pipe.draw(pic,&m_cacheDC,&m_bgcDC);                                               //��������
	land.draw(pic,&m_cacheDC,&m_bgcDC);                                               //��·
	bird.paint(&m_cacheDC,&m_tempcDC);

	if(game_state==before_game ||game_state==during_game ||game_state==dying_game)
	{
		int copy=goals,wei=1;                                                         //��ʾ����
		while(copy/10){wei++;copy/=10;}copy=goals;
		int this_wei,first_pos=142-12*wei-wei/2;
		while(wei--)
		{
			this_wei=copy%10;
			copy/=10;
			pic.font[this_wei].TBlt(first_pos+wei*25,60,&m_cacheDC,&m_bgcDC);//����
		}
		
		if(game_state==before_game)
		{
			pic.text_ready.TBlt(50,150,&m_cacheDC,&m_bgcDC);                           //readyͼ��
			pic.tutorial.TBlt(85,220,&m_cacheDC,&m_bgcDC);                             //ָʾ
		}
	}
	else if(game_state==end_game || game_state==start_game)
	{
		if(last_state==0)
		{
			pic.text_game_over.TBlt(50,105,&m_cacheDC,&m_bgcDC);                       //game_overͼ��
			last_state=1;
			PlaySound(MAKEINTRESOURCE(IDR_WAVE_PANEL),AfxGetResourceHandle(),SND_RESOURCE|SND_ASYNC);
		}
		else if(last_state>=1)
		{
			pic.text_game_over.TBlt(50,115,&m_cacheDC,&m_bgcDC);                       //game_overͼ��(0->1ʵ�ֶ���Ч����
			if(last_state==10)
			{
				panel.draw(pic,&m_cacheDC,&m_bgcDC);                                   //���ϼƷְ�
				if(panel.state==2)
				{
					button.draw(pic,&m_cacheDC,&m_bgcDC);
				}
			}
			else last_state++;
		}
	}

	m_cacheDC.SelectObject(&m_tempBitmap);
	cDC->BitBlt(0,0,m_client.Width(),m_client.Height(),&m_cacheDC,0,0,SRCCOPY); 

	ReleaseDC(cDC);
}//*


void CMainWindow::restart()
{
	bg_state=rand()%2;
	game_state=0;
	last_state=0;
	goals=0;




	pipe.recover();//����
	land.recover();
	bird.recover();//��
	panel.recover();//�Ʒְ�
}//*


void CMainWindow::screenShot(CRect rect,int left,int top,char *name)
{                                                                                      //��ȡ���ڵĴ�С��λ�ã����֣�������Ĭ��·����)
    CBitmap*  m_pBitmap; 	                                                           // �������Ա
	CFrameWnd* pMainFrame = (CFrameWnd*)AfxGetMainWnd();                               // ��ý�ͼ���ڵ�ָ�룬Ĭ��Ϊ�����ڣ����Ը���Ϊ�����Ĵ��ڡ�
   	CPaintDC   dc(pMainFrame); 
	
	m_pBitmap=new   CBitmap;   
	m_pBitmap->CreateCompatibleBitmap(&dc,rect.Width(),rect.Height());   

	CDC   memDC;  
	memDC.CreateCompatibleDC(&dc); 
	CBitmap memBitmap, *oldmemBitmap;                                                  // ��������Ļ���ݵ�bitmap
    memBitmap.CreateCompatibleBitmap(&dc, rect.Width(),rect.Height());
	

    oldmemBitmap = memDC.SelectObject(&memBitmap);//��memBitmapѡ���ڴ�DC
    memDC.BitBlt(0, 0, rect.Width(),rect.Height(), &dc,left, top, SRCCOPY);            // ����߶ȿ��
	BITMAP bmp;
    memBitmap.GetBitmap(&bmp);                                                         // ���λͼ��Ϣ 
    
    FILE *fp = fopen(name, "w+b");
	
    BITMAPINFOHEADER bih = {0};                                                        // λͼ��Ϣͷ
    bih.biBitCount = bmp.bmBitsPixel;                                                  // ÿ�������ֽڴ�С
    bih.biCompression = BI_RGB;    
    bih.biHeight = bmp.bmHeight;                                                       // �߶�
    bih.biPlanes = 1;
    bih.biSize = sizeof(BITMAPINFOHEADER);
    bih.biSizeImage = bmp.bmWidthBytes * bmp.bmHeight;                                 // ͼ�����ݴ�С
    bih.biWidth = bmp.bmWidth;                                                         // ���
    
    BITMAPFILEHEADER bfh = {0};                                                        // λͼ�ļ�ͷ
    bfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);               // ��λͼ���ݵ�ƫ����
    bfh.bfSize = bfh.bfOffBits + bmp.bmWidthBytes * bmp.bmHeight;                      // �ļ��ܵĴ�С
    bfh.bfType = (WORD)0x4d42;
    
    fwrite(&bfh, 1, sizeof(BITMAPFILEHEADER), fp);                                     //д��λͼ�ļ�ͷ
    
    fwrite(&bih, 1, sizeof(BITMAPINFOHEADER), fp);                                     //д��λͼ��Ϣͷ
    
    byte * p = new byte[bmp.bmWidthBytes * bmp.bmHeight];                              //�����ڴ汣��λͼ����
	
    GetDIBits(memDC.m_hDC, (HBITMAP) memBitmap.m_hObject, 0, rect.Height(), p, 
    (LPBITMAPINFO) &bih, DIB_RGB_COLORS);                                              //��ȡλͼ����
	
    fwrite(p, 1, bmp.bmWidthBytes * bmp.bmHeight, fp);                                 //д��λͼ����
    delete [] p;	
    fclose(fp);
	memDC.SelectObject(oldmemBitmap);
	memDC.DeleteDC();
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




	



