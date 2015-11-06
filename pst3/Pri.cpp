//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Pri.h"
#include "def_paramter.h"
#include "dwdptest.h"
#include <stdio.h>
#include <Registry.hpp>
#include <windows.h>
#include "main.h"
#include "prompt.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

bool g_bSetBanner = false;  //false :正在下载开机动画图片, true:表示下载开机动画图片操作完成
bool g_bSmsTemplateWrite = false;  //false:正在写短消息模板, true:表示写短消息模板操作完成
bool g_bSmsTemplateRead = false;   //false:正在读短消息模板, true:表示读短消息模板操作完成
extern char outfilename[100];
extern bool g_bOpenPort;
extern int g_hPort;
extern bool g_bAllWrited;
extern bool IsDigit(const char* pSrc);
extern bool g_bTimeout;

TPRI_Form *PRI_Form;
typedef struct
{
    LONG nWidth;
    LONG nHeight;
    WORD dwBitsPixel;
}BMP_WHPIXEL; //定义BMP图的高、宽和象素服

typedef struct
{
    BYTE nItem; //read sms template flag
    BYTE index; // read NO. sms template
}SMS_ITEM; //读取第条短消息模板

BMP_WHPIXEL width_height_pixel;

//---------------------------------------------------------------------------
__fastcall TPRI_Form::TPRI_Form(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TPRI_Form::FormCreate(TObject *Sender)
{
    OpenDialog_Banner->DefaultExt = "bmp";
    OpenDialog_Banner->Filter = "位图文件(*.bmp)|*.bmp|所有文件(*.*)|*.*";
}
//---------------------------------------------------------------------------

void __fastcall TPRI_Form::Button_Banner_Open1Click(TObject *Sender)
{
    if(OpenDialog_Banner->Execute())
    {
        Edit_Banner_File1->Text = OpenDialog_Banner->FileName;
    }
}
//---------------------------------------------------------------------------


void __fastcall TPRI_Form::Button_Banner_Open2Click(TObject *Sender)
{
    if(OpenDialog_Banner->Execute())
    {
        Edit_Banner_File2->Text = OpenDialog_Banner->FileName;
    }
}
//---------------------------------------------------------------------------

/*void __fastcall TPRI_Form::Button_Banner_Open3Click(TObject *Sender)
{
    if(OpenDialog_Banner->Execute())
    {
        Edit_Banner_File1->Text = OpenDialog_Banner->FileName;
    }
}
//---------------------------------------------------------------------------

void __fastcall TPRI_Form::Button_Banner_Open4Click(TObject *Sender)
{
    if(OpenDialog_Banner->Execute())
    {
        Edit_Banner_File1->Text = OpenDialog_Banner->FileName;
    }
}
//---------------------------------------------------------------------------

void __fastcall TPRI_Form::Button_Banner_Open5Click(TObject *Sender)
{
    if(OpenDialog_Banner->Execute())
    {
        Edit_Banner_File1->Text = OpenDialog_Banner->FileName;
    }
}
//---------------------------------------------------------------------------

void __fastcall TPRI_Form::Button_Banner_Open6Click(TObject *Sender)
{
    if(OpenDialog_Banner->Execute())
    {
        Edit_Banner_File1->Text = OpenDialog_Banner->FileName;
    }
}
//---------------------------------------------------------------------------
*/


void __fastcall TPRI_Form::Button_VoiceMail_WriteClick(TObject *Sender)
{
    VOICE_MAIL voice_mail = {0};
    char strTemp[21] = {0};
	bool bResult;

    if(Edit_VoiceMail->Text.Length() == 0)
    {
        ShowMessage("VoiceMail Number is Empty");
        return;
    }
    Button_VoiceMail_Read->Enabled = false;
    Button_VoiceMail_Clear->Enabled = false;
    Button_VoiceMail_Write->Enabled = false;

    strcpy(strTemp, Edit_VoiceMail->Text.c_str());
    if(!IsDigit(strTemp))
    {
        Button_VoiceMail_Read->Enabled = true;
        Button_VoiceMail_Clear->Enabled = true;
        Button_VoiceMail_Write->Enabled = true;
        return;
    }

    strcpy(voice_mail.chVoiceNumber, Edit_VoiceMail->Text.c_str());
    voice_mail.nItem = VOICE_MAIL_SET;
    if(g_bOpenPort)
    {
        try
        {
			DWDIO_SetTimeOutDelay(50);
            //DWD_user_command_timeout(COMMAND_CHAR, (unsigned char *)&voice_mail, sizeof(voice_mail), rxdone2, 200000, g_hPort);
            bResult = DWD_user_command(COMMAND_CHAR, (unsigned char *)&voice_mail, sizeof(voice_mail), rxdone, g_hPort);
        }
        catch(...)
        {
            ShowMessage("Write Voice Mail ERROR");
        }
		if(!bResult)
        {			
			ShowMessage("TimeOut, Please Checking Connection and DUT is on!");
            Button_VoiceMail_Read->Enabled = true;
            Button_VoiceMail_Clear->Enabled = true;
            Button_VoiceMail_Write->Enabled = true;
            g_bTimeout = true;
			return;
        }
    }
    Button_VoiceMail_Read->Enabled = true;
    Button_VoiceMail_Clear->Enabled = true;
    Button_VoiceMail_Write->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TPRI_Form::Button_VoiceMail_ReadClick(TObject *Sender)
{
    unsigned char nItem = VOICE_MAIL_GET;
    if(g_bOpenPort)
    {
        try
        {
			DWDIO_SetTimeOutDelay(50);
	        //DWD_user_command_timeout(COMMAND_CHAR, &nItem, 1, rxdone2, 200000, g_hPort);
	        if(DWD_user_command(COMMAND_CHAR, &nItem, 1, rxdone, g_hPort))
	        {
	            Edit_VoiceMail->Text = voice_mail.chVoiceNumber;
	        }
			else
			{
				ShowMessage("TimeOut, Please Checking the ComPort Connected!");
				return;
			}
        }
        catch(...)
        {
            ShowMessage("Read Voice Mail ERROR");
			return;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TPRI_Form::Button_EM_WriteClick(TObject *Sender)
{
    char strTemp[3][4] = {0};
	bool bResult;
    Button_EM_Read->Enabled = false;
    Button_EM_Clear->Enabled = false;
    Button_EM_Write->Enabled = false;
    if(Edit_EM_Number1->Text.Length() == 0
    && Edit_EM_Number2->Text.Length() == 0
    && Edit_EM_Number3->Text.Length() == 0)
    {
        ShowMessage("Emergency Number is Empty");
        Button_EM_Read->Enabled = true;
        Button_EM_Clear->Enabled = true;
        Button_EM_Write->Enabled = true;
        return;
    }
    
    strcpy(strTemp[0], Edit_EM_Number1->Text.c_str());
    strcpy(strTemp[1], Edit_EM_Number2->Text.c_str());
    strcpy(strTemp[2], Edit_EM_Number3->Text.c_str());
    for(int i = 0; i < 3; i++)
    {
        if(!IsDigit(strTemp[i]))
        {
            Button_EM_Read->Enabled = true;
            Button_EM_Clear->Enabled = true;
            Button_EM_Write->Enabled = true;
            return;
        }
    }

    emergency_number.nItem = EMERGENCY_NUMBER_SET;
    strcpy(emergency_number.chEmergencyNumber1, Edit_EM_Number1->Text.c_str());
    strcpy(emergency_number.chEmergencyNumber2, Edit_EM_Number2->Text.c_str());
    strcpy(emergency_number.chEmergencyNumber3, Edit_EM_Number3->Text.c_str());
    if(g_bOpenPort)
    {
        try
        {
			DWDIO_SetTimeOutDelay(50);
            //DWD_user_command_timeout(COMMAND_CHAR, (unsigned char *)&emergency_number, sizeof(emergency_number), rxdone2, 200000, g_hPort);
            bResult = DWD_user_command(COMMAND_CHAR, (unsigned char *)&emergency_number, sizeof(emergency_number), rxdone, g_hPort);
        }
        catch(...)
        {
            ShowMessage("Write Emergency Number ERROR");
        }
		if(!bResult)
        {
			ShowMessage("TimeOut, Please Checking Connection and DUT is on!");
            Button_EM_Read->Enabled = true;
            Button_EM_Clear->Enabled = true;
            Button_EM_Write->Enabled = true;
            g_bTimeout = true;
			return;
        }
    }
    Button_EM_Read->Enabled = true;
    Button_EM_Clear->Enabled = true;
    Button_EM_Write->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TPRI_Form::Button_EM_ReadClick(TObject *Sender)
{
    unsigned char nItem = EMERGENCY_NUMBER_GET;
    char chEmergencyNumber[10]={0};
    //Edit_EM_Number1->Text  = a;
    if(g_bOpenPort)
    {
        try
        {
			DWDIO_SetTimeOutDelay(50);
	        //DWD_user_command_timeout(COMMAND_CHAR, (unsigned char *)&other_lock, sizeof(other_lock), rxdone2, 200000, g_hPort);
	        if(DWD_user_command(COMMAND_CHAR, &nItem, 1, rxdone, g_hPort))
	        {
                for(int i =0 ;i<5;i++)
                {
	                chEmergencyNumber[i] = emergency_number.chEmergencyNumber1[i];
                }
	//            memcpy(a, &emergency_number.chEmergencyNumber1[0],4) ;
	            Edit_EM_Number1->Text = chEmergencyNumber;
	            strcpy(chEmergencyNumber, emergency_number.chEmergencyNumber2) ;
	            Edit_EM_Number2->Text = chEmergencyNumber;
	            strcpy(chEmergencyNumber, emergency_number.chEmergencyNumber3) ;
	            Edit_EM_Number3->Text = chEmergencyNumber;
	            #if 0
	            Edit_EM_Number1->Text = emergency_number.chEmergencyNumber1;
	            Edit_EM_Number2->Text = emergency_number.chEmergencyNumber2;
	            Edit_EM_Number3->Text = emergency_number.chEmergencyNumber3;
	            #endif
	        }
			else
			{
				ShowMessage("TimeOut, Please Checking Connection and DUT is on!");
				return;
			}
        }
        catch(...)
        {
            ShowMessage("Read Emergency Number ERROR");
        }
    }

}
//---------------------------------------------------------------------------

void __fastcall TPRI_Form::Button_EM_ClearClick(TObject *Sender)
{
    Edit_EM_Number1->Text = "";
    Edit_EM_Number2->Text = "";
    Edit_EM_Number3->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TPRI_Form::Button_VoiceMail_ClearClick(TObject *Sender)
{
    Edit_VoiceMail->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TPRI_Form::Button_WriteSMSClick(TObject *Sender)
{
    int nLen;
    WCHAR wSmsTemplate[10][MAX_SMS_TEXT_LENGTH] = {0};
    sms_template.nItem = SMS_TEMPLATE_SET;
    g_bSmsTemplateWrite = false;

    if(Edit_SMSTemplate1->Text.Length() == 0
    & Edit_SMSTemplate2->Text.Length() == 0
    & Edit_SMSTemplate3->Text.Length() == 0
    & Edit_SMSTemplate4->Text.Length() == 0
    & Edit_SMSTemplate5->Text.Length() == 0
    & Edit_SMSTemplate6->Text.Length() == 0
    & Edit_SMSTemplate7->Text.Length() == 0
    & Edit_SMSTemplate8->Text.Length() == 0
    & Edit_SMSTemplate9->Text.Length() == 0
    & Edit_SMSTemplate10->Text.Length() == 0)
    {
        ShowMessage("Sms Template All Empty");
        return;
    }

    Prompt_Form->Show();
    
    nLen = Edit_SMSTemplate1->Text.Length();
    StringToWideChar(Edit_SMSTemplate1->Text, wSmsTemplate[0], nLen + 1);

    nLen = Edit_SMSTemplate2->Text.Length();
    StringToWideChar(Edit_SMSTemplate2->Text, wSmsTemplate[1], nLen + 1);

    nLen = Edit_SMSTemplate3->Text.Length();
    StringToWideChar(Edit_SMSTemplate3->Text, wSmsTemplate[2], nLen + 1);

    nLen = Edit_SMSTemplate4->Text.Length();
    StringToWideChar(Edit_SMSTemplate4->Text, wSmsTemplate[3], nLen + 1);

    nLen = Edit_SMSTemplate5->Text.Length();
    StringToWideChar(Edit_SMSTemplate5->Text, wSmsTemplate[4], nLen + 1);

    nLen = Edit_SMSTemplate6->Text.Length();
    StringToWideChar(Edit_SMSTemplate6->Text, wSmsTemplate[5], nLen + 1);

    nLen = Edit_SMSTemplate7->Text.Length();
    StringToWideChar(Edit_SMSTemplate7->Text, wSmsTemplate[6], nLen + 1);

    nLen = Edit_SMSTemplate8->Text.Length();
    StringToWideChar(Edit_SMSTemplate8->Text, wSmsTemplate[7], nLen + 1);

    nLen = Edit_SMSTemplate9->Text.Length();
    StringToWideChar(Edit_SMSTemplate9->Text, wSmsTemplate[8], nLen + 1);

    nLen = Edit_SMSTemplate10->Text.Length();
    StringToWideChar(Edit_SMSTemplate10->Text, wSmsTemplate[9], nLen + 1);

/*    wcscpy(sms_template.chSmsTemplate, wSmsTemplate[0]);
    wcscpy(sms_template.chSmsTemplate, wSmsTemplate[1]);
    wcscpy(sms_template.chSmsTemplate, wSmsTemplate[2]);*/
	bool bResult;
    if(g_bOpenPort)
    {
        for(int i = 0; i <10; i++)
        {
            sms_template.index = i;
            wcscpy(sms_template.chSmsTemplate, wSmsTemplate[i]);
            try
            {
				DWDIO_SetTimeOutDelay(50);
                //DWD_user_command_timeout(COMMAND_CHAR, (unsigned char *)&sms_template, sizeof(sms_template), rxdone2, 200000, g_hPort);
                bResult = DWD_user_command(COMMAND_CHAR, (unsigned char *)&sms_template, sizeof(sms_template), rxdone, g_hPort);
            }
            catch(...)
            {
                ShowMessage("Write SMS Template ERROR");
            }
			if(!bResult)
	        {
				ShowMessage("TimeOut, Please Checking Connection and DUT is on!");
                g_bTimeout = true;
				return;
	        }
        }
    }
    g_bSmsTemplateWrite = true;
    Prompt_Form->Close();
}
//---------------------------------------------------------------------------

void __fastcall TPRI_Form::Button_ReadSMSClick(TObject *Sender)
{
    //unsigned char nItem = SMS_TEMPLATE_GET;
    unsigned char index;
    SMS_ITEM sms_item;
    g_bSmsTemplateRead = false;

    Prompt_Form->Show();
    
    /*int j = 0;
    do
    {
        j++;
    }while(j < 50000);
    //Form1->Show(); */
    Edit_SMSTemplate1->Text = "";
    Edit_SMSTemplate2->Text = "";
    Edit_SMSTemplate3->Text = "";
    Edit_SMSTemplate4->Text = "";
    Edit_SMSTemplate5->Text = "";
    Edit_SMSTemplate6->Text = "";
    Edit_SMSTemplate7->Text = "";
    Edit_SMSTemplate8->Text = "";
    Edit_SMSTemplate9->Text = "";
    Edit_SMSTemplate10->Text = "";

    if(g_bOpenPort)
    {
        for(int i = 0; i < 10; i++)
        {
            sms_item.nItem = SMS_TEMPLATE_GET;
            sms_item.index = i;
            try
            {
				DWDIO_SetTimeOutDelay(50);
            //DWD_user_command_timeout(COMMAND_CHAR, (unsigned char *)&sms_item, sizeof(sms_item), rxdone2, 200000, g_hPort);
	            if(DWD_user_command(COMMAND_CHAR, (unsigned char *)&sms_item, sizeof(sms_item), rxdone, g_hPort))
	            {
	                index = sms_template.index;
	                switch(index)
	                {
	                    //memset(&strTemp, 0, sizeof(strTemp));
	                    case 0:
	                    //WideCharToStrVar(sms_template.chSmsTemplate, Edit_SMSTemplate1->Text);
	                    Edit_SMSTemplate1->Text = WideCharLenToString(sms_template.chSmsTemplate, 30);
	                    //Edit_SMSTemplate1->Text = sms_template.chSmsTemplate;
	                    break;
	                    case 1:
	                    //strTemp = WideCharLenToString(sms_template.chSmsTemplate, 30);
	                    //strTemp[31] = '\0';
	                    Edit_SMSTemplate2->Text = WideCharLenToString(sms_template.chSmsTemplate, 30);
	                    break;
	                    case 2:
	                    Edit_SMSTemplate3->Text = WideCharLenToString(sms_template.chSmsTemplate, 30);
	                    break;
	                    case 3:
	                    Edit_SMSTemplate4->Text = WideCharLenToString(sms_template.chSmsTemplate, 30);
	                    break;
	                    case 4:
	                    Edit_SMSTemplate5->Text = WideCharLenToString(sms_template.chSmsTemplate, 30);
	                    break;
	                    case 5:
	                    Edit_SMSTemplate6->Text = WideCharLenToString(sms_template.chSmsTemplate, 30);
	                    break;
	                    case 6:
	                    Edit_SMSTemplate7->Text = WideCharLenToString(sms_template.chSmsTemplate, 30);
	                    break;
	                    case 7:
	                    Edit_SMSTemplate8->Text = WideCharLenToString(sms_template.chSmsTemplate, 30);
	                    break;
	                    case 8:
	                    Edit_SMSTemplate9->Text = WideCharLenToString(sms_template.chSmsTemplate, 30);
	                    break;
	                    case 9:
	                    Edit_SMSTemplate10->Text = WideCharLenToString(sms_template.chSmsTemplate, 30);
	                    break;
	                    default:
	                    break;
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
            ShowMessage("Read SMS Template ERROR");
            }
        }
    }
    g_bSmsTemplateRead = true;
    Prompt_Form->Hide();
}
//---------------------------------------------------------------------------

//unsigned char BITBuf[65][129];
void ReadRowDataToBitBuff(unsigned char RowBuff[], int RowLen, BYTE BitBuff[])
{
	int i,j;
	BYTE RowByte;
    BYTE temp;

	for(i=0; i<RowLen; i++)
	{
		RowByte = RowBuff[i];
		for(j=0; j<8; j++)
		{
			BitBuff[i*8 + j] = RowByte >> 7;
            temp = RowByte & 0x7F;
            RowByte = temp << 1;
            //BitBuff[i*8 + j] = RowByte >> (7 - j);
			//RowByte = RowByte & ((1 << (7 - j)) - 1);
		}
	}
}

/*int WriteBinBuff(unsigned char* BinBuff, int iWidth, int iHeight)
{
   int pack=0, i, j, k;
   pack = iHeight / 8;
   unsigned char TempBuff[1025] = {0};
   for(k = 0; k < pack; k++)
   {
        for(i = 0; i<iWidth; i++)
            {
                for(j = 0; j < 8; j++)
                {
                    TempBuff[k*8*iWidth + i*8 + j] = BITBuf[k * 8 + j][i];
                }
            }
   }

   BYTE p, data;
   int size = iHeight*iWidth;
	    //size = (size%8 == 0)?(size / 8):(size / 8 + 1);
   size = ((iHeight + 7) / 8) * iWidth;
   for(int index=0; index<size; index++)
   {
        p=0;
        for(int x=0;x<8;x++)
        {
            data=TempBuff[index*8+x];
            data=data<<x;
            p |= data;
        }
        BinBuff[index] = p;
   }
   return size;
}  */
/*int WriteBinBuff(unsigned char BinBuff[], int iWidth, int iHeight)
{

	BYTE TempBuff[64 * 112],data,p;
    //char BITBuff[100][100];
	int i,j,size,index,x;
	for(i = 0; i<iWidth; i++)
	{
		for(j=0; j<iHeight; j++)
		{
			TempBuff[i * iHeight + j] = BITBuf[iHeight - j - 1][i];
		}
	}

	size = iWidth*iHeight;
	size = (size%8 == 0)?(size / 8):(size / 8 + 1);
	for(index=0; index<size; index++)
	{
		p=0;
		for(x=0;x<8;x++)
		{
			data=TempBuff[index*8+x];
			data=data<<x;
			p |= data;
		}
		BinBuff[index] = p;
	}

	return size;
} */
/*    BMP图转换为LCD能显示的点陈                */
int bmpconvert(const char *pSrc, unsigned char BinBuff[])
{
    BITMAP TempBMP;
    HBITMAP hBitmap;
    HINSTANCE hInstance;
    int countByte;
    int nRowLen;
    int nRowCount;
    //int nColCount;
    unsigned char strBuf[1025] = {0};
    unsigned char BitBuf[100][20];
    unsigned char TempBuf[100][20];
    unsigned char TempBuf1[10000] ={0};
    unsigned char BITBuf[65][129];
    int i, j, k = 0;
    int pack, size;
    BYTE p, data;

    memset(BitBuf, 0, sizeof(BitBuf));
    memset(TempBuf, 0, sizeof(TempBuf));
    memset(BITBuf, 0, sizeof(BITBuf));
    BYTE TempBuff[129*65];
    memset(&width_height_pixel, 0 ,sizeof(width_height_pixel));

    hBitmap = (HBITMAP)LoadImage(hInstance, pSrc, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);
       GetObject(hBitmap , sizeof(TempBMP) , &TempBMP);
      //图片尺寸和象素不对时提示信息
      if((TempBMP.bmWidth != 128) || (TempBMP.bmHeight != 64) || (TempBMP.bmBitsPixel != 1))
        {
            MessageDlg("Open Bitmap Error!", mtInformation, TMsgDlgButtons() << mbOK, 0);
            return 0;//0;
        }
        width_height_pixel.nWidth = TempBMP.bmWidth;
        width_height_pixel.nHeight = TempBMP.bmHeight;
        width_height_pixel.dwBitsPixel = TempBMP.bmBitsPixel;
        nRowLen = (TempBMP.bmWidth + 31)/32 * 4; //一行字节数
        nRowCount = TempBMP.bmHeight;// (TempBMP.bmHeight +7)/8 *8; //行数

        countByte = nRowLen*TempBMP.bmHeight;//TempBMP.bmHeight * TempBMP.bmWidth / TempBMP.bmWidthBytes * nRowLen / 8;  //图片数据总字节数
        memcpy(strBuf, TempBMP.bmBits, countByte);

        for(i = 0; i < nRowCount; i++)
        {
            memcpy(BitBuf[i], strBuf + i*nRowLen, nRowLen);
            //ReadBmpData(strBuf, nRowLen, BitBuf[i]);
            for(j = 0; j < nRowLen; j++)
            {
                BitBuf[i][j] = ~BitBuf[i][j];
            }
        }

        //由于BMP图最后一行数据放的是第一行的数据，所把最后一个放在第一个，第一个放在最后一个，依此反序。
        for(i = nRowCount; i >0 ; i--)
        {
            memcpy(TempBuf1 + k*nRowLen, &BitBuf[i-1], nRowLen);
            k++;
        }

        for(i=0; i<TempBMP.bmHeight; i++)
	    {
	    	ReadRowDataToBitBuff(&TempBuf1[i*nRowLen], nRowLen, BITBuf[i]);
	    }

        pack = TempBMP.bmHeight / 8;
        for(k = 0; k < pack; k++)
        {
            for(i = 0; i<TempBMP.bmWidth; i++)
            {
                for(j = 0; j < 8; j++)
                {
                    TempBuff[k*8*TempBMP.bmWidth + i*8 + j] = BITBuf[k * 8 + j][i];
                }
            }
        }

        //size = TempBMP.bmHeight*TempBMP.bmWidth;
	    //size = (size%8 == 0)?(size / 8):(size / 8 + 1);
        size = ((TempBMP.bmHeight + 7) / 8) * TempBMP.bmWidth;
	    for(int index=0; index<size; index++)
	    {
		    p=0;
		    for(int x=0;x<8;x++)
		    {
			    data=TempBuff[index*8+x];
			    data=data<<x;
			    p |= data;
		    }
		    BinBuff[index] = p;
	    }
        return size;
}

void __fastcall TPRI_Form::Button_SetBannerClick(TObject *Sender)
{
    int i;
    int index;
    BYTE BinBuff[1025]={0};
    BYTE BinBuff1[1025]={0};
    g_bSetBanner = false;
    int nbmp1, nbmp2;
    //StatusBar1->Panels->Items[0]->Text = "Downloading picture Please wait...";


    memset(&set_banner, 0, sizeof(set_banner));
    if(Edit_Banner_File1->Text == "" || Edit_Banner_File2->Text == "")
    {
        MessageDlg("NO Open Bitmap or Only open one Bitmap!", mtInformation, TMsgDlgButtons() << mbOK, 0);
        return;
    }

    if(Edit_Banner_File1->Text != "")
    {
       nbmp1 = bmpconvert(Edit_Banner_File1->Text.c_str(), BinBuff);

    }
    if(Edit_Banner_File2->Text != "")
    {
        nbmp2 = bmpconvert(Edit_Banner_File2->Text.c_str(), BinBuff1);
    }
    if(nbmp1 != 0 && nbmp2 != 0)
    {
    Prompt_Form->Show();
    set_banner.nItem = BANNER_SET;
    for(int j = 0; j < 2; j++)
    {
        for(i = 0; i < 6; i++)
        {
            memset(set_banner.p_bitmap, 0, sizeof(set_banner.p_bitmap));
            set_banner.index = j;
            if(i == 5)
            {
                set_banner.nLen = 1024 - i*180;
            }
            else
            {
                set_banner.nLen = 180;
            }
            set_banner.nFrame = i;
            set_banner.width = width_height_pixel.nWidth;
            set_banner.height = width_height_pixel.nHeight;
            set_banner.bits = width_height_pixel.dwBitsPixel;
            if(j == 1)
            {
                memcpy(set_banner.p_bitmap, BinBuff1 + i*180, 180);
            }
            else
            {
                memcpy(set_banner.p_bitmap, BinBuff + i*180, 180);
            }
			
			bool bResult;
			
            if(g_bOpenPort)
            {
                try
                {
					DWDIO_SetTimeOutDelay(50);
                    //DWD_user_command_timeout(COMMAND_CHAR, (unsigned char *)&set_banner, sizeof(set_banner), rxdone2, 200000, g_hPort);
                    bResult = DWD_user_command(COMMAND_CHAR, (unsigned char *)&set_banner, sizeof(set_banner), rxdone, g_hPort);
                }
                catch(...)
                {
                    ShowMessage("Set Banner ERROR");
                }
				if(!bResult)
		        {
					ShowMessage("TimeOut, Please Checking Connection and DUT is on!");
                    g_bTimeout = true;
					return;
		        }

            }
        }
    }

    g_bSetBanner = true;
    Prompt_Form->Close();
    }
    //StatusBar1->Panels->Items[0]->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TPRI_Form::FormClose(TObject *Sender, TCloseAction &Action)
{
    PRI_Form->Hide();
    MainForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TPRI_Form::Button_SMS_ClearClick(TObject *Sender)
{
    Edit_SMSTemplate1->Text = "";
    Edit_SMSTemplate2->Text = "";
    Edit_SMSTemplate3->Text = "";
    Edit_SMSTemplate4->Text = "";
    Edit_SMSTemplate5->Text = "";
    Edit_SMSTemplate6->Text = "";
    Edit_SMSTemplate7->Text = "";
    Edit_SMSTemplate8->Text = "";
    Edit_SMSTemplate9->Text = "";
    Edit_SMSTemplate10->Text = "";
}
//---------------------------------------------------------------------------

 


