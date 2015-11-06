//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Version.h"
#include "Security.h"
#include "dwdptest.h"
#include "Pri.h"
//#include "port.h"
#include "string.h"
#include <windows.h>
#include <stdio.h>
#include "prompt.h"
#include "About.h"
#include "Version.h"
#include "V3_KEY.h"
//---------------------------------------------------------------------------
int g_hPort;// = 0; /*串口句柄 */
bool g_bOpenPort = false;  /*握手是否成功 true:表示成功 false:表示失败*/
bool g_bAllWrited = false;
bool g_bTimeout = false; //判断是否超时, false:表示末超时 true:表示超时

extern bool g_bSetBanner;
extern bool g_bSmsTemplateWrite;
extern bool g_bSmsTemplateRead;

//int ComPort_Handle=0;
//#define COM_PORT 13
#define COMM_BAUD_RATE 115200
//---------------------------------------------------------------------------
typedef struct
{
    char chItemName[10];
    char strHWVersion[20];
    char strSWVersion[50];
    char strEEPVersion[8];
    char strFFSVersion[8];
}VERSIONINFO_STRUCT;

typedef struct
{
    char chItemName[10];
    char chMccMnc[4][6];
    BYTE mccmnc_lock[2];
}MCC_STRUCT;

typedef struct
{
	char itemname[20];
	BYTE simpin[2];
	BYTE autopinlock[2];
	char defaultpin[8];
	char autopin[8];
	BYTE randompin[2];
	BYTE imsilock[2];
	//char imsiNumber[20];
}SIM_IMSI_STRUCT;

typedef struct
{
	char itemname[20];
	BYTE autokeylock[2];
	BYTE gid1lock[2];
	BYTE gid2lock[2];
}OTHERLOCK_STRUCT;

typedef struct
{
	char itemname[20];
	char voiceNumber[42];
}VOICEMAIL_STRUCT;

typedef struct
{
	char itemname[20];
	char smsTemplate[10][31];
}SMSTEMPLATE_STRUCT;

typedef struct
{
	char itemname[20];
	char filePath[2][100];
}BANNER_STRUCT;

typedef struct
{
	char itemname[20];
	char emergencyNumber[3][4];
}EMERGENCYNUMBER_STRUCT;

typedef struct
{
    char itemname[20];
    BYTE bSave[2];
    char manufactur[3];
    char version[3];
    char key_value[5][33];
}V3_KEY_STRUCT;
//---------------------------------------------------------------------------
VERSIONINFO_STRUCT      versionInfo;
MCC_STRUCT              mcc_struct;
SIM_IMSI_STRUCT         sim_imsi;
OTHERLOCK_STRUCT        otherlock;
VOICEMAIL_STRUCT        voicemail;
SMSTEMPLATE_STRUCT      smsTemplate;
BANNER_STRUCT           banner;
EMERGENCYNUMBER_STRUCT  emergencyNumber;
V3_KEY_STRUCT           v3key;
//---------------------------------------------------------------------------
/*获得数据保存到文件中*/
bool   GetMCCMNC();       		//获得MCC/MNC数据
bool   GetSIM_IMSI();       	//得到SIM/IMSI数据
bool   GetOtherLock(); 			//得到其它数据
bool   GetVoiceMail();  		//得到VOICEMAIL号码
bool   GetSmsTemplate();		//得到短消息模板
bool   GetBannerPath(); 		//得到开机动画的路径
bool   GetEmergencyNumber();	//得到紧急呼叫号码
bool   GetV3key();              //得到V3密钥码

//---------------------------------------------------------------------------
/*从文件中读出数据,并进行各项功能设置*/
void   SetMCCMNC(MCC_STRUCT* mcc);  						    //Set MCC/MNC DATA   设置MCC/MNC
void   SetSIM_IMSI(SIM_IMSI_STRUCT* pSim); 						//设置SIM_IMSI
void   SetOtherLock(OTHERLOCK_STRUCT* pOtherLock); 				//设置其它项
void   SetVoiceMail(VOICEMAIL_STRUCT* pVoiceMail); 				//设置VOICEMAIL号码
void   SetSmsTemplate(SMSTEMPLATE_STRUCT *pSms); 				//设置短消息模板
void   SetBannerPath(BANNER_STRUCT* pBanner);  					//设置开机动画图片的路径
void   SetEmergencyNumber(EMERGENCYNUMBER_STRUCT* pEmNumber); 	//设置紧急呼叫号码
void   SetV3keyCode(V3_KEY_STRUCT* pV3key); 	                //从文本文件中读出V3密钥码
//---------------------------------------------------------------------------

