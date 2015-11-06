// GSensor1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GSensor1.h"
#include "GSensor1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define REGMAXLEN 200
// CGSensor1Dlg 对话框

CGSensor1Dlg::CGSensor1Dlg(CWnd* pParent /*=NULL*/)
: CDialog(CGSensor1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGSensor1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CGSensor1Dlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP

	ON_WM_TIMER()

END_MESSAGE_MAP()


// CGSensor1Dlg 消息处理程序

BOOL CGSensor1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();


	pWndl = GetDlgItem( IDC_STATICl );      //获取控件指针，IDC_EDIT1为控件ID号
	pWndl->ShowWindow( SW_HIDE );     //隐藏控件

	pWndr = GetDlgItem( IDC_STATICr );      //获取控件指针，IDC_EDIT1为控件ID号
	pWndr->ShowWindow( SW_HIDE );     //隐藏控件


	ris=0;
	lis=0;

	hdll=LoadLibrary(L"HTCSensorSDK.dll");
	if(hdll!=NULL)
	{
		HTCSensorOpen=(hTCSensorOpen)GetProcAddress(hdll,L"HTCSensorOpen");
		HTCSensorClose=(hTCSensorClose)GetProcAddress(hdll,L"HTCSensorClose");
		HTCSensorGetDataOutput=(hTCSensorGetDataOutput)GetProcAddress(hdll,L"HTCSensorGetDataOutput");

	}
	else
	{
		MessageBoxW(L"HTCGSensor Loading Error");
	}
	HTCSensorOpen(this);
	HTCSensorGetDataOutput(this,&OrcleData);

	SetTimer(1,10,NULL);
	SetTimer(2,1000,NULL);

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
/*	lianxu=0;*/
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CGSensor1Dlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_GSENSOR1_DIALOG_WIDE) : 
		MAKEINTRESOURCE(IDD_GSENSOR1_DIALOG));
	}
}
#endif


void CGSensor1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent==1)
	{
		SENSORDATA OutData;
		HTCSensorGetDataOutput(this,&OutData);

		// 		
		if((OutData.TiltX>(OrcleData.TiltX+10))&&!ris)	

		{
			PlaySound(MAKEINTRESOURCE(IDR_WAVE1),AfxGetResourceHandle(),SND_ASYNC|SND_RESOURCE);
			pWndl->ShowWindow( SW_HIDE ); 
			pWndr->ShowWindow( SW_SHOW ); 
			ris=1;
			lis=0;
/*             lianxu++;*/
		}

		// 		
		if((OutData.TiltX<(OrcleData.TiltX-10))&&!lis)	

		{
			PlaySound(MAKEINTRESOURCE(IDR_WAVE2),AfxGetResourceHandle(),SND_ASYNC|SND_RESOURCE);
			ris=0;
			lis=1;
			pWndr->ShowWindow( SW_HIDE ); 
			pWndl->ShowWindow( SW_SHOW ); 
/*		 lianxu++;*/
		}

		if((OutData.TiltX>(OrcleData.TiltX-9))&&(OutData.TiltX<(OrcleData.TiltX+9))	)
		{
			pWndr->ShowWindow( SW_HIDE ); 
			pWndl->ShowWindow( SW_HIDE ); 
			
		}
		// 
		// 			KillTimer(1);
		// 			HTCSensorClose(this);// TODO: 在此添加控件通知处理程序代码
		// 			FreeLibrary(hdll);
		SetTimer(1,50,NULL);

	}
// if(nIDEvent==2)
// {
// 	if(lianxu>4)
// 	{
// 	PlaySound(MAKEINTRESOURCE(IDR_WAVE3),AfxGetResourceHandle(),SND_ASYNC|SND_RESOURCE);
// 	}
// 	lianxu=0;
// 	SetTimer(2,1000,NULL);
// }


	CDialog::OnTimer(nIDEvent);


}









