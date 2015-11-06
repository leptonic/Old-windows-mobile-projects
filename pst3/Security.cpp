//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Security.h"
#include "dwdptest.h"
#include "def_paramter.h"
#include "main.h"
#include "Pri.h"
#include "prompt.h"
#include "stdio.h"

extern bool g_bOpenPort;
extern int g_hPort;
extern bool g_bTimeout;

VOICE_MAIL voice_mail = {0};
SMS_TEMPLATE sms_template = {0};
EMERGENCY_NUMBER emergency_number = {0};
SET_BANNER set_banner = {0};
MCC_MNC mcc_mnc = {0};
SIM_LOCK_1 sim_lock = {0};
IMSI_LOCK imsi_lock = {0};
OTHER_LOCK other_lock = {0};
MASTER_RESET master_reset = {0};
V3_KEY_TYPE v3_key = {0};
CITY_CODE citycodes = {0};
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSecurity_Form *Security_Form;

extern "C" void rxdone(unsigned char *rxdata, int rx_length)
{
    unsigned char nSuccess;
    //memset(&emergency_number, 0,sizeof(EMERGENCY_NUMBER));
    unsigned char nItem;
    nItem = rxdata[0];
    switch(nItem)
    {
    case MCC_MNC_LOCK_SET:
    {
        if(rxdata[1] == ERROR)
        {
            MessageDlg("Write MCC/MNC Failure!", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
        else
        {
            Security_Form->Button_MCC_Read->Enabled = true;
            Security_Form->Button_MCCMNCClear->Enabled = true;
			Security_Form->Button_MCC_Write->Enabled = true;
        }
    }
    break;
    case MCC_MNC_LOCK_GET:
    {
        memset(&mcc_mnc, 0, sizeof(mcc_mnc));
        memcpy(&mcc_mnc, rxdata, rx_length);
    }
    break;
    case SIM_LOCK_SET:
    {
        if(rxdata[1] == ERROR)
        {
            MessageDlg("Write MCC/MNC Failure!", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
        else
        {
            Security_Form->Button_SIM_Read->Enabled = true;
            Security_Form->Button_SIM_Write->Enabled = true;
            Security_Form->SIMLock_Clear->Enabled = true;
        }
    }
    break;
    case SIM_LOCK_GET:
    {
        memset(&sim_lock, 0, sizeof(sim_lock));
        memcpy(&sim_lock, rxdata, rx_length);
    }
    break;
    case IMSI_LOCK_SET:
    {
        if(rxdata[1] == ERROR)
        {
            MessageDlg("Write MCC/MNC Failure!", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
        else
        {

            Security_Form->Button_IMSI_Read->Enabled = true;
            Security_Form->Button_IMSI_Reset->Enabled = true;
            Security_Form->Button_IMSI_Write->Enabled = true;
        }
    }
    return;
    case IMSI_LOCK_GET:
    {
        memset(&imsi_lock, 0, sizeof(imsi_lock));
        memcpy(&imsi_lock, rxdata, rx_length);
    }
    break;
	case IMSI_LOCK_RESET:
	{
		if(rxdata[1] == ERROR)
		{
			ShowMessage("IMSI Lock Reset Failure");
		}
		else
		{
			ShowMessage("IMSI Lock Reset OK");
		}
	}
	break;
    /*case MASTER_RESET_SET:
    if(rxdata[1] == ERROR)
    {
        MessageDlg("Master Reset Failure!", mtInformation, TMsgDlgButtons() << mbOK, 0);
    }
    else
    {
        Security_Form->Button_Reset_Phone->Enabled = true;
    }
    break; */
    case OTHER_LOCK_SET:
    {
        if(rxdata[1] == ERROR)
        {
            MessageDlg("Write MCC/MNC Failure!", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
        else
        {
            Security_Form->Button_OtherLock_Read->Enabled = true;
            Security_Form->Button_OtherLock_Write->Enabled = true;
        }

    }
    break;
    case OTHER_LOCK_GET:
    {
        memset(&other_lock, 0, sizeof(other_lock));
        memcpy(&other_lock, rxdata, rx_length);
    }
    break;
    case VOICE_MAIL_SET:
    {
         if(rxdata[1] == ERROR)
         {
            MessageDlg("Write Voicemail Failure!", mtInformation, TMsgDlgButtons() << mbOK, 0);
         }
         else
         {
            PRI_Form->Button_VoiceMail_Read->Enabled = true;
            PRI_Form->Button_VoiceMail_Clear->Enabled = true;
            PRI_Form->Button_VoiceMail_Write->Enabled = true;
         }
         break;
    }
    case VOICE_MAIL_GET:
    {
        memset(&voice_mail, 0, sizeof(voice_mail));
        memcpy(&voice_mail, rxdata, rx_length);
    }
    break;
    case SMS_TEMPLATE_SET:
    if(rxdata[1] == ERROR)
    {
        MessageDlg("Write SmsTemplate Failure!", mtInformation, TMsgDlgButtons() << mbOK, 0);
    }
    break;
    case SMS_TEMPLATE_GET:
    {
        memset(&sms_template, 0, sizeof(sms_template));
        memcpy(&sms_template, rxdata, rx_length);
    }
    break;
    case EMERGENCY_NUMBER_SET:
    if(rxdata[1] == ERROR)
    {
        MessageDlg("Write EmergencyNumber Failure!", mtInformation, TMsgDlgButtons() << mbOK, 0);
    }
    else
    {
        PRI_Form->Button_EM_Read->Enabled = true;
        PRI_Form->Button_EM_Clear->Enabled = true;
        PRI_Form->Button_EM_Write->Enabled = true;
    }
    break;
    case EMERGENCY_NUMBER_GET:
    {
        memset(&emergency_number, 0, sizeof(emergency_number));
        memcpy(&emergency_number, rxdata, rx_length);
    }
    break;
    case BANNER_SET:
    if(rxdata[1] == ERROR)
    {
        MessageDlg("Banner Failure!", mtInformation, TMsgDlgButtons() << mbOK, 0);
    }
    break;
    /*case BANNER_GET:
    break; */
    case MASTER_RESET_SET:
    {
	    if(rxdata[1] == ERROR)
	    {
	        MessageDlg("Master Reset Failure!", mtInformation, TMsgDlgButtons() << mbOK, 0);
	    }
	    else
	    {
	         MessageDlg("Master Reset ok!", mtInformation, TMsgDlgButtons() << mbOK, 0);
	        Security_Form->Button_Reset_Phone->Enabled = true;
	    }
        break;
    }
    case V3_KEY_SET:
    {
        if(rxdata[1] == ERROR)
        {
            MessageDlg("Write VE_KEY_SET Failure!", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
        /*else
        {
            ShowMessage("Set the V3KEY Successful!");
        } */
        break;
    }
    case V3_KEY_GET:
    {
        memset(&v3_key, 0, sizeof(v3_key));
        memcpy(&v3_key, rxdata, rx_length);
        break;
    }
    /*case MASTER_RESET_GET:
    break; */
    default:
    break;
    }
}

/*unsigned short StringToInt(char *chTemp, int nLength)
{
    //int nMcc_Mnc;
    unsigned short mccTemp;
    unsigned short temp;
    unsigned short temp1;
    int i;
    for(i = 0; i < nLength; i++)
    {
        if(chTemp[i] >= '0' && chTemp[i] <= '9')
        {
            if(i == 2)
            {
                temp = chTemp[i] - 0x30;
                temp = temp | 0xF0;
                mccTemp = (mccTemp << 8) |temp;
            }
            else
            {
               if(i % 2 == 0)
                {
                    temp = chTemp[i] - 0x30;
                    //mcc = temp >> 4;
                }
                else
                {
                    temp1 = chTemp[i] - 0x30;
                    temp1 = temp1 << 4;
                     mccTemp = temp1 | temp;
                }
            }
        }
    }
    return mccTemp;
} */

/*************************************************************
字符转换成整数 如字符'1'转换成整数1
输入: chtemp 字符
输出:
**************************************************************/
unsigned char StrToInt(char chtemp)
{
    unsigned char ch;
    if(chtemp >= '0' && chtemp <='9')
    {
        ch = chtemp - 0x30;
    }
    if(chtemp >= 'A' && chtemp <='F')
    {
        ch = chtemp - 0x37;
    }
    return ch;
}

/*************************************************************
字符串转换成字节数组, 如"12345678"转换成0x21, 0x43, 0x65, 0x87
输入: pSrc 源字符串
      nLen 源字符串长度
输出: pDes 目标数据指针
**************************************************************/
int StringToChar(const char *pSrc, char* pDes, int nLen)
{
    unsigned char ch;
    int j = 0;
    for(int i = 0; i < nLen; i += 2)
    {
        if(*pSrc >= '0' && *pSrc <= '9')
        {
            ch = *pSrc - 0x30;
        }
        if(*pSrc >= 'A' && *pSrc <= 'F')
        {
            ch = *pSrc - 0x37;
        }
        pSrc++;
        if(*pSrc >= '0' && *pSrc <= '9')
        {
            *pDes = *pSrc - 0x30;
        }
        if(*pSrc >= 'A' && *pSrc <= 'F')
        {
            *pDes = *pSrc - 0x37;
        }
        *pDes = (*pDes << 4) | ch;
        pSrc++;
        pDes++;
        j++;

    }
    *pDes = '\0';
    return j; //(nLen/2);
}

/**********************************************************************
 字节数据转换为可打印字符串
 如：{0xC8, 0x32, 0x9B, 0xFD, 0x0E, 0x01} --> "8C23B9DFE010"
 输入: pSrc - 源数据指针
       nSrcLength - 源数据长度
 输出: pDst - 目标字符串指针
 返回: 目标字符串长度
***********************************************************************/
INT BytesToString(const BYTE* pSrc, char* pDst, INT nSrcLength)
{
    const char tab[] = "0123456789ABCDEF";
    for(int i = 0; i < nSrcLength; i++)
    {
        *pDst++ = tab[*pSrc & 0x0F]; //得到低位
        *pDst++ = tab[*pSrc >> 4];   //得到高位
        pSrc++;
    }
    // 输出字符串加个结束符
    *pDst = '\0';
    // 返回目标字符串长度
    return (nSrcLength * 2);

}


/*************************************************************
字符串转换成十六进制数, 如"23"转换成0x23
输入: str 源字符串
      nLen 源字符串长度
输出:
**************************************************************/
unsigned short IntToHex(char* str, int nLen)
{
    unsigned char ch[3];
    unsigned short temp;
    int i;
    for(i = 0; i < nLen; i++)
    {
        ch[i] = StrToInt(str[i]);
    }
    if(nLen == 3)
    {
        temp = ch[0];
        temp = (temp << 4) | ch[1];
        temp = (temp << 4) | ch[2];
    }
    else
    {
        temp = ch[0];
        temp = (temp << 4) | ch[1];
    }
    return temp;
}
//---------------------------------------------------------------------------
__fastcall TSecurity_Form::TSecurity_Form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

bool IsDigit(const char* pSrc)
{
    int i = 0;
    while(pSrc[i] != '\0')
    {
        if(pSrc[i] < '0' || pSrc[i] > '9')
        {
            ShowMessage("There are non_digit Characters in the string!");
            return false;
        }
        i++;
    }
    return true;
}

bool GetChar()
{
    char strTemp[4][6] = {0};
    strcpy(strTemp[0], Security_Form->Edit_MCC1->Text.c_str());
    strcpy(strTemp[1], Security_Form->Edit_MCC2->Text.c_str());
    strcpy(strTemp[2], Security_Form->Edit_MCC3->Text.c_str());
    strcpy(strTemp[3], Security_Form->Edit_MCC4->Text.c_str());
    for(int i = 0; i < 4; i++)
    {
        if(!IsDigit(strTemp[i]))
        {
            return false;
        }
    }
    return true;
}

//---------------------------------------------------------------------------
/************************    Write MCC/MNC   ************************/
void __fastcall TSecurity_Form::Button_MCC_WriteClick(TObject *Sender)
{
    //MCC_MNC mcc_mnc = {0};
    //MCCMNC_STRUCT MCCMNC;
    //int nMcc_Mnc[4] = {0};
 //   unsigned short mcc = 0;
    unsigned char mnc;
    char strMcc_Mnc[5] = {0};
    char strMcc[3] = {0};
    char strMnc[2] = {0};
    int i;
    char ch;
    unsigned char temp;
    unsigned char temp1;
    unsigned char unmcc[3];
    unsigned char unmnc[2];
    memset(&mcc_mnc, 0, sizeof(mcc_mnc));

    //Button_MCC_Read->Enabled = false;
    //Button_MCCMNCClear->Enabled = false;

    mcc_mnc.nItem = MCC_MNC_LOCK_SET;

    if(Edit_MCC1->Text.Length() < 5 || Edit_MCC2->Text.Length() < 5
    || Edit_MCC3->Text.Length() < 5 || Edit_MCC4->Text.Length() < 5)
    {
        MessageDlg("MCC/MNC Error!", mtInformation, TMsgDlgButtons() << mbOK, 0);
        //Button_MCC_Read->Enabled = true;
        //Button_MCCMNCClear->Enabled = true;
        return;
    }

    if(!GetChar())
    {
        //Button_MCC_Read->Enabled = true;
        //Button_MCCMNCClear->Enabled = true;
        return;
    }
    Button_MCC_Read->Enabled = false;
    Button_MCCMNCClear->Enabled = false;
    Button_MCC_Write->Enabled = false;
    /*第一项MCC/MNC的内容*/
    strcpy(strMcc_Mnc, Edit_MCC1->Text.c_str());
    strncpy(strMcc, strMcc_Mnc, 3);
    ch = strMcc[1];
    temp = StrToInt(ch);
    temp1 =  StrToInt(strMcc[2]);
    temp = (temp << 4) | temp1;
    mcc_mnc.MCCMNC[0].mcc[0] = temp;
    ch = strMcc[0];
    temp = StrToInt(ch);
    mcc_mnc.MCCMNC[0].mcc[1] = temp;


    //mcc = IntToHex(strMcc, 3);

    strncpy(strMnc, strMcc_Mnc + 3, 2);
    mnc = IntToHex(strMnc, 2);

    //mcc_mnc.MCCMNC[0].mcc[0] = mcc;
    mcc_mnc.MCCMNC[0].mnc = mnc;

    /*第二项MCC/MNC的内容*/
    memset(strMcc_Mnc, 0, sizeof(strMcc_Mnc));
    memset(strMcc, 0, sizeof(strMcc));
    memset(strMnc, 0, sizeof(strMnc));
    strcpy(strMcc_Mnc, Edit_MCC2->Text.c_str());
    strncpy(strMcc, strMcc_Mnc, 3);
    ch = strMcc[1];
    temp = StrToInt(ch);
    temp1 =  StrToInt(strMcc[2]);
    temp = (temp << 4) | temp1;
    mcc_mnc.MCCMNC[1].mcc[0] = temp;
    ch = strMcc[0];
    temp = StrToInt(ch);
    mcc_mnc.MCCMNC[1].mcc[1] = temp;
    //mcc = IntToHex(strMcc, 3);

    strncpy(strMnc, strMcc_Mnc + 3, 2);
    mnc = IntToHex(strMnc, 2);

   // mcc_mnc.MCCMNC[1].mcc = mcc;
    mcc_mnc.MCCMNC[1].mnc = mnc;

    /*第三项MCC/MNC的内容*/
    memset(strMcc_Mnc, 0, sizeof(strMcc_Mnc));
    memset(strMcc, 0, sizeof(strMcc));
    memset(strMnc, 0, sizeof(strMnc));
    strcpy(strMcc_Mnc, Edit_MCC3->Text.c_str());
    strncpy(strMcc, strMcc_Mnc, 3);
    ch = strMcc[1];
    temp = StrToInt(ch);
    temp1 =  StrToInt(strMcc[2]);
    temp = (temp << 4) | temp1;
    mcc_mnc.MCCMNC[2].mcc[0] = temp;
    ch = strMcc[0];
    temp = StrToInt(ch);
    mcc_mnc.MCCMNC[2].mcc[1] = temp;
    //mcc = IntToHex(strMcc, 3);

    strncpy(strMnc, strMcc_Mnc + 3, 2);
    mnc = IntToHex(strMnc, 2);

    //mcc_mnc.MCCMNC[2].mcc = mcc;
    mcc_mnc.MCCMNC[2].mnc = mnc;

    /*第四项MCC/MNC的内容*/
    memset(strMcc_Mnc, 0, sizeof(strMcc_Mnc));
    memset(strMcc, 0, sizeof(strMcc));
    memset(strMnc, 0, sizeof(strMnc));
    strcpy(strMcc_Mnc, Edit_MCC4->Text.c_str());
    strncpy(strMcc, strMcc_Mnc, 3);
    ch = strMcc[1];
    temp = StrToInt(ch);
    temp1 =  StrToInt(strMcc[2]);
    temp = (temp << 4) | temp1;
    mcc_mnc.MCCMNC[3].mcc[0] = temp;
    ch = strMcc[0];
    temp = StrToInt(ch);
    mcc_mnc.MCCMNC[3].mcc[1] = temp;
    //mcc = IntToHex(strMcc, 3);

    strncpy(strMnc, strMcc_Mnc + 3, 2);
    mnc = IntToHex(strMnc, 2);

    //mcc_mnc.MCCMNC[3].mcc = mcc;
    mcc_mnc.MCCMNC[3].mnc = mnc;

    if(RadioButton_MCC_Disable->Checked == true)
    {
        mcc_mnc.mccmnc_lock_available = 0;
    }
    else
    {
        mcc_mnc.mccmnc_lock_available = 1;
    }

	bool bResult;
    if(g_bOpenPort)
    {
         try
         {
		 	DWDIO_SetTimeOutDelay(50);
             //DWD_user_command_timeout(COMMAND_CHAR, (unsigned char *)&mcc_mnc, sizeof(mcc_mnc), rxdone2, 200000, g_hPort);
             bResult = DWD_user_command(COMMAND_CHAR, (unsigned char *)&mcc_mnc, sizeof(mcc_mnc), rxdone, g_hPort);
         }
         catch(...)
         {
             ShowMessage("Write ERROR");
         }
		 if(!bResult)
         {
            g_bTimeout = true;
			ShowMessage("TimeOut, Please Checking Connection and DUT is on!");
            Button_MCC_Read->Enabled = true;
            Button_MCCMNCClear->Enabled = true;
            Button_MCC_Write->Enabled = true;
            return;
         }

    }
    Button_MCC_Read->Enabled = true;
    Button_MCCMNCClear->Enabled = true;
    Button_MCC_Write->Enabled = true;

}
//---------------------------------------------------------------------------


void __fastcall TSecurity_Form::Button_SIM_WriteClick(TObject *Sender)
{
    SIM_LOCK_1  sim_lock={0};

    sim_lock.nItem = SIM_LOCK_SET;
    if(Edit_SIM_PIN_Default->Text == "" || Edit_SIM_PIN_Locked->Text == "")
    {
        ShowMessage("SIM PIN Default is empty or SIM PIN Locked is empty");
        return;
    }
    strcpy(sim_lock.chPinDefault, Edit_SIM_PIN_Default->Text.c_str());
    strcpy(sim_lock.chPinLocked, Edit_SIM_PIN_Locked->Text.c_str());

    Button_SIM_Read->Enabled = false;
    SIMLock_Clear->Enabled = false;
    Button_SIM_Write->Enabled = false;

    if(RadioButton_SIM_Disable->Checked == true)
    {
        sim_lock.auto_pin_available = 0;
    }
    else
    {
        sim_lock.auto_pin_available = 1;
    }
    if(CheckBox_Random_SIM_PIN->Checked == true)
    {
        sim_lock.radom_sim_pin = 1;
    }
    else
    {
        sim_lock.radom_sim_pin = 0;
    }
    if(strcmp("Deactive", ComboBox_AutoSIMState->Text.c_str()) == 0)
    {
        sim_lock.auto_sim_pin_state = 0;
    }
    else
    {
        sim_lock.auto_sim_pin_state = 1;
    }
    //ComboBox_AutoSIMState->Text.c_str();

	bool bResult;
    if(g_bOpenPort)
    {
        try
        {
			DWDIO_SetTimeOutDelay(50);
            //DWD_user_command_timeout(COMMAND_CHAR, (unsigned char *)&sim_lock, sizeof(sim_lock), rxdone2, 200000, g_hPort);
            bResult = DWD_user_command(COMMAND_CHAR, (unsigned char *)&sim_lock, sizeof(sim_lock), rxdone, g_hPort);
        }
        catch(...)
        {
            ShowMessage("SIM LOCK WRITE ERROR");
        }
		if(!bResult)
        {
			ShowMessage("TimeOut, Please Checking Connection and DUT is on!");
            Button_SIM_Read->Enabled = true;
            SIMLock_Clear->Enabled = true;
            Button_SIM_Write->Enabled = true;
            g_bTimeout = true;
			return;
        }

    }
    Button_SIM_Read->Enabled = true;
    SIMLock_Clear->Enabled = true;
    Button_SIM_Write->Enabled = true;

}
//---------------------------------------------------------------------------


void __fastcall TSecurity_Form::Button_SIM_ReadClick(TObject *Sender)
{
    unsigned char  nItem = SIM_LOCK_GET;
    //strcpy(sim_lock.chPinDefault , "1234");
    //Edit_SIM_PIN_Default->Text = sim_lock.chPinDefault;

    Edit_SIM_PIN_Default->Enabled = true;
    Edit_SIM_PIN_Locked->Enabled = true;
    CheckBox_Random_SIM_PIN->Enabled = true;
    ComboBox_AutoSIMState->Enabled = true;

    //读数据时,先清空所有的项
    Edit_SIM_PIN_Default->Text = "";
    Edit_SIM_PIN_Locked->Text = "";
    RadioButton_SIM_Enable->Checked = false;
    CheckBox_Random_SIM_PIN->Checked = false;
    ComboBox_AutoSIMState->Text = "";

    if(g_bOpenPort)
    {
        try
        {
			DWDIO_SetTimeOutDelay(50);
        //DWD_user_command_timeout(COMMAND_CHAR, &nItem, 1, rxdone2, 200000, g_hPort);
	        if(DWD_user_command(COMMAND_CHAR, &nItem, 1, rxdone, g_hPort))
	        {
	            //strcpy(chPinDefault, sim_lock.chPinDefault);
	            Edit_SIM_PIN_Default->Text = sim_lock.chPinDefault;
	            //strcpy(Edit_SIM_PIN_Locked->Text.c_str(), sim_lock.chPinLocked);
	            Edit_SIM_PIN_Locked->Text = sim_lock.chPinLocked;
	            if(sim_lock.auto_pin_available == 1)
	            {
	                RadioButton_SIM_Enable->Checked = true;
	            }
	            else
	            {
	                RadioButton_SIM_Disable->Checked = true;
	                Edit_SIM_PIN_Default->Enabled = false;
	                Edit_SIM_PIN_Locked->Enabled = false;
	                CheckBox_Random_SIM_PIN->Enabled = false;
	                ComboBox_AutoSIMState->Enabled = false;
	            }
	            if(sim_lock.radom_sim_pin == 1)
	            {
	                CheckBox_Random_SIM_PIN->Checked = true;
	            }
	            else
	            {
	                CheckBox_Random_SIM_PIN->Checked = false;
	            }
	            if(sim_lock.auto_sim_pin_state == 0)
	            {
	                ComboBox_AutoSIMState->Text = "Deactive";
	            }
	            else
	            {
	                ComboBox_AutoSIMState->Text = "Active";
	            }

	        }
			else
			{
				ShowMessage("TimeOut, Please Checking Connection and DUT is on!");
				return;
			}
        }
        catch(...)
        {
            ShowMessage("Read Voice Mail ERROR");
        }
    }
}
//---------------------------------------------------------------------------
/*int hextostr(unsigned short temp, char* str)
{
    int i = 0;
    unsigned char ch;
    if(temp > 0xFF)
    {
        i = 3;
       ch = temp >> 8;
    IntToStr(&ch);
    *str++= ch;
    ch = (temp >> 4) & 0x0F;
    IntToStr(&ch);
    *str++ = ch;
    ch = temp & 0x00F;
    IntToStr(&ch);
    *str = ch;
    }
    else
    {
    i = 2;
        ch = temp >> 4;
    IntToStr(&ch);
    *str++= ch;
    ch = temp & 0x0F;
    IntToStr(&ch);
    *str = ch;
    }
    return i;
} */


void __fastcall TSecurity_Form::Button_MCC_ReadClick(TObject *Sender)
{
    unsigned char  nItem = MCC_MNC_LOCK_GET;
    unsigned char ch;
    String str;

    Edit_MCC1->Enabled = true;
    Edit_MCC2->Enabled = true;
    Edit_MCC3->Enabled = true;
    Edit_MCC4->Enabled = true;

    if(g_bOpenPort)
    {
        try
        {
			DWDIO_SetTimeOutDelay(50);
        //DWD_user_command_timeout(COMMAND_CHAR, &nItem, 1, rxdone2, 200000, g_hPort);
		    if(DWD_user_command(COMMAND_CHAR, &nItem, 1, rxdone, g_hPort))
	        {
	            ch = mcc_mnc.MCCMNC[0].mcc[1] & 0x0F;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[0].mcc[0] >> 4 & 0x0F;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[0].mcc[0]  & 0x0F;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[0].mnc >> 4;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[0].mnc & 0x0F;
	            IntToStr(&ch);
	            str += ch;
	            Edit_MCC1->Text = str;
	            str = "";

	            /*ch = mcc_mnc.MCCMNC[1].mcc >> 8;
	            IntToStr(&ch);
	            str += ch;
	            ch = (mcc_mnc.MCCMNC[1].mcc >> 4) & 0x0F;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[1].mcc  & 0x00F; */
	            ch = mcc_mnc.MCCMNC[1].mcc[1] & 0x0F;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[1].mcc[0] >> 4 & 0x0F;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[1].mcc[0]  & 0x0F;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[1].mnc >> 4;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[1].mnc & 0x0F;
	            IntToStr(&ch);
	            str += ch;
	            Edit_MCC2->Text = str;
	            str = "";

	            /*ch = mcc_mnc.MCCMNC[2].mcc >> 8;
	            IntToStr(&ch);
	            str += ch;
	            ch = (mcc_mnc.MCCMNC[2].mcc >> 4) & 0x0F;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[2].mcc  & 0x00F;
	            IntToStr(&ch);
	            str += ch; */
	            ch = mcc_mnc.MCCMNC[2].mcc[1] & 0x0F;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[2].mcc[0] >> 4 & 0x0F;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[2].mcc[0]  & 0x0F;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[2].mnc >> 4;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[2].mnc & 0x0F; 
	            IntToStr(&ch);
	            str += ch;
	            Edit_MCC3->Text = str;
	            str = "";

	            /*ch = mcc_mnc.MCCMNC[3].mcc >> 8;
	            IntToStr(&ch);
	            str += ch;
	            ch = (mcc_mnc.MCCMNC[3].mcc >> 4) & 0x0F;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[3].mcc  & 0x00F;*/
	            ch = mcc_mnc.MCCMNC[3].mcc[1] & 0x0F;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[3].mcc[0] >> 4 & 0x0F;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[3].mcc[0]  & 0x0F;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[3].mnc >> 4;
	            IntToStr(&ch);
	            str += ch;
	            ch = mcc_mnc.MCCMNC[3].mnc & 0x0F;
	            IntToStr(&ch);
	            str += ch;
	            Edit_MCC4->Text = str;
	            if(mcc_mnc.mccmnc_lock_available == 1)
	            {
	                RadioButton_MCC_Enable->Checked = true;
	            }
	            else
	            {
	                RadioButton_MCC_Disable->Checked = true;
	                Edit_MCC1->Enabled = false;
	                Edit_MCC2->Enabled = false;
	                Edit_MCC3->Enabled = false;
	                Edit_MCC4->Enabled = false;
	            }

	        }
			else
			{
				ShowMessage("TimeOut, Please Checking Connection and DUT is on!");
				return;
			}
        }
        catch(...)
        {
            ShowMessage("Read MCC/MNC ERROR");
        }
    }
}
//---------------------------------------------------------------------------


void __fastcall TSecurity_Form::Button_MCCMNCClearClick(TObject *Sender)
{
    if(RadioButton_MCC_Enable->Checked == true)
    {
        Edit_MCC1->Text = "";
        Edit_MCC2->Text = "";
        Edit_MCC3->Text = "";
        Edit_MCC4->Text = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TSecurity_Form::Button_IMSI_ReadClick(TObject *Sender)
{
    unsigned char  nItem = IMSI_LOCK_GET;
    String str;
    char chImsi[21];
    unsigned char a;
    unsigned char ch;
    //because del eidt_IMSINumber
    //Edit_IMSINumber->Enabled = true;
    //Edit_IMSINumber->Text = "";
    if(g_bOpenPort)
    {
        try
        {
			DWDIO_SetTimeOutDelay(50);
        //DWD_user_command_timeout(COMMAND_CHAR, &nItem, 1, rxdone2, 200000, g_hPort);
		    if(DWD_user_command(COMMAND_CHAR, &nItem, 1, rxdone, g_hPort))
	        {
	            if(imsi_lock.nFlag == 1)
	            {
	                RadioButton_IMSI_Enable->Checked = true;
	            }
	            else
	            {
	                RadioButton_IMSI_Disable->Checked = true;
	                //Edit_IMSINumber->Enabled = false; because del eidt_IMSINumber

	            }
	            //BytesToString(imsi_lock.chIMSINumber, chImsi, 10);
	            //because del eidt_IMSINumber
	            //Edit_IMSINumber->Text = chImsi;  because del eidt_IMSINumber
	/*            for(int i = 0; i < 10; i++)
	            {
	                a = imsi_lock.chIMSINumber[i];
	                ch = a & 0x0F;
	                if(ch > 9 && ch <= 15)
	                {
	                    ch = 'A';
	                }
	                else
	                {
	                IntToStr(&ch);
	                }
	                str += ch;
	                ch = a >> 4;
	                if(ch > 9 && ch <= 15)
	                {
	                    //ch = ch + 0x37;
	                    ch = 'A';
	                }
	                else
	                {
	                IntToStr(&ch);
	                }
	                str += ch;
	             }
	            Edit_IMSINumber->Text = str;//imsi_lock.chIMSINumber;*/
	        }
			else
			{
				ShowMessage("TimeOut, Please Checking Connection and DUT is on!");
				return;
			}
        }
        catch(...)
        {
            ShowMessage("Read IMSI ERROR");
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TSecurity_Form::Button_IMSI_WriteClick(TObject *Sender)
{

    imsi_lock.nItem = IMSI_LOCK_SET;
    unsigned char ch;
    unsigned char temp;
    Button_IMSI_Read->Enabled = false;
    Button_IMSI_Reset->Enabled = false;
    Button_IMSI_Write->Enabled = false;
    if(RadioButton_IMSI_Disable->Checked == true)
    {
        imsi_lock.nFlag = 0;
    }
    else
    {
        imsi_lock.nFlag = 1;
    }
    /*char strIMSI[21] = {0};
    //strcpy(strIMSI, Edit_IMSINumber->Text.c_str());
    //int nLen = Edit_IMSINumber->Text.Length();
    if(nLen != 20)
    {
        MessageDlg("IMSI Number Error!", mtInformation, TMsgDlgButtons() << mbOK, 0);
        Button_IMSI_Read->Enabled = true;
        Button_IMSI_Clear->Enabled = true;
        return;
    }
    char strNumber[10] = {0};
    StringToChar(strIMSI, strNumber, nLen);
    //int len = StringToChar(strIMSI, strNumber, nLen);
    String str;
    strcpy(imsi_lock.chIMSINumber, strNumber);
    for(int i = 0; i < nLen/2; i++)
    {
        temp = imsi_lock.chIMSINumber[i];
       ch = temp & 0x0F;
       IntToStr(&ch);
       str += ch;
       ch = temp >> 4;
       IntToStr(&ch);
       str += ch;
    } */

	bool bResult;
    if(g_bOpenPort)
    {
	    try
		{
			DWDIO_SetTimeOutDelay(50);
	        //DWD_user_command_timeout(COMMAND_CHAR, (unsigned char *)&imsi_lock, sizeof(imsi_lock), rxdone2, 200000, g_hPort);
	        bResult = DWD_user_command(COMMAND_CHAR, (unsigned char *)&imsi_lock, sizeof(imsi_lock), rxdone, g_hPort);
        }
        catch(...)
        {
           ShowMessage("WRITE IMSI LOCK ERROR");
        }
		
		if(!bResult)
        {
			ShowMessage("TimeOut, Please Checking Connection and DUT is on!");
            Button_IMSI_Read->Enabled = true;
            Button_IMSI_Reset->Enabled = true;
            Button_IMSI_Write->Enabled = true;
            g_bTimeout = true;
			return;
        }
    }
    Button_IMSI_Read->Enabled = true;
    Button_IMSI_Reset->Enabled = true;
    Button_IMSI_Write->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TSecurity_Form::Button_OtherLock_ReadClick(TObject *Sender)
{
    unsigned char  nItem = OTHER_LOCK_GET;
    if(g_bOpenPort)
    {
        try
        {
			DWDIO_SetTimeOutDelay(50);
        //DWD_user_command_timeout(COMMAND_CHAR, &nItem, 1, rxdone2, 20000, g_hPort);
	        if(DWD_user_command(COMMAND_CHAR, &nItem, 1, rxdone, g_hPort))
	        {
	            if(other_lock.nFlagAutokeyLock == 1)
	            {
	                RadioButton_AutoKeyLock->Checked = true;
	            }
	            else
	            {
	                RadioButton_AutoKey_Unlock->Checked = true;
	            }
	            if(other_lock.nFlagGid1 == 1)
	            {
	                RadioButton_Gid1_Lock->Checked = true;
	            }
	            else
	            {
	                RadioButton_Gid1_Unlock->Checked = true;
	            }
	            if(other_lock.nFlagGid2 == 1)
	            {
	                RadioButton_Gid2_Lock->Checked = true;
	            }
	            else
	            {
	                RadioButton_Gid2_Unlock->Checked = true;
	            }
	        }
			else
			{
				ShowMessage("TimeOut, Please Checking Connection and DUT is on!");
				return;
			}
        }
        catch(...)
        {
            ShowMessage("Read Other Lock Error");
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TSecurity_Form::Button_OtherLock_WriteClick(TObject *Sender)
{
    Button_OtherLock_Read->Enabled = false;
    Button_OtherLock_Write->Enabled = false;
    other_lock.nItem = OTHER_LOCK_SET;
    if(RadioButton_AutoKeyLock->Checked == true)
    {
        other_lock.nFlagAutokeyLock = 1;
    }
    else
    {
        other_lock.nFlagAutokeyLock = 0;
    }
    if(RadioButton_Gid1_Lock->Checked == true)
    {
        other_lock.nFlagGid1 = 1;
    }
    else
    {
        other_lock.nFlagGid1 = 0;
    }
    if(RadioButton_Gid2_Lock->Checked == true)
    {
        other_lock.nFlagGid2 = 1;
    }
    else
    {
        other_lock.nFlagGid2 = 0;
    }

	bool bResult;
    if(g_bOpenPort)
    {
        try
        {
			DWDIO_SetTimeOutDelay(50);
            //DWD_user_command_timeout(COMMAND_CHAR, (unsigned char *)&other_lock, sizeof(other_lock), rxdone2, 200000, g_hPort);
            bResult = DWD_user_command(COMMAND_CHAR, (unsigned char *)&other_lock, sizeof(other_lock), rxdone, g_hPort);
        }
        catch(...)
        {
            ShowMessage("Write OTHER LOCK ERROR");
        }

		if(!bResult)
        {
			ShowMessage("TimeOut, Please Checking Connection and DUT is on!");
            Button_OtherLock_Read->Enabled = true;
            Button_OtherLock_Write->Enabled = true;
            g_bTimeout = true;
			return;
        }
    }
    Button_OtherLock_Read->Enabled = true;
    Button_OtherLock_Write->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TSecurity_Form::FormCreate(TObject *Sender)
{
    /*Edit_MCC1->Enabled = false;
    Edit_MCC2->Enabled = false;
    Edit_MCC3->Enabled = false;
    Edit_MCC4->Enabled = false; */

    /*if(g_bOpenPort)
    {
        Label_Master_Reset->Caption = "Please keep phone on or the com open Failure!";
    }
    else
    {
        Label_Master_Reset->Caption = "Reset Phone!";
    }  */
}

void __fastcall TSecurity_Form::Button_Reset_PhoneClick(TObject *Sender)
{
     unsigned char i = MASTER_RESET_SET;
     bool bResult;
    if(g_bOpenPort)
    {
        Button_Reset_Phone->Enabled = false;
        try
		{
	        DWDIO_SetTimeOutDelay(50);
	//        DWD_user_command_timeout(COMMAND_CHAR, (unsigned char *)&i, 1, rxdone2, 10000, g_hPort);
	        bResult= DWD_user_command(COMMAND_CHAR, /*(unsigned char *)*/&i, 1, rxdone, g_hPort);
        }
        catch(...)
        {
            ShowMessage("Reset Error");
        }
        //Prompt_Form->Hide();
        //ShowMessage("reset ok");
        if(!bResult)
        {
			ShowMessage("TimeOut, Please Checking Connection and DUT is on!");
            g_bTimeout = true;
        }
        Button_Reset_Phone->Enabled = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TSecurity_Form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Security_Form->Hide();
    MainForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TSecurity_Form::Button_IMSI_ResetClick(TObject *Sender)
{
    unsigned char i = IMSI_LOCK_RESET;
	bool bResult;
    if(g_bOpenPort)
    {
        //Button_Reset_Phone->Enabled = false;
        //DWD_user_command_timeout(COMMAND_CHAR, (unsigned char *)&i, 1, rxdone, 20000, g_hPort);
		try
        {
			DWDIO_SetTimeOutDelay(50);
			bResult = DWD_user_command(COMMAND_CHAR, /*(unsigned char *)*/&i, 1, rxdone, g_hPort);        
        }
		catch(...)
		{
			ShowMessage("Reset Error");
		}

		if(!bResult)
        {
			ShowMessage("TimeOut, Please Checking Connection and DUT is on!");
            g_bTimeout = true;
			return;
        }
        //Button_Reset_Phone->Enabled = true;
    }
	

}
//---------------------------------------------------------------------------

void __fastcall TSecurity_Form::SIMLock_ClearClick(TObject *Sender)
{
    if(RadioButton_SIM_Enable->Checked == true)
    {
        Edit_SIM_PIN_Default->Text = "";
        Edit_SIM_PIN_Locked->Text = "";
        ComboBox_AutoSIMState->Text = "";
    }

    /*if(RadioButton_SIM_Enable->Checked == true)
    {
        RadioButton_SIM_Disable->Checked = true;
    }
    if(strcmp(ComboBox_AutoSIMState->Text.c_str(), "Active") == 0)
    {
        ComboBox_AutoSIMState->Text = "Deactive" ;
    } 
    if(CheckBox_Random_SIM_PIN->Checked == true)
    {
        CheckBox_Random_SIM_PIN->Checked = false;
    }*/
}
//---------------------------------------------------------------------------

void __fastcall TSecurity_Form::TabSheet_MCCShow(TObject *Sender)
{
    /*Edit_MCC1->Enabled = false;
    Edit_MCC2->Enabled = false;
    Edit_MCC3->Enabled = false;
    Edit_MCC4->Enabled = false; */
}
//---------------------------------------------------------------------------

void __fastcall TSecurity_Form::PageControl_SecurityChange(TObject *Sender)
{
    /*Edit_MCC1->Enabled = false;
    Edit_MCC2->Enabled = false;
    Edit_MCC3->Enabled = false;
    Edit_MCC4->Enabled = false; */
}
//---------------------------------------------------------------------------

void __fastcall TSecurity_Form::RadioButton_MCC_DisableClick(
      TObject *Sender)
{
    Edit_MCC1->Enabled = false;
    Edit_MCC2->Enabled = false;
    Edit_MCC3->Enabled = false;
    Edit_MCC4->Enabled = false;

}
//---------------------------------------------------------------------------

void __fastcall TSecurity_Form::RadioButton_MCC_EnableClick(
      TObject *Sender)
{
    Edit_MCC1->Enabled = true;
    Edit_MCC2->Enabled = true;
    Edit_MCC3->Enabled = true;
    Edit_MCC4->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TSecurity_Form::RadioButton_SIM_DisableClick(
      TObject *Sender)
{
    Edit_SIM_PIN_Default->Enabled = false;
    Edit_SIM_PIN_Locked->Enabled = false;
    ComboBox_AutoSIMState->Enabled = false;
    CheckBox_Random_SIM_PIN->Enabled = false;

}
//---------------------------------------------------------------------------

void __fastcall TSecurity_Form::RadioButton_SIM_EnableClick(
      TObject *Sender)
{
    Edit_SIM_PIN_Default->Enabled = true;
    Edit_SIM_PIN_Locked->Enabled = true;
    ComboBox_AutoSIMState->Enabled = true;
    CheckBox_Random_SIM_PIN->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TSecurity_Form::ComboBox_AutoSIMStateClick(TObject *Sender)
{
    if(strcmp(ComboBox_AutoSIMState->Text.c_str(), "Deactive") == 0)
    {
        Edit_SIM_PIN_Default->Enabled = false;
        Edit_SIM_PIN_Locked->Enabled = false;
    }
    else
    {
        Edit_SIM_PIN_Default->Enabled = true;
        Edit_SIM_PIN_Locked->Enabled = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TSecurity_Form::RadioButton_IMSI_DisableClick(
      TObject *Sender)
{
    //Edit_IMSINumber->Enabled = false;  because del eidt_IMSINumber
}
//---------------------------------------------------------------------------

void __fastcall TSecurity_Form::RadioButton_IMSI_EnableClick(
      TObject *Sender)
{
    //Edit_IMSINumber->Enabled = true; because del eidt_IMSINumber
}
//---------------------------------------------------------------------------