/*********************************************************************
                           判断字符串是否为空
*********************************************************************/
bool StringIsEmpty(String str, int nLen)
{
    //char chTemp[80];
    if(str == "" || str.Length() != nLen)
    {
        return false;
    }
    /*memset(chTemp, 0, sizeof(chTemp));
    memcpy(chTemp, str.c_str(), nLen);
    for(int i = 0; i < nLen; i++)
    {
        if()
    } */
    return true;
}
/*********************************************************************
                           获得MCC/MNC数据
*********************************************************************/
bool GetMCCMNC()
{
    memset(&mcc_struct, 0 , sizeof(mcc_struct));
    sprintf(mcc_struct.chItemName, "MCC/MNC");
    if(!StringIsEmpty(Security_Form->Edit_MCC1->Text, 5)
    || !StringIsEmpty(Security_Form->Edit_MCC2->Text, 5)
    || !StringIsEmpty(Security_Form->Edit_MCC3->Text, 5)
    || !StringIsEmpty(Security_Form->Edit_MCC4->Text, 5))
    {
        //ShowMessage("MCC/MNC1非法");
        return false;
    }
    strcpy(mcc_struct.chMccMnc[0], Security_Form->Edit_MCC1->Text.c_str());
    strcpy(mcc_struct.chMccMnc[1], Security_Form->Edit_MCC2->Text.c_str());
    strcpy(mcc_struct.chMccMnc[2], Security_Form->Edit_MCC3->Text.c_str());
    strcpy(mcc_struct.chMccMnc[3], Security_Form->Edit_MCC4->Text.c_str());
    if(Security_Form->RadioButton_MCC_Disable->Checked == true)
    {
        mcc_struct.mccmnc_lock[0] = '0';
    }
    else
    {
        mcc_struct.mccmnc_lock[0] = '1';
    }
    return true;
}


/*********************************************************************
                           获得SIM/IMSI数据
*********************************************************************/
bool GetSIM_IMSI()
{
    memset(&sim_imsi, 0, sizeof(sim_imsi));
    sprintf(sim_imsi.itemname, "SIM_IMSI");
    if(Security_Form->RadioButton_SIM_Disable->Checked == true)
    {
        sim_imsi.simpin[0] = '0';
    }
    else
    {
        sim_imsi.simpin[0] = '1';
    }
    if(Security_Form->ComboBox_AutoSIMState->Text == ""
    || !StringIsEmpty(Security_Form->Edit_SIM_PIN_Default->Text, Security_Form->Edit_SIM_PIN_Default->Text.Length())
    || !StringIsEmpty(Security_Form->Edit_SIM_PIN_Locked->Text, Security_Form->Edit_SIM_PIN_Locked->Text.Length()))
    {
        return false;
    }
    if(strcmp(Security_Form->ComboBox_AutoSIMState->Text.c_str(), "Deactive") == 0)
    {
        sim_imsi.autopinlock[0] = '0';
    }
    else
    {
        sim_imsi.autopinlock[0] = '1';
    }
    strcpy(sim_imsi.defaultpin , Security_Form->Edit_SIM_PIN_Default->Text.c_str());
    strcpy(sim_imsi.autopin, Security_Form->Edit_SIM_PIN_Locked->Text.c_str());
    if(Security_Form->RadioButton_IMSI_Disable->Checked == true)
    {
        sim_imsi.imsilock[0] = '0';
    }
    else
    {
        sim_imsi.imsilock[0] = '1';
    }
    return true;
    //strcpy(sim_imsi.imsiNumber, Security_Form->Edit_IMSINumber->Text.c_str());
}


/*********************************************************************
                       获得其它一些加锁数据信息
*********************************************************************/
bool GetOtherLock()
{
    sprintf(otherlock.itemname, "OTHER LOCK");
    if(Security_Form->RadioButton_AutoKeyLock->Checked == true)
    {
        otherlock.autokeylock[0] = '1';
    }
    else
    {
        otherlock.autokeylock[0] = '0';
    }
    if(Security_Form->RadioButton_Gid1_Lock->Checked == true)
    {
        otherlock.gid1lock[0] = '1';
    }
    else
    {
        otherlock.gid1lock[0] = '0';
    }
    if(Security_Form->RadioButton_Gid2_Lock->Checked == true)
    {
        otherlock.gid2lock[0] = '1';
    }
    else
    {
        otherlock.gid2lock[0] = '0';
    }
    return true;
}


/*********************************************************************
                           获得VOICEMAIL号码
*********************************************************************/
bool GetVoiceMail()
{
    memset(&voicemail, 0, sizeof(voicemail));
    sprintf(voicemail.itemname, "VOICEMAIL");
    if(!StringIsEmpty(PRI_Form->Edit_VoiceMail->Text, PRI_Form->Edit_VoiceMail->Text.Length()))
    {
        return false;
    }
    strcpy(voicemail.voiceNumber, PRI_Form->Edit_VoiceMail->Text.c_str());
    return true;
}


