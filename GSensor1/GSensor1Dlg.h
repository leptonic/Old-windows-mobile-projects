// GSensor1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

//xxx.h �ļ�

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


// CGSensor1Dlg �Ի���
class CGSensor1Dlg : public CDialog
{
// ����
public:
	CGSensor1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	SENSORDATA OrcleData;//��֮ǰ������

// �Ի�������
	enum { IDD = IDD_GSENSOR1_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);


};
