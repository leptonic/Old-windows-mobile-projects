// GSensor1Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"

//xxx.h 文件

typedef struct _SENSORDATA
{
	SHORT   TiltX;          // From -1000 to 1000 (about), 0 is flat
	SHORT   TiltY;          // From -1000 to 1000 (about), 0 is flat
	SHORT   Orientation;    // From -1000 to 1000 (about)
	// 0 = Straight up, -1000 = Flat, 1000 = Upside down
	WORD    Unknown1;       // Always zero
	DWORD   AngleY;         // From 0 to 359
	DWORD   AngleX;         // From 0 to 359
	DWORD   Unknown2;       // Bit field?
} SENSORDATA, *PSENSORDATA;


// CGSensor1Dlg 对话框
class CGSensor1Dlg : public CDialog
{
// 构造
public:
	CGSensor1Dlg(CWnd* pParent = NULL);	// 标准构造函数

	HINSTANCE hdll;
	typedef HANDLE  (*hTCSensorOpen)(HANDLE x);
	typedef void  (*hTCSensorClose)(HANDLE x);
	typedef DWORD  (*hTCSensorGetDataOutput)(HANDLE x, PSENSORDATA y);
	hTCSensorOpen  HTCSensorOpen;
	hTCSensorClose HTCSensorClose;
	hTCSensorGetDataOutput HTCSensorGetDataOutput;

	BOOL ris;
	BOOL lis;
/*	int lianxu;*/
	CWnd *pWndr;
	CWnd *pWndl;
	SENSORDATA OrcleData;//震动之前的数据

// 对话框数据
	enum { IDD = IDD_GSENSOR1_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);


};