/*********************************************************************
                           获得短消息模板
*********************************************************************/
bool GetSmsTemplate()
{
    memset(&smsTemplate, 0, sizeof(smsTemplate));
    sprintf(smsTemplate.itemname, "SMSTEMPLATE");
    if(!StringIsEmpty(PRI_Form->Edit_SMSTemplate1->Text, PRI_Form->Edit_SMSTemplate1->Text.Length())
    || !StringIsEmpty(PRI_Form->Edit_SMSTemplate2->Text, PRI_Form->Edit_SMSTemplate2->Text.Length())
    || !StringIsEmpty(PRI_Form->Edit_SMSTemplate3->Text, PRI_Form->Edit_SMSTemplate3->Text.Length())
    || !StringIsEmpty(PRI_Form->Edit_SMSTemplate4->Text, PRI_Form->Edit_SMSTemplate4->Text.Length())
    || !StringIsEmpty(PRI_Form->Edit_SMSTemplate5->Text, PRI_Form->Edit_SMSTemplate5->Text.Length())
    || !StringIsEmpty(PRI_Form->Edit_SMSTemplate6->Text, PRI_Form->Edit_SMSTemplate6->Text.Length())
    || !StringIsEmpty(PRI_Form->Edit_SMSTemplate7->Text, PRI_Form->Edit_SMSTemplate7->Text.Length())
    || !StringIsEmpty(PRI_Form->Edit_SMSTemplate8->Text, PRI_Form->Edit_SMSTemplate8->Text.Length())
    || !StringIsEmpty(PRI_Form->Edit_SMSTemplate9->Text, PRI_Form->Edit_SMSTemplate9->Text.Length())
    || !StringIsEmpty(PRI_Form->Edit_SMSTemplate10->Text, PRI_Form->Edit_SMSTemplate10->Text.Length()))
    {
        return false;
    }
    strcpy(smsTemplate.smsTemplate[0], PRI_Form->Edit_SMSTemplate1->Text.c_str());
    strcpy(smsTemplate.smsTemplate[1], PRI_Form->Edit_SMSTemplate2->Text.c_str());
    strcpy(smsTemplate.smsTemplate[2], PRI_Form->Edit_SMSTemplate3->Text.c_str());
    strcpy(smsTemplate.smsTemplate[3], PRI_Form->Edit_SMSTemplate4->Text.c_str());
    strcpy(smsTemplate.smsTemplate[4], PRI_Form->Edit_SMSTemplate5->Text.c_str());
    strcpy(smsTemplate.smsTemplate[5], PRI_Form->Edit_SMSTemplate6->Text.c_str());
    strcpy(smsTemplate.smsTemplate[6], PRI_Form->Edit_SMSTemplate7->Text.c_str());
    strcpy(smsTemplate.smsTemplate[7], PRI_Form->Edit_SMSTemplate8->Text.c_str());
    strcpy(smsTemplate.smsTemplate[8], PRI_Form->Edit_SMSTemplate9->Text.c_str());
    strcpy(smsTemplate.smsTemplate[9], PRI_Form->Edit_SMSTemplate10->Text.c_str());
    return true;
}


/*********************************************************************
                     获得Banner开机动画图片的路径
*********************************************************************/
bool GetBannerPath()
{
    memset(&banner, 0, sizeof(banner));
    sprintf(banner.itemname, "SET BANNER");
    if(!StringIsEmpty(PRI_Form->Edit_Banner_File1->Text, PRI_Form->Edit_Banner_File1->Text.Length())
    || !StringIsEmpty(PRI_Form->Edit_Banner_File2->Text, PRI_Form->Edit_Banner_File2->Text.Length()))
    {
        return false;
    }
    strcpy(banner.filePath[0], PRI_Form->Edit_Banner_File1->Text.c_str());
    strcpy(banner.filePath[1], PRI_Form->Edit_Banner_File2->Text.c_str());
    return true;
}


/*********************************************************************
                           获得紧急呼叫号码
*********************************************************************/
bool GetEmergencyNumber()
{
    memset(&emergencyNumber, 0, sizeof(emergencyNumber));
    sprintf(emergencyNumber.itemname, "EMERGENCY NUMBER");
    if(!StringIsEmpty(PRI_Form->Edit_EM_Number1->Text, PRI_Form->Edit_EM_Number1->Text.Length())
    || !StringIsEmpty(PRI_Form->Edit_EM_Number2->Text, PRI_Form->Edit_EM_Number2->Text.Length())
    || !StringIsEmpty(PRI_Form->Edit_EM_Number3->Text, PRI_Form->Edit_EM_Number3->Text.Length()))
    {
        return false;
    }
    strcpy(emergencyNumber.emergencyNumber[0], PRI_Form->Edit_EM_Number1->Text.c_str());
    strcpy(emergencyNumber.emergencyNumber[1], PRI_Form->Edit_EM_Number2->Text.c_str());
    strcpy(emergencyNumber.emergencyNumber[2], PRI_Form->Edit_EM_Number3->Text.c_str());
    return true;
}
/*********************************************************************
                Get the V3_KEY In order to save it
*********************************************************************/
bool GetV3key()
{
    memset(&v3key, 0, sizeof(v3key));
    if(Form_V3KEY->CheckBox_SaveV3->Checked)
    {
        if(!StringIsEmpty(Form_V3KEY->Edit1->Text, 2)
        || !StringIsEmpty(Form_V3KEY->Edit2->Text, 2)
        || !StringIsEmpty(Form_V3KEY->Edit3->Text, 32)
        || !StringIsEmpty(Form_V3KEY->Edit4->Text, 32)
        || !StringIsEmpty(Form_V3KEY->Edit5->Text, 32)
        || !StringIsEmpty(Form_V3KEY->Edit6->Text, 32)
        || !StringIsEmpty(Form_V3KEY->Edit7->Text, 32))
        {
            return false;
        }
        sprintf(v3key.itemname, "V3KEY");
        v3key.bSave[0] = '1';
        //if(Form_V3KEY->Edit_Manufactur->Text)
        strcpy(v3key.manufactur, Form_V3KEY->Edit1->Text.c_str());
        strcpy(v3key.version, Form_V3KEY->Edit2->Text.c_str());
        strcpy(v3key.key_value[0], Form_V3KEY->Edit3->Text.c_str());
        strcpy(v3key.key_value[1], Form_V3KEY->Edit4->Text.c_str());
        strcpy(v3key.key_value[2], Form_V3KEY->Edit5->Text.c_str());
        strcpy(v3key.key_value[3], Form_V3KEY->Edit6->Text.c_str());
        strcpy(v3key.key_value[4], Form_V3KEY->Edit7->Text.c_str());
        return true;
    }
    return false;
}
/*********************************************************************
                           设置MCC/MNC数据
*********************************************************************/
void SetMCCMNC(MCC_STRUCT* pMcc)
{
    //设置时,把项都清空
    Security_Form->Edit_MCC1->Text = "";
    Security_Form->Edit_MCC2->Text = "";
    Security_Form->Edit_MCC3->Text = "";
    Security_Form->Edit_MCC4->Text = "";
    Security_Form->RadioButton_SIM_Disable->Checked = true;
    //设置值
    Security_Form->Edit_MCC1->Text = pMcc->chMccMnc[0];
    Security_Form->Edit_MCC2->Text = pMcc->chMccMnc[1];
    Security_Form->Edit_MCC3->Text = pMcc->chMccMnc[2];
    Security_Form->Edit_MCC4->Text = pMcc->chMccMnc[3];
    if(pMcc->mccmnc_lock[0] == '0')
    {
        Security_Form->RadioButton_MCC_Disable->Checked = true;
    }
    else
    {
        Security_Form->RadioButton_MCC_Enable->Checked = true;
    }
}

/*********************************************************************
                          设置SIM_IMSI
*********************************************************************/
void   SetSIM_IMSI(SIM_IMSI_STRUCT* pSim)
{
	Security_Form->RadioButton_SIM_Disable->Checked = true;
    Security_Form->ComboBox_AutoSIMState->Text = "Deactive";
    Security_Form->Edit_SIM_PIN_Default->Text = "";
    Security_Form->Edit_SIM_PIN_Locked->Text = "";
    Security_Form->CheckBox_Random_SIM_PIN->Checked = false;
    Security_Form->RadioButton_IMSI_Disable->Checked = false;
    //Security_Form->Edit_IMSINumber->Text = "";
    //pSim->imsiNumber[20] = '\0';
    //Security_Form->Edit_IMSINumber->Text = pSim->imsiNumber;
    if(pSim->simpin[0] == '0')
    {
        Security_Form->RadioButton_SIM_Disable->Checked = true;
    }
    else
    {
        Security_Form->RadioButton_SIM_Enable->Checked = true;
    }
    if(pSim->autopinlock[0] == '0')
    {
        Security_Form->ComboBox_AutoSIMState->Text = "Deactive";
    }
    else
    {
        Security_Form->ComboBox_AutoSIMState->Text = "Active";
    }
    Security_Form->Edit_SIM_PIN_Default->Text = pSim->defaultpin;
    Security_Form->Edit_SIM_PIN_Locked->Text = pSim->autopin;
    if(pSim->randompin[0] == '0')
    {
        Security_Form->CheckBox_Random_SIM_PIN->Checked = true;
    }
    else
    {
        Security_Form->CheckBox_Random_SIM_PIN->Checked = true;
    }
    if(pSim->imsilock[0] == '0')
    {
        Security_Form->RadioButton_IMSI_Disable->Checked = true;
    }
    else
    {
        Security_Form->RadioButton_IMSI_Enable->Checked = true;
    }
}

/*********************************************************************
                          设置其它项的加锁与否
*********************************************************************/
void   SetOtherLock(OTHERLOCK_STRUCT* pOtherLock)
{
    Security_Form->RadioButton_AutoKey_Unlock->Checked = true;
    Security_Form->RadioButton_Gid1_Unlock->Checked = true;
    Security_Form->RadioButton_Gid2_Unlock->Checked = true;

    if(pOtherLock->autokeylock[0] == '0')
    {
        Security_Form->RadioButton_AutoKey_Unlock->Checked = true;
    }
    else
    {
        Security_Form->RadioButton_AutoKeyLock->Checked = true;
    }
    if(pOtherLock->gid1lock[0] == '0')
    {
        Security_Form->RadioButton_Gid1_Unlock->Checked = true;
    }
    else
    {
        Security_Form->RadioButton_Gid1_Lock->Checked = true;
    }
    if(pOtherLock->gid2lock[0] == '0')
    {
        Security_Form->RadioButton_Gid2_Unlock->Checked = true;
    }
    else
    {
        Security_Form->RadioButton_Gid2_Lock->Checked = true;
    }
}

/*********************************************************************
                          设置VOICEMAIL号码 
*********************************************************************/
void   SetVoiceMail(VOICEMAIL_STRUCT* pVoiceMail)
{
    PRI_Form->Edit_VoiceMail->Text = "";

    PRI_Form->Edit_VoiceMail->Text = pVoiceMail->voiceNumber;
}


/*********************************************************************
                           设置短消息模板
*********************************************************************/
void   SetSmsTemplate(SMSTEMPLATE_STRUCT *pSms)
{
    PRI_Form->Edit_SMSTemplate1->Text = "";
    PRI_Form->Edit_SMSTemplate2->Text = "";
    PRI_Form->Edit_SMSTemplate3->Text = "";
    PRI_Form->Edit_SMSTemplate4->Text = "";
    PRI_Form->Edit_SMSTemplate5->Text = "";
    PRI_Form->Edit_SMSTemplate6->Text = "";
    PRI_Form->Edit_SMSTemplate7->Text = "";
    PRI_Form->Edit_SMSTemplate8->Text = "";
    PRI_Form->Edit_SMSTemplate9->Text = "";
    PRI_Form->Edit_SMSTemplate10->Text = "";

    PRI_Form->Edit_SMSTemplate1->Text = pSms->smsTemplate[0];
    PRI_Form->Edit_SMSTemplate2->Text = pSms->smsTemplate[1];
    PRI_Form->Edit_SMSTemplate3->Text = pSms->smsTemplate[2];
    PRI_Form->Edit_SMSTemplate4->Text = pSms->smsTemplate[3];
    PRI_Form->Edit_SMSTemplate5->Text = pSms->smsTemplate[4];
    PRI_Form->Edit_SMSTemplate6->Text = pSms->smsTemplate[5];
    PRI_Form->Edit_SMSTemplate7->Text = pSms->smsTemplate[6];
    PRI_Form->Edit_SMSTemplate8->Text = pSms->smsTemplate[7];
    PRI_Form->Edit_SMSTemplate9->Text = pSms->smsTemplate[8];
    PRI_Form->Edit_SMSTemplate10->Text = pSms->smsTemplate[9];

}

/*********************************************************************
                         设置开机动画图片的路径
*********************************************************************/
void   SetBannerPath(BANNER_STRUCT* pBanner)
{
    PRI_Form->Edit_Banner_File1->Text = "";
    PRI_Form->Edit_Banner_File2->Text = "";

    PRI_Form->Edit_Banner_File1->Text = pBanner->filePath[0];
    PRI_Form->Edit_Banner_File2->Text = pBanner->filePath[1];
}

/*********************************************************************
                           设置紧急呼叫号码
*********************************************************************/
void   SetEmergencyNumber(EMERGENCYNUMBER_STRUCT* pEmNumber)
{
    PRI_Form->Edit_EM_Number1->Text = "";
    PRI_Form->Edit_EM_Number2->Text = "";
    PRI_Form->Edit_EM_Number3->Text = "";

    PRI_Form->Edit_EM_Number1->Text = pEmNumber->emergencyNumber[0];
    PRI_Form->Edit_EM_Number2->Text = pEmNumber->emergencyNumber[1];
    PRI_Form->Edit_EM_Number3->Text = pEmNumber->emergencyNumber[2];
}

void   SetV3keyCode(V3_KEY_STRUCT *pV3key)
{
    Form_V3KEY->Edit1->Text = "";
    Form_V3KEY->Edit2->Text = "";
    Form_V3KEY->Edit3->Text = "";
    Form_V3KEY->Edit4->Text = "";
    Form_V3KEY->Edit5->Text = "";
    Form_V3KEY->Edit6->Text = "";
    Form_V3KEY->Edit7->Text = "";
    if(pV3key->bSave[0] == '1')
    {
        Form_V3KEY->CheckBox_SaveV3->Checked = true;
    }
    else
    {
        Form_V3KEY->CheckBox_SaveV3->Checked = false;
    }

    Form_V3KEY->Edit1->Text = pV3key->manufactur;
    Form_V3KEY->Edit2->Text = pV3key->version;
    Form_V3KEY->Edit3->Text = pV3key->key_value[0];
    Form_V3KEY->Edit4->Text = pV3key->key_value[1];
    Form_V3KEY->Edit5->Text = pV3key->key_value[2];
    Form_V3KEY->Edit6->Text = pV3key->key_value[3];
    Form_V3KEY->Edit7->Text = pV3key->key_value[4];
}
/*********************************************************************
                              判断超时
*********************************************************************/
bool IsTimeOut()
{
    if(g_bTimeout)
    {
        Prompt_Form->Hide();
        return true;  //超时
    }
    else
    {
        return false; //末超时
    }
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
    char strCom[15] = {0};
    char strCom2[10] = {0};
    HANDLE handle;
    for(int i = 0; i < 50; i++)
    {
        sprintf(strCom2, "COM%d", i);
        if(i > 9)
        {
           sprintf(strCom, "\\\\.\\COM%d", i);
        }
        else
        {
            sprintf(strCom, "COM%d", i);
        }
        handle = CreateFile(strCom, GENERIC_READ | GENERIC_WRITE,0,0,OPEN_EXISTING,
							FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED,
							0 );
        if(INVALID_HANDLE_VALUE != handle)
        {
            ComboBox_Port->Items->Add(strCom2);
            CloseHandle(handle);
        }
    }
    //禁用四个按钮功能
    Button_Version->Enabled = false;
    Button_Security->Enabled = false;
    Button_PRI->Enabled = false;
    Button_ClosePort->Enabled = false;
    Button_V3KEY->Enabled = false;
    //禁用FIL下的打开、保存、写所有数据菜单功能
    OpenFile->Enabled = false;
    SaveFile->Enabled = false;
    WriteAll->Enabled = false;

    StatusBar1->Panels->Items[0]->Text = "Ready";
    
    OpenDialog_File->DefaultExt = "txt";
    OpenDialog_File->Filter = "(*.txt)|*.txt|(*.*)|*.*";
    SaveDialog->DefaultExt = "txt";
    SaveDialog->Filter = "(*.txt)|*.txt|(*.*)|*.*)";
     Button_V3KEY->Enabled = 1;//for test by leon
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button_OpenPortClick(TObject *Sender)
{
    char strText[10] = {0};
    char chPort[5] = {0};
    int nPort;
    int nCount = 0;
    char strError[100] = {0};

    //当一开始握手时,禁用握手按钮
    Button_OpenPort->Enabled = false;

    strcpy(strText, ComboBox_Port->Text.c_str());
    if(strText[0] == 0)
    {
        MessageDlg("Please Select Serial Port!", mtInformation, TMsgDlgButtons() << mbOK, 0);
        Button_OpenPort->Enabled = true;
        return;
    }

    StatusBar1->Panels->Items[0]->Text = "Connecting the mobile Please Waiting...";

    strcpy(chPort, strText + 3);
    nPort = atoi(chPort);
    try
    {
	    if(DWD_set_com_port(nPort, &g_hPort))
	    {
	        /*if(DWD_set_v24_mode(dwd_at_hash_on, g_hPort))
	        {
		        for(int i = 0; i < 100000; i++)
		        {
		            for(int j = 0; j < 1000; j++);
		        } */
                while(!DWD_check_comm_link(g_hPort))
                {
                    if(nCount > 3)
                    {
                        DWD_close_com_port(g_hPort);
                        strcpy(strError, "DWD_check_comm_link Failed! ErrorMsg:");
                        strcat(strError, DWD_get_last_error());
                        ShowMessage(strError);
                        Button_OpenPort->Enabled = true;
                        return;
                    }
                    nCount++;
                }
                g_bOpenPort = true;
		            StatusBar1->Panels->Items[0]->Text = "Connecting Success!";
		            //激活四个按钮功能
		            Button_Version->Enabled = true;
		            Button_Security->Enabled = true;
		            Button_PRI->Enabled = true;
		            Button_ClosePort->Enabled = true;
                    Button_V3KEY->Enabled = true;
		            //激活FIL下的打开、保存、写所有数据菜单功能
		            OpenFile->Enabled = true;
		            SaveFile->Enabled = true;
		            WriteAll->Enabled = true;
		        /*if(DWD_check_comm_link(g_hPort))
		        {
		            g_bOpenPort = true;
		            StatusBar1->Panels->Items[0]->Text = "Connecting Success!";
		            //激活四个按钮功能
		            Button_Version->Enabled = true;
		            Button_Security->Enabled = true;
		            Button_PRI->Enabled = true;
		            Button_ClosePort->Enabled = true;
		            //激活FIL下的打开、保存、写所有数据菜单功能
		            OpenFile->Enabled = true;
		            SaveFile->Enabled = true;
		            WriteAll->Enabled = true;
		        }
		        else
		        {
	                ShowMessage(DWD_get_last_error());
		            DWD_close_com_port(g_hPort);
		            MessageDlg("Port has used or No the Port!", mtInformation, TMsgDlgButtons() << mbOK, 0);
		            StatusBar1->Panels->Items[0]->Text = "Connecting Failure!";
		            //握手不成功,激活握手按钮
		            Button_OpenPort->Enabled = true; 
		        } */
	       /* }
	        else
	        {
	            ShowMessage("Error in sending AT# On\n");
	            Button_OpenPort->Enabled = true;
	        } */
	    }
	    else
	    {
	        DWD_close_com_port(g_hPort);
	        MessageDlg("Open Port Failure!", mtInformation, TMsgDlgButtons() << mbOK, 0);
	        StatusBar1->Panels->Items[0]->Text = "Open Port Failure!";
	        //打开串口不成功,激活握手按钮
	        Button_OpenPort->Enabled = true;
	    }
    }
    catch(...)
    {
        ShowMessage("Exception Error");
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button_ClosePortClick(TObject *Sender)
{
    if(DWD_close_com_port(g_hPort))
    {
        g_bOpenPort = false;
        StatusBar1->Panels->Items[0]->Text = "Disconnect Communication!";
        //禁用四个按钮功能
        Button_Version->Enabled = false;
        Button_Security->Enabled = false;
        Button_PRI->Enabled = false;
        Button_ClosePort->Enabled = false;
        Button_V3KEY->Enabled = false;
        //禁用FIL下的打开与保存菜单功能
        OpenFile->Enabled = false;
        SaveFile->Enabled = false;
        WriteAll->Enabled = false;
        //打开握手按钮
        Button_OpenPort->Enabled = true;
        //MessageDlg("Close Port!", mtInformation, TMsgDlgButtons() << mbOK, 0);
     }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button_VersionClick(TObject *Sender)
{
    Version_Form->Show();
    MainForm->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button_SecurityClick(TObject *Sender)
{
    Security_Form->Show();
    MainForm->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button_PRIClick(TObject *Sender)
{
     PRI_Form->Show();
     MainForm->Hide();
}
//---------------------------------------------------------------------------


/*********************************************************************
                        打开文件，并设置各项数据值
*********************************************************************/
void __fastcall TMainForm::OpenFileClick(TObject *Sender)
{
    char strFileName[80] = {0};
    FILE* fp;
    //memset(&mcc_struct, 0 , sizeof(mcc_struct));
    if(OpenDialog_File->Execute())
    {
        strcpy(strFileName, OpenDialog_File->FileName.c_str());
        if(strFileName == "")
        {
            ShowMessage("NO Select File");
            return;
        }
        else
        {
            if((fp = fopen(strFileName, "r")) == NULL)
            {
                ShowMessage("No Open File!");
                return;
            }
            else
            {
                /*设置版本信息
                fread(&versionInfo, sizeof(versionInfo), 1, fp);
                void SetVersion(VERSIONINFO_STRUCT* );
                SetVersionInfo(&versionInfo);
                fread("\n", sizeof("\n"), 1, fp); */
                //设置MCC/MNC
                fread(&mcc_struct, sizeof(mcc_struct), 1, fp);
                void  SetMCCMNC(MCC_STRUCT* );
                SetMCCMNC(&mcc_struct);
                fread("\n", sizeof("\n"), 1, fp);
                //设置SIM_IMSI
                fread(&sim_imsi, sizeof(sim_imsi), 1, fp);
                void   SetSIM_IMSI(SIM_IMSI_STRUCT* );
                SetSIM_IMSI(&sim_imsi);
                fread("\n", sizeof("\n"), 1, fp);
                //设置其它项
                fread(&otherlock, sizeof(otherlock), 1, fp);
                void   SetOtherLock(OTHERLOCK_STRUCT* );
                SetOtherLock(&otherlock);
                fread("\n", sizeof("\n"), 1, fp);
                //设置VOICEMAIL号码
                fread(&voicemail, sizeof(voicemail), 1, fp);
                void   SetVoiceMail(VOICEMAIL_STRUCT* );
                SetVoiceMail(&voicemail);
                fread("\n", sizeof("\n"), 1, fp);
                //设置短消息模板
                fread(&smsTemplate, sizeof(smsTemplate), 1, fp);
                void   SetSmsTemplate(SMSTEMPLATE_STRUCT *);
                SetSmsTemplate(&smsTemplate);
                fread("\n", sizeof("\n"), 1, fp);
                //设置开机动画图片的路径
                fread(&banner, sizeof(banner), 1, fp);
                void   SetBannerPath(BANNER_STRUCT* );
                SetBannerPath(&banner);
                fread("\n", sizeof("\n"), 1, fp);
                //设置紧急呼叫号码
                fread(&emergencyNumber, sizeof(emergencyNumber), 1, fp);
                void   SetEmergencyNumber(EMERGENCYNUMBER_STRUCT* );
                SetEmergencyNumber(&emergencyNumber);
                fread("\n", sizeof("\n"), 1, fp);
                //读出V3密钥
                fread(&v3key, sizeof(v3key), 1, fp);
                void SetV3keyCode(V3_KEY_STRUCT *);
                SetV3keyCode(&v3key);
                /*
                Security_Form->Edit_MCC1->Text = mcc_struct.chMccMnc[0];
                Security_Form->Edit_MCC2->Text = mcc_struct.chMccMnc[1];
                Security_Form->Edit_MCC3->Text = mcc_struct.chMccMnc[2];
                Security_Form->Edit_MCC4->Text = mcc_struct.chMccMnc[3];
                if(mcc_struct.mccmnc_lock[0] == '0')
                {
                    Security_Form->RadioButton_MCC_Disable->Checked = true;
                }
                else
                {
                    Security_Form->RadioButton_MCC_Enable->Checked = true;
                    //Security_Form->RadioButton_SIM_Disable->Checked = false;
                }  */

            }
            fclose(fp);
        }
    }
}
//---------------------------------------------------------------------------

/*********************************************************************
                            把各项数据保存到文件中
*********************************************************************/
void __fastcall TMainForm::SaveFileClick(TObject *Sender)
{
   char strFileName[80] = {0};
   FILE *fp;
   //GetVersionInfo();
   //获得MCC/MNC的值
   if(!GetMCCMNC())
   {
       ShowMessage("MCC/MNC illegal！");
       return;
   }
   if(!GetSIM_IMSI())
   {
       ShowMessage("SIM Setting illegal！");
       return;
   }
   if(!GetOtherLock())
   {
       ShowMessage("Other Lock illegal！");
       return;
   }
   if(!GetVoiceMail())
   {
       ShowMessage("VoiceMail illegal！");
       return;
   }
   if(!GetSmsTemplate())
   {
       ShowMessage("SmsTemplate illegal！");
       return;
   }
   if(!GetBannerPath())
   {
       ShowMessage("Banner Path illegal！");
       return;
   }
   if(!GetEmergencyNumber())
   {
       ShowMessage("EmergencyNumber illegal！");
       return;
   }
   if(Form_V3KEY->CheckBox_SaveV3->Checked)
   {
        if(!GetV3key())
        {
            ShowMessage("V3Key illegal！");
            return;
        }
   }
   /*memset(&mcc_file, 0 , sizeof(mcc_file));
   sprintf(mcc_file.chItemName, "MCC/MNC");
   strcpy(mcc_file.chMccMnc[0], Security_Form->Edit_MCC1->Text.c_str());
   strcpy(mcc_file.chMccMnc[1], Security_Form->Edit_MCC2->Text.c_str());
   strcpy(mcc_file.chMccMnc[2], Security_Form->Edit_MCC3->Text.c_str());
   strcpy(mcc_file.chMccMnc[3], Security_Form->Edit_MCC4->Text.c_str());
   if(Security_Form->RadioButton_MCC_Disable->Checked == true)
   {
        mcc_file.mccmnc_lock_available = 1;
   }
   else
   {
         mcc_file.mccmnc_lock_available = 1;
   } */ 

   if(SaveDialog->Execute())
   {
        strcpy(strFileName, SaveDialog->FileName.c_str());
        if(strFileName != "")
        {
            if((fp = fopen(strFileName, "w")) == NULL)
            {
                MessageDlg("Cann't open file!", mtInformation, TMsgDlgButtons() << mbOK, 0);
                return;
            }
            else
            {
                /*fwrite(&versionInfo, sizeof(versionInfo), 1, fp);
                fwrite("\n", sizeof("\n"), 1, fp); */
                fwrite(&mcc_struct, sizeof(mcc_struct), 1, fp);
                fwrite("\n", sizeof("\n"), 1, fp);
                fwrite(&sim_imsi, sizeof(sim_imsi), 1, fp);
                fwrite("\n", sizeof("\n"), 1, fp);
                fwrite(&otherlock, sizeof(otherlock), 1, fp);
                fwrite("\n", sizeof("\n"), 1, fp);
                fwrite(&voicemail, sizeof(voicemail), 1, fp);
                fwrite("\n", sizeof("\n"), 1, fp);
                fwrite(&smsTemplate, sizeof(smsTemplate), 1, fp);
                fwrite("\n", sizeof("\n"), 1, fp);
                fwrite(&banner, sizeof(banner), 1, fp);
                fwrite("\n", sizeof("\n"), 1, fp);
                fwrite(&emergencyNumber, sizeof(emergencyNumber), 1, fp);
                if(Form_V3KEY->CheckBox_SaveV3->Checked)
                {
                fwrite("\n", sizeof("\n"), 1, fp);
                fwrite(&v3key, sizeof(v3key), 1, fp);
                }
            }
        }
        fclose(fp);
   }
   else
   {
       MessageDlg("Cann't Save file!", mtInformation, TMsgDlgButtons() << mbOK, 0);
   }

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::About1Click(TObject *Sender)
{
    About_Form->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    if(g_bOpenPort)
    {
        DWD_close_com_port(g_hPort);
    }

    for(int i = 0; i < 10000; i++)
    {
        for(int j = 0; j < 100; j++);
    }

    Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Exit1Click(TObject *Sender)
{

    if(g_bOpenPort)
    {
        DWD_close_com_port(g_hPort);
    }
    /*关串口需要一定的时间，以下用来延时*/
    for(int i = 0; i < 10000; i++)
    {
         for(int j = 0; j < 100; j++);
    }

    Application->Terminate();

}
//---------------------------------------------------------------------------
/*********************************************************************
                           写所有数据到手机中
*********************************************************************/
void __fastcall TMainForm::WriteAllClick(TObject *Sender)
{
    //StatusBar1->Panels->Items[0]->Text = "Writing Data Please Waiting......";
    Prompt_Form->Show();
    Security_Form->Button_MCC_WriteClick(Sender);
    if(IsTimeOut())
    {
        return;
    }
    Security_Form->Button_SIM_WriteClick(Sender);
    if(IsTimeOut())
    {
        return;
    }
    Security_Form->Button_IMSI_WriteClick(Sender);
    if(IsTimeOut())
    {
        return;
    }
    /*Security_Form->Button_OtherLock_WriteClick(Sender);
    if(g_bTimeout)
    {
        return;
    }*/
    PRI_Form->Button_VoiceMail_WriteClick(Sender);
    if(IsTimeOut())
    {
        return;
    }

    PRI_Form->Button_WriteSMSClick(Sender);
    if(IsTimeOut())
    {
        return;
    }

    /*PRI_Form->Button_SetBannerClick(Sender);
    if(IsTimeOut())
    {
        return;
    }*/

    PRI_Form->Button_EM_WriteClick(Sender);
    if(IsTimeOut())
    {
        return;
    }

    if(Form_V3KEY->CheckBox_SaveV3->Checked)//if(Form_V3KEY->Edit_Version->Text != "")
    {
        Form_V3KEY->Button_WriteClick(Sender);
        if(IsTimeOut())
        {
            return;
        }
    }
    //StatusBar1->Panels->Items[0]->Text = "Writing Data Over!";
    //ShowMessage("Write all ok");
    Prompt_Form->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button_V3KEYClick(TObject *Sender)
{
    Form_V3KEY->Show();
    MainForm->Hide();
}
//---------------------------------------------------------------------------

